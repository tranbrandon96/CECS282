// Name: Brandon Tran
// Class: CECS 282-05 (Lecture: 7:30PM - 8:20PM | Lab: 8:30PM - 9:45PM)
// Professor Steve Gold
// Programming Assignment #5

#ifndef BigInt_h
#define BigInt_h

#include <iostream>
#include <vector>
#include <string>
#include <iomanip>
#include <time.h>
using namespace std;

class BigInt
{
private:
	vector<char> storage; 


private:

	vector<char> tensComplement();
	void trim();
	bool isNeg() const;

public:
	void showStorage();

public:
	
	BigInt();
	BigInt(const BigInt &other);
	BigInt(int x);
	BigInt(string s);
	BigInt operator-(int n);
	BigInt operator-(BigInt N);
	BigInt operator++(int dummy);
	BigInt operator--(int dummy);
	BigInt operator++();
	BigInt operator--();
	friend bool operator>(const BigInt& left, const BigInt& right);
	friend bool operator<(const BigInt& left, const BigInt& right);
	BigInt operator+=(int n);
	BigInt operator*=(BigInt N);
	BigInt operator*(BigInt N);
	friend ostream & operator<<(ostream & out, const BigInt & n);
	BigInt operator+(int n);
	BigInt operator+(BigInt N);
	BigInt operator+=(BigInt n);
	bool isZero() const;
	friend bool operator==(const BigInt& left, const BigInt& right);

}; // end of BigInt class

#endif /* BigInt_h */