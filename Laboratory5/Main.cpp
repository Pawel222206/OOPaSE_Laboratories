#include <iostream>  // input/output
#include <fstream>   // external files support
#include <string>    // string
#include <vector>    // vector
#include <map>       // map

using namespace std; // saves the "std::" clutter

////////////////////////////////////////////////////////////////////////////////

class Thing
{
private:
    string nameT; // data
    int amount_available;

public:
    void setname_T(string n); // method
    void setamount_available(int a);
    void printall();
};

void Thing::setname_T(string n) // method definision
{
    nameT = n;
    //cout << "Name set to: " << nameT; // *check
}

void Thing::setamount_available(int a)
{
    amount_available = a;
    //cout << "Amount set to: " << amount_available; // *check
}

void Thing::printall()
{
    cout << nameT << amount_available << endl;
}
////////////////////////////////////////////////////////////////////////////////

class Request
{
private:
    string nameR; // data
    int amount_wanted;

public:
    void setname_R(); // method
    void setamount_wanted();
};

void Request::setname_R() // method definision
{
    cout << "What do you want?" << endl;
    string nn; cin >> nn;
    nameR = nn;
    cout << "Name set to: " << nameR << endl; // *check
}

void Request::setamount_wanted()
{
    cout << "How many?" << endl;
    int b; cin >> b;
    amount_wanted = b;
    cout << "Amount set to: " << amount_wanted << endl; // *check
}

////////////////////////////////////////////////////////////////////////////////

int main()
{
    std::cout << "Welcome to my shop!" << std::endl; // Intorduction
    Thing cursed_amulet;        cursed_amulet.setname_T("cursed__amulet");               cursed_amulet.setamount_available(1);  // Creating objects, and setting their data using a method
    Thing sinister_potion;      sinister_potion.setname_T("sinister__potion");           sinister_potion.setamount_available(2);
    Thing evil_minion;          evil_minion.setname_T("evil__minion");                   evil_minion.setamount_available(3);
    Thing beiwtched_bonemarrow; beiwtched_bonemarrow.setname_T("beiwtched__bonemarrow"); beiwtched_bonemarrow.setamount_available(4);
    Thing milk_spoiled;         milk_spoiled.setname_T("milk__spoiled");                 milk_spoiled.setamount_available(5);
    // Apples.amount = 10; // won't work becouse amount is private

    cursed_amulet.printall(); sinister_potion.printall(); evil_minion.printall(); beiwtched_bonemarrow.printall(); milk_spoiled.printall();

    Request request1; // creaing a request object
    request1.setname_R(); // asking for input
    request1.setamount_wanted(); // asking for input

    if (nameT.amount_wanted > nameR.amount_available)
    {
        cout << "TO MANY! Pick a lower number..." << endl; // error output, if not enought product
        goto again; // throwing user back to the choise of amount
    }
    else
    {
        std::cout << "You have chosen: " << nameR.amount_available << endl;
        // Return chosen goods
    }

    return 0;
}