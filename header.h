#include"struct.h"

int addScore(char winner[], char playerName[], int *playerScore);

void boardInitialization(char board[7][7], int size);

int checkBoard(char board[7][7], int row, int col, int size);

int checkDraw(char board[7][7], int size);

int checkWin(char board[7][7], int size, int turn);

int checkWinner(char board[7][7], int size, int turn, int winObjective);

void gameInitialization();

void gameplay(game mainGame, player playerOne, player playerTwo);

int getBoardSize(int choice);

void makeMove(char board[7][7], int row, int col, char symbol);

void mediocreBot(char board[7][7], int size, int *row, int *col);

void mediumBot(char board[7][7], int size, int *row, int *col, char symbol, int winObjective);

void printDifficulty();

void printPlayerCount();

void playerSymbol(char *symbol, int turn);

void printBoard(char board[7][7], int size);

void printBoardSize();

void printGame(int playerOneScore, int playerTwoScore, char board[7][7], int boardSize, char playerOneName[], char playerTwoName[]);

void printGameOver();

void printMenu();

void printPlayerName(int player);

void printScore(int score1, int score2, char playerOneName[], char playerTwoName[]);

void printTutorial();

void printWin(int winner, char name[]);

void printWinObjective(int size);

void readHighScore();

void saveHighScore(hs highscore[], int playerScore, int difficulty);

void scanInteger(int *value);

void scanName(char playerName[]);

void scanUserInput(char board[7][7], int boardSize, int *row, int *col);


