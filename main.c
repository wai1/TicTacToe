/**
* Section 9
* Tic Tac Toe
* Section 9 - Udemy Class
* Author: Walt Iddings
* A basic game of tic-tac-Toe
*/

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

// Prototypes
void welcome();
void drawBoard();
bool checkForWin(char);
bool checkLocation(char);
void markBoard(char, char);

char board[9][11] =      {{' ', ' ', ' ', '|', ' ', ' ', ' ', '|', ' ', ' ', ' '},
                          {' ', '1', ' ', '|', ' ', '2', ' ', '|', ' ', '3', ' '},
                          {'_', '_', '_', '|', '_', '_', '_', '|', '_', '_', '_'},
                          {' ', ' ', ' ', '|', ' ', ' ', ' ', '|', ' ', ' ', ' '},
                          {' ', '4', ' ', '|', ' ', '5', ' ', '|', ' ', '6', ' '},
                          {'_', '_', '_', '|', '_', '_', '_', '|', '_', '_', '_'},
                          {' ', ' ', ' ', '|', ' ', ' ', ' ', '|', ' ', ' ', ' '},
                          {' ', '7', ' ', '|', ' ', '8', ' ', '|', ' ', '9', ' '},
                          {' ', ' ', ' ', '|', ' ', ' ', ' ', '|', ' ', ' ', ' '},
                         };

int main(void)
{
    bool win = false;
    bool openLocation = false;
    char player1 = 'X';
    char player2 = 'O';
    char player;  // Current player
    char location;  // User position request

    welcome();  // Welcome the players to the game
    drawBoard();  // Draw the board

    player = player1;

    while (!win) {

        printf("Player %c please select the location (1).\n", player);

        scanf(" %c", &location);  // Space is required before conversion factor or else it will read in \n from last input

        openLocation = checkLocation(location);  // Check for valid location

        while (!openLocation) {
            printf("Player %c please select the location(2).\n", player);
            scanf("%c", &location);
            openLocation = checkLocation(location);  // Check for valid location
        }

        markBoard(location, player);  // Add player to position

        drawBoard();  // Redraw the board

        win = checkForWin(player);

        if (win) {
            if (player == 'X') {
                printf("Player 1 wins!\n");
                // break;
            }
            else {
                printf("Player 2 wins!\n");
                // break;
            }
        }

        if (player == player1)
            player = player2;  // Next player
        else
            player = player1;

        // printf("Current player is %c\n", player);
    }

    return 0;
}

void welcome() {

    printf("Welcome to the Tic-Tac-Toe game.\n");
    printf("Player 1 will be X and player 2 will be O.\n\n\n");
}

void drawBoard(){

    for (int y = 0; y < 9; y++) {
        for (int x = 0; x < 11; x++) {
            printf("%c", board[y][x]);
        }
        printf("\n");
    }

    return;
}

bool checkForWin(char player) {

    if(((board[1][1] == player) && (board[1][5] == player) && (board [1][9] == player)) ||
       ((board[1][9] == player) && (board[4][9] == player) && (board [7][9] == player)) ||
       ((board[7][1] == player) && (board[7][5] == player) && (board [7][9] == player)) ||
       ((board[1][1] == player) && (board[4][1] == player) && (board [7][1] == player)) ||
       ((board[1][1] == player) && (board[4][5] == player) && (board [7][9] == player)) ||
       ((board[1][9] == player) && (board[4][5] == player) && (board [7][1] == player)))
       return true;

    else
        return false;
}

bool checkLocation(char location) {

    bool validLocation = true;

    switch (location) {
    case 1:
        if (board[1][1] == 'X' || 'Y')
            validLocation = false;
        break;
    case 2:
        if (board[1][5] == 'X' || 'Y')
            validLocation = false;
        break;
    case 3:
        if (board[1][9] == 'X' || 'Y')
            validLocation = false;
        break;
    case 4:
        if (board[4][1] == 'X' || 'Y')
            validLocation = false;
        break;
    case 5:
        if (board[4][5] == 'X' || 'Y')
            validLocation = false;
        break;
    case 6:
        if (board[4][9] == 'X' || 'Y')
            validLocation = false;
        break;
    case 7:
        if (board[7][1] == 'X' || 'Y')
            validLocation = false;
        break;
    case 8:
        if (board[7][5] == 'X' || 'Y')
            validLocation = false;
        break;
    case 9:
        if (board[7][9] == 'X' || 'Y')
            validLocation = false;
        break;
    }

    return validLocation;
}

void markBoard(char location, char player) {

    switch (location) {
    case '1':
        board[1][1] = player;
        break;
    case '2':
        board[1][5] = player;
        break;
    case '3':
        board[1][9] = player;
        break;
    case '4':
        board[4][1] = player;
        break;
    case '5':
        board[4][5] = player;
        break;
    case '6':
        board[4][9] = player;
        break;
    case '7':
        board[7][1] = player;
        break;
    case '8':
        board[7][5] = player;
        break;
    case '9':
        board[7][9] = player;
        break;
    }
}

