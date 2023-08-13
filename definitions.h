#define _CRT_SECURE_NO_WARNINGS 
#include <stdio.h>
#include <stdlib.h>
#include <time.h> 
#define NUMBER_OF_ROWS 6 
#define NUMBER_OF_COLUMNS 7
int display_menu();
void initialize_game_board(char arr[][NUMBER_OF_COLUMNS]);
int select_who_starts_first();
int find_winner(char arr[][7], int color);
void get_random_position(int* row, int* column);
void display_board(char arr[][NUMBER_OF_COLUMNS]);
int is_valid_placement(char arr[][NUMBER_OF_COLUMNS], int row_index, int column_index);