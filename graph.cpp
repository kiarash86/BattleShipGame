
#define WIN32_LEAN_AND_MEAN
#define _HAS_STD_BYTE 0
#include <windows.h>
#include "graph.h"
#include "menu.h"
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
bool isThereAWinner()
{
    if (howManyDestroyedPlayer1 == 17)
    {
        player1 += "is the winner";

        MessageBoxA(NULL, player1.c_str(), "finish", MB_OK);
        return true;
    }
    else if (howManyDestroyedPlayer2 == 17)
    {
        player2 += "is the winner";

        MessageBoxA(NULL, player2.c_str(), "finish", MB_OK);
        return true;
    }

    return false;
}

void startOfGame()
{
    cout << "ENTER PLAYER 1 NAME'S: ";
    cin >> player1;
    cout << "ENTER PLAYER 2 NAME'S: ";
    cin >> player2;
}
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

void moveShips()
{
    bool changeposition1 = false;
    bool changeposition2 = false;
    bool changeposition3 = false;
    bool changeposition4 = false;
    bool changeposition5 = false;
    bool changeposition21 = false;
    bool changeposition22 = false;
    bool changeposition23 = false;
    bool changeposition24 = false;
    bool changeposition25 = false;
    for (size_t i = 1; i < 11; i++)
    {
        for (size_t j = 1; j < 10; j++)
        {

            if (abs(matrix[i][j]) >= 11 and abs(matrix[i][j]) <= 15)
            {
                if (abs(matrix[i][j]) == 11 and abs(matrix[i][j + 1]) == 11)
                {
                    if (!changeposition1)
                    {

                        if ((matrix[i][j]) == -11 and (matrix[i][j + 1]) == -11)
                        {

                            changeposition1 = true;
                        }
                        else
                        {
                            changeposition1 = matrix11(i, j);
                        }
                    }
                }
                else if (j <= 8 and abs(matrix[i][j]) == 12 and abs(matrix[i][j + 1]) == 12 and abs(matrix[i][j + 2]) == 12)
                {
                    if (!changeposition2)
                    {

                        if ((matrix[i][j]) == -12 and (matrix[i][j + 1]) == -12 and (matrix[i][j + 2]) == -12)
                        {

                            changeposition2 = true;
                        }
                        else
                        {
                            changeposition2 = matrix12(i, j);
                        }
                    }
                }
                else if (j <= 8 and abs(matrix[i][j]) == 13 and abs(matrix[i][j + 1]) == 13 and abs(matrix[i][j + 2]) == 13)
                {

                    if (!changeposition3)
                    {

                        if ((matrix[i][j]) == -13 and (matrix[i][j + 1]) == -13 and (matrix[i][j + 2]) == -13)
                        {

                            changeposition3 = true;
                        }
                        else
                        {
                            changeposition3 = matrix13(i, j);
                        }
                    }
                }
                else if (j <= 7 and abs(matrix[i][j]) == 14 and abs(matrix[i][j + 1]) == 14 and abs(matrix[i][j + 2]) == 14 and abs(matrix[i][j + 3]) == 14)
                {

                    if (!changeposition4)
                    {

                        if ((matrix[i][j]) == -14 and (matrix[i][j + 1]) == -14 and (matrix[i][j + 2]) == -14 and (matrix[i][j + 3]) == -14)
                        {

                            changeposition4 = true;
                        }
                        else
                        {

                            changeposition4 = matrix14(i, j);
                        }
                    }
                }
                else if (j <= 6 and abs(matrix[i][j]) == 15 and abs(matrix[i][j + 1]) == 15 and abs(matrix[i][j + 2]) == 15 and abs(matrix[i][j + 3]) == 15 and abs(matrix[i][j + 4]) == 15)
                {

                    if (!changeposition5)
                    {

                        if ((matrix[i][j]) == -15 and (matrix[i][j + 1]) == -15 and (matrix[i][j + 2]) == -15 and (matrix[i][j + 3]) == -15 and (matrix[i][j + 4]) == -15)
                        {

                            changeposition5 = true;
                        }
                        else
                        {

                            changeposition5 = matrix15(i, j);
                        }
                    }

                    /* code */
                }
            }

            if (abs(matrix2[i][j]) >= 21 and abs(matrix2[i][j]) <= 25)
            {
                if (abs(matrix2[i][j]) == 21 and abs(matrix2[i][j + 1]) == 21)
                {
                    if (!changeposition21)
                    {

                        if ((matrix2[i][j]) == -21 and (matrix2[i][j + 1]) == -21)
                        {

                            changeposition21 = true;
                        }
                        else
                        {
                            changeposition21 = matrix211(i, j);
                        }
                    }
                }
                else if (j <= 8 and abs(matrix2[i][j]) == 22 and abs(matrix2[i][j + 1]) == 22 and abs(matrix2[i][j + 2]) == 22)
                {

                    if (!changeposition22)
                    {

                        if ((matrix2[i][j]) == -22 and (matrix2[i][j + 1]) == -22 and (matrix2[i][j + 2]) == -22)
                        {

                            changeposition22 = true;
                        }
                        else
                        {

                            changeposition22 = matrix212(i, j);
                        }
                    }
                }
                else if (j <= 8 and abs(matrix2[i][j]) == 23 and abs(matrix2[i][j + 1]) == 23 and abs(matrix2[i][j + 2]) == 23)
                {

                    if (!changeposition23)
                    {

                        if ((matrix2[i][j]) == -23 and (matrix2[i][j + 1]) == -23 and (matrix2[i][j + 2]) == -23)
                        {

                            changeposition23 = true;
                        }
                        else
                        {

                            changeposition23 = matrix213(i, j);
                        }
                    }
                }
                else if (j <= 7 and abs(matrix2[i][j]) == 24 and abs(matrix2[i][j + 1]) == 24 and abs(matrix2[i][j + 2]) == 24 and abs(matrix2[i][j + 3]) == 24)
                {

                    if (!changeposition24)
                    {

                        if ((matrix2[i][j]) == -24 and (matrix2[i][j + 1]) == -24 and (matrix2[i][j + 2]) == -24 and (matrix2[i][j + 3]) == -24)
                        {

                            changeposition24 = true;
                        }
                        else
                        {
                            changeposition24 = matrix214(i, j);
                        }
                    }
                }
                else if (j <= 6 and abs(matrix2[i][j]) == 25 and abs(matrix2[i][j + 1]) == 25 and abs(matrix2[i][j + 2]) == 25 and abs(matrix2[i][j + 3]) == 25 and abs(matrix2[i][j + 4]) == 25)
                {

                    if (!changeposition25)
                    {

                        if ((matrix2[i][j]) == -25 and (matrix2[i][j + 1]) == -25 and (matrix2[i][j + 2]) == -25 and (matrix2[i][j + 3]) == -25 and (matrix2[i][j + 4]) == -25)
                        {

                            changeposition25 = true;
                        }
                        else
                        {
                            changeposition25 = matrix215(i, j);
                        }
                    }
                }
            }
        }
    }
}

