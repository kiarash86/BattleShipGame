
#define WIN32_LEAN_AND_MEAN
#define _HAS_STD_BYTE 0
#include <windows.h>
#include "graph.h"
#include "menu.h"
#include "movement.h"
#include <cstdlib>
#include <iostream>
#include <vector>
#include <ctime>
#include <algorithm>
#include <cmath>
#include <random>
using namespace std;
vector<pair<int, int>> dots;
vector<vector<int>> matrix(11, vector<int>(11, -1));
vector<vector<int>> matrixMineA(11, vector<int>(11, 0));
vector<vector<int>> matrixMineB(11, vector<int>(11, 0));
vector<vector<int>> matrix2(11, vector<int>(11, -1));
string player1;
string player2;
int howManyDestroyedPlayer1 = 0;
int howManyDestroyedPlayer2 = 0;
int howManyHealedPlayer1 = 0;
int howManyHealedPlayer2 = 0;


void utfChange()
{
    system("chcp 65001");
}
void clsDelete()
{
    std::system("cls");
}
// vector<pair<int, int>> dots
void tabledraw()
{

    cout << "      1     2    3    4    5    6    7    8    9   10\n";

    cout << "    ┏━━━━┳━━━━┳━━━━┳━━━━┳━━━━┳━━━━┳━━━━┳━━━━┳━━━━┳━━━━┓\n";

    for (size_t u = 0; u < 9; u++)
    {

        /* code */
        cout << u + 1 << "   ┃    ┃    ┃    ┃    ┃    ┃    ┃    ┃    ┃    ┃    ┃   \n";
        cout << "    ┣━━━━╋━━━━╋━━━━╋━━━━╋━━━━╋━━━━╋━━━━╋━━━━╋━━━━╋━━━━┫\n";
    }
    cout << "10  ┃    ┃    ┃    ┃    ┃    ┃    ┃    ┃    ┃    ┃    ┃   \n";

    cout << "    ┗━━━━┻━━━━┻━━━━┻━━━━┻━━━━┻━━━━┻━━━━┻━━━━┻━━━━┻━━━━┛\n";
    ;
    // func();
}
// bool placeShips(int n, int player)
// {
//     bool created = false;
//     int y = rand() % 10 + 1;
//     int x = rand() % 10 + 1;
//     while (!created)
//     {
//         created = true;
//         y = rand() % 10 + 1;
//         x = rand() % 10 + 1;
//         while (y + n > 11)
//         {
//             y = rand() % 10 + 1;
//         }
//         for (size_t j = 0; j < n; j++)
//         {
//             if (matrix[x][y + j] != -1)
//             {
//                 created = false;
//                 break;
//             }
//         }
//     }

//     for (size_t j = 0; j < n; j++)
//     {
//         matrix[x][y + j] = player;
//     }

//     //   for (auto &&i : matrix)
//     // {
//     //     for (auto &&j : i)
//     //     {
//     //         cout << j << ' ';
//     //     }
//     //     cout << endl;
//     // }
//     return true;
// }

bool placeShips(int n, int player)
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

bool placeShips2(int n, int player)
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
            if (matrix2[x][y + j] != -1)
            {
                created = false;
                break;
            }
        }
    }

    for (size_t j = 0; j < n; j++)
    {
        matrix2[x][y + j] = player;
    }

    //   for (auto &&i : matrix)
    // {
    //     for (auto &&j : i)
    //     {
    //         cout << j << ' ';
    //     }
    //     cout << endl;
    // }
    return true;
}

void randomShips()
{
    placeShips(2, 11);
    placeShips(3, 12);
    placeShips(3, 13);
    placeShips(4, 14);
    placeShips(5, 15);
    placeShips2(2, 21);
    placeShips2(3, 22);
    placeShips2(3, 23);
    placeShips2(4, 24);
    placeShips2(5, 25);
    placeMine();
}
void placeMine()
{

    int y;
    int x;

    for (size_t i = 0; i < 3; i++)
    {
        /* code */

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
        /* code */

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
void func()
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

void drawPlayerTable(int name)
{

    clsDelete();

    if (name == 1)
    {
        cout << "                             " << player1 << endl;

        tabledraw();

        for (size_t i = 1; i < 11; i++)
        {
            for (size_t j = 1; j < 11; j++)
            {

                // if (matrix2[i][j] == 1 and (matrix[i][j] == 11 or matrix[i][j] == 12 or matrix[i][j] == 13 or matrix[i][j] == 14 or matrix[i][j] == 15))
                // {
                //     matrix2[i][j] = -1;
                //     matrix[i][j] = -matrix[i][j];
                // }
                // if (matrix[i][j] == 1 and (matrix2[i][j] == 21 or matrix2[i][j] == 22 or matrix2[i][j] == 23 or matrix2[i][j] == 24 or matrix2[i][j] == 25))
                // {
                //     matrix[i][j] = -1;
                //     matrix2[i][j] = -matrix2[i][j];
                // }

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
        cout << "                             " << player2 << endl;

        tabledraw();

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
                    cout << "☠☠";
                }
            }
        }
        cout << "\033[999;1H";
    }
    func();
}
