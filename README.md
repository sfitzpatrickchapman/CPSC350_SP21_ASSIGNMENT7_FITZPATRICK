# Assignment 7: Sorting
With this program, one can either create a file with a custom amount of doubles
or create arrays from the doubles in a file to sort. If the user chooses to sort,
6 duplicate arrays will be created from the doubles inside of the input file. The
program will run Quick Sort, Merge Sort, Selection Sort, Insertion Sort, Bubble Sort,
and Shell Sort on each designated array. The start time, end time, and total execution
time is printed to the console as a result.
* Using a late day.

## Identifying Information
* Name: Scott Fitzpatrick
* Student ID: 2328196
* Email: sfitzpatrick@chapman.edu
* Course: CPSC 350
* Assignment: 7

## Source Files  
* main.cpp
* FileProcessor.h
* Sort.h
* FileProcessor.cpp
* Sort.cpp
* Main.cpp

## References
* Sorting Methods: Data Structures ZyBooks Textbook
* Chrono: https://www.geeksforgeeks.org/chrono-in-c/
* Shell Sort: https://www.geeksforgeeks.org/return-local-array-c-function/

## Build Insructions
* g++ *.cpp

## Execution Instructions
* To Create File:      ./a.out create numDoubles fileName.txt
* Sort Existing File:  ./a.out sort numDoubles fileName.txt
* NOTE: numDoubles should be an actual integer; Ex: 50000
* NOTE: Correct numDoubles value is required for BOTH create and sort functions
* NOTE: Only .txt files have been used/tested