bool matrix11(int i, int j)
{

    vector<int> random = randomNumber();

    for (auto &&ww : random)
    {
        switch (ww)
        {
        case 1:
            if (i >= 2 and matrix[i - 1][j] == -1 and matrix[i - 1][j + 1] == -1)
            {
                matrix[i - 1][j] = matrix[i][j];
                matrix[i - 1][j + 1] = matrix[i][j + 1];
                matrix[i][j] = -1;
                matrix[i][j + 1] = -1;
                return true;
            }
            break;
        case 2:
            if (i <= 9 and matrix[i + 1][j] == -1 and matrix[i + 1][j + 1] == -1)
            {
                matrix[i + 1][j] = matrix[i][j];
                matrix[i + 1][j + 1] = matrix[i][j + 1];
                matrix[i][j] = -1;
                matrix[i][j + 1] = -1;
                return true;
            }
            break;
        case 3:
            if (j >= 2 and matrix[i][j - 1] == -1)
            {
                matrix[i][j - 1] = matrix[i][j];
                matrix[i][j] = matrix[i][j + 1];
                matrix[i][j + 1] = -1;
                return true;
            }
            break;
        case 4:
            if (j <= 8 and matrix[i][j + 2] == -1)
            {
                matrix[i][j + 2] = matrix[i][j + 1];
                matrix[i][j + 1] = matrix[i][j];
                matrix[i][j] = -1;
                return true;
            }
            break;
        }
    }
    return false;
}
bool matrix12(int i, int j)
{
    vector<int> random = randomNumber();

    for (auto &&ww : random)
    {

        switch (ww)
        {
        case 1:
            if (i >= 2 and matrix[i - 1][j] == -1 and matrix[i - 1][j + 1] == -1 and matrix[i - 1][j + 2] == -1)
            {
                matrix[i - 1][j] = matrix[i][j];
                matrix[i - 1][j + 1] = matrix[i][j + 1];
                matrix[i - 1][j + 2] = matrix[i][j + 2];
                matrix[i][j] = -1;
                matrix[i][j + 1] = -1;
                matrix[i][j + 2] = -1;
                return true;
            }
            break;
        case 2:
            if (i <= 9 and matrix[i + 1][j] == -1 and matrix[i + 1][j + 1] == -1 and matrix[i + 1][j + 2] == -1)
            {
                matrix[i + 1][j] = matrix[i][j];
                matrix[i + 1][j + 1] = matrix[i][j + 1];
                matrix[i + 1][j + 2] = matrix[i][j + 2];
                matrix[i][j] = -1;
                matrix[i][j + 1] = -1;
                matrix[i][j + 2] = -1;
                return true;
            }
            break;
        case 3:
            if (j >= 2 and matrix[i][j - 1] == -1)
            {
                matrix[i][j - 1] = matrix[i][j];
                matrix[i][j] = matrix[i][j + 1];
                matrix[i][j + 1] = matrix[i][j + 2];
                matrix[i][j + 2] = -1;
                return true;
            }
            break;
        case 4:
            if (j <= 7 and matrix[i][j + 3] == -1)
            {
                matrix[i][j + 3] = matrix[i][j + 2];
                matrix[i][j + 2] = matrix[i][j + 1];
                matrix[i][j + 1] = matrix[i][j];
                matrix[i][j] = -1;
                return true;
            }
            break;
        }
    }
    return false;
}
bool matrix13(int i, int j)
{

    vector<int> random = randomNumber();

    for (auto &&ww : random)
    {

        switch (ww)
        {
        case 1:
            if (i >= 2 and matrix[i - 1][j] == -1 and matrix[i - 1][j + 1] == -1 and matrix[i - 1][j + 2] == -1)
            {
                matrix[i - 1][j] = matrix[i][j];
                matrix[i - 1][j + 1] = matrix[i][j + 1];
                matrix[i - 1][j + 2] = matrix[i][j + 2];
                matrix[i][j] = -1;
                matrix[i][j + 1] = -1;
                matrix[i][j + 2] = -1;
                return true;
            }

            break;
        case 2:
            if (i <= 9 and matrix[i + 1][j] == -1 and matrix[i + 1][j + 1] == -1 and matrix[i + 1][j + 2] == -1)
            {
                matrix[i + 1][j] = matrix[i][j];
                matrix[i + 1][j + 1] = matrix[i][j + 1];
                matrix[i + 1][j + 2] = matrix[i][j + 2];
                matrix[i][j] = -1;
                matrix[i][j + 1] = -1;
                matrix[i][j + 2] = -1;
                return true;
            }
            break;
        case 3:
            if (j >= 2 and matrix[i][j - 1] == -1)
            {
                matrix[i][j - 1] = matrix[i][j];
                matrix[i][j] = matrix[i][j + 1];
                matrix[i][j + 1] = matrix[i][j + 2];
                matrix[i][j + 2] = -1;
                return true;
            }
            break;
        case 4:
            if (j <= 7 and matrix[i][j + 3] == -1)
            {
                matrix[i][j + 3] = matrix[i][j + 2];
                matrix[i][j + 2] = matrix[i][j + 1];
                matrix[i][j + 1] = matrix[i][j];
                matrix[i][j] = -1;
                return true;
            }
            break;
        }
    }

    return false;
}
bool matrix14(int i, int j)
{
    vector<int> random = randomNumber();

    for (auto &&ww : random)
    {

        switch (ww)
        {
        case 1:
            if (i >= 2 and matrix[i - 1][j] == -1 and matrix[i - 1][j + 1] == -1 and matrix[i - 1][j + 2] == -1 and matrix[i - 1][j + 3] == -1)
            {
                matrix[i - 1][j] = matrix[i][j];
                matrix[i - 1][j + 1] = matrix[i][j + 1];
                matrix[i - 1][j + 2] = matrix[i][j + 2];
                matrix[i - 1][j + 3] = matrix[i][j + 3];
                matrix[i][j] = -1;
                matrix[i][j + 1] = -1;
                matrix[i][j + 2] = -1;
                matrix[i][j + 3] = -1;
                return true;
            }

            break;
        case 2:
            if (i <= 9 and matrix[i + 1][j] == -1 and matrix[i + 1][j + 1] == -1 and matrix[i + 1][j + 2] == -1 and matrix[i + 1][j + 3] == -1)
            {
                matrix[i + 1][j] = matrix[i][j];
                matrix[i + 1][j + 1] = matrix[i][j + 1];
                matrix[i + 1][j + 2] = matrix[i][j + 2];
                matrix[i + 1][j + 3] = matrix[i][j + 3];
                matrix[i][j] = -1;
                matrix[i][j + 1] = -1;
                matrix[i][j + 2] = -1;
                matrix[i][j + 3] = -1;
                return true;
            }

            break;
        case 3:
            if (j >= 2 and matrix[i][j - 1] == -1)
            {
                matrix[i][j - 1] = matrix[i][j];
                matrix[i][j] = matrix[i][j + 1];
                matrix[i][j + 1] = matrix[i][j + 2];
                matrix[i][j + 2] = matrix[i][j + 3];
                matrix[i][j + 3] = -1;
                return true;
            }

            break;
        case 4:
            if (j <= 6 and matrix[i][j + 4] == -1)
            {
                matrix[i][j + 4] = matrix[i][j + 3];
                matrix[i][j + 3] = matrix[i][j + 2];
                matrix[i][j + 2] = matrix[i][j + 1];
                matrix[i][j + 1] = matrix[i][j];
                matrix[i][j] = -1;
                return true;
            }

            break;
        }
    }
    return false;
}
bool matrix15(int i, int j)
{
    vector<int> random = randomNumber();

    for (auto &&ww : random)
    {

        switch (ww)
        {
        case 1:
            if (i >= 2 and matrix[i - 1][j] == -1 and matrix[i - 1][j + 1] == -1 and matrix[i - 1][j + 2] == -1 and matrix[i - 1][j + 3] == -1 and matrix[i - 1][j + 4] == -1)
            {
                matrix[i - 1][j] = matrix[i][j];
                matrix[i - 1][j + 1] = matrix[i][j + 1];
                matrix[i - 1][j + 2] = matrix[i][j + 2];
                matrix[i - 1][j + 3] = matrix[i][j + 3];
                matrix[i - 1][j + 4] = matrix[i][j + 4];
                matrix[i][j] = -1;
                matrix[i][j + 1] = -1;
                matrix[i][j + 2] = -1;
                matrix[i][j + 3] = -1;
                matrix[i][j + 4] = -1;
                return true;
            }

            break;
        case 2:
            if (i <= 9 and matrix[i + 1][j] == -1 and matrix[i + 1][j + 1] == -1 and matrix[i + 1][j + 2] == -1 and matrix[i + 1][j + 3] == -1 and matrix[i + 1][j + 4] == -1)
            {
                matrix[i + 1][j] = matrix[i][j];
                matrix[i + 1][j + 1] = matrix[i][j + 1];
                matrix[i + 1][j + 2] = matrix[i][j + 2];
                matrix[i + 1][j + 3] = matrix[i][j + 3];
                matrix[i + 1][j + 4] = matrix[i][j + 4];
                matrix[i][j] = -1;
                matrix[i][j + 1] = -1;
                matrix[i][j + 2] = -1;
                matrix[i][j + 3] = -1;
                matrix[i][j + 4] = -1;
                return true;
            }

            break;
        case 3:
            if (j >= 2 and matrix[i][j - 1] == -1)
            {
                matrix[i][j - 1] = matrix[i][j];
                matrix[i][j] = matrix[i][j + 1];
                matrix[i][j + 1] = matrix[i][j + 2];
                matrix[i][j + 2] = matrix[i][j + 3];
                matrix[i][j + 3] = matrix[i][j + 4];
                matrix[i][j + 4] = -1;
                return true;
            }

            break;
        case 4:
            if (j <= 5 and matrix[i][j + 5] == -1)
            {
                matrix[i][j + 5] = matrix[i][j + 4];
                matrix[i][j + 4] = matrix[i][j + 3];
                matrix[i][j + 3] = matrix[i][j + 2];
                matrix[i][j + 2] = matrix[i][j + 1];
                matrix[i][j + 1] = matrix[i][j];
                matrix[i][j] = -1;
                return true;
            }

            break;
        }
    }
    return false;
}

