#pragma once

/*
	This header file defines the structure of the class Card. 
	A Card belongs to one of four suits, and holds a value of either two through ten, a face value, or is an ace.
	These define the individual units of a Deck.

	Written by Jeff Foreman, 5 April 2018
*/
class Card
{
protected:
	enum Suit {Clubs, Diamonds, Hearts, Spades}; // Enumerate the card suits.
	const int Ace = 1, Jack = 11, Queen = 12, King = 13; // Declare the special values of the face cards and the ace.

public:
	Card();

};