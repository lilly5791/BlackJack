#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "card processing functions.h"
#include "card array controllers.h"
#include "playing game functions.h"

int main(int argc, char *argv[]) {
   int roundIndex = 1;
   int i; 
   int k, w; //initialize player card hold, if one player is out of money then game ends
   
   srand((unsigned)time(NULL));
   
   //set the number of players
   configUser();


   //Game initialization --------
   for(i=0; i<n_user; i++) //1. players' dollar
   {
      dollar[i] = N_DOLLAR; // making dollar array 0 to n_user
   }
   
   //2. card tray
   mixCardTray();

   //Game start --------
   do {
      if(cardIndex >= N_CARD * N_CARDSET) // if out of card then game ends
      {
         printf("\nOut of Card!! Game Ends!\n");
         gameEnd = 1;
         break;
      }
      printf("\n------------------ Round %d (card index %d)--------------------------\n", roundIndex, cardIndex);
      
      betDollar();
      offerCards(); //1. give cards to all the players
      
      printCardInitialStatus();
      printf("\n------------------ GAME start --------------------------\n");
      
      //each player's turn
    for(k = 0; k<= n_user; k++) // initialize player card hold
         playercardhold[k] = 2;
         
      for (i=0; i<=n_user; i++) //each player
      {
         if(i==0)// array 0 is mine
            printf("\n>>> my turn! -------------\n");
         else if(i>0 && i<n_user)//array 1 ~ (user-1) is player
            printf("\n>>> player %d turn! -------------\n", i);
         else if(i==n_user)//array n_user is server 
            printf("\n>>> server turn! -------------\n");
         
         while (1) //do until the player dies or player says stop
         {
            printUserCardStatus(i, playercardhold[i]);//print current card status printUserCardStatus();
            cardSum[i] = calcStepResult(i,playercardhold[i]);//check the card status ::: calcStepResult()
            
            if(cardSum[i] < 21)
            {
               printf("sum : %d ", cardSum[i]);
               if(getAction(i, playercardhold[i]) != 0) //GO? STOP? ::: getAction()
               {
                  break;
               }
            }

            else if(cardSum[i] > 21)
            {
               if(i!=n_user)//if you and player turn then calculate Dead 
               {
                  dollar[i] = dollar[i]-bet[i];
                  printf("::: DEAD (sum:%d) ---> -$%d ($%d)\n", cardSum[i], bet[i], dollar[i]);
               }
               else
               {
                  printf("::: DEAD (sum:%d)\n", cardSum[i]);
               }
               break;
            }
            
            else if(cardSum[i] == 21)//if you and player turn then calculate Blackjack
            {
               if(i!=n_user)
               {
                  dollar[i] = dollar[i]+ 2*bet[i];
                  printf("Black Jack!!!congratulation, you win!! --> +$%d ($%d)\n", 2*bet[i],dollar[i]);
               }
               else
               {
                  printf("Black Jack!!\n");
               }
               break;
            }
            playercardhold[i]++;
            //check if the turn ends or not
            //break;
         }

         //show server result
         if(i==n_user)
         {
            printf("[[[[[[[ server result is ....  ");
            if(cardSum[i] <= 21) // just show the record
            {
               printf("%d ]]]]]]]\n", cardSum[i]);
            }
            else// overflow
            {
               printf("overflow!! ]]]]]]]");
            }
         }
      }
      
      //result
      checkResult(roundIndex);
      
      roundIndex++;
      for (i=0;i<=n_user;i++) //cardSum initialize
      {
         cardSum[i] = 0;
      }
    
         
//      //escape this for() to end game
//      if(cardIndex > N_CARD * N_CARDSET) // if out of card then game ends
//      {
//         printf("Out of Card!! Game Ends!\n");
//         gameEnd = 1;
//      }

      for(w = 0; w<n_user; w++) // if one player is out of money then game ends
      {
         if(w == 0 && dollar[w] <= 0)
         {
            printf("\nYou go bankrupt!! Game Ends!\n");
            gameEnd = 1;
         }
         
         if(w > 0 && dollar[w] <= 0)
         {
            printf("\nplayer[%d] goes bankrupt!! Game Ends!\n", w);
            gameEnd = 1;
         }
      }
         
   } while (gameEnd == 0);
   
   
   checkWinner(n_user);
   
   printf("\nYou played %d rounds\n", roundIndex-1);
   
   return 0;
}
