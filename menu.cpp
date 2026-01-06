#include "menu.h"
#include "graph.h"
#include <iostream>
#include <vector>
#include<cctype>
using namespace std;
bool exit(string input)
{
    for (auto &&i : input)
    {
        i = tolower(i);
    }
    
    if (input == "exit")
    {

    return true;

    }
    return false;
}


void showMenu()
{
clsDelete();
    cout << "1) START GAME!!!\n";
    cout << "2) HELP?\n";
    cout << "3) CLOSE GAME(| |)\n";

}


void switchToGo()
{
    int input ;
    cin >> input;
    switch (input)
    {
    case 1:
        startOfGame();
    break;
    
    
    case 2:
        help();
        break;
    
    
    case 3:
       exit(0);
        break;
    
    
    default:
    showMenu();
        break;
    }


}


void help()
{
    cout << "this is battleship game\n";
    string str;
    cin >> str;
    if(!exit(str))
    {
        cin >> str;
    }
    else
    {
        showMenu();
    }
}