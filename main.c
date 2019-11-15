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
int playercardhold[N_MAX_USER] = {2,2,2,2,2};				//card number of each player

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
	int i; // j is card number that each player has.
	
	srand((unsigned)time(NULL));
	
	//set the number of players
	configUser(void);


	//Game initialization --------
	for(i=0; i<n_user; i++) //1. players' dollar
	{
		dollar[i] = N_DOLLAR; // making dollar array 0 to n_user
	}
	
	//2. card tray
	mixCardTray(void);



	//Game start --------
	do {
		
		printf("\n------------------ Round %d (card index %d)--------------------------\n", roundIndex, cardIndex);
		
		betDollar(void);
		offerCards(void); //1. give cards to all the players
		
		printCardInitialStatus(void);
		printf("\n------------------ GAME start --------------------------\n");
		
		//each player's turn
		for (i=0; i<n_user; i++) //each player
		{
			if(i==0)
				printf(">>> my turn! -------------\n");
			else if(i>0 && i<n_user)
				printf(">>> player %d turn! -------------\n", i);
			else if(i==n_user)
				printf(">>> dealer turn! -------------\n");	
			
			while (1) //do until the player dies or player says stop
			{
				printUserCardStatus(i, playercardhold[i]);//print current card status printUserCardStatus();
				if(calcStepResult(i,playercardhold[i]) < 21)//check the card status ::: calcStepResult()
				{
					if(getAction(i,playercardhold[i]) != 0) //GO? STOP? ::: getAction()
						break;
				}

				else if(calcStepResult(i, playercardhold[i]) > 21)
				{
					printUserCardStatus(i, playercardhold[i]);
					dollar[i] = dollar[i]-bet[i]
					printf("::: DEAD (sum:%d) ---> -$%d ($%d)\n", calcStepResult(i, playercardhold[i]), bet[i],dollar[i])
					break;
				}
				
				else if(calcStepResult(i, playercardhold[i]) == 21)
				{
					printUserCardStatus(i, playercardhold[i]);
					dollar[i] = dollar[i]+ 2*bet[i]
					printf("Black Jack!!!congratulation, you win!! --> +$%d ($%d)\n", calcStepResult(i, playercardhold[i]), bet[i],dollar[i])
					break;
				}
				playercardhold[i]++; 	
				//check if the turn ends or not
			}
		
		}
		
		//result
		checkResult(roundIndex);
		
		roundIndex++;
		playercardhold[N_MAX_USER] = {2,2,2,2,2};
	} while (gameEnd == 0);
	
	
	checkWinner();
	
	printf("You played %d rounds\n", roundIndex);
	
	return 0;
}

