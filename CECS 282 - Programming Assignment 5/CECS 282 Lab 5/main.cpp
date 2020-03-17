// Name: Brandon Tran
// Class: CECS 282-05 (Lecture: 7:30PM - 8:20PM | Lab: 8:30PM - 9:45PM)
// Professor Steve Gold
// Programming Assignment #5

#include "BigInt.h"
#include <iostream>
#include <map>
#include <exception>
using namespace std;

template<typename T>
T goldBonacci(T x)
{
	static map<T, T> map;
	static int counter = 0;
	counter++;
	if (x == -1)
	{
		return T(counter);
	}
	if (x == -2)
	{
		counter = 0;
		cout << "goldBonacci: resetting count to 0\n";
		map.clear();
		return T(0);
	}
	T one = T(1);
	T zero = T(0);
	if (x == one || x == zero)
	{
		return T(1);
	}
	else
	{
		auto search = map.find(x);
		if (search != map.end())
		{
			try
			{
				if (search->second < 0)
				{
					throw exception("Integer Overflow in goldBonacci\nInteger Overflow in goldBonacci\nInteger Overflow in goldBonacci\n");
				}
				else
				{
					return search->second;
				}
			}
			catch (exception ex)
			{
				cout << ex.what();
				return 0;
			}
		}
		else
		{
			return map[x] = goldBonacci(x - T(1)) + goldBonacci(x - T(2));
		}
	}
}

int main()
{
	int n = 45;
	int intResult = goldBonacci(n);
	cout << "\n... calculating goldBonacci(45)...\n";
	cout << "\ngoldBonacci[" << n << "] = " << intResult << endl;
	cout << "function was called " << goldBonacci(-1) << " times\n";
	getchar();


	goldBonacci(-2);    // reset counter to 0
	n = 50;
	cout << "\n... calculating goldBonacci(50)...\n";
	intResult = goldBonacci(n);
	cout << "\ngoldBonacci[" << n << "] = " << intResult << endl;
	cout << "function was called " << goldBonacci(-1) << " times\n";
	getchar();


	BigInt N = 45;
	cout << "\n... calculating goldBonacci(BigInt(45))...\n";
	BigInt BigIntResult = goldBonacci(N);
	cout << "\ngoldBonacci[" << N << "] = " << BigIntResult << endl;
	cout << "function was called " << goldBonacci(BigInt(-1)) << " times\n";
	getchar();

	goldBonacci(BigInt(-2));            // reset counter to BigInt(0)

	N = BigInt(50);
	cout << "\n... calculating goldBonacci(BigInt(50))...\n";
	BigIntResult = goldBonacci(N);
	cout << "\ngoldBonacci[" << N << "] = " << BigIntResult << endl;
	cout << "function was called " << goldBonacci(BigInt(-1)) << " times\n";
	getchar();

	goldBonacci(BigInt(-2));            // reset counter to BigInt(0)

	N = BigInt(2000);
	cout << "\n... calculating goldBonacci(BigInt(2000))...\n";
	BigIntResult = goldBonacci(N);
	cout << "\ngoldBonacci[" << N << "] = " << BigIntResult << endl;
	cout << "function was called " << goldBonacci(BigInt(-1)) << " times\n";
	getchar();

	return 0;

}

