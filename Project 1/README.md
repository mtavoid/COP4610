# Problem Description # 
You are to implement a program that would solve questions like the one below:
Given the below slot locations and the process list, allocate the slots to the processes as per First Fit
Algorithm. (The example uses the decimal number system for easier understanding.)
Starting locations of the slots: 1200, 1700, 2550, 3220, 4245, 6450
Sizes of the slots (number of memory locations in the slot): 100, 300, 50, 200, 150, 250
Process list (number of memory locations the process spans, processes identified as A, B, C and so
on): 40, 150, 50, 200, 50, 20, 10, 150
• report the first fit memory allocations of the processes with their respective starting locations
and process sizes
• report the new slot locations with the new slot sizes after each successful memory allocation
to a process
• keep allocating till you exhaust the list or stop when you cannot allocate the memory space to
a process
• report the situation if an allocation is not possible; report if you were able to successfully
allocate memory to all requesting processes in the list

# General requirements for the program # 

1. Your program should be written to use a text file for inputs. It should not ask the user for any
input.
2. The program accepts a list containing slot-start locations (in ascending order) of any length
specified by the user – as inputs from a text file. Under no circumstances should you assume a
fixed number of slot-start locations. The number of slot-start locations should be variable. They
could be any number, as decided by the first entry in the input text file which will be a decimal
number. Following the number, the subsequent entries will contain the starting memory location
addresses of the available memory slots. These addresses will be indicated in the file in the
hexadecimal number system.
3. The program accepts a list containing the slot sizes corresponding to the previously entered slot-
start locations (and hence having the same number of values as the list containing slot-start
locations) – as the subsequent values in the input text file. These slot-size values will also be
indicated in the file in the hexadecimal number system.
4. The program confirms the user inputs by printing the slot-start locations and the corresponding
slot-sizes.
5. The next entry in the text file – a decimal number, indicates how many programs have queued up
and are requesting for memory slots to be allocated to them so that they can be loaded into the
memory and become processes (referred to as ‘processes’ from this point onwards).
6. Your program should next accept a list containing the process sizes in the number of locations
requested (variable – and decided by the previous input indicated in #5 above) – as the subsequent
values in the input text file. These process size values will also be indicated in the file in the
hexadecimal number system.
7. Your program should next confirm the user inputs by printing the list of processes with labels A,
B, C and so on.
8. Based on the user inputs as above, your program should pick up entries in the process sizes one
at a time, identify if a process can be allocated a slot as per the First Fit Algorithm. If it can be
allocated a slot, the memory manager program allocates memory to the process in an existing
memory slot.
9. If a process cannot be allocated a slot, your program should print a message indicating an
allocation failure for the process – informing the user which process it was and stops.
10. If the process can be allocated a slot, the information is printed, and subsequent processes are
taken up.
11. If the allocation was successful, the slot information is accordingly updated and is printed with
the new slot-start locations and updated slot-size values in the hexadecimal number system.
12. The allocation process proceeds as long as it can. If your program ends up successfully allocating
slots to all the processes in the list indicated in the input file, it prints this information before
exiting.
13. The program should clear any dynamically allocated memory used and not leave any memory
leaks before exiting.
14. The program should be tested on the UWF SSH server (or on the VM – only if the SSH server is
down) before submission and submitted with a makefile. The instructor/grader will test the
program files by only running ‘make’ and ‘make clean’ on the command line which should
compile, link and run the executable file. The instructor/grader should not be required to run the
executable by entering another command on the command line and typing make (or make clean)
should create and run the target executable. Please make sure that the makefile also contains the
name of the target executable file and the command to run the target. Entering the ‘make’
command on the command prompt should run the target executable file.

Provided text file is named 25S_COP4610_Project1_InputFile.txt and reads as follows: 
6
0x4B0 0x6A4 0x9F6 0xC94 0x1081 0x1932 0x64 0x12C 0x32 0xC8 0x96 0xFA
8
0x28 0x96 0x32 0xC8 0x32 0x14 0xA 0x96