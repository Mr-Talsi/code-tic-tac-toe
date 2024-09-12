#include <iostream>
#include <string>
#include "XO.hpp"
#include <typeinfo>
#include <limits>
#include <cstdlib>
#include <random>
using namespace std;

int main()
{
  tictatoe board;
  int starter;
  int x;
  int niveau;
  string mode;

  cout << "bienvenue au jeu \n";
  cout<<"choissir un mode --> normal ou robot :";
  cin>>mode;

  
  if (mode=="robot")
  {
  cout<<"\n1-facile \n2-intermediare\n3-extreme\nchoissir un niveau -->";
  cin>>niveau;
  }
  

  cout << "choissir X/O : 1/2 ?";
  cin >> starter;

  check(starter);
  board.SetTurn(starter);
  board.setniveau(niveau);
  while (board.HaveWinner() == 0)
  { 
    board.mode(mode,x);
    board.play(x);
    if (board.equalitecheck() == 1)
    {
      break;
    }
  }
  getch();
  return 0;
}
