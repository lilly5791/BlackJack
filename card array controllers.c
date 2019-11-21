#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "card array controllers.h"
#include "card processing functions.h"
//card array controllers -------------------------------

//mix cardTray[]
void swap (int *x, int *y)
{
   int temp;
   temp = *x;
   *x = *y;
   *y = temp;
}

//mix the card sets and put in the array
int mixCardTray(void) {
   int i;
   int j = 0;
   
   for(i=0; i<N_CARD * N_CARDSET; i++) // CardTray[] is 0 to N_CARD*N_CARDSET
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
   return CardTray[cardIndex-1];
}
