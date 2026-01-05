#include "graph.h"
#include <cstdlib>
#include <iostream>
#include <vector>
using namespace std;
vector<pair<int , int>> dots;
string player1;
string player2;
void startOfGame()
{
cin >> player1;
}
void utfChange()
{
    system("chcp 65001");
}
void clsDelete()
{
    std::system("cls");
}
//vector<pair<int, int>> dots
void tabledraw()
{
    cout << "┏";
    cout << "━━━━┳━━━━┳━━━━┳━━━━┳━━━━┳━━━━┳━━━━┳━━━━┳━━━━┳━━━━";
    cout << "┓\n";
    for (size_t u = 0; u < 9; u++)
    {

        /* code */
        cout << "┃    ┃    ┃    ┃    ┃    ┃    ┃    ┃    ┃    ┃    ┃   \n";
        cout << "┣━━━━╋━━━━╋━━━━╋━━━━╋━━━━╋━━━━╋━━━━╋━━━━╋━━━━╋━━━━┫\n";
    }
            cout << "┃    ┃    ┃    ┃    ┃    ┃    ┃    ┃    ┃    ┃    ┃   \n";

    cout << "┗━━━━┻━━━━┻━━━━┻━━━━┻━━━━┻━━━━┻━━━━┻━━━━┻━━━━┻━━━━┛\n";
    ;
}
