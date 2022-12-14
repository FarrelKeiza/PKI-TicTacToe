#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>
#include <windows.h>

typedef struct{
	int highScore;
	char board[7][7];
	int boardSize;
	int winObjective;
	char winner[100];
	int playerCount;
	int difficulty;
}game;

typedef struct{
	char playerName[100];
	int score;
	char symbol;
}player;

void printMenu(){
	system("cls");
	printf("\n\n\n\n\n\n\n\n");
	printf("\t\t\t\t\t\t=================================================================\n");
	printf("\t\t\t\t\t\t|-                       ---------------                       -|\n");
	printf("\t\t\t\t\t\t||-----------------------| Tic-Tac-Toe |-----------------------||\n");
	printf("\t\t\t\t\t\t|-                       ---------------                       -|\n");
	printf("\t\t\t\t\t\t||                                                             ||\n");
	printf("\t\t\t\t\t\t|-                                                             -|\n");
	printf("\t\t\t\t\t\t||                                                             ||\n");
	printf("\t\t\t\t\t\t|-                                                             -|\n");
	printf("\t\t\t\t\t\t||                       1. Play Game                          ||\n");
	printf("\t\t\t\t\t\t|-                       2. Exit Game                          -|\n");
	printf("\t\t\t\t\t\t||                                                             ||\n");
	printf("\t\t\t\t\t\t|-                                                             -|\n");
	printf("\t\t\t\t\t\t||                                                             ||\n");
	printf("\t\t\t\t\t\t|-                                                             -|\n");
	printf("\t\t\t\t\t\t||                                                             ||\n"); 
	printf("\t\t\t\t\t\t|-                                                             -|\n");
	printf("\t\t\t\t\t\t||                                                             ||\n");
	printf("\t\t\t\t\t\t|-                 By Programmer Keren Indonesia               -|\n");
	printf("\t\t\t\t\t\t=================================================================\n");
	printf("\n\n");
	printf("\t\t\t\t\t\t\t\t\tMasukkan Input: ");
}

void printBoardSize(){
	system("cls");
	printf("\n\n\n\n\n\n\n\n");
	printf("\t\t\t\t\t\t=================================================================\n");
	printf("\t\t\t\t\t\t|-                       ---------------                       -|\n");
	printf("\t\t\t\t\t\t||-----------------------| Tic-Tac-Toe |-----------------------||\n");
	printf("\t\t\t\t\t\t|-                       ---------------                       -|\n");
	printf("\t\t\t\t\t\t||                         Board Size                          ||\n");
	printf("\t\t\t\t\t\t|-                                                             -|\n");
	printf("\t\t\t\t\t\t||                                                             ||\n");
	printf("\t\t\t\t\t\t|-                                                             -|\n");
	printf("\t\t\t\t\t\t||                           1. 3x3                            ||\n");
	printf("\t\t\t\t\t\t|-                           2. 5x5                            -|\n");
	printf("\t\t\t\t\t\t||                           3. 7x7                            ||\n");
	printf("\t\t\t\t\t\t|-                                                             -|\n");
	printf("\t\t\t\t\t\t||                                                             ||\n");
	printf("\t\t\t\t\t\t|-                                                             -|\n");
	printf("\t\t\t\t\t\t||                                                             ||\n"); 
	printf("\t\t\t\t\t\t|-                                                             -|\n");
	printf("\t\t\t\t\t\t||                                                             ||\n");
	printf("\t\t\t\t\t\t|-                 By Programmer Keren Indonesia               -|\n");
	printf("\t\t\t\t\t\t=================================================================\n");
	printf("\n\n");
	printf("\t\t\t\t\t\t\t\t\tMasukkan Input: ");
}

void scanInteger(int *value){
	scanf("%d", &*value);
}

