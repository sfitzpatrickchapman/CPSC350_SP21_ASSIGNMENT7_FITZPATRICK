#include "Sort.h"
#include "FileProcessor.h"
#include <chrono>
#include <ctime>
#include <iostream>
using namespace std;

void printTimeResults(chrono::system_clock::time_point start, chrono::system_clock::time_point end) {
	//create start, end, and elapsed vars with given times
	time_t start_time = chrono::system_clock::to_time_t(start);
	time_t end_time = chrono::system_clock::to_time_t(end);
	chrono::duration<double> elapsed_seconds = end - start;

	//pretty print the time results
	cout << "   Time Started: " << ctime(&start_time);
	cout << "     Time Ended: " << ctime(&end_time);
	cout << "   Time Elapsed: " << elapsed_seconds.count() << "s\n";
}

int main(int argc, char** argv) {
	string command = string(argv[1]);
	int numDoubles = stoi(string(argv[2]));
	string fileName = string(argv[3]);

	chrono::time_point<chrono::system_clock> start, end;
	FileProcessor fileProcessor;
	Sort sort;

	//<=================================== RUN PROGRAM ===================================>
	if (command == "create") {
		fileProcessor.createFile(numDoubles, fileName);
	}
	else if (command == "sort") {
		//create arrays (duplicates)
		double* array1 = fileProcessor.readFileIntoArray(numDoubles, fileName);
		double* array2 = fileProcessor.readFileIntoArray(numDoubles, fileName);
		double* array3 = fileProcessor.readFileIntoArray(numDoubles, fileName);
		double* array4 = fileProcessor.readFileIntoArray(numDoubles, fileName);
		double* array5 = fileProcessor.readFileIntoArray(numDoubles, fileName);
		double* array6 = fileProcessor.readFileIntoArray(numDoubles, fileName);
		

		//QUICK SORT array 1 and print timing results
		start = chrono::system_clock::now(); //collect start time
		sort.quick(array1, 0, numDoubles - 1); //arr, low index, high index
		end = chrono::system_clock::now(); //collect end time
		cout << "\n<=============== Quick Sort ===============>" << endl;
		printTimeResults(start, end);
		

		//MERGE SORT array 2 and print timing results
		start = chrono::system_clock::now(); //collect start time
		sort.merge(array2, 0, numDoubles - 1);
		end = chrono::system_clock::now(); //collect end time
		cout << "\n<=============== Merge Sort ===============>" << endl;
		printTimeResults(start, end);
		

		//SELECTION SORT array 3 and print timing results
		start = chrono::system_clock::now(); //collect start time
		sort.selection(array3, numDoubles);
		end = chrono::system_clock::now(); //collect end time
		cout << "\n<============= Selection Sort =============>" << endl;
		printTimeResults(start, end);


		//INSERTION SORT array 4 and print timing results
		start = chrono::system_clock::now(); //collect start time
		sort.insertion(array4, numDoubles);
		end = chrono::system_clock::now(); //collect end time
		cout << "\n<============= Insertion Sort =============>" << endl;
		printTimeResults(start, end);


		//BUBBLE SORT array 5 and print timing results
		start = chrono::system_clock::now(); //collect start time
		sort.bubble(array5, numDoubles);
		end = chrono::system_clock::now(); //collect end time
		cout << "\n<=============== Bubble Sort ==============>" << endl;
		printTimeResults(start, end);


		//SHELL SORT array 6 and print timing results
		start = chrono::system_clock::now(); //collect start time
		sort.shell(array6, numDoubles);
		end = chrono::system_clock::now(); //collect end time
		cout << "\n<=============== Shell Sort ===============>" << endl;
		printTimeResults(start, end);


		//delete arrays and print spacer
		delete[] array1;
		delete[] array2;
		delete[] array3;
		delete[] array4;
		delete[] array5;
		delete[] array6;
		cout << endl;
	}
	else //if invalid input, gracefully close program
		cout << "ERROR: Invalid command line argument." << endl;

	return 0;
}