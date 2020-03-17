// Name: Brandon Tran
// Class: CECS 282-05 (Lecture: 7:30PM - 8:20PM | Lab: 8:30PM - 9:45PM)
// Professor Steve Gold
// Programming Assignment #5


#include "BigInt.h"

// helper functions.
// These are private because they are not visible to other functions outside the BigInt class

// Helper function: return 10's complement
vector<char> BigInt::tensComplement()
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
void BigInt::trim()
{
	storage.pop_back();
}

// Helper function: to test if this BigInt is negative
bool BigInt::isNeg() const
{
	return (int)storage.back() == 9;
}


// Helper function: show the storage vector
void BigInt::showStorage()
{
	cout << "Storage: ";
	vector<char> temp;
	vector<char>::iterator itr;
	for (itr = storage.begin(); itr != storage.end(); ++itr)
		temp.push_back(*itr);
	reverse(temp.begin(), temp.end());
	for (itr = temp.begin(); itr != temp.end(); ++itr)
		cout << ((int)* itr);
	cout << endl;
}

// public member functions
// default constructor
BigInt::BigInt()
{
	storage.push_back(0);
	storage.push_back(0);
}

BigInt::BigInt(const BigInt & other)
{
	storage = other.storage;
}

// BigInt constructor - parameter is an integer
BigInt::BigInt(int x)
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
BigInt::BigInt(string s)
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

// subtract an integer from a BigInt
BigInt BigInt::operator-(int n)
{
	BigInt nBigInt(n);
	return *this - nBigInt;
}

// subtract a BigInt from a BigInt
BigInt BigInt::operator-(BigInt N)
{
	BigInt n2 = N, n1 = *this;
	char sign = n2.storage.back();
	int diff = storage.size() - n2.storage.size();
	bool revered = false;
	if (diff < 0) {
		n2 = *this;
		n1 = N;
		diff = abs(diff);
		revered = true;
	}
	n2.trim();
	while (diff > 0) {
		n2.storage.push_back(0);
		diff--;
	}
	n2.storage.push_back(sign);
	n2.storage = n2.tensComplement();
	BigInt result = n1 + n2;
	if (revered) {
		result.storage = result.tensComplement();
	}
	while (result.storage.size() > 1 && result.storage.at(result.storage.size() - 2) == 0)
	{
		result.trim();
	}
	return result;
}

// add an integer from a BigInt
BigInt BigInt::operator+(int n)
{
	BigInt nBigInt(n);
	return *this + nBigInt;
}

// add a BigInt from a BigInt
BigInt BigInt::operator+(BigInt N)
{
	// if the numbers are complementary
	BigInt temp = N;
	temp.storage = temp.tensComplement();
	if (temp.storage.size() == storage.size()) {
		bool comp = true;
		for (int i = 0; i < storage.size(); i++) {
			if (storage[i] != temp.storage[i]) {
				comp = false;
				break;
			}
		}
		if (comp)
			return BigInt(0);
	}

	bool neg1 = isNeg(), neg2 = N.isNeg();
	BigInt n1 = *this;
	BigInt n2 = N;

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
	if (neg2) {
		carry = 0;
	}
	while (itr1 != n1.storage.end()) {
		sum = ((int)* itr1) + carry;
		resultStr = (char)(sum % 10 + '0') + resultStr;
		carry = sum / 10;
		++itr1;
	}
	while (itr2 != n2.storage.end()) {
		sum = ((int)* itr2) + carry;
		resultStr = (char)(sum % 10 + '0') + resultStr;
		carry = sum / 10;
		++itr2;
	}
	if (carry != 0)
		resultStr = char(carry + '0') + resultStr;
	if ((neg1 && n1.storage.size() > n2.storage.size()) || (neg2 && n2.storage.size() > n1.storage.size())) {
		resultStr = '-' + resultStr;
	}
	BigInt result(resultStr);
	return result;
}

