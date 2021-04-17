# Unpack-and-prepare-data
A simple yet efficient script for dealing with data coming from moodle. 

<h1> An utilitary for unpacking and selecting folders</h1>


<p> The project at hand was designed to help teachers mnanage files coming from platforms such as moodle.</p>

<p>It contains the following functions:</p>
<ul>
  <li>unpacking data</li>
  <li>removing all files except archives</li>
  <li>adding base files from another folder</li>
  <li>select students and move them in another folder</li>
  <li>run unit tests using the make test command - the unit testing has to have a make test rule that runs the entire code</li>
</ul>

<p>Make rules:</p>

<ol>
  <li>rename_submissions: - removes trailing characters from the folders in the submissions folder</li>
  <li>unzip_files: - unzips all the files placed in the submissions folder </li>
  <li>get_students: runs the above commands and then sleects all the students from the submissions folder that are also in students.txt and places them in the folder named 312AB (to change the folder name just go in the makefile and change 312AB to whatever you need) </li>
  <li>remove_not_archive: - removes all the files from the submissions folder subfolders that are not a valid archive </li>
  <li>prepare_all: - runs the get_students make rule and then selects only the files that have a .c extension (this can be changed, just change or add the parameter endings to the prepare_moss routine), the files are stored in the folder 312AB - for Moss (this can also be changed via the makefile, in order to change the - for Moss ending you'll have to add the parameter folder_ending to the prepare_moss routine)</li>
  <li>prepare_for_grading: - runs the get_students make rule and then creates 2 additional folders, the first one it's identical with the one mentioned above, the other one selects all the files ending in .c and adds the files from the data folder to every submission </li>
  <li>prepare_for_grading_all: - selects all the students from the submission folder, <b>NOT</b> just the ones from the students.txt file, and runs the above mentioned command (prepare_for_grading) on all of them </li>
  <li>clean: - removes the folders created by the script </li>
 </ol>
