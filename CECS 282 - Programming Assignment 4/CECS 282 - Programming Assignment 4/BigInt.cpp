// BigInt Class structure and test harness
// Written by S. Gold for CECS 282 Sprint 2019
#include <iostream>
#include <vector>
#include <string>
#include <iomanip>
#include <time.h>
using namespace std;

class BigInt
{
private:
	vector<char> storage; // data members

private:
	// helper functions.
	// These are private because they are not visible to other functions outside the BigInt class

	// Helper function: return 10's complement
	vector<char> tensComplement()
	{
		vector<char> temp;
		vector<char>::iterator itr;
		int carry = 1;
		for (itr = storage.begin(); itr != storage.end(); ++itr)
			temp.push_back(9 - ((int)* itr) + (itr == storage.begin() ? 1 : 0));
		return temp;
	}

	// Helper function: trim the leading redundat sign digits...
	// remove 9's for negative and 0's for positive
	void trim() {
		storage.pop_back();
	}

	// Helper function: to test if this BigInt is negative
	bool isNeg() {
		return (int)storage.back() == 9;
	}

public:
	// Helper function: show the storage vector
	void showStorage()
	{
		vector<char> temp;
		vector<char>::iterator itr;
		for (itr = storage.begin(); itr != storage.end(); ++itr)
			temp.push_back(*itr);
		reverse(temp.begin(), temp.end());
		for (itr = temp.begin(); itr != temp.end(); ++itr)
			cout << ((int)* itr);
		cout << endl;
	}

public: // public member functions
		// default constructor
	BigInt()
	{
		storage.push_back(0);
		storage.push_back(0);
	}

	// BigInt constructor - parameter is an integer
	BigInt(int x)
	{
		int n = abs(x);
		while (n > 0)
		{
			storage.push_back(n % 10);
			n = n / 10;
			//print digit
		}
		if (x < 0) {
			storage = tensComplement();
		}
		storage.push_back(x < 0 ? 9 : 0);
	}

	// BigInt constructor - parameter is a string
	BigInt(string s)
	{
		bool isNegative = false;
		for (char& c : s)
		{
			if (c != '-') {
				storage.push_back(c - '0');
			}
			else {
				isNegative = true;
			}
		}
		reverse(storage.begin(), storage.end());
		if (isNegative) {
			storage = tensComplement();
		}
		storage.push_back(isNegative ? 9 : 0);
	}

	BigInt copy()
	{
		BigInt c;
		c.storage.clear();
		vector<char>::iterator itr;
		for (itr = storage.begin(); itr != storage.end(); ++itr) {
			c.storage.push_back(*itr);
		}
		return c;
	}

	// subtract an integer from a BigInt
	BigInt operator-(int n)
	{
		BigInt nBigInt(n);
		return *this - nBigInt;
	}

	// subtract a BigInt from a BigInt
	BigInt operator-(BigInt N)
	{
		BigInt n = N.copy();
		n.storage = n.tensComplement();
		return *this + n;
	}

	// add an integer from a BigInt
	BigInt operator+(int n)
	{
		BigInt nBigInt(n);
		return *this + nBigInt;
	}

	// add a BigInt from a BigInt
	BigInt operator+(BigInt N)
	{
		bool neg1 = isNeg(), neg2 = N.isNeg();
		BigInt n1 = copy();
		BigInt n2 = N.copy();
		n1.trim();
		n2.trim();
		string resultStr = "";
		int carry = 0, sum;
		vector<char>::iterator itr1 = n1.storage.begin(), itr2 = n2.storage.begin();
		for (; itr1 != n1.storage.end() && itr2 != n2.storage.end(); ++itr1, ++itr2) {
			sum = ((int)* itr1) + ((int)* itr2) + carry;
			resultStr = (char)(sum % 10 + '0') + resultStr;
			carry = sum / 10;
		}
		while (itr1 != n1.storage.end()) {
			resultStr = ((char)(*itr1 + '0')) + resultStr;
			++itr1;
		}
		while (itr2 != n2.storage.end()) {
			resultStr = ((char)(*itr2 + '0')) + resultStr;
			++itr2;
		}
		if ((neg1 && n1.storage.size() > n2.storage.size()) || (neg2 && n2.storage.size() > n1.storage.size())) {
			resultStr = '-' + resultStr;
		}
		BigInt result(resultStr);
		return result;
	}

