#ifndef __XO__
#define __XO__
#include <string>
#include "conio.h"
#include "stdfix.h"
using namespace std;
class tictatoe
{
public:
    tictatoe();
    int play(int x);
    int HaveWinner();
    void SetTurn(int player);
    char GetTurn();
    int equalitecheck();
    void mode(string& mode, int& x);

private:
    int cell[3][3];
    void ShowBoard(void);
    int turn;
};
void check(int &starter);

#endif