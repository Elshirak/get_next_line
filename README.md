# get_next_line
Project from 42 Ecole, aim is to write a function on C that gets just a line from file descriptor. This project will not only allow you to add a very convenient function to your collection,but it will also make you learn a highly interesting new concept in C programming: static variables, full subject you can see in repo.

| Function name | get_next_line |
| --- | --- |
| Prototype | char *get_next_line(int fd); |
| Turn in files | get_next_line.c, get_next_line_utils.c, get_next_line.h |
| Parameters | fd:  The file descriptor to read from |
| Return value | Read line:  correct behavior <br />NULL: there is nothing else to read, or an error occurred |
| External functs | read, malloc, free |
| Description | Write a function that returns a line read from a file descriptor |
