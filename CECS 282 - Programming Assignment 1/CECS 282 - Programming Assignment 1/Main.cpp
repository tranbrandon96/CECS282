// Name: Brandon Tran
// Class: CECS 282-05
// Project Name: Program #1: Solitaire Prime
// Due Date: Febuary 12, 2019

#include "Card.h"
#include "Deck.h"
#include <string>
#include<iostream>
using namespace std;

// Function Prototypes
void displayMenu();
bool isPrime(int x);

// Main
int main() 
{
	Deck myDeck;
	int count = 0;
	int sum = 0;
	int choice = 0;
	

	
	while (choice != 5)
	{
		// Menu
		displayMenu();

		cin >> choice;
		cout << endl;

		//Switch statements for users choice
		switch (choice)
		{
			// New Deck
			case 1: 
				myDeck.refreshDeck();
				break;

			// Display Deck
			case 2:
				myDeck.showDeck();
				break;

			// Shuffle Deck
			case 3:
				myDeck.shuffle();
				break;

			// Play Solitaire Prime
			case 4:
				cout << "\nPlaying Solitaire Prime!!!\n\n";
				for (int i = 0; i < 52; i++)
				{
					Card myCard = myDeck.deal();
					myCard.showCard();
				}
					/*
					sum += myCard.getValue();
					myCard.showCard();
					if (isPrime(sum)) {
						cout << " Prime: " << sum << endl;
						sum = 0;
						count++;
						continue;
					}
					else 
					{
						continue;
					}
				}
				
				if (sum == 0) 
				{
					cout << " Winner in " << count << " piles!";
				}
				else 
				{
					cout << " Loser";
				}
				
				count = 0;
				sum = 0;
				cout << endl;
				break;
			*/
			// Exit
			case 5:
				break;

			// Invalid choice if user chooses wrong number other than 1-5
			default:
				cout << "Invalid choice, pick another option." << endl;
				break;
		}
	}

	return 0;
} // end of Main

// Function to display the menu
void displayMenu()
{
	cout << endl;
	cout << "Welcome to Solitaire Prime!\n"
	   	 << "1) New Deck\n"
		 << "2) Display Deck\n"
		 << "3) Shuffle Deck\n"
		 << "4) Play Solitaire Prime\n"
		 << "5) Exit\n"
		 << "Enter your choice (1-5) : ";
} // end of function "displayMenu"

// Function to determine if the value is a prime or not
bool isPrime(int x) 
{
	if (x == 1)
		return false;
	else 
	{
		if (x % 2 == 0) 
		{
			return false;
		}
	
		for (int i = 3; i*i <= x; i += 2) 
		{
			if (x%i == 0) 
			{
				return false;
			}
			
			return true;
		}
	}
} // end of function "isPrime"