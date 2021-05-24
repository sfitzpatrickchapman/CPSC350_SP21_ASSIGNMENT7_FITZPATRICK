#ifndef FILEPROCESSOR_H
#define FILEPROCESSOR_H

#include <string>
#include <fstream>
#include <iostream>
using namespace std;

class FileProcessor {
public:
	FileProcessor();
	~FileProcessor();
	void createFile(int numCount, string fileName);
	double* readFileIntoArray(int numDoubles, string fileName);
};

#endif