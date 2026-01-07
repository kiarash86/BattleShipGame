#define WIN32_LEAN_AND_MEAN
#define _HAS_STD_BYTE 0
#include <windows.h>
#include "graph.h"
#include <cstdlib>
#include <iostream>
#include <vector>
#include <ctime>
#include <algorithm>
#include <random>
using namespace std;


bool placeShips(int n, int player , vector<vector<int>> &matrix)
{
    bool created = false;
    int y = rand() % 10 + 1;
    int x = rand() % 10 + 1;
    while (!created)
    {
        created = true;
        y = rand() % 10 + 1;
        x = rand() % 10 + 1;
        while (y + n > 11)
        {
            y = rand() % 10 + 1;
        }
        for (size_t j = 0; j < n; j++)
        {
            if (matrix[x][y + j] != -1)
            {
                created = false;
                break;
            }
        }
    }

    for (size_t j = 0; j < n; j++)
    {
        matrix[x][y + j] = player;
    }
    return true;
}

void randomShips(vector<vector<int>> &matrix, vector<vector<int>> &matrix2)
{

    placeShips(2, 11 ,matrix);
    placeShips(3, 12,matrix);
    placeShips(3, 13,matrix);
    placeShips(4, 14,matrix);
    placeShips(5, 15,matrix);
    placeShips(2, 21,matrix2);
    placeShips(3, 22,matrix2);
    placeShips(3, 23,matrix2);
    placeShips(4, 24,matrix2);
    placeShips(5, 25,matrix2);
}

 


void drawPlayerTable(int name , vector<vector<int>> &matrix , vector<vector<int>> &matrix2 , vector<string> players)
{


    if (name == 1)
    {


        for (size_t i = 1; i < 11; i++)
        {
            for (size_t j = 1; j < 11; j++)
            {

                if (matrix[i][j] == 11 or matrix[i][j] == 12 or matrix[i][j] == 13 or matrix[i][j] == 14 or matrix[i][j] == 15)
                {

                    int row = 4 + (i - 1) * 2;
                    int col = 6 + ((j - 1) * 5);

                    cout << "\033[" << row << ";" << col << "H";
                    cout << "████";
                }
                else if (matrix[i][j] == -11 or matrix[i][j] == -12 or matrix[i][j] == -13 or matrix[i][j] == -14 or matrix[i][j] == -15)
                {
                    int row = 4 + (i - 1) * 2;
                    int col = 6 + ((j - 1) * 5);

                    cout << "\033[" << row << ";" << col << "H";
                    cout << "🔥🔥";
                }
                else if (matrix[i][j] == 1)
                {

                    int row = 4 + (i - 1) * 2;
                    int col = 6 + ((j - 1) * 5);

                    cout << "\033[" << row << ";" << col << "H";
                    cout << "☠ ☠";
                }
            }
        }
        cout << "\033[999;1H";
    }
    else
    {
        for (size_t i = 1; i < 11; i++)
        {
            for (size_t j = 1; j < 11; j++)
            {
                if (matrix2[i][j] == 21 or matrix2[i][j] == 22 or matrix2[i][j] == 23 or matrix2[i][j] == 24 or matrix2[i][j] == 25)
                {
                    int row = 4 + (i - 1) * 2;
                    int col = 6 + ((j - 1) * 5);

                    cout << "\033[" << row << ";" << col << "H";
                    cout << "████";
                }
                else if (matrix2[i][j] == -21 or matrix2[i][j] == -22 or matrix2[i][j] == -23 or matrix2[i][j] == -24 or matrix2[i][j] == -25)
                {
                    int row = 4 + (i - 1) * 2;
                    int col = 6 + ((j - 1) * 5);

                    cout << "\033[" << row << ";" << col << "H";
                    cout << "🔥🔥";
                }
                else if (matrix2[i][j] == 1)
                {
                    int row = 4 + (i - 1) * 2;
                    int col = 6 + ((j - 1) * 5);

                    cout << "\033[" << row << ";" << col << "H";
                    cout << "☠ ☠";
                }
            }
        }
        cout << "\033[999;1H";
    }
}



void func(vector<vector<int>> &matrix , vector<vector<int>> &matrix2)
{
    bool firstl = true;
    for (auto &&i : matrix)
    {
        bool firstcol = true;

        if (firstl)
        {
            firstl = false;
            continue;
            /* code */
        }

        for (auto &&j : i)
        {
            if (firstcol)
            {
                firstcol = false;
                continue;
                /* code */
            }
            cout << j << ' ';
        }
        cout << endl;
    }
    cout << endl;
    firstl = true;
    for (auto &&i : matrix2)
    {
        bool firstcol = true;

        if (firstl)
        {
            firstl = false;
            continue;
            /* code */
        }

        for (auto &&j : i)
        {
            if (firstcol)
            {
                firstcol = false;
                continue;
                /* code */
            }
            cout << j << ' ';
        }
        cout << endl;
    }
    cout << endl;
}



void utfChange()
{
    system("chcp 65001");
}



void clsDelete()
{
    std::system("cls");
}




void tabledraw()
{

    cout << "      1     2    3    4    5    6    7    8    9   10\n";

    cout << "    ┏━━━━┳━━━━┳━━━━┳━━━━┳━━━━┳━━━━┳━━━━┳━━━━┳━━━━┳━━━━┓\n";

    for (size_t u = 0; u < 9; u++)
    {
        cout << u + 1 << "   ┃    ┃    ┃    ┃    ┃    ┃    ┃    ┃    ┃    ┃    ┃   \n";
        cout << "    ┣━━━━╋━━━━╋━━━━╋━━━━╋━━━━╋━━━━╋━━━━╋━━━━╋━━━━╋━━━━┫\n";
    }
    cout << "10  ┃    ┃    ┃    ┃    ┃    ┃    ┃    ┃    ┃    ┃    ┃   \n";

    cout << "    ┗━━━━┻━━━━┻━━━━┻━━━━┻━━━━┻━━━━┻━━━━┻━━━━┻━━━━┻━━━━┛\n";
}




void placeMine(vector<vector<int>> &matrix , vector<vector<int>> &matrix2)
{

    int y;
    int x;

    for (size_t i = 0; i < 3; i++)
    {

        y = rand() % 10 + 1;
        x = rand() % 10 + 1;
        while (matrix2[x][y] != -1)
        {
            y = rand() % 10 + 1;
            x = rand() % 10 + 1;
        }
        matrix2[x][y] = 1;
    }

    for (size_t i = 0; i < 3; i++)
    {

        y = rand() % 10 + 1;
        x = rand() % 10 + 1;
        while (matrix[x][y] != -1)
        {
            y = rand() % 10 + 1;
            x = rand() % 10 + 1;
        }
        matrix[x][y] = 1;
    }
}



