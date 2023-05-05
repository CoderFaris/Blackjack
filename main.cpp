#include <iostream>
#include <vector>
#include <algorithm>
#include <random>
#include <unordered_set>

enum class SUITS
{

	CLUBS,
	DIAMONDS,
	HEARTS,
	SPADES

};

enum class CARDNAMES
{

	ACE = 1,
	TWO,
	THREE,
	FOUR,
	FIVE,
	SIX,
	SEVEN,
	EIGHT,
	NINE,
	TEN,
	JACK,
	QUEEN,
	KING

};

struct Card
{

	CARDNAMES name;
	SUITS suit;
	int value;

	void PrintCard()
	{
		PrintValue();

		std::cout << " of ";

		PrintSuit();



		std::cout << std::endl;
	}

	void PrintValue()
	{

		if (name == CARDNAMES::JACK)
		{

			std::cout << "Jack";


		}

		else if (name == CARDNAMES::QUEEN)
		{

			std::cout << "Queen";


		}

		else if (name == CARDNAMES::KING)
		{

			std::cout << "King";


		}

		else if (name == CARDNAMES::ACE)
		{

			std::cout << "Ace";


		}

		else
		{

			std::cout << (int)value;

		}

	}

	void PrintSuit()
	{

		if (suit == SUITS::CLUBS)
		{

			std::cout << "Clubs";

		}

		else if (suit == SUITS::DIAMONDS)
		{

			std::cout << "Diamonds";

		}

		else if (suit == SUITS::HEARTS)
		{

			std::cout << "Hearts";

		}

		else if (suit == SUITS::SPADES)
		{

			std::cout << "Spades";

		}
	}

};


struct Player
{

	std::vector<Card>PlayerHand;
	std::vector<Card>DealerHand;

	int PlayerWager = 0;
	int Money = 150;

	void PrintPlayerHand()
	{

		for (auto i : PlayerHand)
		{

			std::cout << "Card = ";
			i.PrintCard();



		}

	}

	void PrintDealerHand()
	{

		for (auto i : DealerHand)
		{

			std::cout << "Card = ";
			i.PrintCard();



		}

	}

	void PrintDealerHandHidden()
	{
		int d = 0;

		for (auto i : DealerHand)
		{

			std::cout << "Card = ";
			i.PrintCard();
			++d;

			if (d == 1)
			{

				break;

			}



		}

		std::cout << "Card = hidden" << std::endl;

	}

	int balance()
	{

		return Money;

	}
};


struct Deck
{

	Card arrCards[52]; // initializing cards
	




	void PrintAll()
	{
		

		for (int i = (int)SUITS::CLUBS; i <= (int)SUITS::SPADES; ++i)
		{

			for (int j = (int)CARDNAMES::ACE; j <= (int)CARDNAMES::KING; ++j)
			{


				// 13 x kolone + redova do kojeg trazimo kartu npr. karta je u 3. redu u 6 koloni, da bi je nasli uradicemo 13 x 3 + 6
				// i su kolone, a j su redovi
				int index = (13 * i) + j - 1;
				arrCards[index].PrintCard();


			}

			std::cout << std::endl;

		}

	}

	void SetupCards()
	{

		for (int i = (int)SUITS::CLUBS; i <= (int)SUITS::SPADES; ++i)
		{

			for (int j = (int)CARDNAMES::ACE; j <= (int)CARDNAMES::KING; ++j)
			{

				Card c;
				c.suit = (SUITS)i;
				c.name = (CARDNAMES)j;

				if (c.name == CARDNAMES::JACK)
				{

					c.value = 10;

				}

				else if (c.name == CARDNAMES::QUEEN)
				{

					c.value = 10;

				}

				else if (c.name == CARDNAMES::KING)
				{

					c.value = 10;

				}

				else if (c.name == CARDNAMES::ACE)
				{

					c.value = 11;

				}

				else
				{

					c.value = (int)c.name;

				}

				//	std::cout << (int)c.name << " of " << (int)c.suit << std::endl;

					// 13 x kolone + redova do kojeg trazimo kartu npr. karta je u 3. redu u 6 koloni, da bi je nasli uradicemo 13 x 3 + 6 - 1
					// i su kolone, a j su redovi
				int index = (13 * i) + j - 1;
				arrCards[index] = c;


			}


		}

	}

	void RandomizeDeck()
	{
		std::shuffle(std::begin(arrCards), std::end(arrCards), std::mt19937(std::random_device()()));
		

		

		for (int i = (int)SUITS::CLUBS; i <= (int)SUITS::SPADES; ++i)
		{
			for (int j = (int)CARDNAMES::ACE; j <= (int)CARDNAMES::KING; ++j)
			{
				int index = (13 * i) + j - 1;

				 
				
				arrCards[index];
					
					              
				
				
			}

			//std::cout << std::endl;
		}

		
	}

