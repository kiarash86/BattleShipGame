#include "graph.h"
#include <cstdlib>
#include <iostream>
#include <vector>
#include <ctime>
using namespace std;
vector<pair<int, int>> dots;
vector<vector<int>> matrix(11, vector<int>(11, -1));
string player1;
string player2;



void startOfGame()
{
    cout << "ENTER PLAYER 1 NAME'S: ";
    cin >> player1;
    cout << "ENTER PLAYER 2 NAME'S: ";
    cin >> player2;
    randomShips();
    clsDelete();
    drawPlayerTable(2);
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
    placeShips(2, 21);
    placeShips(3, 22);
    placeShips(3, 23);
    placeShips(4, 24);
    placeShips(5, 25);
}
void func()
{
    for (auto &&i : matrix)
    {
        for (auto &&j : i)
        {
            cout << j << ' ';
        }
        cout << endl;
    }
}

void drawPlayerTable(int name)
{
    clsDelete();
    if (name == 1)
    {

        /* code */
    }

    if (name == 1)
    {
        cout << "                             " << player1 << endl;

        tabledraw();

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
                if (matrix[i][j] == 21 or matrix[i][j] == 22 or matrix[i][j] == 23 or matrix[i][j] == 24 or matrix[i][j] == 25)
                {
                    int row = 4 + (i - 1) * 2;
                    int col = 6 + ((j - 1) * 5);

                    cout << "\033[" << row << ";" << col << "H";
                    cout << "████";
                }
                else if (matrix[i][j] == -21 or matrix[i][j] == -22 or matrix[i][j] == -23 or matrix[i][j] == -24 or matrix[i][j] == -25)
                {
                    int row = 4 + (i - 1) * 2;
                    int col = 6 + ((j - 1) * 5);

                    cout << "\033[" << row << ";" << col << "H";
                    cout << "🔥🔥";
                }
            }
        }
        cout << "\033[999;1H";
    }
    cin >> player1;
}

void moveShips()
{
}