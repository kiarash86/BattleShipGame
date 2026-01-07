#pragma once
#define WIN32_LEAN_AND_MEAN
#define _HAS_STD_BYTE 0
#include <windows.h>
#include <cstdlib>
#include <iostream>
#include <vector>
#include <ctime>
#include <algorithm>
#include <random>
using namespace std;
void clsDelete();
void tabledraw();
void utfChange();
void func(vector<vector<int>> &matrix , vector<vector<int>> &matrix2);
void randomShips(vector<vector<int>> &matrix, vector<vector<int>> &matrix2);
void drawPlayerTable(int name , vector<vector<int>> &matrix , vector<vector<int>> &matrix2 , vector<string> players);
void placeMine(vector<vector<int>> &matrix , vector<vector<int>> &matrix2);
