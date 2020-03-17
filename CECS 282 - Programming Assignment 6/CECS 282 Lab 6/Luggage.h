// Name: Brandon Tran
// Class: CECS 282 - Section 05 (Lecture: 7:30PM - 8:20PM | Lab: 8:30PM - 9:45PM)
// Professor Steve Gold
// Programming Assignment #6: Inheritance


#include <string>
#include <iostream>
#include <vector>
using namespace std;

// -- Luggage ------------------------------------------------------------------------------------------------
// Description:
//				Abstract Base Class: Luggage
// 
// -----------------------------------------------------------------------------------------------------------

class Luggage
{
protected:
	string type;

public:
	void setType(string type)
	{
		this->type = type;
	}

	string getType() {
		return type;
	}

	virtual double volume() = 0;
}; // end of "Luggage" class

// -- Box ---------------------------------------------------------------------------------------------------
// Description: 
//				Concrete Class: Box
//				Private Data Members: length, width, height
//				Volume: length * width * height
// ----------------------------------------------------------------------------------------------------------

class Box : public Luggage
{

private:
	// Variables to solve for volume
	double length, width, height;

public:
	// Type Conversion Constructor
	Box(double l, double w, double h) 
	{
		cout << "Creating Box\n";
		setType("Box");
		length = l;
		width = w;
		height = h;
	}

	// Volume for Box 
	double volume()
	{
		double v = height * length * width;
		return v;
	}
}; // end of "Box" class

// -- Sphere ------------------------------------------------------------------------------------------------
// Description: 
//				Concrete Class: Sphere
//				Private Data Members: radius
//				Volume: 4 * 3.14159 * ((radius * radius * radius) / 3);
// ----------------------------------------------------------------------------------------------------------

class Sphere : public Luggage
{

private:
	// Variable to solve for volume
	double radius;
public:
	// Type Conversion Constructor
	Sphere(double r) {
		setType("Sphere");
		radius = r;
		cout << "Creating Sphere\n";
	}

	// Volume for Sphere
	double volume()
	{
		double v = 4 * 3.14159 * ((radius * radius * radius) / 3);
		return v;
	}
}; // end of "Sphere" class

// -- Pyramid -----------------------------------------------------------------------------------------------
// Description: 
//				Concrete Class: Pyramid
//				Private Data Members: base, height
//				Volume: (base * height) / 3;
// ----------------------------------------------------------------------------------------------------------
class Pyramid : public Luggage 
{

private:
	// Variables to solve for volume
	double base, height;

public:
	// Type conversion constructor
	Pyramid(double b, double h)
	{
		setType("Pyramid");
		cout << "Creating Pyramid\n";
		base = b;
		height = h;
	}

	// Volume for Pyramid
	double volume() 
	{
		return (base * height) / 3;
	}
}; // end of "Pyramid" class

// -- Cylinder ---------------------------------------------------------------------------------------------
// Description:
//				Concrete Class: Cylinder
//				Private Data Members: radius, length
//				Volume: (3.14159 * radius * radius * length)
//
// ---------------------------------------------------------------------------------------------------------
class Cylinder : public Luggage
{

private:
	// Variables to solve for volume
	double radius, length;

public:
	// Type Conversion Constructor
	Cylinder(double r, double l)
	{
		setType("Cylinder");
		radius = r;
		length = l;
		cout << "Creating Cylinder\n";
	}

	// Volume for Cylinder
	double volume()
	{
		return (3.14159 * radius * radius * length);
	}
};

// -- Cube -------------------------------------------------------------------------------------------------
// Description:
//				Concrete Class: Cube
//				Private Data Members: length
//				Volume: length * length * length
//
// ---------------------------------------------------------------------------------------------------------
class Cube : public Luggage 
{

private:
	// Variable to solve for volume
	double length;

public:
	// Type Conversion Constructor
	Cube(double l) 
	{
		setType("Cube");
		cout << "Creating Cube\n";
		length = l;
	}

	// Volume for Cube
	double volume() 
	{
		return length * length * length;
	}
};

// -- Cone -------------------------------------------------------------------------------------------------
// Description:
//				Concrete Class: Cone
//				Private Data Members: radius, length
//				Volume: (3.14159 * radius * radius * length) / 3
//
// ---------------------------------------------------------------------------------------------------------
class Cone : public Luggage
{

private:
	// Variables to solve for volume
	double radius, length;

public:
	// Type Conversion Constructor
	Cone(double r, double l) 
	{
		setType("Cone");
		radius = r;
		length = l;
		cout << "Creating Cone\n";
	}

	double volume() {
		return (3.14159 * radius * radius * length) / 3;
	}
}; // end of "Cone" class

// -- Hemisphere -------------------------------------------------------------------------------------------
// Description:
//				Concrete Class: Hemisphere
//				Private Data Members: radius
//				Volume: 2 * 3.14159 * ((radius * radius * radius) / 3);
//
// ---------------------------------------------------------------------------------------------------------
class Hemisphere : public Luggage 
{

private:
	double radius;
public:
	// Type Conversion Constructor
	Hemisphere(double r)
	{
		setType("Hemisphere");
		radius = r;
		cout << "Creating Hemisphere\n";
	}

	// Volume for Hemisphere
	double volume() 
	{
		double v = 2 * 3.14159 * ((radius * radius * radius) / 3);
		return v;
	}
}; // end of "Hemisphere" class

// -- Prism -------------------------------------------------------------------------------------------
// Description:
//				Concrete Class: Prism
//				Private Data Members: base, height
//				Volume: base * height
//
// ---------------------------------------------------------------------------------------------------------

class Prism : public Luggage 
{

private:
	// Variables to solve for volume
	double base, height;

public:
	// Type Conversion Constructor
	Prism(double b, double h) 
	{
		setType("Prism");
		base = b;
		height = h;
		cout << "Creating Prism" << endl;
	}

	// Volume of Prism 
	double volume() 
	{
		return base * height;
	}
};
