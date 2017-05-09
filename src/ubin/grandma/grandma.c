#include <stdio.h>
#include <math.h>
#include <stdlib.h>

int grid[3][3];

void print_grid()
{
	for(int i = 0; i < 3; i++) {
			char first = grid[i][0] == 0 ? 'x':'o';
			if (grid[i][0] < 0)
				first = ' ';
			char second = grid[i][1] == 0 ? 'x':'o';
			if (grid[i][1] < 0)
				second = ' ';
			char third = grid[i][2] == 0 ? 'x':'o';
			if (grid[i][2] < 0)
				third = ' ';
			printf("%c | %c | %c\n",first,second,third);
			if(i < 2)
				printf("---------\n");
	}
}

// returns 0 if the game isn't number, some int if the game is over
int check_victory() {
	int winlose = 0; // if < 0 then player lost, if > 0 then player won
	int draw = 1; // if > 0, then it's a draw
	for (int i = 0; i < 3; i++) {
		if (grid[i][0] == 0 && grid[i][1] == 0 && grid[i][2] == 0) {
			winlose = 1;
			printf("Player won!\n");
		} else if (grid[i][0] > 0 && grid[i][1] > 0 && grid[i][2] > 0) {
			winlose = -1;
			printf("Computer won!\n");
		}
	}
	// check diagonals:
	if (grid[1][1] == 0 && grid[2][2] == 0 && grid [3][3] == 0) {
		winlose = 1;
		printf("Player won!\n");
	} else if (grid[1][1] > 0 && grid[2][2] > 0 && grid [3][3] > 0) {
		winlose = -1;
		printf("Computer won!\n");
	}

	if (grid[1][3] == 0 && grid [2][2] == 0 && grid[3][1] == 0) {
		winlose = 1;
		printf("Player won!\n");
	} else if (grid[1][3] > 0 && grid [2][2] > 0 && grid[3][1] > 0) {
		winlose = -1;
		printf("Computer won!\n");
	}

	// check for draw
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) {
			if (grid[i][j] < 0) {
				draw = 0;
			}
		}
	}
	if (draw > 0) {
		winlose = 42; // number different than zero just to end the game
	}
	return winlose; 
}

void player_move() {
	printf("Test player movement\n");
	int row, col;
	do {
		row = (int) rand() % 3;
		col = (int) rand() % 3;
	} while (grid[row][col] >= 0);
	grid[row][col] = 0;

}

void computer_move() {
	printf("Test computer movement\n");
	int row, col;
	do {
		row = (int) rand() % 3;
		col = (int) rand() % 3;
	} while (grid[row][col] >= 0);
	grid[row][col] = 1;
}

int main() {
	srand(12312);
	printf("GAME OF THE OLD WOMAN: By Guilherme Cardoso\n");
	printf("Because every Operating System needs a boring game preinstalled. \n");
	// Initializes the board
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) {
			grid[i][j] = -1;
		}
	}
	int playing = 1;
	int player_turn = 1; 
	while(playing) {
		if (check_victory() != 0) {
			playing = 0;
		}
		if (player_turn > 0) {
			player_move();
			player_turn = 0 - player_turn;
		} else {
			computer_move();
			player_turn = 0 - player_turn;
		}
		print_grid(); 
	}
	
}

