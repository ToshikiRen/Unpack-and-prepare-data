import zipfile
import re, os
from openpyxl import load_workbook
from openpyxl.styles import PatternFill
from datetime import datetime
import patoolib
import shutil

# sheet_names = ["321AA", "322AA", "323AA", "324AA", "Restantieri (AA)", "321AB",
#                "322AB", "323AB", "324AB", "321AC", "322AC", "323AC", "324AC"]
sheet_names = ["312AB"]

class Friend():

    def __init__(self, data):
        [self.name, self.percent] = return_name_percent(data)
        self.name = addSpace(self.name)
    
    def get_name(self):
        return self.name

    def get_percent(self):
        return self.percent

class Friends:

    def __init__(self, first, second, lines):
        self.first = Friend(first)
        self.second = Friend(second)
        self.lines = lines

    def __str__(self):
        first = self.first.get_name()
        second = self.second.get_name()
        lines = self.lines

        return first + ' si ' + second + ' au ' + str(int(lines)) + ' de linii identice!'

    def get_name_first(self):
        return self.first.get_name()

    def get_name_second(self):
        return self.second.get_name()
    
    def get_percent_first(self):
        return self.first.get_percent()

    def get_percent_second(self):
        return self.second.get_percent()

    def get_lines(self):
        return self.lines

    def get_mean_percent(self):
        return (self.first.get_percent() + self.second.get_percent())/2

# Adds one space between firstname and lastname
def addSpace(nameString):
    
    nameList = []
    nameList.append(nameString[0])
    for i in range(1, len(nameString)):
        if nameString[i - 1].islower() and nameString[i].isupper():
            nameList.append(" ")
        nameList.append(nameString[i])
    return "".join(nameList)


# Returns data from moss sheet while removing the path
def return_data(active_sheet, desired_collums, substringData = 'C:/Users/leona/OneDrive/Desktop/Moss/'):
    
    firstCol = active_sheet[desired_collums[0]]
    data = [ [] for j in range(len(firstCol)) if firstCol[j].value != None ]
    for col in desired_collums:
    
        for row in range(0,len(active_sheet[col])):
            cell = active_sheet[col][row].value
            if cell != None:
                data[row].append(remove_substr(cell, substringData))

    return data

# Returns the data from the moss sheet wraped in a class
def return_class_data(active_sheet, desired_collums, substringData = 'C:/Users/leona/OneDrive/Desktop/Moss/'):
    
    data = return_data(active_sheet, desired_collums, substringData)
    returned_data = []
    for row in range(len(data)):
        returned_data.append(Friends(data[row][0], data[row][1], data[row][2]))
    
    return returned_data

# String removal with try to avoid type errors
def remove_substr(stringData, substringData):
    try:
       return_data = stringData.replace(substringData, '')
    except:
        return stringData
    return return_data


#Returns the fullname and similarity percent
def return_name_percent(stringData):

    name = "".join([c for c in stringData if not c.isdigit() and c not in "()%/"])
    percent = float(re.sub('[^0-9]+', '', stringData))
    name = name[:-1]
    return [name, percent]

# Removes submission data
def remove_submission_data(stringData, moss = True):
    stringData = remove_substr(stringData, '_assignsubmission_file_')
    stringData = "".join([y for y in stringData if not y.isdigit() and y not in "_()%/"])

    if moss:
        return stringData[:-1]
    return stringData
    
# Renames all the files from moodle in order to keep only the fullname
# of the student
def rename_all(folderName):

    initialFolder = os.getcwd()
    os.chdir(folderName)
    submissionList = os.listdir()

    for friend in submissionList:
        os.rename(friend, remove_submission_data(friend, False))

    os.chdir(initialFolder)

# Color one row
def setRowColor(sheet, index, color):
    for colorRow in sheet.iter_rows(min_row = index, max_row = index, min_col = 1):
        for cell in colorRow:
            cell.fill = PatternFill(start_color = color,  fill_type = "solid")

# Creates an .xlsx where all the naughty ones have 0 and are colored red
def above_threshold(catalogName, class_data, threshold, gradeCol, make_red = True):
    
    catalog = load_workbook(filename = catalogName)
    naughtySet = set()
    
    # Find all the naughty ones
    for friends in class_data:

        if friends.get_mean_percent() >= threshold:
            naughtySet.add(friends.get_name_first())
            naughtySet.add(friends.get_name_second())
    
    # Mark all naughty ones 
    for fiend in naughtySet:
        executed = False
        for sheet_name in sheet_names:
            sheet = catalog[sheet_name]
            
            for row in sheet.iter_rows(min_row = 2, min_col = 1):
                name = row[1].value

                if name == None:
                    break
                index = int(row[0].value) + 1
                
                # Mark the naughty one 
                if name == fiend:
                    executed = True
                    if make_red:
                        setRowColor(sheet, index, 'ff0000')
                    row[gradeCol - 1].value = 0
                    break
                    
            if executed:
                break
                
    now = datetime.now()
    current_time = now.strftime("%H-%M-%S")
    catalogName = catalogName.replace('.xlsx', '') + str(current_time)+ '.xlsx'
    catalog.save(catalogName)

    return naughtySet

