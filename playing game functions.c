//playing game functions -----------------------------

//player settiing
int configUser(void) {
	int user; // user = n_user
	do
	{
		printf("How many players do you want?: ");
		scanf("%d", &user);
		if(user > 5)
			printf("Too many players!\n");
		else if(user <= 0)
			printf("Too little players!\n");
		else
			n_user = user;
	}while(user > 5 || user <= 0 );

	return 0;
}


//betting
int betDollar(void) {
	int i, j;
	
    printf("---------BETTING STEP-----------\n");	
	
	do
	{
		printf("your betting(total %d) :", dollar[0]); 
		scanf("%d", &bet[0]); // what
		
		if(bet[0] > dollar[0])
			printf("You don't have that money\n");
		else if(bet[0] <= 0)
			printf("You have to pay more than that\n");
	
	}while(bet[0] > dollar[0] || bet[0] <= 0);
	
	
	for(j=1; j<n_user; j++)
	{
		bet[j] = rand()%N_MAX_BET + 1;  
		printf("player[%d] bets $%d (out of &%d)\n", j, bet[j], dollar[j]);
	}

	printf("----------------------------\n");
	
	return 0;	
}


//offering initial 2 cards
void offerCards(void) {
	int i;
	//1. give two card for each players
	for (i=0;i<n_user;i++)
	{
		cardhold[i][0] = pullCard(); //return CardTray[]
		cardhold[i][1] = pullCard();
	}
	//2. give two card for the operator (dealer)
	cardhold[n_user][0] = pullCard();
	cardhold[n_user][1] = pullCard();

}

//print initial card status
void printCardInitialStatus(void) {
	
	int i;
	
	printf(" ----------- CARD OFFERING ---------------\n");
	printf("server\t: " );
	printf("X ");
	printCard(cardhold[n_user][1]);
	printf("\n");
	printf("-> you\t: " );
	printCard(cardhold[0][0]);
	printCard(cardhold[0][1]);
	printf("\n");
	
	for(i=1; i<n_user; i++)
	{
		printf("-> player[%d]\t:", i);
		printCard(cardhold[i][0]); // player1 has cardhold[][]
		printCard(cardhold[i][1]);
		printf("\n");
	}

}

int getAction(int i, int j) {
	int go;
	
	if(i==0) //me
	{
		printf("::: Action? (0 - go, others - stay) :");
		scanf("%d", go);
			
		if(go == 0)
		{
			cardhold[i][j+1] = pullCard();
			return 0;
		}
		else 
			return 1;
	}
	else //other players
	{
		if (cardSum[i]	< 17 )	
		{	
			cardhold[i][j+1] = pullCard();
			return 0;	
		}
		else
			return 1;
	}
	

}


void printUserCardStatus(int user, int cardcnt) {  //cardhold[][]
	int j;
	
	printf("   -> card : ");
	for (j=0;j<cardcnt;j++)
		printCard(cardhold[user][j]);
	printf("\t ::: ");
	
}




// calculate the card sum and see if : 1. under 21, 2. over 21, 3. blackjack
int calcStepResult(int user, int cardcnt) {
	
	int j, sum;
	
	for(j=0;j<cardcnt;j++)
	{
		cardSum[user] += getCardNum(cardhold[user][j]);
	}
	sum = cardSum[user];
	if(getCardNum(cardhold[user][j]) == 11 && sum > 21 )
	{
		if(sum-10 > 21)
			return sum-10;
		else if(sum-10 == 21)
			return sum;
		else if(sum-10 < 21)
			return sum;	
	}	

	//if CardTray[i] = 13(CLVA) then calculate 1 or 11
}

int checkResult(int roundindex) {
	int i;
	printf("-------------------ROUND %d result-----------------\n", roundindex);
	
	for(i=0;i<n_user;i++)
	{
		if(i==0)
			printf("your result : ");
		else if(i>0 && i<n_user)
			printf("player[%d] result : ", i);
	
		if(cardSum[n_user] > 21) // server lose, anyone who is less 21 wins
		{
			if(cardSum[i] <= 21)
				printf("win (sum: %d) --> $%d",cardSum[i],dollar[i]);
			else 				
				printf("lose due to overflow! ($%d)", dollar[i]);
			
		}
		else if (cardSum[n_user] == 21) //server win - blackjack
		{
			if(cardSum[i] == 21)
				printf("win (sum: %d) --> $%d",cardSum[i],dollar[i]);
			else 				
				printf("lose! ($%d)", dollar[i]);
		}
		else 
		{
			if(cardSum[i] < 21 && cardSum[i] >= cardSum[n_user])//player wins
			{
				printf("win (sum: %d) --> $%d",cardSum[i],dollar[i]);
			}
			else if(cardSum[i] < 21 && cardSum[i] < cardSum[n_user]) //server wins
			{
				printf("lose! ($%d)", dollar[i]);
			}
			else if(cardSum[i] == 21)
			{
				printf("win (sum: %d) --> $%d",cardSum[i],dollar[i]);
			}
			else if(cardSum[i] > 21)
			{
				printf("lose due to overflow! ($%d)", dollar[i]);
			}
		}
	}
}

int checkWinner(user) {
	
	int i, userIndex, max_dollar=0;
	
	for(i=0; i<user; i++)
	{
		if(dollar[i] > max_dollar)
			max_dollar = dollar[i];
	}
	
	for(userIndex=0; userIndex<user; userIndex++)
	{
		if(max_dollar = dollar[userIndex])
			break;
	}
	
	if(userIndex == 0)
		printf("Congratulation! You have %d dollars so you win!", dollar[0]);
	else	
		printf("player[%d] has %d dollars so you lose", dollar[userIndex]);
}
