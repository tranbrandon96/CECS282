// Brandon Tran
// CECS 282-05
// Program #2 - myDate
// Due: Febuary 28, 2019

#include "myDate.h"

// Gregorian to Julian
int myDate::Greg2Julian(int month, int day, int year)
{
	int JD, I, J, K;
	I = year;
	J = month;
	K = day;


	JD = K - 32075 + 1461 * (I + 4800 + (J - 14) / 12) / 4 + 367 * (J - 2 - (J - 14) / 12 * 12) / 12 - 3 * ((I + 4900 + (J - 14) / 12) / 100) / 4;
	return JD;
}

// Julian to Gregorian
void myDate::Julian2Greg(int JD, int &month, int &day, int &year)
{
	int I, J, K, L, N;


	L = JD + 68569;
	N = 4 * L / 146097;
	L = L - (146097 * N + 3) / 4;
	I = 4000 * (L + 1) / 1461001;
	L = L - 1461 * I / 4 + 31;
	J = 80 * L / 2447;
	K = L - 2447 * J / 80;
	L = J / 11;
	J = J + 2 - 12 * L;
	I = 100 * (N - 49) + I + L;


	year = I;
	month = J;
	day = K;
}

// Default Constructor
myDate::myDate()
{
	year = 1959;
	month = 5;
	day = 11;
}

// Type Conversion Constructor
myDate::myDate(int M, int D, int Y)
{
	int m = M;
	int d = D;
	int y = Y;

	int validDate = Greg2Julian(m,d,y);
	Julian2Greg(validDate, m, d, y);
	if (y == Y && m == M && d == D)
	{
		year = Y;
		month = M;
		day = D;
	}
	else
	{
		year = 1959;
		month = 5;
		day = 11;
	}
}

// Display the date
void myDate::display()
{
	string monthName;
	switch (month)
	{
	case 1:
		monthName = "January";
		break;
	case 2:
		monthName = "Febuary";
		break;
	case 3:
		monthName = "March";
		break;
	case 4:
		monthName = "April";
		break;
	case 5:
		monthName = "May";
		break;
	case 6:
		monthName = "June";
		break;
	case 7:
		monthName = "July";
		break;
	case 8:
		monthName = "August";
		break;
	case 9:
		monthName = "September";
		break;
	case 10:
		monthName = "October";
		break;
	case 11:
		monthName = "November";
		break;
	case 12:
		monthName = "December";
		break;
	}
	cout << monthName << " " << day << ", "<< year;
}

// Get Month
int myDate::getMonth()
{
	return month;
}

// Get Day
int myDate::getDay()
{
	return day;
}

// Get Year
int myDate::getYear()
{
	return year;
}

// Increase the date 
void myDate::increaseDate(int N)
{
	int initialDate = Greg2Julian(month,day,year);
	initialDate += N;
	Julian2Greg(initialDate, month, day, year);
}

// Increase the date
void myDate::decreaseDate(int N)
{
	int initialDate = Greg2Julian(month, day, year);
	initialDate -= N;
	Julian2Greg(initialDate, month, day, year);
}

// Days Between
int myDate::daysBetween(myDate D)
{
	int initialDate = Greg2Julian(D.month, D.day, D.year);
	int endDate = Greg2Julian(month, day, year);
	return initialDate - endDate;
}

// First day of year
int myDate::dayOfYear()
{
	int initialDate = Greg2Julian(1, 1, year);
	int endDate = Greg2Julian(month, day, year);
	return endDate - initialDate + 1;
}

//Print out the day
string myDate::dayName()
{
	int date = Greg2Julian(month, day, year);
	int day = date % 7;

	switch (day)
	{
	case 0:
		return "Monday";
	case 1:
		return "Tuesday";
	case 2:
		return "Wednesday";
	case 3:
		return "Thursday";
	case 4:
		return "Friday";
	case 5:
		return "Saturday";
	case 6:
		return "Sunday";
	}
}



