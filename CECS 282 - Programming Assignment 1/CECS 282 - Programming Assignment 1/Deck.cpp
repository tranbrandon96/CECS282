#include "Deck.h"
#include <iostream>
#include <string>
#include <stdlib.h> 
#include<time.h>
using namespace std;

// Constructor which creates a deck of 52 cards
Deck::Deck()
{
	char rank[] = { 'A','2','3','4','5','6','7','8','9','T','J','Q','K' };
	char suit[] = { 'S','H','D','C' };
	index = 0;
	for (int i = 0; i < 4; i++) 
	{
		for (int j = 0; j < 13; j++)
		{
			deckArray[index++].setCard(rank[j], suit[i]);
		}
	}
} // end of constructor with 0 parameters

// Reset the deck so it looks like a new  deck
void Deck::refreshDeck()
{
	char rank[] = { 'A','2','3','4','5','6','7','8','9','T','J','Q','K' };
	char suit[] = { 'S','H','D','C' };
	index = 0;
	//top = 0;
	for (int i = 0; i < 4; i++) 
	{
		for (int j = 0; j < 13; j++) 
		{
			deckArray[index++].setCard(rank[j], suit[i]);
		}
	}
} // end of public function "refreshDeck"

// Deal a card from the top of the deck
Card Deck::deal()
{
	if (top < 52)
		return deckArray[top++];
	else
		return Card();
} // end of public function "deal"

// Shuffle the cards in the deck
void Deck::shuffle()
{
	srand(time(0));
	for (int i = 0; i < 5000; i++)
	{
		int x = rand() % 52;
		int y = rand() % 52;
		Card temp = deckArray[x];
		deckArray[x] = deckArray[y];
		deckArray[y] = temp;
	}
} // end of public function "shuffle"

// Return the numbers of cards left in the deck
int Deck::cardsLeft()
{
	return 52 - top;
} // end of public function "cardsLeft"

// Show all the cards in the deck: 13 columns and 4 rows
void Deck::showDeck()
{
	index = 0;
	for (int i = 0; i < 4; i++) 
	{
		for (int j = 0; j < 13; j++) 
		{
			deckArray[index++].showCard();
			cout << " ";
		}
		cout << endl;
	}
} // end of public function "showDeck"