// post-increment operator
BigInt BigInt::operator++(int dummy)
{
	BigInt old = *this;
	*this = *this + 1;
	return old;
}

// post-decrement operator
BigInt BigInt::operator--(int dummy)
{
	BigInt old = *this;
	*this = *this - 1;
	return old;
}

// pre-increment operator
BigInt BigInt::operator++()
{
	*this = *this + 1;
	return *this;
}

// pre-decrement operator
BigInt BigInt::operator--()
{
	*this = *this - 1;
	return *this;
}


// += operator - parameter is an interger
BigInt BigInt::operator+=(int n)
{
	BigInt N(n);
	*this = *this + N;
	return *this;
}

// += operator - parameter is an interger
BigInt BigInt::operator+=(BigInt n)
{
	*this = *this + n;
	return *this;
}

// *= operator
BigInt BigInt::operator*=(BigInt N)
{
	BigInt result;
	result = *this * N;
	*this = result;
	return *this;
}

bool BigInt::isZero() const {
	for (int i = 0; i < storage.size() - 1; i++) {
		if (storage[i] != 0)
			return false;
	}
	return true;
}

// multiply operator - mulitiplication is just repeated addition
BigInt BigInt::operator*(BigInt N)
{
	// optimized multiplication
	if (isZero() || N.isZero())
		return BigInt(0);


	BigInt temp1 = N, temp2 = *this;
	int numZeroes = 0;
	vector<char>::iterator it1 = temp1.storage.begin();
	while (*it1 == 0) {
		temp1.storage.erase(it1);
		numZeroes++;
	}
	vector<char>::iterator it2 = temp2.storage.begin();
	while (*it2 == 0) {
		temp2.storage.erase(it2);
		numZeroes++;
	}

	BigInt result(0);
	if (temp1 < temp2) {
		for (BigInt i(0); i < temp1; i++) {
			result = result + temp2;
		}
	}
	else {
		for (BigInt i(0); i < temp2; i++) {
			result = result + temp1;
		}
	}

	reverse(result.storage.begin(), result.storage.end());
	while (numZeroes > 0) {
		result.storage.push_back(0);
		numZeroes--;
	}
	reverse(result.storage.begin(), result.storage.end());
	return result;
}

bool operator>(const BigInt & left, const BigInt & right)
{
	if (left.isNeg() && !right.isNeg())
	{
		return false;
	}
	if (!left.isNeg() && right.isNeg())
	{
		return false;
	}
	if (left.storage.size() > right.storage.size()) {
		if (left.isNeg())
			return false;
		else
			return true;
	}
	else if (left.storage.size() < right.storage.size()) {
		if (left.isNeg())
			return true;
		else
			return false;
	}
	else {
		for (int i = left.storage.size() - 1; i >= 0; i--) {
			if (left.isNeg()) {
				if (left.storage[i] > right.storage[i]) {
					return true;
				}
				else if (left.storage[i] < right.storage[i]) {
					return false;
				}
			}
			else {
				if (left.storage[i] > right.storage[i])
					return true;
				else if (left.storage[i] < right.storage[i])
					return false;
			}
		}
	}
	return false;
}

bool operator<(const BigInt & left, const BigInt & right)
{
	if (left > right)
		return false;
	if (left == right)
		return false;
	return true;
}

// stream insertion operator
ostream& operator<<(ostream & out, const BigInt & n)
{
	vector<char> temp1 = n.storage, temp2, temp;
	vector<char>::iterator itr;

	if (n.isZero()) {
		out << 0;
		return out;
	}


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

bool operator==(const BigInt & left, const BigInt & right)
{
	bool neg = left.isNeg();
	bool neg2 = right.isNeg();
	if ((neg && neg2) || (!neg && !neg2) && left.storage.size() == right.storage.size()) {
		for (int i = 0; i < left.storage.size(); i++)
		{
			if (left.storage[i] != right.storage[i])
			{
				return false;
			}
		}
		return true;
	}
	return false;
}
