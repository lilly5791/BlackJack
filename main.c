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
	int max_user;
	int i;
	
	srand((unsigned)time(NULL));
	
	
	
	//set the number of players
	configUser();


	//Game initialization --------
	//1. players' dollar
	
	//2. card tray
	mixCardTray();



	//Game start --------
	do {
		
		printf("\n------------------ Round %d --------------------------\n", roundIndex);
		
		betDollar();
		offerCards(); //1. give cards to all the players
		
		printCardInitialStatus();
		printf("\n------------------ GAME start --------------------------\n");
		
		//each player's turn
		for () //each player
		{
			while () //do until the player dies or player says stop
			{
				//print current card status printUserCardStatus();
				//check the card status ::: calcStepResult()
				//GO? STOP? ::: getAction()
				//check if the turn ends or not
			}
		}
		
		//result
		checkResult();
		//I think, after check result - plus or minus dollar that players have 
		
		roundIndex++;
		
	} while (gameEnd == 0);
	
	
	checkWinner();
	
	printf("You played %d rounds\n", roundIndex);
	
	return 0;
}

