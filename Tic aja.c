#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>

typedef struct{
	int highScore;
	char board[7][7];
	int boardSize;
	int winObjective;
}game;

typedef struct{
	char playerName[100];
	int score;
	char symbol;
	int turn;
}player;

void printMenu(){
	system("cls");
	printf("==============================");
	printf("\nSelamat Datang di Tic Tac Toe");
	printf("\n=============================");
	printf("\n1. Mainkan Tic Tac Toe");
	printf("\n2. Keluar Game");
	printf("\nPilih menu: ");
}

void printBoardSize(){
	system("cls");
	printf("=====================");
	printf("\nUkuran Papan");
	printf("\n====================");
	printf("\n1. 3x3");
	printf("\n2. 5x5");
	printf("\n3. 7x7");
	printf("\nPilih ukuran papan: ");
}

void scanInteger(int *value){
	scanf("%d", &*value);
}

void printPlayerName(int player){
	system("cls");
	printf("=====================");
	printf("\nNama untuk player %d", player);
	printf("\n====================");
	printf("\nNama player: ");
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
		
	system("cls");
	for(i = 0; i < size; i++){
		for(j = 0; j < size; j++){
			printf("%c", board[i][j]);
			if(j < size - 1){
				printf(" | ");
			}
		}
		printf("\n");
	}
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

int checkBoard(char board[7][7], int row, int col){
	if(board[row][col] == '_'){
		return 1;
	}else{
		return 0;
	} 
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
	board[row][col] = symbol;
}

void printWinObjective(int size){
	system("cls");
	printf("=====================");
	printf("\nTujuan untuk menang");
	printf("\n====================");
	if(size == 5){
		printf("\nInput angka(3-5): ");
	}else{
		printf("\nInput angka(3-7): ");
	}	
}

int checkWinner(char board[7][7], int size, int turn, int winObjective){
	int i = 0, j = 0, winner = 0, count;
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
		while(j < size){
			if(board[i][j] == symbol){
				count++;
			}
			if(count == winObjective){
				return 1;
			}
			j++;
		}
		i++;
	}
	
	i = 0;
	j = 0;
	
	while(j < size){
		count = 0;
		while(i < size){
			if(board[i][j] == symbol){
				count++;
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
	printf("=====================");
	printf("\nMode Pemain");
	printf("\n====================");
	printf("\n1. Singleplayer");
	printf("\n2. Multiplayer");
	printf("\nPilih jumlah pemain: ");
}

void printDifficulty(){
	system("cls");
	printf("=====================");
	printf("\nKesulitan Komputer");
	printf("\n====================");
	printf("\n1. Mediocre");
	printf("\n2. Medium");
	printf("\n3. Masochist");
	printf("\nPilih tingkat kesulitan komputer: ");
}

int getRow(int row){
	return row;
}

int getCol(int col){
	return col;
}

void mediocreBot(char board[7][7], int size, int *row, int *col){
	do{
		*row = rand() % size;
		*col = rand() % size;
	}while(checkBoard(board, *row, *col) == 0);
}

void gameplayMultiplayer(game mainGame, player playerOne, player playerTwo){
	int turn = 0, row, col;

	do{
		printBoard(mainGame.board, mainGame.boardSize);
		do{
			do{
				scanInteger(&row);
				scanInteger(&col);
				if(row < 0 || row >= mainGame.boardSize || col < 0 || col >= mainGame.boardSize){
					printf("Isikan input yang benar\n");
				}
			}while(row < 0 && row >= mainGame.boardSize && col < 0 && col >= mainGame.boardSize);
			if(checkBoard(mainGame.board, row, col) == 0){
				printf("Kotak sudah terisi\n");
			}
		}while(checkBoard(mainGame.board, row, col) == 0);
		switch(turn){
			case 0:
				makeMove(mainGame.board, row, col, playerOne.symbol);
				break;
			case 1:
				makeMove(mainGame.board, row, col, playerTwo.symbol);
				break;
		}
		turn = (turn + 1) % 2;
	}while(checkWinner(mainGame.board, mainGame.boardSize, (turn + 1) % 2, mainGame.winObjective) == 0 && checkDraw(mainGame.board, mainGame.boardSize) == 0);
	
	printBoard(mainGame.board, mainGame.boardSize);
	
	if(checkDraw(mainGame.board, mainGame.boardSize) == 1){
		printf("Permainan Seri");
	}else if((turn + 1) % 2 == 0){
		printf("%s Menang", playerOne.playerName);
		}else{
			printf("%s Menang", playerTwo.playerName);
		}
}

void gameplayMediocre(game mainGame, player playerOne, player playerTwo){
	int turn = 0, row, col;
	
	do{
		printBoard(mainGame.board, mainGame.boardSize);
		if(turn == 0){
			do{
				do{
					scanInteger(&row);
					scanInteger(&col);
					if(row < 0 || row >= mainGame.boardSize || col < 0 || col >= mainGame.boardSize){
						printf("Isikan input yang benar\n");
					}
				}while(row < 0 && row >= mainGame.boardSize && col < 0 && col >= mainGame.boardSize);
				if(checkBoard(mainGame.board, row, col) == 0){
					printf("Kotak sudah terisi\n");
				}
			}while(checkBoard(mainGame.board, row, col) == 0);
		}
		switch(turn){
			case 0:
				makeMove(mainGame.board, row, col, playerOne.symbol);
				break;
			case 1:
				mediocreBot(mainGame.board, mainGame.boardSize, &row, &col);
				makeMove(mainGame.board, row, col, playerTwo.symbol);
				break;
		}
		turn = (turn + 1) % 2;
	}while(checkWinner(mainGame.board, mainGame.boardSize, (turn + 1) % 2, mainGame.winObjective) == 0 && checkDraw(mainGame.board, mainGame.boardSize) == 0);
	
	printBoard(mainGame.board, mainGame.boardSize);
	
	if(checkDraw(mainGame.board, mainGame.boardSize) == 1){
		printf("Permainan Seri");
	}else if((turn + 1) % 2 == 0){
		printf("%s Menang", playerOne.playerName);
		}else{
			printf("Computer Menang");
		}
}

void gameInitialization(){
	game mainGame;
	int choice, row, col;
	player playerOne, playerTwo;
	
	mainGame.winObjective = 3;
	
	playerSymbol(&playerOne.symbol, 1);
	playerSymbol(&playerTwo.symbol, 2);
	
	do{
		printBoardSize();
		scanInteger(&choice);
	}while(choice != 1 && choice != 2 && choice != 3);
	
	mainGame.boardSize = getBoardSize(choice);
	
	boardInitialization(mainGame.board, mainGame.boardSize);
	
	if(mainGame.boardSize > 3){
		switch(mainGame.boardSize){
			case 5:
				do{
					printWinObjective(mainGame.boardSize);
					scanInteger(&mainGame.winObjective);
				}while(mainGame.winObjective < 3 && mainGame.winObjective > 5);
				break;
			case 7:
				do{
					printWinObjective(mainGame.boardSize);
					scanInteger(&mainGame.winObjective);
				}while(mainGame.winObjective < 3 && mainGame.winObjective > 7);
				break;
		}
	}
	
	do{
		printPlayerCount();
		scanInteger(&choice);
	}while(choice != 1 && choice != 2);
	
	if(choice == 1){
		printPlayerName(1);
		scanName(playerOne.playerName);
		printPlayerName(2);
		scanName(playerTwo.playerName);
		gameplayMultiplayer(mainGame, playerOne, playerTwo);
	}else{
		do{
			printDifficulty();
			scanInteger(&choice);
		}while(choice != 1 && choice != 2 && choice != 3);
		
		printPlayerName(1);
		scanName(playerOne.playerName);
				
		switch(choice){
			case 1:
				gameplayMediocre(mainGame, playerOne, playerTwo);
				break;
		}
	}
}

int main(){
	int initialize = 1;
	
	do{
		printMenu();
		if(initialize != 1 && initialize != 2){
			printf("\n\nInput hanya 1/2\n");
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

