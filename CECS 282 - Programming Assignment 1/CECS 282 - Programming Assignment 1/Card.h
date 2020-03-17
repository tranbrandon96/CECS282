#ifndef CARD_H
#define CARD_H

// Class Card
class Card
{
	private:
		char rank;
		char suit;

	public:
		Card();
		Card(char r, char s);
		void setCard(char r, char s);
		int getValue();
		void showCard();

}; // end of class "Card"

#endif