	// post-increment operator
	BigInt operator++(int dummy)
	{
		BigInt old = copy();
		*this = *this + 1;
		return old;
	}

	// post-decrement operator
	BigInt operator--(int dummy)
	{
		BigInt old = copy();
		*this = *this - 1;
		return old;
	}

	// pre-increment operator
	BigInt operator++()
	{
		*this = *this + 1;
		return *this;
	}

	// pre-decrement operator
	BigInt operator--()
	{
		*this = *this - 1;
		return *this;
	}

	// greaterThan operator
	bool operator>(BigInt right)
	{
		if (isNeg() && !right.isNeg())
			return false;
		if (right.isNeg())
			return true;
		if (storage.size() > right.storage.size())
			return true;
		else if (storage.size() < right.storage.size())
			return false;
		else {
			vector<char>::iterator itr1, itr2;
			for (itr1 = storage.begin(), itr2 = right.storage.begin(); itr1 != storage.end(); ++itr1, ++itr2) {
				if (*itr1 > * itr2)
					return true;
				else if (*itr1 < *itr2)
					return false;
			}
		}
		return false;
	}

	// lessThan operator
	bool operator<(BigInt right)
	{
		if (*this > right)
			return false;
		if (*this == right)
			return false;
		return true;
	}

	// += operator - parameter is an interger
	BigInt operator+=(int n)
	{
		return *this + n;
	}

	// += operator - parameter is an interger
	BigInt operator+=(BigInt n)
	{
		return *this + n;
	}

	// *= operator
	BigInt operator*=(BigInt N)
	{
		return *this * N;
	}

	// multiply operator - mulitiplication is just repeated addition
	BigInt operator*(BigInt N)
	{
		BigInt result(0);
		for (BigInt i; i < N; i++) {
			result += result;
		}
		return result;
	}

	// multiply operator - mulitiplication is just repeated addition
	bool operator==(BigInt N)
	{
		bool neg = isNeg();
		bool neg2 = isNeg();
		if ((neg && neg2) || (!neg && !neg2) && storage.size() == N.storage.size()) {
			vector<char>::iterator itr1, itr2;
			for (itr1 = storage.begin(), itr2 = N.storage.begin(); itr1 != storage.end(); ++itr1, ++itr2) {
				if (*itr1 != *itr2)
					return false;
			}
			return true;
		}
		return false;
	}

	// stream insertion operator
	friend ostream& operator<<(ostream& out, const BigInt& n)
	{
		vector<char> temp1 = n.storage, temp2, temp;
		vector<char>::iterator itr;
		if ((int)temp1.back() == 9) {
			cout << '-';
			for (itr = temp1.begin(); itr != temp1.end(); ++itr)
				temp.push_back(9 - ((int)* itr) + (itr == temp1.begin() ? 1 : 0));
			temp1 = temp;
		}
		int i = 1;
		for (itr = temp1.begin(); itr != temp1.end(); ++itr) {
			temp2.push_back(*itr);
			if (i % 3 == 0)
				temp2.push_back(',');
			i++;
		}
		if ((int)temp2.back() == ',') {
			temp2.pop_back();
		}
		temp2.pop_back();
		if ((int)temp2.back() == ',') {
			temp2.pop_back();
		}
		reverse(temp2.begin(), temp2.end());
		for (itr = temp2.begin(); itr != temp2.end(); ++itr)
			if (*itr != ',')
				out << ((int)* itr);
			else
				out << (*itr);
		return out;
	}

}; // end of BigInt class

   // factorial using BigInt