	int PlayerCardValues(const Player& player)
	{
		
		int sumvalue=0;
		for (auto i : player.PlayerHand)
		{

			sumvalue += i.value;

		}

		return sumvalue;

	}

	int DealerCardValues(const Player& player)
	{

		
		int sumvalue = 0;
		for (auto i : player.DealerHand)
		{

			sumvalue += i.value;

		}

		return sumvalue;

	}

	std::string DealerBlackjackCalculation(const Player& player)
	{

		int total = DealerCardValues(player);
		int aceCount = 0;
		for (Card card : player.DealerHand) {
			if (card.value == 11) {
				aceCount++;
			}
		}

		while (total > 21 && aceCount > 0) {
			total -= 10;
			aceCount--;
		}


		if (total == 21)
		{

			return "D";

		}

		else if (total > 21)
		{

			return "DL";

		}

		else if (total < 21)
		{

			return "DC";

		}
	}

	std::string PlayerBlackjackCalculation(const Player& player)
	{

		int total = PlayerCardValues(player);
		int aceCount = 0;
		for (Card card : player.PlayerHand) {
			if (card.value == 11) {
				aceCount++;
			}
		}

		while (total > 21 && aceCount > 0) {
			total -= 10;
			aceCount--;
		}

		if (total == 21)
		{

			return "P";

		}

		

		else if (total>21)
		{

			return "PL";

		}

		

		else if (total < 21)
		{

			return "PC";

		}

		

	}

};

void WelcomeScreen()
{

	std::cout << "|-----------------------------------------|" << std::endl;
	std::cout << "|            WELCOME TO BLACKJACK         |" << std::endl;
	std::cout << "|           PLAY SMART AND WIN BIG        |" << std::endl;
	std::cout << "|-----------------------------------------|" << std::endl;


}

void DisplayRules()
{

	std::cout << "The rules of blackjack are fairly simple and your only opponent in the game is the dealer. " << std::endl;
	std::cout << "Each player is dealt a two cards face up while the dealer only has one card face up." << std::endl;
	std::cout << "The goal is to have your two cards added total to be higher than the dealers two cards and under 21. " << std::endl;
	std::cout << "If you go over 21 you bust, or lose, or if the dealers two cards added together are higher than yours you also lose." << std::endl;
	std::cout << "If your two card total is equal to the dealers then it is a stand - off or a tie." << std::endl;
	std::cout << "Cards values are usually face value, 2 is 2 and 10 is 10, while all face cards, jack / queen / king, are also 10." << std::endl;
	std::cout << "The only exception to this rule are Aces, they can take on the value of 1 or 11." << std::endl;
	std::cout << "To get your two cards total you simply add your two cards together." << std::endl;
	std::cout << "If you have any combination of an Ace or any card that is 10 points then you have what is called blackjack, 21 pts" << std::endl;
	std::cout << "WIN = x2 THE WAGERED" << std::endl;
	
}


