#include "FileProcessor.h"

FileProcessor::FileProcessor() {}

FileProcessor::~FileProcessor() {}

void FileProcessor::createFile(int numCount, string fileName) {
	fstream writeFile;

	writeFile.open(fileName, ios::out);
	writeFile << numCount << endl; //first line: number of doubles

	//rest of lines: the random doubles
	for (int i = 0; i < numCount; i++) {
		writeFile << (double)rand() / RAND_MAX << endl;
	}

	writeFile.close();
}

double* FileProcessor::readFileIntoArray(int numCount, string fileName) {
	fstream readFile;
	string inputHolder;
	double* array = new double[numCount];
	readFile.open(fileName, ios::in);
	
	int itr = -1; //avoids first line
	while (getline(readFile, inputHolder)) {
		if (itr >= 0) //exclude first line
			array[itr] = stod(inputHolder); //read str as double into arr

		itr++;
	}

	readFile.close();
	return array;
}