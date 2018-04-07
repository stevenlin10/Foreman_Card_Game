/*
	Function definitions of the deck class. Please reference Deck.h for more abstract details and API.

	This is written using SIG libraries, which are the property of Professor Kallmann of University of California, Merced.

	Written by Jeff Foreman, 6 April 2018
*/

# include "Deck.h"
# include <algorithm>

Deck::Deck()
{
	// Build the deck.
	generateDeck();

	// Shuffle up the deck.
	shuffle();
}

void Deck::generateDeck()
{
	// Temporary card pointer.
	Card *temp;

	// Add the Aces.
	temp = new Card(Card::Ace, Card::CardSuits::Clubs, GsColor::black);
	Deck::cards.push_front(*temp);
	temp = new Card(Card::Ace, Card::CardSuits::Diamonds, GsColor::red);
	Deck::cards.push_front(*temp);
	temp = new Card(Card::Ace, Card::CardSuits::Hearts, GsColor::red);
	Deck::cards.push_front(*temp);
	temp = new Card(Card::Ace, Card::CardSuits::Spades, GsColor::black);
	Deck::cards.push_front(*temp);

	// Add the numeric cards.
	for (int i = 2; i < 11; i++)
	{
		temp = new Card(i, Card::CardSuits::Clubs, GsColor::black);
		Deck::cards.push_front(*temp);
	}

	for (int i = 2; i < 11; i++)
	{
		temp = new Card(i, Card::CardSuits::Diamonds, GsColor::red);
		Deck::cards.push_front(*temp);
	}

	for (int i = 2; i < 11; i++)
	{
		temp = new Card(i, Card::CardSuits::Hearts, GsColor::red);
		Deck::cards.push_front(*temp);
	}

	for (int i = 2; i < 11; i++)
	{
		temp = new Card(i, Card::CardSuits::Spades, GsColor::black);
		Deck::cards.push_front(*temp);
	}

	// Add the face cards.
	temp = new Card(Card::Jack, Card::CardSuits::Clubs, GsColor::black);
	Deck::cards.push_front(*temp);
	temp = new Card(Card::Jack, Card::CardSuits::Diamonds, GsColor::red);
	Deck::cards.push_front(*temp);
	temp = new Card(Card::Jack, Card::CardSuits::Hearts, GsColor::red);
	Deck::cards.push_front(*temp);
	temp = new Card(Card::Jack, Card::CardSuits::Spades, GsColor::black);
	Deck::cards.push_front(*temp);

	temp = new Card(Card::Queen, Card::CardSuits::Clubs, GsColor::black);
	Deck::cards.push_front(*temp);
	temp = new Card(Card::Queen, Card::CardSuits::Diamonds, GsColor::red);
	Deck::cards.push_front(*temp);
	temp = new Card(Card::Queen, Card::CardSuits::Hearts, GsColor::red);
	Deck::cards.push_front(*temp);
	temp = new Card(Card::Queen, Card::CardSuits::Spades, GsColor::black);
	Deck::cards.push_front(*temp);

	temp = new Card(Card::King, Card::CardSuits::Clubs, GsColor::black);
	Deck::cards.push_front(*temp);
	temp = new Card(Card::King, Card::CardSuits::Diamonds, GsColor::red);
	Deck::cards.push_front(*temp);
	temp = new Card(Card::King, Card::CardSuits::Hearts, GsColor::red);
	Deck::cards.push_front(*temp);
	temp = new Card(Card::King, Card::CardSuits::Spades, GsColor::black);
	Deck::cards.push_front(*temp);
}

Card Deck::drawCard() 
{ 
	// Temporary card to store the drawn card.
	Card drawnCard;

	// Draw from the "top" of the deck.
	drawnCard = cards.front();

	// Remove from the "top" of the deck.
	cards.pop_front();

	// Return the drawn card.
	return drawnCard;
}

void Deck::shuffle() 
{
	// Seed the random number generator.
	srand(unsigned int(gs_time()));

	// Randomized index.
	int r;

	for (size_t i = 0; i < cards.size(); i++)
	{
		// Get the random index.
		r = i + (rand() % (cards.size() - i));

		// Swap the current index with the random one.
		std::swap(cards[i], cards[r]);
	}
}