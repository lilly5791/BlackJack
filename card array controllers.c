//card array controllers -------------------------------

//mix the card sets and put in the array, didn't mix only array
int mixCardTray(void) {
	int i;
	int j = 1;
	
	for(i=0; i<N_CARD; i++) // put the cardnumber 1-13 in the array
	{		
		CardTray[i] = j;
		j++;
		if(j >= 10)
		{
			CardTray[i] = 10;
		}
		if(j == 13)
		{
			j = 1;
		}
	}
	
	printf("card is mixed and put into the tray\n");
	
	
}

//get one card from the tray
int pullCard(void) {
	
	int i, num, flag[N_CARD];
	

	num = rand()%51;
	flag[check] = num; // pulled card num is saved in flag[]
	check++;
	
	for(int j = 0; j<check;j++ )//to check overlap
	{
		if (flag[j] == num)
			num = rand()%51; // if rand()%51 is used num, then rewrite num 	
	}
	
	return CardTray[num]; // not used num will be returned
	
}