bool matrix211(int i, int j)
{
    vector<int> random = randomNumber();

    for (auto &&ww : random)
    {

        switch (ww)
        {
        case 1:
            if (i >= 2 and matrix2[i - 1][j] == -1 and matrix2[i - 1][j + 1] == -1)
            {
                matrix2[i - 1][j] = matrix2[i][j];
                matrix2[i - 1][j + 1] = matrix2[i][j + 1];
                matrix2[i][j] = -1;
                matrix2[i][j + 1] = -1;
                return true;
            }

            break;
        case 2:
            if (i <= 9 and matrix2[i + 1][j] == -1 and matrix2[i + 1][j + 1] == -1)
            {
                matrix2[i + 1][j] = matrix2[i][j];
                matrix2[i + 1][j + 1] = matrix2[i][j + 1];
                matrix2[i][j] = -1;
                matrix2[i][j + 1] = -1;
                return true;
            }

            break;
        case 3:
            if (j >= 2 and matrix2[i][j - 1] == -1)
            {
                matrix2[i][j - 1] = matrix2[i][j];
                matrix2[i][j] = matrix2[i][j + 1];
                matrix2[i][j + 1] = -1;
                return true;
            }

            break;
        case 4:
            if (j <= 8 and matrix2[i][j + 2] == -1)
            {
                matrix2[i][j + 2] = matrix2[i][j + 1];
                matrix2[i][j + 1] = matrix2[i][j];
                matrix2[i][j] = -1;
                return true;
            }

            break;
        }
    }
    return false;
}
bool matrix212(int i, int j)
{
    vector<int> random = randomNumber();

    for (auto &&ww : random)
    {

        switch (ww)
        {
        case 1:
            if (i >= 2 and matrix2[i - 1][j] == -1 and matrix2[i - 1][j + 1] == -1 and matrix2[i - 1][j + 2] == -1)
            {
                matrix2[i - 1][j] = matrix2[i][j];
                matrix2[i - 1][j + 1] = matrix2[i][j + 1];
                matrix2[i - 1][j + 2] = matrix2[i][j + 2];
                matrix2[i][j] = -1;
                matrix2[i][j + 1] = -1;
                matrix2[i][j + 2] = -1;
                return true;
            }

            break;
        case 2:
            if (i <= 9 and matrix2[i + 1][j] == -1 and matrix2[i + 1][j + 1] == -1 and matrix2[i + 1][j + 2] == -1)
            {
                matrix2[i + 1][j] = matrix2[i][j];
                matrix2[i + 1][j + 1] = matrix2[i][j + 1];
                matrix2[i + 1][j + 2] = matrix2[i][j + 2];
                matrix2[i][j] = -1;
                matrix2[i][j + 1] = -1;
                matrix2[i][j + 2] = -1;
                return true;
            }

            break;
        case 3:
            if (j >= 2 and matrix2[i][j - 1] == -1)
            {
                matrix2[i][j - 1] = matrix2[i][j];
                matrix2[i][j] = matrix2[i][j + 1];
                matrix2[i][j + 1] = matrix2[i][j + 2];
                matrix2[i][j + 2] = -1;
                return true;
            }

            break;
        case 4:
            if (j <= 7 and matrix2[i][j + 3] == -1)
            {
                matrix2[i][j + 3] = matrix2[i][j + 2];
                matrix2[i][j + 2] = matrix2[i][j + 1];
                matrix2[i][j + 1] = matrix2[i][j];
                matrix2[i][j] = -1;
                return true;
            }

            break;
        }
    }
    return false;
}
bool matrix213(int i, int j)
{
    vector<int> random = randomNumber();

    for (auto &&ww : random)
    {

        switch (ww)
        {
        case 1:
            if (i >= 2 and matrix2[i - 1][j] == -1 and matrix2[i - 1][j + 1] == -1 and matrix2[i - 1][j + 2] == -1)
            {
                matrix2[i - 1][j] = matrix2[i][j];
                matrix2[i - 1][j + 1] = matrix2[i][j + 1];
                matrix2[i - 1][j + 2] = matrix2[i][j + 2];
                matrix2[i][j] = -1;
                matrix2[i][j + 1] = -1;
                matrix2[i][j + 2] = -1;
                return true;
            }

            break;
        case 2:
            if (i <= 9 and matrix2[i + 1][j] == -1 and matrix2[i + 1][j + 1] == -1 and matrix2[i + 1][j + 2] == -1)
            {
                matrix2[i + 1][j] = matrix2[i][j];
                matrix2[i + 1][j + 1] = matrix2[i][j + 1];
                matrix2[i + 1][j + 2] = matrix2[i][j + 2];
                matrix2[i][j] = -1;
                matrix2[i][j + 1] = -1;
                matrix2[i][j + 2] = -1;
                return true;
            }

            break;
        case 3:
            if (j >= 2 and matrix2[i][j - 1] == -1)
            {
                matrix2[i][j - 1] = matrix2[i][j];
                matrix2[i][j] = matrix2[i][j + 1];
                matrix2[i][j + 1] = matrix2[i][j + 2];
                matrix2[i][j + 2] = -1;
                return true;
            }

            break;
        case 4:
            if (j <= 7 and matrix2[i][j + 3] == -1)
            {
                matrix2[i][j + 3] = matrix2[i][j + 2];
                matrix2[i][j + 2] = matrix2[i][j + 1];
                matrix2[i][j + 1] = matrix2[i][j];
                matrix2[i][j] = -1;
                return true;
            }

            break;
        }
    }
    return false;
}
bool matrix214(int i, int j)
{
    vector<int> random = randomNumber();

    for (auto &&ww : random)
    {

        switch (ww)
        {
        case 1:
            if (i >= 2 and matrix2[i - 1][j] == -1 and matrix2[i - 1][j + 1] == -1 and matrix2[i - 1][j + 2] == -1 and matrix2[i - 1][j + 3] == -1)
            {
                matrix2[i - 1][j] = matrix2[i][j];
                matrix2[i - 1][j + 1] = matrix2[i][j + 1];
                matrix2[i - 1][j + 2] = matrix2[i][j + 2];
                matrix2[i - 1][j + 3] = matrix2[i][j + 3];
                matrix2[i][j] = -1;
                matrix2[i][j + 1] = -1;
                matrix2[i][j + 2] = -1;
                matrix2[i][j + 3] = -1;
                return true;
            }

            break;
        case 2:
            if (i <= 9 and matrix2[i + 1][j] == -1 and matrix2[i + 1][j + 1] == -1 and matrix2[i + 1][j + 2] == -1 and matrix2[i + 1][j + 3] == -1)
            {
                matrix2[i + 1][j] = matrix2[i][j];
                matrix2[i + 1][j + 1] = matrix2[i][j + 1];
                matrix2[i + 1][j + 2] = matrix2[i][j + 2];
                matrix2[i + 1][j + 3] = matrix2[i][j + 3];
                matrix2[i][j] = -1;
                matrix2[i][j + 1] = -1;
                matrix2[i][j + 2] = -1;
                matrix2[i][j + 3] = -1;
                return true;
            }

            break;
        case 3:
            if (j >= 2 and matrix2[i][j - 1] == -1)
            {
                matrix2[i][j - 1] = matrix2[i][j];
                matrix2[i][j] = matrix2[i][j + 1];
                matrix2[i][j + 1] = matrix2[i][j + 2];
                matrix2[i][j + 2] = matrix2[i][j + 3];
                matrix2[i][j + 3] = -1;
                return true;
            }

            break;
        case 4:
            if (j <= 6 and matrix2[i][j + 4] == -1)
            {
                matrix2[i][j + 4] = matrix2[i][j + 3];
                matrix2[i][j + 3] = matrix2[i][j + 2];
                matrix2[i][j + 2] = matrix2[i][j + 1];
                matrix2[i][j + 1] = matrix2[i][j];
                matrix2[i][j] = -1;
                return true;
            }

            break;
        }
    }

    return false;
}
bool matrix215(int i, int j)
{
    vector<int> random = randomNumber();

    for (auto &&ww : random)
    {

        switch (ww)
        {
        case 1:
            if (i >= 2 and matrix2[i - 1][j] == -1 and matrix2[i - 1][j + 1] == -1 and matrix2[i - 1][j + 2] == -1 and matrix2[i - 1][j + 3] == -1 and matrix2[i - 1][j + 4] == -1)
            {
                matrix2[i - 1][j] = matrix2[i][j];
                matrix2[i - 1][j + 1] = matrix2[i][j + 1];
                matrix2[i - 1][j + 2] = matrix2[i][j + 2];
                matrix2[i - 1][j + 3] = matrix2[i][j + 3];
                matrix2[i - 1][j + 4] = matrix2[i][j + 4];
                matrix2[i][j] = -1;
                matrix2[i][j + 1] = -1;
                matrix2[i][j + 2] = -1;
                matrix2[i][j + 3] = -1;
                matrix2[i][j + 4] = -1;
                return true;
            }

            break;
        case 2:
            if (i <= 9 and matrix2[i + 1][j] == -1 and matrix2[i + 1][j + 1] == -1 and matrix2[i + 1][j + 2] == -1 and matrix2[i + 1][j + 3] == -1 and matrix2[i + 1][j + 4] == -1)
            {
                matrix2[i + 1][j] = matrix2[i][j];
                matrix2[i + 1][j + 1] = matrix2[i][j + 1];
                matrix2[i + 1][j + 2] = matrix2[i][j + 2];
                matrix2[i + 1][j + 3] = matrix2[i][j + 3];
                matrix2[i + 1][j + 4] = matrix2[i][j + 4];
                matrix2[i][j] = -1;
                matrix2[i][j + 1] = -1;
                matrix2[i][j + 2] = -1;
                matrix2[i][j + 3] = -1;
                matrix2[i][j + 4] = -1;
                return true;
            }

            break;
        case 3:
            if (j >= 2 and matrix2[i][j - 1] == -1)
            {
                matrix2[i][j - 1] = matrix2[i][j];
                matrix2[i][j] = matrix2[i][j + 1];
                matrix2[i][j + 1] = matrix2[i][j + 2];
                matrix2[i][j + 2] = matrix2[i][j + 3];
                matrix2[i][j + 3] = matrix2[i][j + 4];
                matrix2[i][j + 4] = -1;
                return true;
            }

            break;
        case 4:
            if (j <= 5 and matrix2[i][j + 5] == -1)
            {
                matrix2[i][j + 5] = matrix2[i][j + 4];
                matrix2[i][j + 4] = matrix2[i][j + 3];
                matrix2[i][j + 3] = matrix2[i][j + 2];
                matrix2[i][j + 2] = matrix2[i][j + 1];
                matrix2[i][j + 1] = matrix2[i][j];
                matrix2[i][j] = -1;
                return true;
            }

            break;
        }
    }

    return false;
}

vector<int> randomNumber()
{
    vector<int> v = {1, 2, 3, 4};

    static mt19937 rng(std::random_device{}());
    shuffle(v.begin(), v.end(), rng);

    return v;
}
