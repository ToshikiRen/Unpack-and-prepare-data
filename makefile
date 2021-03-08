

rename_submissions:
	python extract_friends.py 1 submissions

unzip_files: 
	python extract_friends.py 2 submissions

get_students: 
	make remove_not_archive &&\
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