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


int switchToGo()
{
    int input ;
    cin >> input;
    if (input !=1 and input !=2 and input !=3)
    {
           cin >> input;

    }
    

    return input;




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