typedef struct{
	char board3[3][3];
	char board5[5][5];
	char board7[7][7];
}board;

typedef struct{
	int minute;
	int second;
}timer;

int checkWinner();

int gameplay();

void printMenuMain();

void printMenuPlayerCount();

void printMenuDifficulty();

void printMenuBoardSize();

void printMenuScoretoWin();

void printSaveFileNotFound();

void printSetTimer();

void printUI();

void printWinner(gameplay());

void scanInputUser(char *, );

void scanScoretoWin(int *, );