void printPlayerName(int player){
	system("cls");
	printf("\n\n\n\n\n\n\n\n");
	printf("\t\t\t\t\t\t=================================================================\n");
	printf("\t\t\t\t\t\t|-                       ---------------                       -|\n");
	printf("\t\t\t\t\t\t||-----------------------| Tic-Tac-Toe |-----------------------||\n");
	printf("\t\t\t\t\t\t|-                       ---------------                       -|\n");
	printf("\t\t\t\t\t\t||                                                             ||\n");
	printf("\t\t\t\t\t\t|-                                                             -|\n");
	printf("\t\t\t\t\t\t||                                                             ||\n");
	printf("\t\t\t\t\t\t|-                                                             -|\n");
	printf("\t\t\t\t\t\t||                                                             ||\n");
	printf("\t\t\t\t\t\t|-                        Player Name %d                        -|\n", player);
	printf("\t\t\t\t\t\t||                                                             ||\n");
	printf("\t\t\t\t\t\t|-                                                             -|\n");
	printf("\t\t\t\t\t\t||                                                             ||\n");
	printf("\t\t\t\t\t\t|-                                                             -|\n");
	printf("\t\t\t\t\t\t||                                                             ||\n"); 
	printf("\t\t\t\t\t\t|-                                                             -|\n");
	printf("\t\t\t\t\t\t||                                                             ||\n");
	printf("\t\t\t\t\t\t|-                 By Programmer Keren Indonesia               -|\n");
	printf("\t\t\t\t\t\t=================================================================\n");
	printf("\n\n");
	printf("\t\t\t\t\t\t\t\t\tMasukkan Input: ");
}

void scanName(char playerName[]){
	scanf("%s", playerName);
}

void playerSymbol(char *symbol, int turn){
	switch(turn){
		case 1:
			*symbol = 'X';
			break;
		case 2:
			*symbol = 'O';
			break;
	}
}

void boardInitialization(char board[7][7], int size){
	int i, j;
	
	for(i = 0; i < size; i++){
		for(j = 0; j < size; j++){
			board[i][j] = '_';
		}
	}
}

void printBoard(char board[7][7], int size){
	int i, j;
	
	if(size == 3){
		for(i = 0; i < size; i++){
		printf("\n");
		printf("\t\t\t\t\t\t\t\t\t    ");
			for(j = 0; j < size; j++){
				printf("%c", board[i][j]);
				if(j < size - 1){
					printf(" | ");
				}
			}
		printf("\n");
		}	
	}else if(size == 5){
		for(i = 0; i < size; i++){
		printf("\n");
		printf("\t\t\t\t\t\t\t\t        ");
			for(j = 0; j < size; j++){
				printf("%c", board[i][j]);
				if(j < size - 1){
					printf(" | ");
				}
			}
		printf("\n");
		}
	}else if(size == 7){
		for(i = 0; i < size; i++){
		printf("\n");
		printf("\t\t\t\t\t\t\t\t    ");
			for(j = 0; j < size; j++){
				printf("%c", board[i][j]);
				if(j < size - 1){
					printf(" | ");
				}
			}
		printf("\n");
		}
	}
	printf("\n\t\t\t\t\t\t=================================================================\n");
	printf("\t\t\t\t\t\t                 By Programmer Keren Indonesia                  ");
	printf("\n\n\t\t\t\t\t\t\t\t\tInput Pilihan: ");
}

int getBoardSize(int choice){
	switch(choice){
		case 1:
			return 3;
		case 2:
			return 5;
		case 3:
			return 7;
	}
}

int checkBoard(char board[7][7], int row, int col, int size){
	if(row < 0 || row >= size || col < 0 || col >= size){
		return 99;
	}
	
	if(board[row][col] == '_'){
		return 1;
	}else if(board[row][col] == 'X' || board[row][col] == 'O'){
		return 0;
	}
}

int addScore(char winner[], char playerName[], int *playerScore){
	strcpy(winner, playerName);
	(*playerScore)++;
}

