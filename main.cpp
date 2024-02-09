/*
Name: Fardowsa Muhumed
Due date: 02/08/2024
Section: Tu/Thu 4:00 pm - 5:15 pm
Assignment: 1
*/

#include "array_operations.h"
#include <iostream>
#include <limits>

using namespace std;

int main() {
  // Create an instance of the ArrayOperations class
  ArrayOperations arrayOps;

  // Read data from file
  arrayOps.readDataFile("data.txt");

  // Print the original array
  cout << "Array Data:\n\n";
  arrayOps.printArray();
  cout << endl;

  // Search for a value in the array
  int searchVal;
  bool validInput = false;

  // Loop until valid input is provided
  while (!validInput) {
    try {
      cout << "Please enter a value to search within the array: ";
      cin >> searchVal;
      cout << endl;

      // Call searchElem method
      int searchIndex = arrayOps.searchElem(searchVal);

      // Print the result
      if (searchIndex != -1) {
        cout << "Value " << searchVal << " found at index " << searchIndex
             << "!" << endl;
        validInput = true;
      } else {
        cout << "Value " << searchVal
             << " not found in the array. Please try again..\n";
      }

      validInput = true;
    } catch (const std::exception &e) {
      cout << "Invalid input! Please try again.\n";
      cin.clear();
      cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }
  }

  cout << endl;

  // Modify an element in the array
  int modifyIndex;
  validInput = false;

  // Loop until valid input is provided
  while (!validInput) {
    try {
      cout << "Please enter an index to modify an element: ";
      cin >> modifyIndex;
      cout << endl;

      int modifyNewValue;
      cout << "Please enter the new value: ";
      cin >> modifyNewValue;
      cout << endl;

      // Call modifyElem method
      int oldValue = arrayOps.modifyElem(modifyIndex, modifyNewValue);

      // Print the result
      cout << "Modified value at index " << modifyIndex
           << ". Old value: " << oldValue << ", New value: "
           << arrayOps.modifyElem(modifyIndex, modifyNewValue) << std::endl;

      validInput = true;
    } catch (const std::exception &e) {
      cout << "Invalid input. Please try again.\n";
      cin.clear();
      cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }
  }

  cout << endl;

  // Add a value to the array
  int addValue;
  validInput = false;

  // Loop until valid input is provided
  while (!validInput) {
    try {
      cout << "Enter a value to add to the array: ";
      cin >> addValue;
      cout << endl;

      // Call addEle method
      arrayOps.addElem(addValue);

      // Print the result
      cout << "Added value " << addValue << " to the array.\n";

      validInput = true;
    } catch (const std::exception &e) {
      cout << "Invalid input. Please try again.\n";
      cin.clear();
      cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }
  }

  cout << endl;

  // Replace an element in the array
  int replaceIndex;
  validInput = false;

  // Loop until valid input is provided
  while (!validInput) {
    try {
      cout << "Enter an index to replace an element: ";
      cin >> replaceIndex;
      cout << endl;

      int replaceValue;
      cout << "Enter the new value: ";
      cin >> replaceValue;
      cout << endl;

      // Call replaceElem method
      arrayOps.replaceElem(replaceIndex, replaceValue);

      // Print the result
      cout << "Replaced value at index " << replaceIndex << " with "
           << replaceValue << ".\n";

      validInput = true;
    } catch (const std::exception &e) {
      cout << "Invalid input. Please try again.\n";
      cin.clear();
      cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }
  }

  cout << endl;

  // Remove an element from the array
  int removeIndex;
  validInput = false;

  // Loop until valid input is provided
  while (!validInput) {
    try {
      cout << "Enter an index to remove an element: ";
      cin >> removeIndex;
      cout << endl;

      // Call removeElem method
      arrayOps.removeElem(removeIndex);

      // Print the result
      cout << "Removed value at index " << removeIndex << ".\n";

      validInput = true;
    } catch (const std::exception &e) {
      cout << "Invalid input. Please try again.\n";
      cin.clear();
      cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }
  }

  cout << endl;

  // Print the updated array
  cout << "The updated array is now:\n";
  arrayOps.printArray();

  return 0;
}
