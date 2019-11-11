//playing game functions -----------------------------

//player settiing
int configUser(void) {

	do
	{
		printf("How many players do you want?: ");
		scanf("%d", &n_user);
		if(n_user > N_MAX_USER)
			printf("Too many players!\n");
		else if(n_user <= 0)
			printf("Too little players!\n")
		else
			return n_user;	
	}while (n_user > N_MAX_USER || n_user <= 0 )
	
}


//betting
int betDollar(void) {
	int i, j;
	
    printf("---------BETTING STEP-----------");	
	for(i=0; i<n_user; i++)
	{
		dollar[i] = N_DOLLAR; // making dollar array 0 to n_user
	}
	
	do
	{
	printf("your betting(total %d) :", dollar[0]); 
	scanf("%d", &my_dollar); // what
	
	if(my_dollar > dollar[0])
		printf("You don't have that money\n");
	else if(my_dollar <= 0)
		printf("You have to pay more than that\n");
	
	}while(my_dollar > dollar[0] || my_dollar <= 0) 
	
	
	for(j=0; j<n_user; j++)
	{
		printf("player[%d] %d bets $%d (out of &%d)\n", j+1, rand() % (dollar[j]) + 1, dollar[j]);
	}
	
	printf("--------------------\n");	
	
}


//offering initial 2 cards
void offerCards(void) {
	int i;
	//1. give two card for each players
	for (i=0;i<n_user;i++)
	{
		cardhold[i][0] = pullCard();
		cardhold[i][1] = pullCard();
	}
	//2. give two card for the operator
	cardhold[n_user][0] = pullCard();
	cardhold[n_user][1] = pullCard();
	
	return;
}

//print initial card status
void printCardInitialStatus(void) {
	
}

int getAction(void) {
	
}


void printUserCardStatus(int user, int cardcnt) {
	int i;
	
	printf("   -> card : ");
	for (i=0;i<cardcnt;i++)
		printCard(cardhold[user][i]);
	printf("\t ::: ");
}




// calculate the card sum and see if : 1. under 21, 2. over 21, 3. blackjack
int calcStepResult() {
	dollar[j] = dollar[j]
}

int checkResult() {
	
}

int checkWinner() {
	
}