void printScore(int score1, int score2, char playerOneName[], char playerTwoName[]){
	printf("\n\n\n\n\n\n\n\n");
	printf("\t\t\t\t\t\tScore %s: %d                               Score %s : %d       \n", playerOneName,score1, playerTwoName, score2);
	printf("\t\t\t\t\t\t=================================================================\n");
	printf("\t\t\t\t\t\t|-                       ---------------                       -|\n");
	printf("\t\t\t\t\t\t||-----------------------| Tic-Tac-Toe |-----------------------||\n");
	printf("\t\t\t\t\t\t|-                       ---------------                       -|\n");
	printf("\t\t\t\t\t\t=================================================================\n");
}

void printGame(int playerOneScore, int playerTwoScore, char board[7][7], int boardSize, char playerOneName[], char playerTwoName[]){
	system("cls");
	printScore(playerOneScore, playerTwoScore, playerOneName, playerTwoName);
	printBoard(board, boardSize);
}

int checkDraw(char board[7][7], int size){
	int i = 0, j;
	
	while(i < size){
		j = 0;
		while(j < size){
			if(board[i][j] == '_'){
				return 0;
			}
			j++;
		}
		i++;
	}
	
	return 1;
}

void makeMove(char board[7][7], int row, int col, char symbol){
	int index[7][7], i, j, k = 1;
	
	for(i = 0; i < 7; i++){
		for(j = 0; j < 7; j++){
			index[i][j] = k;
			k++;
		}
	}
	
	board[row][col] = symbol;
}

void printWinObjective(int size){
	system("cls");
	printf("\n\n\n\n\n\n\n\n");
	printf("\t\t\t\t\t\t=================================================================\n");
	printf("\t\t\t\t\t\t|-                       ---------------                       -|\n");
	printf("\t\t\t\t\t\t||-----------------------| Tic-Tac-Toe |-----------------------||\n");
	printf("\t\t\t\t\t\t|-                       ---------------                       -|\n");
	printf("\t\t\t\t\t\t||                                                             ||\n");
	printf("\t\t\t\t\t\t|-                                                             -|\n");
	printf("\t\t\t\t\t\t||                                                             ||\n");
	printf("\t\t\t\t\t\t|-                                                             -|\n");
	printf("\t\t\t\t\t\t||                                                             ||\n");
	printf("\t\t\t\t\t\t|-                         Score to win                        -|\n");
	printf("\t\t\t\t\t\t||                                                             ||\n");
	printf("\t\t\t\t\t\t|-                                                             -|\n");
	printf("\t\t\t\t\t\t||                                                             ||\n");
	printf("\t\t\t\t\t\t|-                                                             -|\n");
	printf("\t\t\t\t\t\t||                                                             ||\n"); 
	printf("\t\t\t\t\t\t|-                                                             -|\n");
	printf("\t\t\t\t\t\t||                                                             ||\n");
	printf("\t\t\t\t\t\t|-                 By Programmer Keren Indonesia               -|\n");
	printf("\t\t\t\t\t\t=================================================================\n");
	printf("\n\n");
	
	if(size == 5){
		printf("\t\t\t\t\t\t\t\t\tMasukkan Input(3-5): ");
	}else{
		printf("\t\t\t\t\t\t\t\t\tMasukkan Input(3-7): ");
	}	
}

int checkWinner(char board[7][7], int size, int turn, int winObjective){
	int i = 0, j, count;
	char symbol;
	
	switch(turn){
		case 0:
			symbol = 'X';
			break;
		case 1:
			symbol = 'O';
			break;
	}
	
	while(i < size){
		count = 0;
		j = 0;
		while(j < size){
			if(board[i][j] == symbol){
				count++;
			}else{
				count = 0;
			}
			if(count == winObjective){
				return 1;
			}
			j++;
		}
		i++;
	}
	
	j = 0;
	
	while(j < size){
		count = 0;
		i = 0;
		while(i < size){
			if(board[i][j] == symbol){
				count++;
			}else{
				count = 0;
			}
			if(count == winObjective){
				return 1;
			}
			i++;
		}
		j++;
	}
	
	i = 0;
	j = 0;
	count = 0;
	
	while(i < size){
		if(board[i][j] == symbol){
				count++;
			}else{
				count = 0;
			}
		if(count == winObjective){
			return 1;
		}
		i++;
		j++;
	}
	
	i = 0;
	j = size - 1;
	count = 0;
	
	while(i < size){
		if(board[i][j] == symbol){
			count++;
		}else{
				count = 0;
		}
		if(count == winObjective){
			return 1;
		}
		i++;
		j--;
	}
	
	return 0;
}

