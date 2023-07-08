all: ./shell
	gcc basic_shell.c -o shell
	gcc mkdir.c -o make_object
	gcc date.c -o date_object
	gcc ls.c -o ls_object
	gcc cat.c -o cat_object
	gcc rm.c -o rm_object
