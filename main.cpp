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
    switch (swit)
    {
    case 1:
        startOfGame();
        randomShips();
        drawPlayerTable(1);
        break;

    case 2:
        help();
        break;

    case 3:
        exit(0);
        break;
    }
}
