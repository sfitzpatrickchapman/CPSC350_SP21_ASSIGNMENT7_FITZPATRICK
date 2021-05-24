#include "Sort.h"

Sort::Sort() {}

Sort::~Sort() {}

void Sort::quick(double* numbers, int lowIndex, int highIndex) {
    if (lowIndex >= highIndex) //base case (if already sorted)
        return;

    //partition the data in the array
    int lowEndIndex = partition(numbers, lowIndex, highIndex);

    //recursively sort low and high partition
    quick(numbers, lowIndex, lowEndIndex);
    quick(numbers, lowEndIndex + 1, highIndex);
}

void Sort::merge(double* numbers, int i, int k) {
    int j = 0;

    if (i < k) {
        j = (i + k) / 2; //find midpoint

        //recursively sort left and right partitions
        merge(numbers, i, j);
        merge(numbers, j + 1, k);

        //merge left and right partition in sorted order
        justMerge(numbers, i, j, k);
    }
}

void Sort::selection(double* numbers, int numbersSize) {
    int i = 0;
    int j = 0;
    int indexSmallest = 0;
    double temp = 0; //for swapping

    for (i = 0; i < numbersSize - 1; ++i) {
        //find index of smallest remaining element
        indexSmallest = i;
        for (j = i + 1; j < numbersSize; ++j) {
            if (numbers[j] < numbers[indexSmallest]) {
                indexSmallest = j;
            }
        }

        //swap numbers[i] and numbers[indexSmallest]
        temp = numbers[i];
        numbers[i] = numbers[indexSmallest];
        numbers[indexSmallest] = temp;
    }
}

void Sort::insertion(double* numbers, int numbersSize) {
    int i = 0;
    int j = 0;
    double temp = 0; //for swapping

    for (i = 1; i < numbersSize; ++i) {
        j = i;
        //insert numbers[i] into sorted part until in correct pos
        while (j > 0 && numbers[j] < numbers[j - 1]) {
            //swap numbers[j] and numbers[j - 1]
            temp = numbers[j];
            numbers[j] = numbers[j - 1];
            numbers[j - 1] = temp;
            --j;
        }
    }
}

void Sort::bubble(double* numbers, int numbersSize) {
    for (int i = 0; i < numbersSize - 1; i++) {
        for (int j = 0; j < numbersSize - i - 1; j++) {
            if (numbers[j] > numbers[j + 1]) {
                double temp = numbers[j];
                numbers[j] = numbers[j + 1];
                numbers[j + 1] = temp;
            }
        }
    }
}

int Sort::shell(double* numbers, int numbersSize) {
    //starts with a big gap and gets smaller
    for (int gap = numbersSize / 2; gap > 0; gap /= 2) {
        //perform gapped insertion sort for curr gap
        //keep adding one more element until array is gap sorted
        for (int i = gap; i < numbersSize; i += 1) {
            //add a[i] to elements that have been gap sorted
            //save a[i] in temp and make hole at position i
            double temp = numbers[i];

            //shift prev gap-sorted elements up until correct loc found
            int j;
            for (j = i; j >= gap && numbers[j - gap] > temp; j -= gap)
                numbers[j] = numbers[j - gap];

            //put temp in correct location
            numbers[j] = temp;
        }
    }
    return 0;
}

double Sort::partition(double* numbers, int lowIndex, int highIndex) {
    //middle element as pivot
    int midpoint = lowIndex + (highIndex - lowIndex) / 2;
    double pivot = numbers[midpoint];

    bool done = false;
    while (!done) {
        //increment lowIndex while numbers[lowIndex] < pivot
        while (numbers[lowIndex] < pivot)
            lowIndex += 1;

        //decrement highIndex while pivot < numbers[highIndex]
        while (pivot < numbers[highIndex])
            highIndex -= 1;

        //if zero or one elements remain, all numbers partitioned
        if (lowIndex >= highIndex)
            done = true;
        else {
            //swap numbers[lowIndex] and numbers[highIndex]
            double temp = numbers[lowIndex];
            numbers[lowIndex] = numbers[highIndex];
            numbers[highIndex] = temp;

            //update lowIndex and highIndex
            lowIndex += 1;
            highIndex -= 1;
        }
    }

    return highIndex;
}

void Sort::justMerge(double* numbers, int i, int j, int k) {
    int mergedSize = k - i + 1; //size of merged partition
    int mergePos = 0; //pos to insert merged number
    int leftPos = 0; //pos of elements in left partition
    int rightPos = 0; //position of elements in right partition
    double* mergedNumbers = new double[mergedSize]; //for merged nums
    leftPos = i; //initialize left partition pos
    rightPos = j + 1; //initialize right partition pos

    //add smallest element from left or right partition to merged numbers
    while (leftPos <= j && rightPos <= k) {
        if (numbers[leftPos] <= numbers[rightPos]) {
            mergedNumbers[mergePos] = numbers[leftPos];
            ++leftPos;
        }
        else {
            mergedNumbers[mergePos] = numbers[rightPos];
            ++rightPos;
        }
        ++mergePos;
    }

    //if left partition not empty, add remaining elements to merged numbers
    while (leftPos <= j) {
        mergedNumbers[mergePos] = numbers[leftPos];
        ++leftPos;
        ++mergePos;
    }

    //if right partition is not empty, add remaining elements to merged numbers
    while (rightPos <= k) {
        mergedNumbers[mergePos] = numbers[rightPos];
        ++rightPos;
        ++mergePos;
    }

    //copy merge number back to numbers
    for (mergePos = 0; mergePos < mergedSize; ++mergePos) {
        numbers[i + mergePos] = mergedNumbers[mergePos];
    }

    delete[] mergedNumbers;
}

void Sort::insertionSortInterleaved(double* numbers, int numbersSize, int startIndex, int gap) {
    int i = 0;
    int j = 0;
    double temp = 0; //for swapping

    for (i = startIndex + gap; i < numbersSize; i = i + gap) {
        j = i;
        while (j - gap >= startIndex && numbers[j] < numbers[j - gap]) {
            temp = numbers[j];
            numbers[j] = numbers[j - gap];
            numbers[j - gap] = temp;
            j = j - gap;
        }
    }
}