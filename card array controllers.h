#ifndef card_array_controllers_h
#define card_array_controllers_h

#include <stdio.h>
#include "card processing functions.h"

#define N_CARD            52

//card tray object
int CardTray[N_CARDSET*N_CARD]; //[1*52]
int cardIndex;

int mixCardTray(void);
int pullCard(void);

#endif /* card_array_collectors_h */
