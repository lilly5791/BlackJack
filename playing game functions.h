#ifndef playing_game_functions_h
#define playing_game_functions_h

#include <stdio.h>

#define N_MAX_USER         5
#define N_MAX_CARDHOLD      10
#define N_DOLLAR         50

#define N_MAX_CARDNUM      13
#define N_MAX_GO         17
#define N_MAX_BET         5

#define N_MIN_ENDCARD      30


//player info
int dollar[N_MAX_USER];                  //dollars that each player has
int n_user;                           //number of users
int playercardhold[N_MAX_USER+1];            //card number of each player

//play yard information
int cardhold[N_MAX_USER+1][N_MAX_CARDHOLD];   //cards that currently the players hold, [6][10]
int cardSum[N_MAX_USER+1];               //sum of the cards [5]
int bet[N_MAX_USER];                  //current betting  [5]
int gameEnd ;                      //game end flag

int configUser(void);
int betDollar(void);
void offerCards(void);
void printCardInitialStatus(void);
int getAction(int i, int j);

int getIntegerInput(void);

void printUserCardStatus(int user, int cardcnt);
int calcStepResult(int user, int cardcnt);
int checkResult(int user);
int checkWinner(int user);

#endif /* playing_gami_function_h */
