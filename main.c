#include <stdio.h>
#include <stdlib.h>

#define N_CARDSET			1
#define N_CARD				52
#define N_DOLLAR			50

#define N_MAX_CARDNUM		13
#define N_MAX_USER			5
#define N_MAX_CARDHOLD		10
#define N_MAX_GO			17
#define N_MAX_BET			5

#define N_MIN_ENDCARD		30


//card tray object
int CardTray[N_CARDSET*N_CARD]; //[1*52]
int cardIndex = 0;							

//player info
int dollar[N_MAX_USER];						//dollars that each player has
int n_user;									//number of users
int check;									//numbers of calling pullcard

//play yard information
int cardhold[N_MAX_USER+1][N_MAX_CARDHOLD];	//cards that currently the players hold, [6][10]
int cardSum[N_MAX_USER];					//sum of the cards [5]
int bet[N_MAX_USER];						//current betting  [5]
int gameEnd = 0; 							//game end flag

//some utility functions

//get an integer input from standard input (keyboard)
//return : input integer value
//         (-1 is returned if keyboard input was not integer)
int getIntegerInput(void) {
    int input, num;
    
    num = scanf("%d", &input);
    fflush(stdin);
    if (num != 1) //if it fails to get integer
        input = -1;
    
    return input;
}

int main(int argc, char *argv[]) {
	int roundIndex = 1; 
//	int max_user; = n_user
	int i, j=2;
	
	srand((unsigned)time(NULL));
	
	
	
	//set the number of players
	configUser(void);


	//Game initialization --------
	//1. players' dollar
	
	//2. card tray
	mixCardTray(void);



	//Game start --------
	do {
		
		printf("\n------------------ Round %d --------------------------\n", roundIndex);
		
		betDollar(void);
		offerCards(void); //1. give cards to all the players
		
		printCardInitialStatus(void);
		printf("\n------------------ GAME start --------------------------\n");
		
		//each player's turn
		for (i=0; i<n_user; i++) //each player
		{
			while (1) //do until the player dies or player says stop
			{
				printUserCardStatus(i, j);//print current card status printUserCardStatus();
				if(calcStepResult(i, j) < 21)//check the card status ::: calcStepResult()
					getAction(void);//GO? STOP? ::: getAction()
				else if(calcStepResult(i, j) > 21)
				{
					printUserCardStatus(i, j);
					printf("::: DEAD (sum:%d) ---> -$%d ($%d)\n", calcStepResult(i, j), bet[i],dollar[i]-bet[i] )
				}
					
				
				//check if the turn ends or not
			}
			DEAD (sum:26) --> -$2 ($48)
		}
		
		//result
		checkResult();
		//I think, after check result - plus or minus dollar that players have no
		
		roundIndex++;
		
	} while (gameEnd == 0);
	
	
	checkWinner();
	
	printf("You played %d rounds\n", roundIndex);
	
	return 0;
}

