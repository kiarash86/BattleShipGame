#define WIN32_LEAN_AND_MEAN
#define _HAS_STD_BYTE 0
#include <windows.h>
#include <iostream>
#include <vector>
using namespace std;



bool radar(int player , vector<vector<int>> &matrix, vector<vector<int>> &matrix2)
{
    int x, y;
    cin >> x >> y;

    while (x > 10 or x < 1 or y > 10 or y < 1)
    {
        cin >> x >> y;
    }
    if (player == 1)
    {

        for (size_t i = x; i < x + 4; i++)
        {
            for (size_t j = y; j < y + 4; j++)
            {
                if (i <= 10 and j <= 10)
                {
                    /* code */

                    if (matrix2[i][j] >= 21 and matrix2[i][j] <= 25)
                    {
                                    MessageBoxA(NULL, "maybe there is something!!! who knows", "radar", MB_OK);

                        return true;
                    }
                }
            }
        }
                    MessageBoxA(NULL, "there is nothing!!", "radar", MB_OK);

        return false;
    }
    else
    {

        for (size_t i = x; i < x + 4; i++)
        {
            for (size_t j = y; j < y + 4; j++)
            {
                if (i <= 10 and j <= 10)
                {
                    /* code */

                    if (matrix[i][j] >= 21 and matrix[i][j] <= 25)
                    {
                                    MessageBoxA(NULL, "maybe there is something!!! who knows", "radar", MB_OK);

                        return true;
                    }
                }
            }
        }
                    MessageBoxA(NULL, "there is nothing!!", "radar", MB_OK);

        return false;
    }
}
void heal(int player , vector<vector<int>> &matrix, vector<vector<int>> &matrix2 , int &howManyDestroyedPlayer1 , int &howManyDestroyedPlayer2)
{
    int x, y;
    cin >> x >> y;
    if (player == 1)
    {

        while (matrix[x][y] != -11 and matrix[x][y] != -12 and matrix[x][y] != -13 and matrix[x][y] != -14 and matrix[x][y] != -15)
        {
            cin >> x >> y;
        }
        matrix[x][y] = -matrix[x][y];
        MessageBoxA(NULL, "heal succesfully", "heal", MB_OK);
        howManyDestroyedPlayer2--;
    }

    else
    {
        while (matrix2[x][y] != -21 and matrix2[x][y] != -22 and matrix2[x][y] != -23 and matrix2[x][y] != -24 and matrix2[x][y] != -25)
        {
            cin >> x >> y;
        }
        matrix2[x][y] = -matrix2[x][y];

        MessageBoxA(NULL, "heal succesfully", "heal", MB_OK);
        howManyDestroyedPlayer1--;
    }
}
void hit(int player , vector<vector<int>> &matrix, vector<vector<int>> &matrix2 ,  int &howManyDestroyedPlayer1 , int &howManyDestroyedPlayer2  , int & howManyHealedPlayer1, int & howManyHealedPlayer2)
{
    int x, y;
    cin >> x >> y;

    if (x == 11 and y == 11)
    {
        if (radar(player,matrix , matrix2))
        {

            return;
        }
        else
        {
            return;
        }
    }

    if (x == 0 and y == 0)
    {
        if (player == 1 and howManyDestroyedPlayer2 != 0)
        {
            if (howManyHealedPlayer1 < 3)
            {
                heal(player , matrix , matrix2 ,howManyDestroyedPlayer1 , howManyDestroyedPlayer2);
                return;
            }

            /* code */
        }
        else if (player == 2 and howManyDestroyedPlayer1 != 0)
        {
            if (howManyHealedPlayer2 < 3)
            {

                heal(player , matrix , matrix2 ,howManyDestroyedPlayer1 , howManyDestroyedPlayer2);
                return;
            }
        }
    }

    if (player == 1)
    {

        while (x > 10 or x < 1 or y > 10 or y < 1)
        {
            cin >> x >> y;
        }

        if (matrix2[x][y] <= 25 and matrix2[x][y] >= 21)
        {
            matrix2[x][y] = -matrix2[x][y];
            MessageBoxA(NULL, "hit succesfully", "hit", MB_OK);
            howManyDestroyedPlayer1++;
        }
        else if (matrix2[x][y] == 1)
        {
            matrix2[x][y] = -1;
            if (matrix[x][y] >= 11 and matrix[x][y] <= 15)
            {
                matrix[x][y] = -matrix[x][y];
                howManyDestroyedPlayer2++;
            }
        }
    }
    else
    {
        while (x > 10 or x < 1 or y > 10 or y < 1)
        {
            cin >> x >> y;
        }

        if (matrix[x][y] <= 15 and matrix[x][y] >= 11)
        {
            matrix[x][y] = -matrix[x][y];
            MessageBoxA(NULL, "hit succesfully", "hit", MB_OK);

            howManyDestroyedPlayer2++;
        }
        else if (matrix[x][y] == 1)
        {
            matrix[x][y] = -1;
            if (matrix2[x][y] >= 21 and matrix2[x][y] <= 25)
            {
                matrix2[x][y] = -matrix2[x][y];
                howManyDestroyedPlayer1++;
            }
        }
    }
}
bool isThereAWinner(int howManyDestroyedPlayer1 , int howManyDestroyedPlayer2 , vector<string> players)
{
    if (howManyDestroyedPlayer1 == 17)
    {
        players[0] += "is the winner";

        MessageBoxA(NULL, players[0] .c_str(), "finish", MB_OK);
        return true;
    }
    else if (howManyDestroyedPlayer2 == 17)
    {
        players[1]  += "is the winner";

        MessageBoxA(NULL, players[1].c_str(), "finish", MB_OK);
        return true;
    }

    return false;
}
