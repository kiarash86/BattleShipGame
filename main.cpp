#include <iostream>
#include "graph.h"
#include "hit.h"
#include "menu.h"
#include "movement.h"
#include <vector>

using namespace std;
int main()
{
    srand(time(0));

    utfChange();
    int swit;
    int player = 1;

    while (true)
    {
        vector<vector<int>> matrix(11, vector<int>(11, -1));
        vector<vector<int>> matrixMineA(11, vector<int>(11, 0));
        vector<vector<int>> matrixMineB(11, vector<int>(11, 0));
        vector<vector<int>> matrix2(11, vector<int>(11, -1));
        vector<string> players(2);
        int howManyDestroyedPlayer1 = 0;
        int howManyDestroyedPlayer2 = 0;
        int howManyHealedPlayer1 = 0;
        int howManyHealedPlayer2 = 0;
        showMenu();
        swit = switchToGo();
        switch (swit)
        {
        case 1:
            players = startOfGame();
            randomShips();
            // drawPlayerTable(player);
            //  hit(player);
            //  player = 3 - player;

            while (!isThereAWinner(howManyDestroyedPlayer1 , howManyDestroyedPlayer2))
            {
                drawPlayerTable(player);
                hit(player, matrix, matrix2, howManyDestroyedPlayer1, howManyDestroyedPlayer2, howManyHealedPlayer1, howManyHealedPlayer2);
                player = 3 - player;
                moveShips(matrix, matrix2);
            }

            break;

        case 2:
            if (help())
            {
                showMenu();
                swit = switchToGo();
            }
            break;

        case 3:
            exit(0);
            break;
        }
    }
}