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

    while (true)
    {
        int swit;
        int player = 1;
        vector<vector<int>> matrix(11, vector<int>(11, -1));
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
            randomShips(matrix, matrix2);
            placeMine(matrix, matrix2);

            while (!isThereAWinner(howManyDestroyedPlayer1, howManyDestroyedPlayer2, players))
            {
                // if (player==1)
                // {
                //     system("color 0F");
                // }
                // else 
                // system("color F0");
                
                clsDelete();
                cout << "                             " << players[player - 1] << "\n";

                tabledraw();

                //
                drawPlayerTable(player, matrix, matrix2, players);
                //

                func(matrix, matrix2);

                //
                hit(player, matrix, matrix2, howManyDestroyedPlayer1, howManyDestroyedPlayer2, howManyHealedPlayer1, howManyHealedPlayer2);
                //
                player = 3 - player;
                //
                moveShips(matrix, matrix2);
                //
            }

            break;

        case 2:
            help();
            
               // showMenu();
              //  swit = switchToGo();
            
            break;

        case 3:
            exit(0);
            break;
        }
    }
}