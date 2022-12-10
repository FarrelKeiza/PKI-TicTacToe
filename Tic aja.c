#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct{
	int highScore;
	char board[7][7];
	int boardSize;
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
	printf("\nPilih Ukuran Papan: ");
}

void scanInteger(int *value){
	scanf("%d", &*value);
}

void printPlayerName(int player){
	system("cls");
	printf("=====================");
	printf("\nNama untuk player %d", player);
	printf("\n====================");
	printf("\nNama Player: ");
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

void scanUserInput(int *row, int *col){
	scanf("%d %d", &*row, &*col);
}

int checkBoard(char board[7][7], int row, int col){
	if(board[row][col] == '_'){
		return 0;
	}else{
		return 1;
	}
}

void makeMove(char board[7][7], int row, int col, char symbol){
	board[row][col] = symbol;
}

int checkWinner(char board[7][7], int size, int turn){
	int i = 0, j = 0, winner = 0, count, winCondition = 3;
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
		while(j < size && size - j >= winCondition){
			if(board[i][j] == symbol){
				count++;
			}
			if(count == winCondition){
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
		while(i < size && size - i >= winCondition){
			if(board[i][j] == symbol){
				count++;
			}
			if(count == winCondition){
				return 1;
			}
			i++;
		}
		j++;
	}
	
	i = 0;
	j = 0;
	
	while(i < size){
		count = 0;
		if(board[i][j] == symbol){
				count++;
			}
		if(count == winCondition){
			return 1;
		}
		i++;
		j++;
	}
	
	i = 0;
	j = size - 1;
	
	while(i < size){
		count = 0;
		if(board[i][j] == symbol){
			count++;
		}
		if(count == winCondition){
			return 1;
		}
		i++;
		j--;
	}
}

void gameplay(){
	game mainGame;
	int choice, row, col;
	player playerOne, playerTwo;
	
	do{
		printBoardSize();
		scanInteger(&choice);
	}while(choice != 1 && choice != 2 && choice != 3);
	
	mainGame.boardSize = getBoardSize(choice);
	
	printPlayerName(1);
	scanName(playerOne.playerName);
	printPlayerName(2);
	scanName(playerTwo.playerName);
	
	playerSymbol(&playerOne.symbol, 1);
	playerSymbol(&playerTwo.symbol, 2);
	
	boardInitialization(mainGame.board, mainGame.boardSize);

	
	int turn = 0;
	
	do{
		printBoard(mainGame.board, mainGame.boardSize);
		do{
			scanUserInput(&row, &col);
			if(checkBoard(mainGame.board, row, col) == 1){
				printf("Kotak sudah terisi\n");
			}
		}while(checkBoard(mainGame.board, row, col) == 0);
		switch(turn){
			case 0:
				makeMove(mainGame.board, row, col, 'X');
				break;
			case 1:
				makeMove(mainGame.board, row, col, 'O');
				break;
		}
		turn = (turn + 1) % 2;
	}while(checkWinner(mainGame.board, mainGame.boardSize, (turn + 1) % 2) == 0);
	
	if((turn + 1) % 2){
		printf("Player 1 Menang");
	}else{
		printf("Player 2 Menang");
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
			gameplay();
			break;
		case 2:
			return 0;
	}
}

