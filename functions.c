#include"definitions.h"
int display_menu() {
	int option = 0;
	printf("\n please select from the following options\n");
	printf("\n 1. play game\n");
	printf("\n 2. rules\n");
	printf("\n 3. Quit\n");
	scanf("%d", &option);
	return option;
}

void initialize_game_board(char arr[][NUMBER_OF_COLUMNS]) {
	for (int row = 0; row < (NUMBER_OF_ROWS); row++) {
		for (int column = 0; column < (NUMBER_OF_COLUMNS); column++) {
			arr[row][column] = '-';
		}
	}
}

void display_board(char arr[][NUMBER_OF_COLUMNS]) {
	printf("\n Connect 4 Board \n");
	printf(" ");
	for (int i = 0; i < NUMBER_OF_COLUMNS; i++) {
		printf(" %d", i);
	}
	printf("\n");
	for (int row = 0; row < (NUMBER_OF_ROWS); row++) {
		printf("%d", row);
		printf(" ");
		for (int column = 0; column < (NUMBER_OF_COLUMNS); column++) {
			printf(" %c", arr[row][column]);
		}
		printf("\n");
	}
}

int select_who_starts_first() {
	return rand() % 2 + 1;
}

int is_valid_placement(char arr[][NUMBER_OF_COLUMNS], int row_index, int column_index) {
	if (arr[row_index][column_index] != '-') {
		return 0;
	}
	else {
		return 1;
	}
}

void get_random_position(int* row, int* column) {
	*row = rand() % 7;
	*column = rand() % 8;
}

void manually_place_coin_on_board(char arr[][NUMBER_OF_COLUMNS], int row_index, int column_index) {
	arr[row_index][column_index] = 'r';
}

void manually_place_coin_on_board_p2(char arr[][NUMBER_OF_COLUMNS], int row_index, int column_index) {
	arr[row_index][column_index] = 'b';
}

int find_winner(char arr[][7], char color) {

	int row = 6;
	int col = 7;
	// first check all the rows to see if there is a sequence of 4 coins of the same color
	int winner = 0;
	int count = 0;
	int prev_i = 0;
	int prev_j = 0;
	int prev_flag = 1;

	for (int i = 0; i < row && count < 4; i++)
	{
		for (int j = 0; j < col && count < 4; j++)
		{
			if (arr[i][j] == color)
			{
				if (i == 0 && j == 0)
				{
					prev_j = j - 1;
				}
				if (prev_i == i && prev_j == j - 1)
				{
					count++;
					prev_i = i;
					prev_j = j;
					prev_flag = 1;
				}
			}
			else
			{
				count++;
				prev_flag = 0;
			}

			if (prev_flag == 1 && count >= 4)
			{
				winner = 1;
				return winner;
			}
		}
	}

	/*if (count >= 4)
	{
		winner = 1;
		return winner;
	}*/

	count = 0;
	prev_flag = 1;
	prev_i = 0;
	prev_j = 0;
	// check all the columns to see if there is a sequence of 4 coins of the same color
	for (int j = 0; j < col; j++)
	{
		for (int i = 0; i < row || count == 4; i++)
		{
			if (arr[i][j] == color)
			{
				if (i == 0 && j == 0) prev_i = i - 1;
				if (prev_i == i-1 && prev_j == j)
				{
					count++;
					prev_i = i;
					prev_j = j;
					prev_flag = 1;
				}
			}
			else
			{
				count++;
				prev_flag = 0;
			}

			if (prev_flag == 1 && count >= 4)
			{
				winner = 1;
				return winner;
			}
		}
	}
	/*
	if (count >= 4)
	{
		winner = 1;
		return winner;
	}*/

	count = 0;
	// check negative diagonal
	for (int j = 0; j < col && count <4; j++)
	{
		for (int i = 0; i < row && count < 4; i++)
		{
			if (i==j && arr[i][j] == color)
			{
				count++;
			}
			else
			{
				if (i==j && count < 4)
				{
					count = 0;
				}
			}
		}
	}
	if(count >= 4)
	{
		winner = 1;
		return winner;
	}

	count = 0;
	// check negative diagonal
	for (int i = 0; i < row && count < 4; i++)
	{
		for (int j = 0; j < col && count < 4; j++)
		{
			if ( (j== (i-1)) && arr[i][j] == color)
			{
				count++;
			}
			else
			{
				if ((j == (i - 1)) && count < 4)
				{
					count = 0;
				}
			}
		}
	}

	if (count >= 4)
	{
		winner = 1;
		return winner;
	}

	count = 0;
	prev_i = 0;
	prev_j = 0;
	prev_flag = 0;
	// check negative diagonal
	for (int i = 0; i < row && count < 4; i++)
	{
		for (int j = col-1; j >= 1 && count < 4; j--)
		{
			if (arr[i][j] == color)
			{
				if (count == 0)
				{
					prev_i = i - 1;
					prev_j = j + 1;
				}
				if (prev_i == (i - 1) && prev_j == (j + 1))
				{
					count++;
					prev_i = i;
					prev_j = j;
					prev_flag = 1;
				}
				else
				{
					count++;
					prev_flag = 0;
				}
				if (prev_flag==1 && count >= 4)
				{
					winner = 1;
					return winner;
				}
			}
		}
	}

	return winner;
}
