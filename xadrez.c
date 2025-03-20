#include <stdio.h>

#define BOARD_SIZE 8

void move_bishop(int x, int y, int board[BOARD_SIZE][BOARD_SIZE]) 
{
    for (int i = 1; i < BOARD_SIZE; i++) 
    {
        if (x + i < BOARD_SIZE && y + i < BOARD_SIZE) board[x + i][y + i] = 1;
        if (x - i >= 0 && y - i >= 0) board[x - i][y - i] = 1;
        if (x + i < BOARD_SIZE && y - i >= 0) board[x + i][y - i] = 1;
        if (x - i >= 0 && y + i < BOARD_SIZE) board[x - i][y + i] = 1;
    }
}

void move_rook(int x, int y, int board[BOARD_SIZE][BOARD_SIZE]) 
{
    for (int i = 0; i < BOARD_SIZE; i++) 
    {
        board[x][i] = 1;
        board[i][y] = 1;
    }
}

void move_queen(int x, int y, int board[BOARD_SIZE][BOARD_SIZE]) 
{
    move_bishop(x, y, board);
    move_rook(x, y, board);
}

void move_knight(int x, int y, int board[BOARD_SIZE][BOARD_SIZE]) 
{
    int moves[8][2] = {{2, 1}, {2, -1}, {-2, 1}, {-2, -1},
                        {1, 2}, {1, -2}, {-1, 2}, {-1, -2}};
    for (int i = 0; i < 8; i++) 
    {
        int new_x = x + moves[i][0];
        int new_y = y + moves[i][1];
        if (new_x >= 0 && new_x < BOARD_SIZE && new_y >= 0 && new_y < BOARD_SIZE) 
        {
            board[new_x][new_y] = 1;
        }
    }
}

void print_board(int board[BOARD_SIZE][BOARD_SIZE]) 
{
    for (int i = 0; i < BOARD_SIZE; i++) 
    {
        for (int j = 0; j < BOARD_SIZE; j++) 
        {
            printf("%d ", board[i][j]);
        }
        printf("\n");
    }
}

int main() 
{
    int board[BOARD_SIZE][BOARD_SIZE] = {0};
    int x = 3, y = 3;

    printf("Movimentação do Bispo:\n");
    move_bishop(x, y, board);
    print_board(board);

    printf("\nMovimentação da Torre:\n");
    for (int i = 0; i < BOARD_SIZE; i++)
        for (int j = 0; j < BOARD_SIZE; j++)
            board[i][j] = 0;
    move_rook(x, y, board);
    print_board(board);

    printf("\nMovimentação da Rainha:\n");
    for (int i = 0; i < BOARD_SIZE; i++)
        for (int j = 0; j < BOARD_SIZE; j++)
            board[i][j] = 0;
    move_queen(x, y, board);
    print_board(board);

    printf("\nMovimentação do Cavalo:\n");
    for (int i = 0; i < BOARD_SIZE; i++)
        for (int j = 0; j < BOARD_SIZE; j++)
            board[i][j] = 0;
    move_knight(x, y, board);
    print_board(board);

    return 0;
}