void printPlayerCount(){
	system("cls");
	printf("\n\n\n\n\n\n\n\n");
	printf("\t\t\t\t\t\t=================================================================\n");
	printf("\t\t\t\t\t\t|-                       ---------------                       -|\n");
	printf("\t\t\t\t\t\t||-----------------------| Tic-Tac-Toe |-----------------------||\n");
	printf("\t\t\t\t\t\t|-                       ---------------                       -|\n");
	printf("\t\t\t\t\t\t||                         Player Mode                         ||\n");
	printf("\t\t\t\t\t\t|-                                                             -|\n");
	printf("\t\t\t\t\t\t||                                                             ||\n");
	printf("\t\t\t\t\t\t|-                                                             -|\n");
	printf("\t\t\t\t\t\t||                      1. Single Player                       ||\n");
	printf("\t\t\t\t\t\t|-                      2. Multi Player                        -|\n");
	printf("\t\t\t\t\t\t||                                                             ||\n");
	printf("\t\t\t\t\t\t|-                                                             -|\n");
	printf("\t\t\t\t\t\t||                                                             ||\n");
	printf("\t\t\t\t\t\t|-                                                             -|\n");
	printf("\t\t\t\t\t\t||                                                             ||\n"); 
	printf("\t\t\t\t\t\t|-                                                             -|\n");
	printf("\t\t\t\t\t\t||                                                             ||\n");
	printf("\t\t\t\t\t\t|-                 By Programmer Keren Indonesia               -|\n");
	printf("\t\t\t\t\t\t=================================================================\n");
	printf("\n\n");
	printf("\t\t\t\t\t\t\t\t\tMasukkan Input: ");
}

void printDifficulty(){
	system("cls");
	printf("\n\n\n\n\n\n\n\n");
	printf("\t\t\t\t\t\t=================================================================\n");
	printf("\t\t\t\t\t\t|-                       ---------------                       -|\n");
	printf("\t\t\t\t\t\t||-----------------------| Tic-Tac-Toe |-----------------------||\n");
	printf("\t\t\t\t\t\t|-                       ---------------                       -|\n");
	printf("\t\t\t\t\t\t||                         Difficulty                          ||\n");
	printf("\t\t\t\t\t\t|-                                                             -|\n");
	printf("\t\t\t\t\t\t||                                                             ||\n");
	printf("\t\t\t\t\t\t|-                                                             -|\n");
	printf("\t\t\t\t\t\t||                        1. Mediocre                          ||\n");
	printf("\t\t\t\t\t\t|-                        2. Medium                            -|\n");
	printf("\t\t\t\t\t\t||                        3. Masochist                         ||\n");
	printf("\t\t\t\t\t\t|-                        4. PKI                               -|\n");
	printf("\t\t\t\t\t\t||                                                             ||\n");
	printf("\t\t\t\t\t\t|-                                                             -|\n");
	printf("\t\t\t\t\t\t||                                                             ||\n"); 
	printf("\t\t\t\t\t\t|-                                                             -|\n");
	printf("\t\t\t\t\t\t||                                                             ||\n");
	printf("\t\t\t\t\t\t|-                 By Programmer Keren Indonesia               -|\n");
	printf("\t\t\t\t\t\t=================================================================\n");
	printf("\n\n");
	printf("\t\t\t\t\t\t\t\t\tMasukkan Input: ");


}

int checkWin(char board[7][7], int size, int turn){
	if(checkDraw(board, size) == 1){
		return 1;
	}else if((turn + 1) % 2 == 0){
		return 2;
		}else{
			return 3;
		}
}

