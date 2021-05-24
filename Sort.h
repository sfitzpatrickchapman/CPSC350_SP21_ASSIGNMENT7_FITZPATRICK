#ifndef SORT_H
#define SORT_H

#include <vector>
#include <iostream>
using namespace std;

class Sort {
public:
	Sort();
	~Sort();

	//primary sort functions
	void quick(double* numbers, int lowIndex, int highIndex);
	void merge(double* numbers, int i, int k);
	void selection(double* numbers, int numbersSize);
	void insertion(double* numbers, int numbersSize);
	void bubble(double* numbers, int numbersSize);
	int shell(double* numbers, int numbersSize);

private:
	//helper functions
	double partition(double* numbers, int lowIndex, int highIndex);
	void justMerge(double* numbers, int leftFirst, int leftLast, int rightLast);
	void insertionSortInterleaved(double*  numbers, int numbersSize, int startIndex, int gap);
};

#endif