// Name: Brandon Tran
// Class: CECS 282 - Section 05 (Lecture: 7:30PM - 8:20PM | Lab: 8:30PM - 9:45PM)
// Professor Steve Gold
// Programming Assignment #6: Inheritance

#include "Luggage.h"
#include <iostream>
#include <string>
#include <vector>
#include <iomanip>
using namespace std;

// -- getInteger ----------------------------------------------------------------------
// Description: 
//				1. Displays the given message
//				2. Asks the user to enter a value
//				3. If the value lies between min and max (inclusive), returns it
//				4. Else, ask the user to enter the value again
// ------------------------------------------------------------------------------------
int getInteger(string message, int min, int max)
{
	int val;
	cout << message;
	cin >> val;
	// if the value does not lie between min and max
	while (val < min || val > max) {
		cout << "Error: Value must be between " << min << " and " << max << endl;
		cout << message;
		cin >> val;
	}
	return val;
} // end of "getInteger" function

// -- getPositiveInt ------------------------------------------------------------------
// Description: 
//				1. Asks the user to enter a value
//				2. If the value is a positive integer (>= 1), returns it
//				3. Else, ask the user to enter the value again
//
// ------------------------------------------------------------------------------------
int getPositiveInt() 
{
	int val;
	cin >> val;
	while (val <= 0)
	{
		cout << "Error: Value must be greater than 0" << endl;
		cin >> val;
	}
	return val;
} // end of "getPositiveInt" function

// -- menu ----------------------------------------------------------------------------
// Description:
//				1.Display the menu to the user
//				2.Asks the user to enter a choice and returns it
//
//
// ------------------------------------------------------------------------------------
int menu() 
{
	cout << "\nMENU" << endl;
	cout << "1. Add luggage to storage container" << endl
		<< "2. Remove luggage from storage container" << endl
		<< "3. Show all luggage" << endl
		<< "4. Quit" << endl;
	int choice = getInteger("> ", 1, 4);
	return choice;
} // end of "menu" function

// -- displayLuggage ------------------------------------------------------------------------------
// Description: 
//				1. Displays all the luggage present in the given vector
//
//
// -------------------------------------------------------------------------------------------------
void displayLuggage(vector<Luggage *> &luggage) 
{
	cout << setw(4) << "#" << setw(10) << "Type" << "  Volume" << endl;
	for (int i = 0; i < luggage.size(); i++) {
		cout << setw(4) << i + 1 << setw(10) << luggage[i]->getType() << "  " << luggage[i]->volume() << endl;
	}
	cout << "--------------------------------------------";
	cout << "\nTotal Items: " << luggage.size() << endl;
	double totalVol = 0.0;
	for (int i = 0; i < luggage.size(); i++)
		totalVol += (luggage[i]->volume());
	cout << "Total Volume: " << totalVol << endl;
} // end of "displayLuggage" function

// -- addLuggage ----------------------------------------------------------------------------------------
// Description:
//				1. Displays the types of luggage that can be added
//				2. Asks user for a choice and then parameters of that luggage
//				3. Adds the luggage to the given vector
// -------------------------------------------------------------------------------------------------------
void addLuggage(vector<Luggage *> &luggage)
{

	cout << "\n1. Box" << endl
		<< "2. Sphere" << endl
		<< "3. Pyramid" << endl
		<< "4. Cylinder" << endl
		<< "5. Cube" << endl
		<< "6. Cone" << endl
		<< "7. Hemisphere" << endl
		<< "8. Prism" << endl;

	int length, width, height, base, radius;
	Luggage *l;
	int choice = getInteger("Which type of luggage do you want to add? ", 1, 8);
	switch (choice) {
	case 1: cout << "Enter length: ";
		length = getPositiveInt();
		cout << "Enter width: ";
		width = getPositiveInt();
		cout << "Enter height: ";
		height = getPositiveInt();
		l = new Box(length, width, height);
		luggage.push_back(l);
		break;
	case 2: cout << "Enter radius: ";
		radius = getPositiveInt();
		l = new Sphere(radius);
		luggage.push_back(l);
		break;
	case 3: cout << "Enter base: ";
		base = getPositiveInt();
		cout << "Enter height: ";
		height = getPositiveInt();
		l = new Pyramid(base, height);
		luggage.push_back(l);
		break;
	case 4: cout << "Enter radius: ";
		radius = getPositiveInt();
		cout << "Enter length: ";
		length = getPositiveInt();
		l = new Cylinder(radius, length);
		luggage.push_back(l);
		break;
	case 5: cout << "Enter length: ";
		length = getPositiveInt();
		l = new Cube(length);
		luggage.push_back(l);
		break;
	case 6: cout << "Enter radius: ";
		radius = getPositiveInt();
		cout << "Enter length: ";
		length = getPositiveInt();
		l = new Cone(radius, length);
		luggage.push_back(l);
		break;
	case 7: cout << "Enter radius: ";
		radius = getPositiveInt();
		l = new Hemisphere(radius);
		luggage.push_back(l);
		break;
	case 8: cout << "Enter base: ";
		base = getPositiveInt();
		cout << "Enter height: ";
		height = getPositiveInt();
		l = new Prism(base, height);
		luggage.push_back(l);
		break;
	default:
		break;
	}
	cout << "Luggage added successfully" << endl;
} // end of "addLugggage" function

// -- removeLuggage ----------------------------------------------------------------
// Description: 
//				1. Displays all the luggage in the given vector
//				2. Asks the user to enter the index of the luggage to be deleted
//				3. Removes that luggage
//
// ---------------------------------------------------------------------------------
void removeLuggage(vector<Luggage *> &luggage)
{

	if (luggage.size() == 0)
	{
		cout << "No luggage" << endl;
		return;
	}

	displayLuggage(luggage);
	int toRemove = getInteger("Which luggage to remove? ", 1, luggage.size());
	toRemove--;
	delete luggage[toRemove];
	luggage.erase(luggage.begin() + toRemove);
	cout << "Luggage removed successfully" << endl;
} // end of "removeLuggage" function

// -- freeMemory -------------------------------------------------------------------
// Description: 
//				1. Deallocates the memory from the vector
//
// ---------------------------------------------------------------------------------
void freeMemory(vector<Luggage *> &luggage) 
{
	for (int i = 0; i < luggage.size(); i++) {
		if (luggage[i] != NULL)
			delete luggage[i];
	}
}

// -- main --------------------------------------------------------------------------
//
// ----------------------------------------------------------------------------------
int main() 
{
	vector<Luggage *> luggage;
	int choice;
	do 
	{
		choice = menu();
		switch (choice) {
		case 1: addLuggage(luggage);
			break;
		case 2: removeLuggage(luggage);
			break;
		case 3: displayLuggage(luggage);
			break;
		default:
			break;
		}
	} while (choice != 4);

	freeMemory(luggage);

	return 0;
} // end of "main" 