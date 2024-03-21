//AUTHOR : Anirudh Mishra [with co partners: Yash Prabhat & Shudhanshu Pal]
//Tic Tac Toe 
#include <iostream> 
#include<stdio.h>
using namespace std; 
  
// Function to draw the Tic-Tac-Toe board 
void drawBoard(char board[3][3]) 
{ 
    cout << "-------------\n"; 
    for (int i = 0; i < 3; i++) { 
        cout << "| "; 
        for (int j = 0; j < 3; j++) { 
            cout << board[i][j] << " | "; 
        } 
        cout << "\n-------------\n"; 
    } 
}
//Check win function fo checking if  player has or not .
bool checkwin(char board[3][3],char player)
{
    //In this, it will check all vertical,horizontal & diagonal elments to be same. 
    for(int j = 0; j < 2; j++)
    {
        if (board[0][j]&&board[1][j]&&board[2][j]==player)
            return true;
        if (board[j][0]&&board[j][1]&&board[j][2]==player)
            return true;;
    }
    if (board[0][0]&&board[1][1]&&board[2][2]==player)
        return true;
    if (board[0][2]&&board[1][1]&&board[2][0]==player)
        return true;
    return false;
}
int main()
{
    int row,col,turn;
    char player='X';
    //2D array 
    char board[3][3]= { {' ',' ',' '},
                        {' ',' ',' '},
                        {' ',' ',' '}   };
    //Turn is used to fill all the elements i.e. 9.
    for ( turn = 0; turn < 9; turn++)
    {
        //Starting the game
        drawBoard(board);
        //It will take input from two users X and O, and check for the inavlid inputs if given.
        while(true)
        {
            // Taking Row and Column for the place player wants to input.
            cout<<"Player  "<<player<<" Please enter row(0-2) and column(0-2) :";
            cin>>row>>col;
            fflush(stdin);
            //checking invalidity
            if (board[row][col]!=' '|| row<0 || row>2 || col<0 || col>>2 )
            {
                cout<<"\nINVALID MOVE\n";
            }
            else
                break;
    }
    //making the move
    board[row][col]=player;
    if (checkwin(board,player))
    {
        drawBoard(board);
        cout<<"Player "<<player<<" wins !!!"<<endl;
        break;
    }
    //switching the player
        player = (player == 'X') ? 'O' : 'X';
    }
    //end the game
    drawBoard(board);
    //check for draw
    if (turn=9 && !checkwin(board,'O') && !checkwin(board,'X') )
    {
        cout<<"Its a Draw !!!"<<endl;
    }
    return 0;

}