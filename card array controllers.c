#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "card array controllers.h"
#include "card processing functions.h"
//card array controllers -------------------------------

//mix swap
void swap (int *x, int *y)
{
   int temp;
   temp = *x;
   *x = *y;
   *y = temp;
}

//mix the card sets and put in the array, didn't mix only array
int mixCardTray(void) {
   int i;
   int j = 0;
   
   for(i=0; i<N_CARD; i++)
   {
      CardTray[i] = j;
      j++;
   }
   
   for(i=0; i<N_CARD; i++)
   {
      swap(&CardTray[rand()%52], &CardTray[i]);
   }

   printf("card is mixed and put into the tray\n");
   return 0;
}

//get one card from the tray
int pullCard(void) {
   cardIndex++;
   //printf("*****[%d]%d*********//", cardIndex, cardhold[user][j]);
   //printf("\n***********cardIndex value : %d  ********\n", cardIndex);
   return CardTray[cardIndex-1];

   
}
