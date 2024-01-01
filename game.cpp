#include <bits/stdc++.h>
using namespace std;

//for initialising the whole Tic Tac Toe setup
void initialise(string &s1,string &s2,vector<vector<char>> &grid)
{
    cout<<"Enter name of player 1 : ";
    cin>>s1;

    cout<<"Enter name of player 2 : ";
    cin>>s2;

    cout<<endl;

    cout<<s1<<" will move first"<<endl;
    cout<<s2<<" will move second"<<endl;

    cout<<endl;

    grid[0][0]='1';
    grid[0][1]='2';
    grid[0][2]='3';
    grid[1][0]='4';
    grid[1][1]='5';
    grid[1][2]='6';
    grid[2][0]='7';
    grid[2][1]='8';
    grid[2][2]='9';

    return;
}

//for displaying the Tic Tac Toe board
void print(vector<vector<char>> &grid)
{
    cout<<endl;

    cout<<"       |       |       "<<endl;
    cout<<"   "<<grid[0][0]<<"   |   "<<grid[0][1]<<"   |   "<<grid[0][2]<<"   "<<endl;
    cout<<"_______|_______|_______"<<endl;
    cout<<"       |       |       "<<endl;
    cout<<"   "<<grid[1][0]<<"   |   "<<grid[1][1]<<"   |   "<<grid[1][2]<<"   "<<endl;
    cout<<"_______|_______|_______"<<endl;
    cout<<"       |       |       "<<endl;
    cout<<"   "<<grid[2][0]<<"   |   "<<grid[2][1]<<"   |   "<<grid[2][2]<<"   "<<endl;
    cout<<"       |       |       "<<endl;

    cout<<endl;

    return;
}

//for changing the grid cell corresponding to the digit
bool setgrid(int &digit,int &row,int &col,char &c,vector<vector<char>> &grid)
{
    //Invalid condition 1
    if(digit<1 || digit>9)
    {
        cout<<"Invalid Number, Try Again"<<endl;
        return false;
    }

    //setting the row and column cells from digit
    row=ceil(digit/3.0)-1;
    col=digit%3==0?2:(digit%3)-1;

    //Invalid condition 2
    if(grid[row][col]=='X' || grid[row][col]=='O')
    {
        cout<<"Invalid Position, Try Again"<<endl;
        return false;
    }

    //changing the grid cell and current character
    grid[row][col]=c;
    c=c=='X'?'O':'X';

    return true;
}

//to know whether the game has finished or not
bool logic(string &s1,string &s2,char &c,vector<vector<char>> &grid)
{
    //if any row or column satisfies the winning condition of Tic Tac Toe 
    for(int i=0;i<3;i++)
    {
        if((grid[i][0]==grid[i][1] && grid[i][1]==grid[i][2]) || (grid[0][i]==grid[1][i] && grid[1][i]==grid[2][i]))
        {
            if(c=='X')
            {
                cout<<s2<<" Won"<<endl;
            }

            else
            {
                cout<<s1<<" Won"<<endl;
            }

            //halting the program
            exit(0);
        }
    }

    //if any diagonal satisfies the winning condition of Tic Tac Toe
    if((grid[0][0]==grid[1][1] && grid[1][1]==grid[2][2]) || (grid[0][2]==grid[1][1] && grid[1][1]==grid[2][0]))
    {
        if(c=='X')
        {
            cout<<s2<<" Won"<<endl;
        }

        else
        {
            cout<<s1<<" Won"<<endl;
        }

        //halting the program
        exit(0);
    }

    //to check whether there are still cells left that can be filled
    for(int i=0;i<3;i++)
    {
        for(int j=0;j<3;j++)
        {
            if(grid[i][j]!='X' && grid[i][j]!='O')
            {
                return false;
            }
        }
    }

    return true;
}

int main()
{
    //Player 1 has character 'X'
    //Player 2 has character 'O'

    char c='X';
    int digit,row,col;

    string s1,s2;
    vector<vector<char>> grid(3,vector<char>(3));

    initialise(s1,s2,grid);
    print(grid);

    while(logic(s1,s2,c,grid)==false)
    {
        cout<<"Enter number where you want to place your mark : ";
        cin>>digit;

        while(!setgrid(digit,row,col,c,grid))
        {
            cout<<"Enter number where you want to place your mark : ";
            cin>>digit;
        }

        print(grid);
    }
    
    //if none of the players win
    cout<<"Match is Tie"<<endl;

    return 0;
}