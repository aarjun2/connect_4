#include "definitions.h"

int main(void) {
	int option = 0;
	option = display_menu();
	int win = 0, turn_count = 0, player_turn = 0;
	char board[NUMBER_OF_ROWS][NUMBER_OF_COLUMNS];
	switch (option) {
	case 1:
		initialize_game_board(board);
		player_turn = rand() % 2 + 1;
		int player_1_count = 0, player_2_count = 0;
		do {
			if (player_turn == 1 && player_1_count == 0) {
				turn_count++;
				player_1_count++;
				display_board(board);
				int row = 0;
				int column = 0;
				char red_coordinate[3];
				printf("enter a coordinate to place your coin :");
				scanf("%s", &red_coordinate);
				row = red_coordinate[0] - '0';
				column = red_coordinate[1] - '0';
				if (board[row][column] == '-')
				{
					board[row][column] = 'r';
				}
				// is_valid_placement(board, row, column);
				win = find_winner(board, 'r');
				if (win == 1) {
					printf("\nplayer 1 wins\n");
					display_board(board);
					break;
				}
				else
				{
					player_2_count = 0;
					player_turn = 2;
				}
			}
			if (player_turn == 2 && player_2_count == 0) {
				turn_count++;
				player_2_count++;
				display_board(board);
				int row;
				int column;
				get_random_position(&row, &column);
				if (board[row][column] == '-')
				{
					board[row][column] = 'b';
				}
				// is_valid_placement(board, row, column);
				win = find_winner(board, 'b');
				if (win == 1) {
					printf("\nplayer 2 wins\n");
					display_board(board);
					break;
				}
				else
				{
					player_1_count = 0;
					player_turn = 1;
				}
			}
		} while (turn_count <= 42 || win != 1);
		break;
	case 2:
		printf("player must connect four in a row diagonally, vertically or horizontally to win, player alternate turns");
		break;
	case 3:
		printf("goodbye");
		break;
	}
	return 0;
}