void printWinMultiplayer(int winner, char name[]){
	system("cls");
	printf("\n\n\n\n\n\n\n\n");
	printf("\t\t\t\t\t\t=================================================================\n");
	printf("\t\t\t\t\t\t|-                       ---------------                       -|\n");
	printf("\t\t\t\t\t\t||-----------------------|    RESULT   |-----------------------||\n");
	printf("\t\t\t\t\t\t|-                       ---------------                       -|\n");
	switch(winner){
		case 1:
			printf("\t\t\t\t\t\tGame is Tie");
			break;
		case 2:
			printf("\t\t\t\t\t\t%s Win", name);
			break;
		case 3:
			printf("\t\t\t\t\t\t%s Win", name);
			break;
	}
	printf("\n\t\t\t\t\t\t=================================================================\n");
	printf("\t\t\t\t\t\t                 By Programmer Keren Indonesia                  ");
}

void printWinSingleplayer(int winner, char name[]){
	system("cls");
	printf("\n\n\n\n\n\n\n\n");
	printf("\t\t\t\t\t\t=================================================================\n");
	printf("\t\t\t\t\t\t|-                       ---------------                       -|\n");
	printf("\t\t\t\t\t\t||-----------------------|    RESULT   |-----------------------||\n");
	printf("\t\t\t\t\t\t|-                       ---------------                       -|\n");
	switch(winner){
		case 1:
			printf("\t\t\t\t\t\tGame is Tie");
			break;
		case 2:
			printf("\n\n\t\t\t\t\t\t\t\t\t   %s Win\n\n", name);
			break;
		case 3:
			printf("\t\t\t\t\t\t%s Win", name);
			break;
	}
	printf("\n\t\t\t\t\t\t=================================================================\n");
}

void printGameOver(){
	printf("\n\t\t\t\t\t\t\t\t     Apakah ingin main lagi?");
	printf("\n\t\t\t\t\t\t\t\t     1. Main Lagi");
	printf("\n\t\t\t\t\t\t\t\t     2. Kembali ke Menu Utama\n");
	printf("\n\t\t\t\t\t\t=================================================================\n");
	printf("\t\t\t\t\t\t                   By Programmer Keren Indonesia                  \n");
	printf("\n");
	printf("\t\t\t\t\t\t\t\t\tMasukkan input: ");
}

void scanUserInput(char board[7][7], int boardSize, int *row, int *col){
	do{
		do{
			scanInteger(&*row);
			scanInteger(&*col);
			*row = *row - 1;
			*col = *col - 1;
			if(checkBoard(board, *row, *col, boardSize) == 99){
				printf("Masukkan input dengan benar");
			}
		}while(*row < 0 || *row >= boardSize || *col < 0 || *col >= boardSize);
		
		if(checkBoard(board, *row, *col, boardSize) == 0){
			printf("Kotak Sudah Terisi");
		}
		
	}while(checkBoard(board, *row, *col, boardSize) != 1);
}

void mediocreBot(char board[7][7], int size, int *row, int *col){
	do{
		*row = rand() % size;
		*col = rand() % size;
	}while(checkBoard(board, *row, *col, size) == 0);
}

void mediumBot(char board[7][7], int size, int *row, int *col, char symbol, int winObjective){
	int i = 0, j, isWin = 0;
	
	while(i < size && isWin == 0){
		j = 0;
		while(j < size && isWin == 0){
			if(checkBoard(board, i, j, size) == 1){
				board[i][j] = symbol;
				if(checkWinner(board, size, 0, winObjective) == 1){
					*row = i;
					*col = j;
					isWin = 1;
				}
				board[i][j] = '_';
			}
			j++;
		}
		i++;
	}
	
	if(isWin == 0){
		mediocreBot(board, size, &(*row), &(*col));
	}
}

