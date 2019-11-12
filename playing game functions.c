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
	scanf("%d", &bet[0]); // what
	
	if(bet[0] > dollar[0])
		printf("You don't have that money\n");
	else if(bet[0] <= 0)
		printf("You have to pay more than that\n");
	
	}while(bet[0] > dollar[0] || bet[0] <= 0) 
	
	
	for(j=1; j<n_user; j++)
	{
		bet[j] = rand()%dollar[j] + 1;
		printf("player[%d] bets $%d (out of &%d)\n", j, bet[j], dollar[j]);
	}

	printf("----------------------------\n");	
	
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
	//2. give two card for the operator (dealer)
	cardhold[n_user][0] = pullCard();
	cardhold[n_user][1] = pullCard();
	
	return;
}

//print initial card status
void printCardInitialStatus(void) {
	
	printf(" ----------- CARD OFFERING ---------------\n");
	printf("server\t: " );
	printCard(int );
	printf("-> you\t: " );
	printCard(int );
	
	server      : ? HRT8  
   -> you        : SPD7 HRT9
   -> player 1   : CLV1 SPDJack
	
}

int getAction(void) {
	int i;
	
	if( go  == 0)
		pullcard
		printf()
}


void printUserCardStatus(int user, int cardcnt) {
	int i;
	
	printf("   -> card : ");
	for (i=0;i<cardcnt;i++)
		printCard(cardhold[user][i]);
	printf("\t ::: ");
	
	
//	printf(" ----------- CARD OFFERING ---------------\n");
//	printf("server\t: " );
//	printCard(int );
//	printf("-> you\t: " );
//	printCard(int ); 
	
}




// calculate the card sum and see if : 1. under 21, 2. over 21, 3. blackjack
int calcStepResult() {
	
	//if CardTray[i] = 13(CLVA) then calculate 1 or 11
}

int checkResult() {
	
}

int checkWinner() {
	
}
