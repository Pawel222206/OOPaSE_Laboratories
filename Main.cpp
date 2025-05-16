/* Example - first code
#include <iostream>

int main()
{
	std::cout << "Hello World!" << std::endl;
}
*/

//if ((Input == "0") || (Input == "Red"))

#include <iostream>
#include <map>
#include <string>
using namespace std; // removes need for constant "std::" spam

void message1(); // funtion declaration

int math(int x, int y) // function declaration & definition
{
    return x - y;
}

int main()
{
    message1(); // Calling function
    // cout << "Welcome to my shop!" << endl; //Printing introduction - OLD

    map<string, int> products = { {"beiwtched_bone_marrow", 1},{"cursed_amulet", 2},{"evil_minion", 3},{"milk_spoiled", 4},{"sinister_potion", 5} }; // storing products and amounts in "map" format
    for (map<string, int>::const_iterator it = products.begin(); it != products.end(); ++it) // printing products and amounts
    {
        cout << it->first << " " << it->second << endl;
    }

    cout << "What do you want?" << endl;
    string in_productName; // seting up variable
    cin >> in_productName; // Get user input from the keyboard

    if (in_productName == "secretcode") // kill switch
    {
        return 0;
    }

    cout << "How many?" << endl;
again: // throwing user anchor
    string in_productAmount; // seting up variable
    cin >> in_productAmount;

    if (in_productAmount == "secretcode") // kill switch
    {
        return 0;
    }

    int in_productAmount_int = stoi(in_productAmount); // string to int
    // cout << in_productAmount_int; // *check

    if (in_productAmount_int > products[in_productName])
    {
        cout << "TO MANY! Pick a lower number..." << endl; // error output, if not enought product
        goto again; // throwing user back to the choise of amount
    }
    else
    {
        cout << "You have chosen: " << in_productAmount_int << "x " << in_productName << endl; // Return chosen goods
    }

    products[in_productName] = math(products[in_productName], in_productAmount_int); // updating amount of product with function calculating new amount of product
    // products[in_productName] = products[in_productName] - in_productAmount; // updating the amount of product - OLD

    cout << endl << "List of products with updated stock value:" << endl;
    for (map<string, int>::const_iterator it = products.begin(); it != products.end(); ++it)
    {
        cout << it->first << " " << it->second << endl;
    }

    return 0;
}

void message1() { // function definition
    cout << "Welcome to my shop!" << endl;
}