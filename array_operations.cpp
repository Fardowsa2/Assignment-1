#include "array_operations.h"
#include <fstream>
#include <iostream>

using namespace std;

void ArrayOperations::readDataFile(const string &filename) {
  // Open the file
  ifstream file(filename);

  // Check if the file is opened successfully
  if (file.is_open()) {
    int value;

    // Read data from the file
    while (file >> value) {
      // Create a new row and push the first value
      arrayData.push_back({value});

      // Read and push the remaining values in the row
      for (int i = 1; i < 10; ++i) {
        file >> value;
        arrayData.back().push_back(value);
      }
    }

    // Close the file
    file.close();
  } else {
    // Print an error message if the file cannot be opened
    cout << "Unable to open the file.\n";
  }
}

int ArrayOperations::searchElem(int value) {
  // Search for the given value in the array
  for (int i = 0; i < arrayData.size(); ++i) {
    for (int j = 0; j < arrayData[i].size(); ++j) {
      if (arrayData[i][j] == value) {
        return i * 10 + j;
      }
    }
  }

  // Return -1 if the value is not found
  return -1;
}

int ArrayOperations::modifyElem(int index, int newValue) {
  // Calculate row and column indices
  int row = index / 10;
  int col = index % 10;

  // Store the old value
  int oldValue = arrayData[row][col];

  // Update the element with the new value
  arrayData[row][col] = newValue;

  // Return the old value
  return oldValue;
}

void ArrayOperations::addElem(int value) {
  // Get the index of the last row
  int row = arrayData.size() - 1;

  // Get the number of columns in the last row
  int col = arrayData.back().size();

  // Check if the last row is full
  if (col == 10) {
    // If the last row is full, add a new row
    arrayData.push_back({value});
  } else {
    // If the last row is not full, add the value to the last row
    arrayData[row].push_back(value);
  }
}

void ArrayOperations::replaceElem(int index, int newValue) {
  // Calculate row and column indices
  int row = index / 10;
  int col = index % 10;

  // Replace the element with the new value
  arrayData[row][col] = newValue;
}

void ArrayOperations::removeElem(int index) {
  // Calculate row and column indices
  int row = index / 10;
  int col = index % 10;

  // Remove the element at the specified index
  arrayData[row].erase(arrayData[row].begin() + col);
}

void ArrayOperations::printArray() {
  // Print the elements of the array
  for (const auto &row : arrayData) {
    for (int value : row) {
      cout << value << " ";
    }
    cout << endl;
  }
}
