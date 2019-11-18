//card processing functions ---------------

//calculate the actual card number in the blackjack game
int getCardNum(int cardnum) {
	
	if(cardnum % (13*N_CARDSET) == 0)
		return 11; // after that, if cardsum is over 21 then -10, if over21 - 10 is over 21 then lose
	else if(cardnum % (13*N_CARDSET) == 1)
		return 2;
	else if(cardnum % (13*N_CARDSET) == 2)
		return 3;
	else if(cardnum % (13*N_CARDSET) == 3)
		return 4;			
	else if(cardnum % (13*N_CARDSET) == 4)
		return 5;
	else if(cardnum % (13*N_CARDSET) == 5)
		return 6;
	else if(cardnum % (13*N_CARDSET) == 6)
		return 7;
	else if(cardnum % (13*N_CARDSET) == 7)
		return 8;
	else if(cardnum % (13*N_CARDSET) == 8)
		return 9;			
	else if(cardnum % (13*N_CARDSET) == 9)
		return 10;
	else if(cardnum % (13*N_CARDSET) == 10)
		return 10;
	else if(cardnum % (13*N_CARDSET) == 11)
		return 10;
	else if(cardnum % (13*N_CARDSET) == 12)
		return 10;
}

//print the card information (e.g. DiaA)
void printCard(int cardnum) {
	
	if(cardnum / (13*N_CARDSET) == 0)
		printf("DIA");
	else if(cardnum / (13*N_CARDSET) == 1)
		printf("SPD");
	else if(cardnum / (13*N_CARDSET) == 2)
		printf("CLV");
	else if(cardnum / (13*N_CARDSET) == 3)
		printf("HRT");			
	
	if(cardnum % (13*N_CARDSET) == 0)
		printf("A ");
	else if(cardnum % (13*N_CARDSET) == 1)
		printf("2 ");
	else if(cardnum % (13*N_CARDSET) == 2)
		printf("3 ");
	else if(cardnum % (13*N_CARDSET) == 3)
		printf("4 ");			
	else if(cardnum % (13*N_CARDSET) == 4)
		printf("5 ");
	else if(cardnum % (13*N_CARDSET) == 5)
		printf("6 ");
	else if(cardnum % (13*N_CARDSET) == 6)
		printf("7 ");
	else if(cardnum % (13*N_CARDSET) == 7)
		printf("8 ");
	else if(cardnum % (13*N_CARDSET) == 8)
		printf("9 ");			
	else if(cardnum % (13*N_CARDSET) == 9)
		printf("10 ");
	else if(cardnum % (13*N_CARDSET) == 10)
		printf("Jack ");
	else if(cardnum % (13*N_CARDSET) == 11)
		printf("Queen ");
	else if(cardnum % (13*N_CARDSET) == 12)
		printf("King ");	
	
}

