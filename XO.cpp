#include <iostream>
#include "XO.hpp"
#include "conio.h"
#include "stdfix.h"
#include <string>
#include <limits>
#include <random>
#include <ctime>
#include <cstdlib>
using namespace std;

tictatoe::tictatoe()
{
    for (int i = 0; i < 3; i++)
        for (int j = 0; j < 3; j++)
            cell[i][j] = 0;
    ShowBoard();
};

int tictatoe::play(int x)
{
    if (turn == 1)
    {
        if (x < 4)
        {
            if (cell[0][x - 1] == 0)
            {
                cell[0][x - 1] = 1;
                turn = 2;
            }
            else
            {
                cout << "mouvement invalide";
                turn = 1;
            }
        }
        else if (4 <= x && x < 7)
        {
            if (cell[1][x - 4] == 0)
            {
                cell[1][x - 4] = 1;
                turn = 2;
            }
            else
            {
                cout << "mouvement invalide";
                turn = 1;
            }
        }
        else if (7 <= x)
        {
            if (cell[2][x - 7] == 0)
            {
                cell[2][x - 7] = 1;
                turn = 2;
            }
            else
            {
                cout << "mouvement invalide";
                turn = 1;
            }
        }
    }
    else if (turn == 2)
    {
        if (x < 4)
        {
            if (cell[0][x - 1] == 0)
            {
                cell[0][x - 1] = 2;
                turn = 1;
            }
            else
            {
                cout << "mouvement invalide";
                turn = 2;
            }
        }
        else if (4 <= x && x < 7)
        {
            if (cell[1][x - 4] == 0)
            {
                cell[1][x - 4] = 2;
                turn = 1;
            }
            else
            {
                cout << "mouvement invalide";
                turn = 2;
            }
        }
        else if (7 <= x)
        {
            if (cell[2][x - 7] == 0)
            {
                cell[2][x - 7] = 2;
                turn = 1;
            }
            else
            {
                cout << "mouvement invalide";
                turn = 2;
            }
        }
    }
    ShowBoard();
    int winner = HaveWinner();
    if (winner != 0)
    {
        cout << "Winner is: " << (winner == 1 ? 'X' : 'O') << "\n";
    }
    else if (winner == 0 && equalitecheck()==1)
    {
       cout<<"votre game est :draw";
    }
    

};

void tictatoe::ShowBoard()
{
    cout << "\n";
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            if (cell[i][j] == 1)
            {
                cout << "X ";
            }
            else if (cell[i][j] == 2)
            {
                cout << "O ";
            }
            else
            {
                cout << j + 1 + (i * 3) << " ";
            }
        }
        cout << "\n";
    }
};

int tictatoe::HaveWinner()
{
    for (int i = 0; i < 3; i++)
        if (cell[i][0] != 0 && cell[i][0] == cell[i][1] && cell[i][1] == cell[i][2] && cell[i][2] == cell[i][0])
            return cell[i][0];
    for (int i = 0; i < 3; i++)
        if (cell[0][i] != 0 && cell[0][i] == cell[1][i] && cell[2][i] == cell[1][i] && cell[0][i] == cell[2][i])
            return cell[0][i];
    if (cell[0][0] != 0 && cell[0][0] == cell[1][1] && cell[1][1] == cell[2][2] && cell[0][0] == cell[2][2])
        return cell[0][0];
    if (cell[0][2] != 0 && cell[0][2] == cell[1][1] && cell[2][0] == cell[1][1] && cell[2][0] == cell[0][2])
        return cell[1][1];
    return 0;
};

void tictatoe::SetTurn(int player)
{
    turn = player;
};
char tictatoe::GetTurn()
{

    if (turn == 1)
    {
        return 'X';
    }
    else if (turn == 2)
    {
        return 'O';
    }
};

void check(int &starter)
{
    while ((starter > 2) || starter == 0)
    {
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cout << "enter un entier 1/2 :" << endl;
        cin >> starter;
    };
};
int tictatoe::equalitecheck()
{
    int b = 0;
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            if (cell[i][j] != 0)
            {
                b = b + 1;
            }
        }
    }
    if (b == 9)
    { 
        return 1;
    }
    return 0;
};

void tictatoe::mode(string& mode,int& x)
{
    if (mode=="normal")
    {
        cout << "player " << GetTurn() << ":";
        cin>>x;
    }
    else if (mode=="robot")
    {   
    if(turn==1)
    {
        cout << "player " << GetTurn() << ":";
        cin>>x;
    }
    else if (turn==2)
    {   
        cout << "player " << GetTurn() << ":";
        srand(time(0));
        x=rand()%9+1;
        while (x==a || cell[(x-1) / 3][(x-1) % 3] != 0)
        {
            srand(time(0));
            x=rand()%9+1;
        }
        cout << "Robot plays: " << x << "\n";
    }
    }
}
