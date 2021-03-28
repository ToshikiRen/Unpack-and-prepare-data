

rename_submissions:
	python extract_friends.py 1 submissions

unzip_files: 
	python extract_friends.py 2 submissions

get_students: 
	make rename_submissions &&\
	make unzip_files &&\
	python extract_friends.py 0 submissions 312AB students.txt
	
select_naughty:
	python extract_friends.py 3

remove_not_archive:
	python extract_friends.py 4 submissions

prepare_all:
	make get_students &&\
	python extract_friends.py 5 312AB src
	
	
prepare_for_grading:
	make get_students &&\
	python extract_friends.py 6 312AB 
	
prepare_for_grading_all:
	make rename_submissions &&\
	make unzip_files &&\
	python extract_friends.py 6 submissions 
	
get_grades:
	python extract_friends.py 7 $(xlsx).xlsx students.txt $(output).txt