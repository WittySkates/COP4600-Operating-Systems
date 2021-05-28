# Descriptions
In this lab I accomplished adding system calls along with three static library functions
that allow the implemented system calls to be invoked. We also added a process log level to the kernel
that tracks the current log level. The three system calls include getting the log level, setting the
log level, and logging a message at a defined log level.

## Getting the process log level
This syscall/library function gets the current process log level. Any process can use this call.
To use the library function: get_proc_log_level();

## Setting the process log level
This syscall/library function sets the current process log level as long as the process running is a
superuser, otherwise the action is denied.
To use the library function: set_proc_log_level(int new_level);

## Logging a message at a defined log level
This syscall/library function allows a process to add a process log message at a defined log level.
The message is only logged if the message's log level is equal to or lower than the process log level.
To use the library function: proc_log_message(int level, char *message);

# Design
## File modifications
The first step was adding the three syscalls to the system call table in the file syscall_64.tbl.
Once the system call table was updated I then declared the following system calls to the header
file syscalls.h. Finally I defined the system calls in the sys.c file. The sys.c file contains most
of the code for the lab including the privilege checks and all other logic.

## File additions
This lab required the creation of three files: process_log.c, process_log.h, and the makefile.
These files are what creates the static library that the process' will use to execute the system
calls. This level of abstraction is taken to not allow the users to directly access the system calls.
The process_log.h declares the three main functions that get, set, and log messages; it also contains
the declaration of extra functions for testing purposes. The process.c function defines the functions
declared in the header file. Finally the makefile allows the static library to be created from the
header and the c file.

# Verification
Create and compile a driver that uses the functions defined the static library. This can be done by
creating a C or C++ file and utilizing the functions, then link with the library and run the created
driver. Following these steps will allow a user to verify that the functionality works as specified

# Testing
Testing was performed by repeatedly using the functions and attempting edge cases throughout the entire
process. Once a final build was created I created a diff file and reset the kernel to a clean state. While
in the clean state I applied the diff file and made the static library. Finally I ran numerous personal test 
along with the provided test files to confirm that my code worked on a clean kernel. 

