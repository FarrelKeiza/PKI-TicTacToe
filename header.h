#include"struct.h"

int addScore(char winner[], char playerName[], int *playerScore);
/*I.S :
  F.S : */

void boardInitialization(char board[7][7], int size);
/*I.S :
  F.S : */

int checkBoard(char board[7][7], int row, int col, int size);
/*I.S :
  F.S : */

int checkDraw(char board[7][7], int size);
/*I.S :
  F.S : */

int checkWin(char board[7][7], int size, int turn, int winObjective);
/*I.S :
  F.S : */

int checkWinner(char board[7][7], int size, int turn, int winObjective);
/*I.S :
  F.S : */

void gameInitialization();
/*I.S :
  F.S : */

void gameplay(game mainGame, player playerOne, player playerTwo);
/*I.S :
  F.S : */

int getBoardSize(int choice);
/*I.S :
  F.S : */

void makeMove(char board[7][7], int row, int col, char symbol);
/*I.S :
  F.S : */

void mediocreBot(char board[7][7], int size, int *row, int *col);
/*I.S :
  F.S : */

void mediumBot(char board[7][7], int size, int *row, int *col, char symbol, int winObjective);

char playerSymbol(int turn);

void printDifficulty();

void printPlayerCount();
/*I.S :
  F.S : */

void printDifficulty();
/*I.S : Halaman Difficulty belum ditampilkan dan masih menampilkan halaman Player Mode 
  F.S : Halaman Difficulty sudah tertampilkan yang berisi opsi tingkat kesusahan game Tic-Tac-Toe*/

void printPlayerCount();
/*I.S :
  F.S : */

void printBoard(char board[7][7], int size);
/*I.S :
  F.S : */

void printBoardSize();
/*I.S :	Halaman Player Mode belum ditampilkan dan masih menampilkan halaman Main Menu
  F.S : Halaman Player Mode sudah tertampilkan yang berisi mode player yaitu Single Player dan Multi Player*/

void printGame(int playerOneScore, int playerTwoScore, char board[7][7], int boardSize, char playerOneName[], char playerTwoName[]);
/*I.S :
  F.S : */

void printGameOver();
/*I.S :
  F.S : */

void printHighScore(hs highScore[]);
/*I.S :
  F.S : */

void printMenu();
/*I.S :
  F.S : */

void printPlayerName(int player);
/*I.S :
  F.S : */

void printScore(int score1, int score2, char playerOneName[], char playerTwoName[]);
/*I.S :
  F.S : */

void printTutorial();
/*I.S : Halaman Tutorial masih belum ditampilkan dan masih menampilkan halaman Utama
  F.S : Halaman Tutorial sudah tertampilkan yang berisi tata cara bermain Tic-Tac-Toe*/

void printWin(int winner, char name[]);
/*I.S :
  F.S : */

void printWinObjective(int size);
/*I.S :
  F.S : */

void readHighScore(hs highScore[]);
/*I.S :
  F.S : */

void saveHighScore(hs highScore[], int playerScore, int difficulty, char playerName[]);
/*I.S :
  F.S : */

void scanInteger(int *value);
/*I.S : Variable passing by reference belum terisi nilai integer dari inputan user
  F.S : Variable passing by reference sudah terisi nilai integer dari inputan user */
  
void scanName(char playerName[]);
/*I.S : Variable passing by reference belum terisi nilai array of character dari inputan user 
  F.S : Variable passing by reference sudah terisi nilai array of character dari inputan user */

void scanUserInput(char board[7][7], int boardSize, int *row, int *col);
/*I.S : Pada saat di halaman gameplay, jikalau user meng inputkan nilai baris dan kolom > atau < papan board tidak akan menampilkan  (belum selesai)
  F.S : */


