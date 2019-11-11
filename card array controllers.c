//card array controllers -------------------------------

//mix the card sets and put in the array
int mixCardTray(void) {
	int i;
	int j = 1;
	
	for(i=0; i<N_CARD; i++)
	{		
		CardTray[i] = j;
		j++;
		if(j == 13)
		{
			j = 1;
		}
	}
	printf("card is mixed and put into the tray\n");
	
	
}

//get one card from the tray
int pullCard(void) {
	
	
	
}
