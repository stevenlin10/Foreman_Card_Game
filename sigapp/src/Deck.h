/*
	This header file defines the structure of the class Deck.
	It is a data structure that contains a literal deck of Cards.

	Written by Jeff Foreman, 6 April 2018
*/

# pragma once

# include "Card.h"

# include <deque>

class Deck
{
protected: // Class variables.
	
	// The vector of cards in the deck.
	std::deque<Card> cards; 

protected: // Helper class functions.

	// Places the cards onto the stack.
	void generateDeck(); 

public: // Class functions.

	// Constructor. Takes in no arguments. Creates a standard deck of cards in random order.
	Deck(); 

	// Draws a card from top of the deck.
	Card drawCard(); 

	// Shuffles the deck of cards.
	void shuffle(); 

};