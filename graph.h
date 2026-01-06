
#define WIN32_LEAN_AND_MEAN
#define _HAS_STD_BYTE 0
#include <windows.h>



#include <cstdlib>
#include <iostream>

#include <cmath>
#include <random>
#include <algorithm>

#include <vector>
using namespace std;
void clsDelete();
void tabledraw();
void utfChange();
void startOfGame();
void func();
void randomShips();
bool placeShips(int n, int player);
void drawPlayerTable(int name);
void moveShips();
vector<int> randomNumber();
bool matrix11(int i, int j);
bool matrix12(int i, int j);
bool matrix13(int i, int j);
bool matrix14(int i, int j);
bool matrix15(int i, int j);
bool matrix211(int i, int j);
bool matrix212(int i, int j);
bool matrix213(int i, int j);
bool matrix214(int i, int j);
bool matrix215(int i, int j);
bool isThereAWinner();
void hit(int player);
