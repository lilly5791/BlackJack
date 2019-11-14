//card processing functions ---------------

//calculate the actual card number in the blackjack game
int getCardNum(int cardnum) {
	
	cardnum =  
}

//print the card information (e.g. DiaA)
void printCard(int cardnum) {
	
	int i, j;
	
	for(i=0; i<cardnum; i++)
	{
		//some function - pullcard or cardtray
		
		for(j=0; j<cardcnt; j++)
		{
			if(cardhold[i][j]>=0 && cardhold[i][j]<= 12)
			{
				switch(CaryTray[i])
				case 1:
					printf("DIA(A)");
				case 10:
					printf("DIA(Jack) ");
				case 11:
					printf("DIA(Queen)");
				case 12:
					printf("DIA(King)");
				default
					printf("DIA(%d)", i);				
				
			}
			if(CaryTray[i]>=13 && CaryTray[i]<= 25)
			{
				switch(CaryTray[i])
				case 1:
					printf("CLV(A)");
				case 10:
					printf("CLV(Jack) ");
				case 11:
					printf("CLV(Queen)");
				case 12:
					printf("CLV(King)");
				default
					printf("CLV(%d)", i+1 - 13);				
				
			}
			if(CaryTray[i]>=0 && CaryTray[i]<= 12)
			{
				switch(CaryTray[i])
				case 1:
					printf("DIA(A)");
				case 10:
					printf("DIA(Jack) ");
				case 11:
					printf("DIA(Queen)");
				case 12:
					printf("DIA(King)");
				default
					printf("DIA(%d)", i+1);				
				
			}
			if(CaryTray[i]>=0 && CaryTray[i]<= 12)
			{
				switch(CaryTray[i])
				case 1:
					printf("DIA(A)");
				case 10:
					printf("DIA(Jack) ");
				case 11:
					printf("DIA(Queen)");
				case 12:
					printf("DIA(King)");
				default
					printf("DIA(%d)", i+1);				
				
			}
		}
		
	}
	
	
}
