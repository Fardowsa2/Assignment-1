#ifndef ARRAY_OPERATIONS_H
#define ARRAY_OPERATIONS_H

#include <fstream>
#include <iostream>
#include <vector>
using namespace std;

class ArrayOperations {

public:
  // Function to read data from a file and populate the array
  void readDataFile(const string &filename);

  // Function to search for an element in the array and return its index
  int searchElem(int value);

  // Function to modify an element at a specific index with a new value
  int modifyElem(int index, int newValue);

  // Function to add a new element to the end of the array
  void addElem(int value);

  // Function to replace an element at a specific index with a new value
  void replaceElem(int index, int newValue);

  // Function to remove an element at a specific index from the array
  void removeElem(int index);

  // Function to print the elements of the array
  void printArray();

private:
  // 2D vector to store the array data
  vector<vector<int>> arrayData;
};

#endif // ARRAY_OPERATIONS_H