# Unzip files in folder and rename unzipfile
def unzip_files(folder, subFolderName = "src"):
    
    naughtyOnes = open("naughtyOnes.txt", mode = "w", encoding = 'UTF-8')
    
    
    initialFolder = os.getcwd()
    os.chdir(folder)
    folder_list = os.listdir()
    root_folder = os.path.join(initialFolder, folder)

    for attempt in folder_list:
        # Path to attemt 
        attempt_folder = os.path.join(root_folder, attempt)
        os.chdir(attempt_folder)
        # Get the first zip-file
        zip_file = os.listdir()
        
        try:
            zip_file = zip_file[0]
            path_to_zip_file = os.path.join(attempt_folder, zip_file)
        except:
            naughtyOnes.write(str(attempt.encode('UTF-8')) + ' n-a incarcat o arhiva\n')
            continue
        try:
            # Unzip file
            patoolib.extract_archive(zip_file, outdir = attempt_folder)
            os.remove(zip_file)
            files = os.listdir()
            
            # Zip contains only the src folder
            if len(files) == 1:
                file = files[0]
                filePath = os.path.join(attempt_folder, file)
                if os.path.isdir(filePath):
                    os.rename(file, subFolderName)
            else:
                # Zip has many folders
                naughtyOnes.write(str(attempt.encode('UTF-8')) + ' n-a incarcat src-ul\n')
                os.mkdir(subFolderName)
                
                for file in files:
                   
                    destination = os.path.join(attempt_folder, subFolderName)
                    source = os.path.join(attempt_folder, file)
                    
                    shutil.move(source , destination)

        except:
            naughtyOnes.write(str(attempt) + ' n-a incarcat o arhiva ok\n')
    naughtyOnes.close()
    os.chdir(initialFolder)
   
# Place all students form student_list in the destination_folder
def get_students(source_folder, student_list, destination_folder):

    
    
    
    current_directory = os.getcwd()
    
    file = open(student_list, mode="r", encoding="utf-8")
    our_students = [student.replace('\n', "") for student in file]
    
    # Create the destination_folder or overwrite it
    try:
        os.mkdir(destination_folder)
    except:
        shutil.rmtree(os.path.join(current_directory, destination_folder))
        os.mkdir(os.path.join(current_directory, destination_folder))
    
    # Go in the source folder
    os.chdir(source_folder)
    
    # Get file names and setup src and dst path
    students_submissions = os.listdir()
    source_path = os.path.join(current_directory, source_folder)
    destination_path = os.path.join(current_directory, destination_folder)
    
    # Loop through the submissions
    for student in students_submissions:
        
        if student in our_students:
            source_path_student = os.path.join(source_path, student)
            shutil.move(source_path_student, destination_path)


# Check if a file has one of the given extensions
def file_ending_in(file, endings):
    
    for end in endings:
        if file.endswith(end):
            return True
    return False

# Remove all files from the submissions except the arhives
def remove_all_but_arhives(submission_folder):
    
    endings = ['.zip', '.rar', '.taz', '.z']
    current_directory = os.getcwd()
    os.chdir(submission_folder)
    submission_directory = os.getcwd()
    students_submissions = os.listdir()
    
    for student in students_submissions:
        student_path = os.path.join(submission_directory, student)
        os.chdir(student_path)
        
        files = os.listdir()
        for file in files:
            if not file_ending_in(file, endings):
                path = os.path.join(student_path, file)
                if os.path.isdir(file):
                    shutil.rmtree(path)
                else:
                    os.remove(path)
                
# Move one file with one of the given endings
def move(src_path, file, moss_dest, endings = []):
    file_path = os.path.join(src_path, file)
    if len(endings):
        if file_ending_in(file, endings):
            shutil.copy(file_path, moss_dest)
    else:
        shutil.copy(file_path, moss_dest)

# Move the files with a given ending while keeping the directory structure
def move_all(src, dest, endings = []):
    
    os.chdir(src)
    files = os.listdir(src)
    for file in files:
        if os.path.isdir(file):
            try:
                os.mkdir(os.path.join(dest, file))
            except:
                shutil.rmtree(os.path.join(dest, file))
                os.mkdir(os.path.join(dest, file))
            
            move_all(os.path.join(src, file), os.path.join(dest, file), endings)
            os.chdir(src)
        else:
            move(src, file, dest, endings)

# Move all files with one of the given endings to dest folder
def move_all_TO(src, dest, endings = []):
    
    os.chdir(src)
    files = os.listdir(src)
    for file in files:
        if os.path.isdir(file):            
            move_all_TO(os.path.join(src, file), dest, endings)
            os.chdir(src)
        else:
            move(src, file, dest, endings)
    

# Prepare data for moss by moving all the with one of the given
# endings to one folder for each student  
def prepare_moss(submission_folder, sub_folder_name = 'src', endings = ['.h', '.c']):

    current_directory = os.getcwd()
    
    moss_file_dest = submission_folder + ' - for Moss'
    try:
        os.mkdir(moss_file_dest)
    except:
        shutil.rmtree(moss_file_dest)
        os.mkdir(moss_file_dest)
    
    moss_file_dest = os.path.join(current_directory, moss_file_dest)
    
    os.chdir(submission_folder)
    submission_directory = os.getcwd()
    students_submissions = os.listdir()
   
    for student in students_submissions:
        student_path = os.path.join(submission_directory, student)
        moss_dest = os.path.join(moss_file_dest, student)
        try:
            os.mkdir(moss_dest)
        except:
            shutil.rmtree(moss_dest)
            os.mkdir(moss_dest)
            
        src_path = os.path.join(student_path, sub_folder_name);
        
        try:
            os.mkdir(moss_dest)
        except:
            shutil.rmtree(moss_dest)
            os.mkdir(moss_dest)
        
        move_all_TO(src_path, moss_dest, endings)
            
        
        
        
