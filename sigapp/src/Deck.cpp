/*
	Function definitions of the deck class. Please reference Deck.h for more abstract details and API.

	This is written using SIG libraries, which are the property of Professor Kallmann of University of California, Merced.

	Written by Jeff Foreman, 6 April 2018
*/

# include "Deck.h"
# include <algorithm>

Deck::Deck(Deck::DeckType type)
{
	// Build the deck based on the type.
	switch (type)
	{
		// The main playing deck.
		case Deck::Main:
			// Build the full deck.
			generateDeck();

			// Shuffle up the deck.
			shuffle();
			break;

		// A player's hand. Composed of cards drawn from the deck. Empty at first.
		case Deck::Hand:
			break;

		// Discard pile. Composed of discarded cards. Empty at first.
		case Deck::Discard:
			break;

		default:
			break;
	}
}

void Deck::generateDeck()
{
	// Temporary card pointer.
	Card *temp;

	// Add the Aces.
	temp = new Card(Card::Ace, Card::CardSuits::Clubs, testCard);
	Deck::cards.push_front(*temp);
	temp = new Card(Card::Ace, Card::CardSuits::Diamonds, testCard);
	Deck::cards.push_front(*temp);
	temp = new Card(Card::Ace, Card::CardSuits::Hearts, testCard);
	Deck::cards.push_front(*temp);
	temp = new Card(Card::Ace, Card::CardSuits::Spades, testCard);
	Deck::cards.push_front(*temp);

	// Add the numeric cards.
	for (int i = 2; i < 11; i++)
	{
		temp = new Card(i, Card::CardSuits::Clubs, testCard);
		Deck::cards.push_front(*temp);
	}

	for (int i = 2; i < 11; i++)
	{
		temp = new Card(i, Card::CardSuits::Diamonds, testCard);
		Deck::cards.push_front(*temp);
	}

	for (int i = 2; i < 11; i++)
	{
		temp = new Card(i, Card::CardSuits::Hearts, testCard);
		Deck::cards.push_front(*temp);
	}

	for (int i = 2; i < 11; i++)
	{
		temp = new Card(i, Card::CardSuits::Spades, testCard);
		Deck::cards.push_front(*temp);
	}

	// Add the face cards.
	temp = new Card(Card::Jack, Card::CardSuits::Clubs, testCard);
	Deck::cards.push_front(*temp);
	temp = new Card(Card::Jack, Card::CardSuits::Diamonds, testCard);
	Deck::cards.push_front(*temp);
	temp = new Card(Card::Jack, Card::CardSuits::Hearts, testCard);
	Deck::cards.push_front(*temp);
	temp = new Card(Card::Jack, Card::CardSuits::Spades, testCard);
	Deck::cards.push_front(*temp);

	temp = new Card(Card::Queen, Card::CardSuits::Clubs, testCard);
	Deck::cards.push_front(*temp);
	temp = new Card(Card::Queen, Card::CardSuits::Diamonds, testCard);
	Deck::cards.push_front(*temp);
	temp = new Card(Card::Queen, Card::CardSuits::Hearts, testCard);
	Deck::cards.push_front(*temp);
	temp = new Card(Card::Queen, Card::CardSuits::Spades, testCard);
	Deck::cards.push_front(*temp);

	temp = new Card(Card::King, Card::CardSuits::Clubs, testCard);
	Deck::cards.push_front(*temp);
	temp = new Card(Card::King, Card::CardSuits::Diamonds, testCard);
	Deck::cards.push_front(*temp);
	temp = new Card(Card::King, Card::CardSuits::Hearts, testCard);
	Deck::cards.push_front(*temp);
	temp = new Card(Card::King, Card::CardSuits::Spades, testCard);
	Deck::cards.push_front(*temp);
}

Card Deck::drawCard()
{

	// Temporary storage for drawn card.
	Card drawnCard;

	// First check if there are even cards to draw. If not, "return" a blank card.
	if (cards.empty()) return drawnCard;

	// Draw the card from the top of the deck.
	drawnCard = cards.front();

	// Remove the card from the top of the deck.
	cards.pop_front();

	// Return the drawn card.
	return drawnCard;
}

Card Deck::drawCard(Deck deck) 
{ 
	// Draw a card from the other deck.
	Card drawnCard = deck.drawCard();

	// Check if there actually was a card drawn.
	if (drawnCard.getValue() == 0) return drawnCard;

	// Add the drawn card to this deck.
	cards.push_front(drawnCard);

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