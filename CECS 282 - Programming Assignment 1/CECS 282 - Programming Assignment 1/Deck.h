#ifndef DECK_H
#define DECK_H

#include "Card.h"

// Class Deck
class Deck
{
	private:
		Card deckArray[52];
		int top = 53;
		int index;

	public:
		Deck();
		void refreshDeck();
		Card deal();
		void shuffle();
		int cardsLeft();
		void showDeck();

}; // end of class "Deck"

#endif