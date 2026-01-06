#include <iostream>
#include "graph.h"
#include "menu.h"
#include <vector>

using namespace std;
int main()
{
    srand(time(0));

    utfChange();
    showMenu();
    int swit = switchToGo();
    int player = 1;

    while (true)
    {

        switch (swit)
        {
        case 1:
            startOfGame();
            randomShips();
            drawPlayerTable(player);
            hit(player);
            player = 3 - player;

            while (!isThereAWinner())
            {
                hit(player);
                drawPlayerTable(player);
                player = 3 - player;
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