void gameplay(game mainGame, player playerOne, player playerTwo){
	int turn, row, col, play;
	
	do{
		boardInitialization(mainGame.board, mainGame.boardSize);
		turn = 0;
		do{
			printGame(playerOne.score, playerTwo.score,mainGame.board, mainGame.boardSize, playerOne.playerName, playerTwo.playerName);
			if(mainGame.difficulty == 0){
				scanUserInput(mainGame.board, mainGame.boardSize, &row, &col);
			}else{
				if(turn == 0){
					scanUserInput(mainGame.board, mainGame.boardSize, &row, &col);
				}
			}
			
			switch(turn){
				case 0:
					makeMove(mainGame.board, row, col, playerOne.symbol);
					break;
				case 1:
					switch(mainGame.difficulty){
						case 1:
							mediocreBot(mainGame.board, mainGame.boardSize, &row, &col);
							break;
						case 2:
							mediumBot(mainGame.board, mainGame.boardSize, &row, &col, playerOne.symbol, mainGame.winObjective);
						default:
							break;
					}
					makeMove(mainGame.board, row, col, playerTwo.symbol);
					break;
			}
			turn = (turn + 1) % 2;
		}while(checkWinner(mainGame.board, mainGame.boardSize, (turn + 1) % 2, mainGame.winObjective) == 0 && checkDraw(mainGame.board, mainGame.boardSize) == 0);
		
		switch(checkWin(mainGame.board, mainGame.boardSize, turn)){
			case 2:
				addScore(mainGame.winner, playerOne.playerName, &playerOne.score);
				break;
			case 3:
				addScore(mainGame.winner, playerTwo.playerName, &playerTwo.score);
				break;
			default:
				strcpy(mainGame.winner, "No One");
		}
		
		printBoard(mainGame.board, mainGame.boardSize);
		
		if(mainGame.difficulty == 0){
			printWinMultiplayer(checkWin(mainGame.board, mainGame.boardSize, turn), mainGame.winner);
		}else{
			printWinSingleplayer(checkWin(mainGame.board, mainGame.boardSize, turn), mainGame.winner);
		}
		
		do{
			printGameOver();
			scanInteger(&play);
		}while(play != 1 && play != 2);
		
		if(play == 2){
			main();
		}
	}while(play == 1);
}

void gameInitialization(){
	game mainGame;
	int choice, row, col;
	player playerOne, playerTwo;
	
	mainGame.winObjective = 3;
	
	playerSymbol(&playerOne.symbol, 1);
	playerSymbol(&playerTwo.symbol, 2);
	
	playerOne.score = 0;
	playerTwo.score = 0;
	
	do{
		printBoardSize();
		scanInteger(&choice);
	}while(choice < 1 && choice > 3);
	
	mainGame.boardSize = getBoardSize(choice);
	
	if(mainGame.boardSize > 3){
		switch(mainGame.boardSize){
			case 5:
				do{
					printWinObjective(mainGame.boardSize);
					scanInteger(&mainGame.winObjective);
				}while(mainGame.winObjective < 3 || mainGame.winObjective > 5);
				break;
			case 7:
				do{
					printWinObjective(mainGame.boardSize);
					scanInteger(&mainGame.winObjective);
				}while(mainGame.winObjective < 3 || mainGame.winObjective > 7);
				break;
		}
	}
	
	do{
		printPlayerCount();
		scanInteger(&choice);
	}while(choice != 1 && choice != 2);
	
	if(choice == 1){
		strcpy(playerTwo.playerName, "Computer");
		do{
			printDifficulty();
			scanInteger(&mainGame.difficulty);
		}while(mainGame.difficulty < 1 && mainGame.difficulty > 4);
	}
	
	printPlayerName(1);
	scanName(playerOne.playerName);
				
	if(choice == 2){
		mainGame.difficulty = 0;
		printPlayerName(2);
		scanName(playerTwo.playerName);
	}
	gameplay(mainGame, playerOne, playerTwo);
}

int main(){
	system("Color 4E");
	ShowWindow(GetConsoleWindow(), SW_MAXIMIZE);
	int initialize = 1;
	
	do{
		printMenu();
		if(initialize != 1 && initialize != 2){
			printf("");
		}
		scanInteger(&initialize);
		
	}while(initialize != 1 && initialize != 2);
	
	switch(initialize){
		case 1:
			gameInitialization();
			break;
		case 2:
			return 0;
	}
}