BigInt fact(BigInt N) {
	BigInt zero(0), one(1);
	if (N == 0)
		return one;
	return N * fact(N - 1);
}
// factorial using integer
int fact(int n) {
	if (n == 0)
		return 1;
	return n * fact(n - 1);
}
// this is the test harness you will use to demo your BigInt class
int main()
{

	// create and display BigInts
	BigInt a;
	cout << "\ntesting BigInt a:\t" << a << endl;
	a.showStorage();

	BigInt b(50);
	cout << "\ntesting BigInt b(50):\t" << b << endl;
	b.showStorage();

	BigInt c(-37);
	cout << "\ntesting BigInt c(-37):\t" << c << endl;
	c.showStorage();

	BigInt d("123456789012");
	cout << "\ntesting BigInt d(\"123456789012\"):\t" << d << endl;
	d.showStorage();

	BigInt e("-2345");
	cout << "\ntesting BigInt e(\"-2345\"):\t" << e << endl;
	e.showStorage();

	// do the addition operator
	BigInt sum = BigInt(10) + BigInt(20);
	cout << "\ntesting sum = BigInt(10) + BigInt(20):\t" << sum << endl;

	// do the subtraction operator
	BigInt diff = sum - BigInt(20);
	cout << "\ntesting diff = sum - BigInt(20):\t" << diff << endl;

	// do the x++ operator
	cout << sum++;
	cout << "\ntesting sum++:\t" << sum << endl;

	// do the ++x operator
	cout << ++sum;
	cout << "\ntesting ++sum:\t" << sum << endl;

	// do the x-- operator
	cout << sum--;
	cout << "\ntesting sum--:\t" << sum << endl;

	// do the --x operator
	cout << --sum;
	cout << "\ntesting --sum:\t" << sum << endl;

	// do the < operator
	BigInt left(24);
	BigInt right(-37);
	cout << "\ntesting left < right:\t";
	cout << "The less of " << left << " and " << right << " is " << ((left < right) ? left : right) << endl;

	// do the == operator
	cout << "\ntesting left == right:\t";
	cout << left << " and " << right << ((left == right) ? " are " : " are not ") << "equal\n";

	// do the > operator
	cout << "\ntesting left > right:\t";
	cout << "The greater of " << left << " and " << right << " is " << ((left > right) ? left : right) << endl;

	// test the int Factorial function
	cout << "\ntesting int factorial loop:";
	for (int i = 0; i < 30; i++)
		cout << "\nfact(" << i << ") = " << fact(i);

	cout << "\n\nLargest positive integer: " << INT_MAX << endl;
	long long huge = LLONG_MAX;
	cout << "\nLargest positive long long: " << huge;

	getchar();

	// test the BigInt Factorial function
	cout << "\ntesting BigInt factorial loop:";
	for (BigInt I = 0; I < BigInt(100); I += 7)
		cout << "\n\nfact(" << I << ") = " << fact(I);

	getchar();

	cout << "\nHow far from the Earth to Pluto?  ";
	// 4.6 billion miles * 5280 feet per mile * 12 inches per foot
	cout << BigInt("4600000000") * BigInt(5280) *
		BigInt(12)
		<< " inches" << endl;

	cout << "\nWhat is the size of the observable universe?" << endl;
	// 93 billion light years *
	// 365 days per year *
	// 24 hours per day *
	// 3600 seconds per hour *
	// 299,792,458 meters oer second *
	// 1000 millimeters per meter
	BigInt AcrossTheUniverse(1);
	AcrossTheUniverse *= BigInt(93) * BigInt(100000000); // 93 * 1 billion light years
	AcrossTheUniverse *= BigInt(365);                    // 365 days per year
	AcrossTheUniverse *= BigInt("24");                   // 24 hours per day
	AcrossTheUniverse *= BigInt(3600);                   // 3600 seconds per hour
	AcrossTheUniverse *= BigInt(299792458);              // 299,792,459 meters per second
	AcrossTheUniverse *= BigInt(1000);                   // 1000 millimeters per meter
	cout << AcrossTheUniverse << " millimeters" << endl;

	left = BigInt(-500000);
	right = BigInt("-499999");
	cout << endl;

	BigInt fact99 = fact(BigInt(99));
	BigInt fact98 = fact(BigInt(98));

	BigInt diff1 = fact99 - fact98;
	BigInt diff2 = fact98 - fact99;

	cout << "\n\nfact99 = " << fact99;
	cout << "\n\nfact98 = " << fact98;
	cout << "\n\nfact99 - fact98 = " << fact99 - fact98;
	cout << "\n\nfact98 - fact99 = " << fact98 - fact99;
	cout << "\n\n(fact99 - fact98) + (fact98 - fact99) = " << (fact99 - fact98) + (fact98 - fact99);

	cout << endl
		<< endl;
	if (left < right)
		cout << left << " is less than " << right;
	else
		cout << left << " is not less than " << right;

	cout << endl
		<< endl;
	if (left > right)
		cout << left << " is greater than " << right;
	else
		cout << left << " is not greater than " << right;

	cout << endl
		<< endl;
	if (left == right)
		cout << left << " is equal to  " << right;
	else
		cout << left << " is not equal to " << right;
	cout << endl;

	getchar();
}
