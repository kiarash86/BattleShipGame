#include "graph.h"
#include <cstdlib>
#include <iostream>
#include <vector>
using namespace std;
void utfChange()
{
    system("chcp 65001");
}
void clsDelete()
{
    std::system("cls");
}

void tabledraw(vector<pair<int, int>> dots)
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
