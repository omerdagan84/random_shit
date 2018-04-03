#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <time.h>

struct singlecard
{
	int cardnum;
	char face;
	char suit;
};

struct singlecard LoadDeck();
bool CheckDup(int trialNum, struct singlecard deck[]);
char LoadFace(int cardnum);
char LoadSuit(int cardnum);
DealCards(struct singlecard deck[]);

int main()
{
	struct singlecard aNewDeck[52];
	memcpy(aNewDeck, LoadDeck(), 52);
	DealCards(aNewDeck);
}
struct singlecard LoadDeck()
{
	struct singlecard deck[52];
	srand(time(NULL));
	int i=0;
	int r = 1 + rand() % 52;

	while (i < 52)
	{
		if (CheckDup(r, deck) == false)
		{
			deck[i].cardnum = r;
			deck[i].face = LoadFace(r);
			deck[i].suit = LoadSuit(r);
			i++;
		}
	}

	return deck[52];
}
bool CheckDup(int trialNum, struct singlecard deck[])
{
	bool duplicate = false;
	int i = 0;
	while (i < 52 || duplicate == false)
	{
		if (trialNum = deck[i].cardnum)
		{
			duplicate = true;
		}
		else
		{
			i++;
		}
	}
	return duplicate;
}
char LoadFace(int cardnum)
{
	char faces[] = { 'A','2','3','4','5','6','7','8','9','T','J','Q','K' };
	int factor = cardnum % 14;
	return faces[factor];
}
char LoadSuit(int cardnum)
{
	char suits[] = { 'H','D','C','S' };
	int factor = cardnum % 5;
	return suits[factor];
}
DealCards(struct singlecard deck[])
{
	for (int i = 0; i < 52; i++)
	{
		printf("[%d %c-%c]", deck[i].cardnum, deck[i].face, deck[i].suit);
	}
}
