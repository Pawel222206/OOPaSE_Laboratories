#include <iostream>  // input/output
#include <fstream>   // external files support
#include <string>    // string
#include <vector>    // vector
#include <map>       // map

using namespace std; // saves the "std::" clutter

enum TraffickLight
{
    Red,
    Yellow,
    Green
};

void getAction(int x)
{
    if (x == 0)
    {
        cout << "Stop" << endl;
    }
    else if (x == 1)
    {
        cout << "Wait" << endl;
    }
    else if (x == 2)
    {
        cout << "Go!!" << endl;
    }

}



int main()
{
    // ENUMERATION
    cout << "1. Enumeration" << endl;

    //TraffickLight currentLight = TraffickLight::Red; // No input

    cout << "Enter a positive integer: 0 for Red, 1 for Yellow, 2 for Green: ";
    string Input;
    cin >> Input;

    TraffickLight currentLight; // Needs declaration
    if ((Input == "0") || (Input == "Red"))
    {
        currentLight = TraffickLight::Red; // Changing the value of our variable
        getAction(currentLight);
    }
    else if (Input == "1" || (Input == "Yellow"))
    {
        currentLight = TraffickLight::Yellow;
        getAction(currentLight);
    }
    else if (Input == "2" || (Input == "Green"))
    {
        currentLight = TraffickLight::Green;
        getAction(currentLight);
    }
    else
    {
        cout << "Wrong, go away" << endl;
    }

    return 0;
}