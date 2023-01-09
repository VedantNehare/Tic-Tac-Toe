#include <iostream>
using namespace std;

#define SIZE 9

//------------------------------------------------------
void printCurrentBoard(char board[])
{
    cout << "\n";
    cout << "\t  " << board[0] << "  | " << board[1] << "  | " << board[2] << "\n";
    cout << "\t---------------\n";
    cout << "\t  " << board[3] << "  | " << board[4] << "  | " << board[5] << "\n";
    cout << "\t---------------\n";
    cout << "\t  " << board[6] << "  | " << board[7] << "  | " << board[8] << "\n\n";

}


//------------------------------------------------------
void player1(char board[])
{
    int move;

    cout << "\nPlayer 1's turn: ";
    cin >> move;

    while(1)
        if (board[move] == 'O')
        {
            cout << "Invalid move, try again: ";
            cin >> move;
        }
        else
        {
            break;
        }

    board[move] = 'X';
}


//------------------------------------------------------
void player2(char board[])
{
    int move;

    cout << "\nPlayer 2's turn: ";
    cin >> move;

    while(1)
        if (board[move] == 'X')
        {
            cout << "Invalid move, try again: ";
            cin >> move;
        }
        else
        {
            break;
        }

    board[move] = 'O';
}


//------------------------------------------------------
int winnerCheck(char board[])
{

    /*  check the diagonals */

    if( ((board[0] == board[4]) && (board[4] == board[8])) ||
        ((board[2] == board[4]) && (board[4] == board[6])))
    {
        if(board[4] == 'X')
        {
            cout << "\nGAME OVER!! Player 1 [X] won!\n";
            return 1;
        }
        else
        {
            cout << "\nGAME OVER!! Player 2 [O] won!\n";
            return 2;
        }
    }

    /* check the rows   */
    if( ((board[0] == board[1]) && (board[1] == board[2])) ||
        ((board[3] == board[4]) && (board[4] == board[5])) ||
        ((board[6] == board[7]) && (board[7] == board[8])) )
    {
        if(board[1] == 'X' || board[4] == 'X' || board[7] == 'X')
        {
            cout << "\nGAME OVER!! Player 1 [X] won!\n";
            return 1;
        }
        else
        {
            cout << "\nGAME OVER!! Player 2 [O] won!\n";
            return 2;
        }
    }

    /* check the columns    */
    if( ((board[0] == board[3]) && (board[3] == board[6])) ||
        ((board[1] == board[4]) && (board[4] == board[7])) ||
        ((board[6] == board[7]) && (board[7] == board[8])) )
    {
        if(board[1] == 'X' || board[4] == 'X' || board[7] == 'X')
        {
            cout << "\nGAME OVER!! Player 1 [X] won!\n";
            return 1;
        }
        else
        {
            cout << "\nGAME OVER!! Player 2 [O] won!\n";
            return 2;
        }
    }
}


//------------------------------------------------------
int main()
{
    char board[SIZE] = {'0', '1', '2', '3', '4', '5', '6', '7', '8'};

    cout << "\t  Tic Tac Toe\n";
    printCurrentBoard(board);
    cout << "\nEnter a number to make a move.\n";

    while(1)
    {
        player1(board);
        printCurrentBoard(board);
        if(winnerCheck(board) == 1)
        {
            return (0);
        }

        player2(board);
        printCurrentBoard(board);
        if(winnerCheck(board) == 2)
        {
            return (0);
        }
    }
}
