/*
	This header file defines the structure of the class Deck.
	It is a data structure that contains a literal deck of Cards.

	This is written using SIG libraries, which are the property of Professor Kallmann of University of California, Merced.

	Written by Jeff Foreman, 6 April 2018
*/

# pragma once

# include "Card.h"

# include <stack>

class Deck
{
protected: // Class variables.

	std::stack<Card> cards; // The stack of cards in the deck.

protected: // Helper class functions.

	void generateDeck(); // Places the cards onto the stack.

public: // Class functions.

	Deck(); // Constructor. Takes in no arguments. Creates a standard deck of cards in random order.

	Card drawCard(); // Draws a card from top of the deck.

	void shuffle(); // Shuffles the deck of cards.

};