#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <windows.h>

#include"body.h"

int main(){
	system("Color 4E");
	ShowWindow(GetConsoleWindow(), SW_MAXIMIZE);
	int initialize = 1;
	char scan;
	
	do{
		printMenu();
		if(initialize != 1 && initialize != 3){
			printf("");
		}
		scanInteger(&initialize);
		
	}while(initialize < 1 || initialize > 3);
	
	switch(initialize){
		case 1:
			gameInitialization();
			break;
		case 2:
			do{
			printTutorial();
			scanf(" %c", &scan);
					
			}while( scan != 'Y' && scan != 'y');
			main();
			
			break;
		case 3:
			return 0;
	}
}

