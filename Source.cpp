//Gergely Sajdik
//A00976672
//Assignment #5

#include <iostream>
#include <array>
using namespace std;

//sets number for array size and function prototypes for C++11 arrays with pass by reference
const unsigned int ARRAY_SIZE = 20;
void fixTheArray(array<int, ARRAY_SIZE> &myArray, int, int);
bool isUnique(const array<int,ARRAY_SIZE> &myArray, int);


int main() {

	//initialize the array and variables needed
	array<int, ARRAY_SIZE> theNumbers = {};
	unsigned int counter = 0;
	int numberEntered = 0;

	//while loop to implement the program
	while (counter < 20) {

		//ask user for input
		cout << "\nEnter # " << counter + 1 << " : ";
		cin >> numberEntered;

		//if statement to test entered value and nested if statement to decide what to do if number was valid
		if (numberEntered < 10 || numberEntered > 100) {
			cout << "The number entered is not in the valid range of 10 to 100\n";
		}
		else {
			if (isUnique(theNumbers, numberEntered) == true) { //calls function to test if the number is unique or not
				fixTheArray(theNumbers, counter, numberEntered); //edits the array with new number
				counter++;
				cout << "The number: " << numberEntered << " is unique\n";
			}
			else {
				counter++;

			}
		}
	}

		//final display message by using a for each loop
		cout << "\nThe unique numbers are:\n\n";
		int tempCounter = 0;
		for (int items : theNumbers) {
			if (items != 0) {
				cout << "\t" << items;
				tempCounter++;
				if (tempCounter % 5 == 0) {
					cout << "\n";
				}
			}
		}

		cout << "\n\n";
		system("pause");
	}

	//tests to see if entered number was unique by searching through the array (passed by reference by not modifiable)
	bool isUnique(const array<int, ARRAY_SIZE> &theNumbers, int numberEntered) {
		bool tempStatus = true;
		for (int temp = 0; temp < theNumbers.size(); temp++) {
			if (numberEntered == theNumbers[temp]) {
				tempStatus = false;
			}
		}
		return tempStatus;
	}

	//edits value in array if the number was valid (passed by reference or changes would not be permanent with C++11 stl array)
void fixTheArray(array<int, ARRAY_SIZE> &theNumbers, int counter, int numberEntered) {
	theNumbers[counter] = numberEntered;
}