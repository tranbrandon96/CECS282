#include <iostream>
#include "Card.h"
#include <string>
#include <iostream>
using namespace std;

// Create a "Blank" card
Card::Card()
{
	suit = 'X';
	rank = 'X';
} // end of constructor "Card" with 0 parameters

// Constructor to create a card, setting the rank and suit

Card::Card(char r, char s) 
{
	suit = s;
	rank = r;
} // end of constructor "Card" with 2 parameters

// Set an existing blank card to a particular value
void Card::setCard(char r, char s)
{
	suit = s;
	rank = r;
} // end of public function "setCard"

// Return the point value of the card
int Card::getValue() 
{
	if (rank == 'A')
		return 1;
	else if (rank == 'T' || rank == 'K' || rank == 'Q' || rank == 'J')
		return 10;
	else
		return (int)rank - 48;
} // end of public function "getValue"

// Display the card using 2 fields
void Card::showCard()
{
	string a = "";
	if (rank == 'A')
		a += " A";
	else if (rank == 'K')
		a += " K";
	else if (rank == 'Q')
		a += " Q";
	else if (rank == 'J')
		a += " J";
	else if (rank == 'T')
		a += " 10";
	else
		a += " " + to_string((int)rank - 48);
	if (suit == 'S')
		a += "S";
	else if (suit == 'D')
		a += "D";
	else if (suit == 'H')
		a += "H";
	else if (suit == 'C')
		a += "C";
	cout << a;

} // end of public function "showCard"