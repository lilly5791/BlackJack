#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "playing game functions.h"
#include "card array controllers.h"
//playing game functions -----------------------------


int getIntegerInput(void) {
    int input, num;
    
    num = scanf("%d", &input);
    fflush(stdin);
    if (num != 1) //if it fails to get integer
        input = -1;
    
    return input;
}

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
   int j;
   
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
      printf("player[%d] bets $%d (out of $%d)\n", j, bet[j], dollar[j]);
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
   int go=0;
   
   if(i==0) //me
   {
      printf("::: Action? (0 - go, others - stay) :");
      go=getIntegerInput();
         
      if(go == 0)
      {
         cardhold[i][j] = pullCard();
         return 0;
      }
      else
         return 1;
   }
   else //other players
   {
      if (cardSum[i]   < 17 )
      {
         cardhold[i][j] = pullCard();
         printf(":::GO:::\n");
         return 0;
      }
      else
      {
         printf(":::STAY:::\n");
         return 1;
      }
   }
    return 0;
}


void printUserCardStatus(int user, int cardcnt) {  //cardhold[][]
   int j;
   
   printf("   -> card : ");
   for (j=0;j<cardcnt;j++)
   {
      printCard(cardhold[user][j]);
      printf("*****[%d]%d*********//", cardIndex, cardhold[user][j]);
   }
   printf("\t ::: ");
   
}




// calculate the card sum and see if : 1. under 21, 2. over 21, 3. blackjack
int calcStepResult(int user, int cardcnt) {
   
   int j,anum = 0;
   cardSum[user] = 0;
   
   for(j=0;j<cardcnt;j++)
   {
      if(getCardNum(cardhold[user][j]) == 11)
      {
         anum++;
      }
      else
      {
         cardSum[user] += getCardNum(cardhold[user][j]);
      }
   }


   if(cardSum[user] > 10)
   {
      if(anum != 0)
      {
         cardSum[user] = cardSum[user] + anum * 1;
      }
   }
   else if(cardSum[user] == 10)
   {
      if (anum > 1)
      {
         cardSum[user] = cardSum[user] + anum * 1;
      }
      else if (anum == 1)
      {
         cardSum[user] = cardSum[user] + 11; // blackjack
      }
   }
   else // cardsum < 10
   {
      if(anum >= 2)
      {
         cardSum[user] = cardSum[user] + 11 + (anum-1)* 1;
      }
      else if(anum == 1)
      {
         cardSum[user] = cardSum[user] + 11;
      }
   }
   
   
   return cardSum[user];
   //if CardTray[i] = 13(CLVA) then calculate 1 or 11
}

int checkResult(int roundindex) {
   int i;
   printf("\n-------------------ROUND %d result-----------------\n", roundindex);
   
   for(i=0;i<n_user;i++)
   {
      if(i==0)
         printf("your result : ");
      else if(i>0 && i<n_user)
         printf("\nplayer[%d] result : ", i);
   
      if(cardSum[n_user] > 21) // server lose, anyone who is less 21 wins
      {
         if(cardSum[i] < 21)
         {
            dollar[i] = dollar[i]+bet[i];
            printf("win (sum: %d) --> $%d",cardSum[i], dollar[i]);
         }
         else if(cardSum[i] > 21)
         {
            printf("lose due to overflow! ($%d)", dollar[i]);
         }
         else
            printf("BlackJack! ($%d)\n", dollar[i]);
         
      }
      else if (cardSum[n_user] == 21) //server win - blackjack
      {
         if(cardSum[i] == 21)
         {
            printf("BlackJack! ($%d)\n", dollar[i]);
         }
         else if(cardSum[i] < 21)
         {
            dollar[i] = dollar[i]-bet[i];
            printf("lose! ($%d)\n", dollar[i]);
         }
         else
         {
            printf("lose due to overflow! ($%d)\n", dollar[i]);
         }
      }
      else //sever is less than 21
      {
         if(cardSum[i] < 21 && cardSum[i] >= cardSum[n_user])//player wins
         {
            dollar[i] = dollar[i]+bet[i];
            printf("win (sum: %d) --> $%d\n",cardSum[i],dollar[i]);
         }
         else if(cardSum[i] < 21 && cardSum[i] < cardSum[n_user]) //server wins
         {
            dollar[i] = dollar[i]-bet[i];
            printf("lose! ($%d)\n", dollar[i]);
         }
         else if(cardSum[i] == 21)
         {
            printf("BlackJack! ($%d)\n",dollar[i]);
         }
         else if(cardSum[i] > 21)
         {
            printf("lose due to overflow! ($%d)\n", dollar[i]);
         }
      }
   }
    return 0;
}

int checkWinner(int user) {
   
   int i, winnerIndex, max_dollar=0;
   
   for(i=0; i<user; i++)
   {
      if(dollar[i] > max_dollar)
         max_dollar = dollar[i];
   }
   
   for(winnerIndex=0; winnerIndex<user; winnerIndex++)
   {
      if(max_dollar == dollar[winnerIndex])
         break;
   }
   
   if(winnerIndex == 0)
      printf("\nCongratulation! You have %d dollars so you win!", dollar[0]);
   else
      printf("\nplayer[%d] has %d dollars so you lose", winnerIndex, dollar[winnerIndex]);
    return 0;
}
