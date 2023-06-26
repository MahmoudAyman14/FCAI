#include <iostream>
#include <stdlib.h>
using namespace std;

void Print(char board[][7]){
cout << "  0  |  1  |  2  |  3  |  4  |  5  |  6  " << endl;
cout << "     |     |     |     |     |     |     " << endl;

cout << "  " << board[5][0] << "  |  " << board[5][1] << "  |  " << board[5][2] << "  |  "  << board[5][3] << "  |  " << board[5][4] << "  |  " << board[5][5] << "  |  " << board[5][6] << endl;

cout << "_____|_____|_____|_____|_____|_____|_____" << endl;
cout << "     |     |     |     |     |     |     " << endl;

cout << "  " << board[4][0] << "  |  " << board[4][1] << "  |  " << board[4][2] << "  |  "  << board[4][3] << "  |  " << board[4][4] << "  |  " << board[4][5] << "  |  " << board[4][6] << endl;

cout << "_____|_____|_____|_____|_____|_____|_____" << endl;
cout << "     |     |     |     |     |     |     " << endl;

cout << "  " << board[3][0] << "  |  " << board[3][1] << "  |  " << board[3][2] << "  |  "  << board[3][3] << "  |  " << board[3][4] << "  |  " << board[3][5] << "  |  " << board[2][6] << endl;

cout << "_____|_____|_____|_____|_____|_____|_____" << endl;
cout << "     |     |     |     |     |     |     " << endl;

cout << "  " << board[2][0] << "  |  " << board[2][1] << "  |  " << board[2][2] << "  |  "  << board[2][3] << "  |  " << board[2][4] << "  |  " << board[2][5] << "  |  " << board[2][6] << endl;

cout << "_____|_____|_____|_____|_____|_____|_____" << endl;
cout << "     |     |     |     |     |     |     " << endl;

cout << "  " << board[1][0] << "  |  " << board[1][1] << "  |  " << board[1][2] << "  |  "  << board[1][3] << "  |  " << board[1][4] << "  |  " << board[1][5] << "  |  " << board[1][6] << endl;

cout << "_____|_____|_____|_____|_____|_____|_____" << endl;
cout << "     |     |     |     |     |     |     " << endl;

cout << "  " << board[0][0] << "  |  " << board[0][1] << "  |  " << board[0][2] << "  |  "  << board[0][3] << "  |  " << board[0][4] << "  |  " << board[0][5] << "  |  " << board[0][6] << endl;

cout << "     |     |     |     |     |     |     " << endl << endl;

}

bool Insert(char board[][7], char player, int column){

    for(int i=0;i<6;i++){

    if(board[i][column] == ' '){
        board[i][column] = player;
        return true;
    }

    }

return false;
}

char Iswinnerning(char board[][7]){

for(int i=0;i<6;i++){
    for(int j=0;j<7;j++){

//-------------------X---------------------
if( board[i][j] == 'X'     &&
    board[i-1][j-1] == 'X' &&
    board[i-2][j-2] == 'X' &&
    board[i-3][j-3] == 'X' )
{
    return 'X';
}


if( board[i][j] == 'X'   &&
    board[i][j-1] == 'X' &&
    board[i][j-2] == 'X' &&
    board[i][j-3] == 'X' )
{
    return 'X';
}

if( board[i][j] == 'X'   &&
    board[i-1][j] == 'X' &&
    board[i-2][j] == 'X' &&
    board[i-3][j] == 'X' )
{
    return 'X';
}

if( board[i][j] == 'X'     &&
    board[i-1][j+1] == 'X' &&
    board[i-2][j+2] == 'X' &&
    board[i-3][j+3] == 'X' )
{
    return 'X';
}

if ( board[i][j] == 'X'   &&
     board[i][j+1] == 'X' &&
     board[i][j+2] == 'X' &&
     board[i][j+3] == 'X' )
{
    return 'X';
}

if ( board[i][j] == 'X'   &&
     board[i+1][j-1] == 'X' &&
     board[i+2][j-2] == 'X' &&
     board[i+3][j-3] == 'X' )
{
    return 'X';
}

if ( board[i][j] == 'X'   &&
     board[i+1][j+1] == 'X' &&
     board[i+2][j+2] == 'X' &&
     board[i+3][j+3] == 'X' )
{
    return 'X';
}

//--------------------O------------------



if( board[i][j] == 'O'     &&
    board[i-1][j-1] == 'O' &&
    board[i-2][j-2] == 'O' &&
    board[i-3][j-3] == 'O' )
{
    return 'O';
}


if( board[i][j] == 'O'   &&
    board[i][j-1] == 'O' &&
    board[i][j-2] == 'O' &&
    board[i][j-3] == 'O' )
{
    return 'O';
}

if( board[i][j] == 'O'   &&
    board[i-1][j] == 'O' &&
    board[i-2][j] == 'O' &&
    board[i-3][j] == 'O' )
{
    return 'O';
}

if( board[i][j] == 'O'     &&
    board[i-1][j+1] == 'O' &&
    board[i-2][j+2] == 'O' &&
    board[i-3][j+3] == 'O' )
{
    return 'O';
}

if ( board[i][j] == 'O'   &&
     board[i][j+1] == 'O' &&
     board[i][j+2] == 'O' &&
     board[i][j+3] == 'O' )
{
    return 'O';
}

if ( board[i][j] == 'O'   &&
     board[i+1][j-1] == 'O' &&
     board[i+2][j-2] == 'O' &&
     board[i+3][j-3] == 'O' )
{
    return 'O';
}

if ( board[i][j] == 'O'   &&
     board[i+1][j+1] == 'O' &&
     board[i+2][j+2] == 'O' &&
     board[i+3][j+3] == 'O' )
{
    return 'O';
}

}
}

return ' ';
}

int main()
{

//---------initializing the board to be empty------------
char board[6][7];
for(int i=0;i<6;i++){
    for(int j=0;j<7;j++){
        board[i][j]=' ';
    }
}

int player_X_flag = 1;
int player_O_flag = 0;
bool status = true;

while(true){
    system("cls");
    char winner = Iswinnerning(board);
    if(winner == 'X'){
        cout<<"The Winner Is: X"<<endl;
        Print(board);
        break;
    }else if(winner == 'O'){
        cout<<"The Winner Is: O"<<endl;
        Print(board);
        break;
    }


    Print(board);
    int column;
    cout<<"Choose the column you want to insert the tile in from 0 to 6: ";
    cin>>column;

if(column >=0 && column <= 6){
    if(player_X_flag == 1){

        status = Insert(board, 'X', column);
        if(status == true){
            player_X_flag = 0;
            player_O_flag = 1;
            }else{cout<<"Kindly choose correct column"<<endl;}
    }else{

        status = Insert(board, 'O', column);
        if(status == true){
            player_O_flag = 0;
            player_X_flag =1;
        }else{cout<<"Kindly choose correct column"<<endl;}
    }

}else{
    cout<<"Kindly choose correct column"<<endl;
}

}







    return 0;
}