int main()
{
	// help variables
	// PlayerCardNum starting from 4 because player gets even card numbers and DealerCardNum gets odd numbers
	// 0, 1, 2 and 3 have already been given as cards
	int PlayerCardNum=4;
	int DealerCardNum=5;
	int money=0;

	// used to help us to determine who won/lost
	bool PlayerWon = false;
	bool DealerWon = false;
	
	WelcomeScreen();
	DisplayRules();
	
	std::random_device rd;
	std::mt19937 gen(rd());

	int numberOfCards = 52;
	int* allCards = new int[numberOfCards];
	for (int i = 0; i < numberOfCards; ++i) {
		allCards[i] = i + 1;
	}

	// Fisher-Yates shuffle
	for (int i = numberOfCards - 1; i > 0; --i) {
		std::uniform_int_distribution<> dis(0, i);
		int j = dis(gen);
		int temp = allCards[i];
		allCards[i] = allCards[j];
		allCards[j] = temp;
	}

	// Take the first 100 elements of the shuffled array as random cards
	int numberOfRandomCards = 100;
	int* randomCards = new int[numberOfRandomCards];
	for (int i = 0; i < numberOfRandomCards; ++i) {
		randomCards[i] = allCards[i];
	}
	
	
	Deck deck;
	Player play;
	deck.SetupCards();
	deck.RandomizeDeck();
	
	std::cout << std::endl;
	std::cout << "Enter your bet (maximum is 150 although you can change it): " << std::endl;
	std::cin >> play.PlayerWager;
	

	std::cout << std::endl;

	std::cout << "Dealing 2 cards..."<<std::endl;
	
	play.PlayerHand.push_back(deck.arrCards[randomCards[0]]);
	play.PlayerHand.push_back(deck.arrCards[randomCards[2]]);
	
	std::cout << "Current player hand: " << std::endl;

	play.PrintPlayerHand();

	std::cout << "Value: " << deck.PlayerCardValues(play) << std::endl;
	
	std::cout << std::endl;
	std::cout << std::endl;
	std::cout << "Dealer takes 2 cards..." << std::endl;

	play.DealerHand.push_back(deck.arrCards[randomCards[1]]);
	play.DealerHand.push_back(deck.arrCards[randomCards[3]]);

	std::cout << "Current dealer hand: " << std::endl;
	
	play.PrintDealerHandHidden();

	std::cout << std::endl;
	std::cout << std::endl;

	std::string playerResult = deck.PlayerBlackjackCalculation(play);
	std::string dealerResult = deck.DealerBlackjackCalculation(play);

	if (playerResult == "P") {
		std::cout << "Blackjack for the player!" << std::endl;
		PlayerWon = true;
		money = play.balance() * 2;
	}
	else if (dealerResult == "D") {
		std::cout << "Blackjack for the dealer" << std::endl;
		DealerWon = true;
		money = play.balance() - play.PlayerWager;
	}
	else if (playerResult == "PL") {
		std::cout << "Player busted" << std::endl;
		DealerWon = true;
		money = play.balance() - play.PlayerWager;
	}
	else if (dealerResult == "DL") {
		std::cout << "Dealer busted" << std::endl;
		PlayerWon = true;
		money = play.balance() * 2;
	}
	else {
		// neither player nor dealer has a blackjack or busted, continue the game

		// player's turn
		int option = 1;
		while (option == 1) {
			// ask the player to hit or stand
			std::cout << "Hit(1) or stand(2)?" << std::endl;
			std::cin >> option;

			if (option == 1) {
				// player chooses to hit, draw a card and update the hand value
				play.PlayerHand.push_back(deck.arrCards[randomCards[PlayerCardNum += 2]]);
				playerResult = deck.PlayerBlackjackCalculation(play);

				std::cout << "Player hand: " << std::endl;
				play.PrintPlayerHand();

				if (playerResult == "P") {
					// player gets a blackjack, end the game
					std::cout << "Blackjack for the player!" << std::endl;
					PlayerWon = true;
					money = play.balance() * 2;
					break;
				}
				else if (playerResult == "PL") {
					// player busts, end the game
					std::cout << "Player busted" << std::endl;
					DealerWon = true;
					money = play.balance() - play.PlayerWager;
					break;
				}
			}
		}

		if (!PlayerWon && !DealerWon) {
			// dealer's turn
			while (deck.DealerCardValues(play) < 17) {
				// dealer draws a card until the hand value is 17 or higher
				play.DealerHand.push_back(deck.arrCards[randomCards[DealerCardNum += 2]]);
				dealerResult = deck.DealerBlackjackCalculation(play);

				std::cout << "Dealer hand: " << std::endl;
				play.PrintDealerHand();

				if (dealerResult == "DL") {
					// dealer busts, end the game
					std::cout << "Dealer busted" << std::endl;
					PlayerWon = true;
					money = play.balance() - play.PlayerWager;
					break;
				}
			}
		}

		if (!PlayerWon && !DealerWon) {
			// determine the winner
			int playerScore = deck.PlayerCardValues(play);
			int dealerScore = deck.DealerCardValues(play);

			if (playerScore > dealerScore) {
				std::cout << "Player wins!" << std::endl;
				PlayerWon = true;
				money = play.balance() * 2;

			}
			else if (dealerScore > playerScore) {
				std::cout << "Dealer wins!" << std::endl;
				DealerWon = true;
				money = play.balance() - play.PlayerWager;
			}
			else {
				if (playerResult == "PL") {
					std::cout << "Dealer wins! Player busted." << std::endl;
					DealerWon = true;
					money = play.balance() - play.PlayerWager;
				}
				else if (dealerResult == "DL") {
					std::cout << "Player wins! Dealer busted." << std::endl;
					PlayerWon = true;
					money = play.balance() * 2;
				}
				else {
					std::cout << "It's a tie!" << std::endl;
				}
			}
		}
		else if (dealerResult == "D") {
			std::cout << "Blackjack for the dealer" << std::endl;
			DealerWon = true;
			money = play.balance() - play.PlayerWager;
		}
		else if (dealerResult == "DL") {
			std::cout << "Dealer busted" << std::endl;
			PlayerWon = true;
			money = play.balance() * 2;
		}
	}

	if (PlayerWon && DealerWon) {
		std::cout << "Something went wrong, both the player and the dealer have won." << std::endl;
	}
	else if (PlayerWon) {
		std::cout << "Congratulations! You won!" << std::endl;
	}
	else if (DealerWon) {
		std::cout << "The dealer won. Better luck next time." << std::endl;
	}
	else {
		std::cout << "Nobody won." << std::endl;
	}

	play.PrintDealerHand();

	std::cout << "Current balance of the player: " << money << std::endl;

	delete[] randomCards;


}

		


	

	


