typedef struct{
	char playerName[100];
	int score;
	char symbol;
}player;

typedef struct{
	char playerName[100];
	int score;
	int difficulty;
}hs;

typedef struct{
	highscore highScore[3];
	char board[7][7];
	int boardSize;
	int winObjective;
	char winner[100];
	int playerCount;
	int difficulty;
}game;
