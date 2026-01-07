
#define WIN32_LEAN_AND_MEAN
#define _HAS_STD_BYTE 0
#include <windows.h>

#include "hit.h"

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

void randomShips();
bool placeShips(int n, int player);
void drawPlayerTable(int name);









void placeMine();
bool radar(int player);