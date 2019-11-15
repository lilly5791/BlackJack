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
		swap(CardTray[rand()%52], CardTray[i]);

	
	
	
	printf("card is mixed and put into the tray\n");
}

//get one card from the tray
int pullCard(void) {
	
	
	
//	int i, j, num, flag[N_CARD];
//	
//	num = rand()%52; // num 0~51
//	flag[check] = num; // pulled card num is saved in flag[]
//	check++;
//	
//	for(j = 0; j<check;j++ )//to check overlap
//	{
//		if (flag[j] == num)
//			num = rand()%51; // if rand()%51 is used num, then rewrite num 	
//	}
//	
//	return CardTray[num]; // not used num will be returned
	
}
