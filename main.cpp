#include <iostream>
#include "graph.h"
#include "hit.h"
#include "menu.h"
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
 showMenu();
                swit = switchToGo();
        switch (swit)
        {
        case 1:
            startOfGame();
            randomShips();
           // drawPlayerTable(player);
          //  hit(player);
          //  player = 3 - player;

            while (!isThereAWinner())
            {
                drawPlayerTable(player);
                hit(player , matrix , matrix2 ,howManyDestroyedPlayer1 , howManyDestroyedPlayer2 , howManyHealedPlayer1 , howManyHealedPlayer2);
                player = 3 - player;
                moveShips();
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