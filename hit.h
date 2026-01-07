#define WIN32_LEAN_AND_MEAN
#define _HAS_STD_BYTE 0
#include <windows.h>
#include <iostream>
#include <vector>


bool isThereAWinner(int howManyDestroyedPlayer1 , int howManyDestroyedPlayer2);
void hit(int player , vector<vector<int>> &matrix, vector<vector<int>> &matrix2 ,  int &howManyDestroyedPlayer1 , int &howManyDestroyedPlayer2  , int & howManyHealedPlayer1, int & howManyHealedPlayer2);
