#include <iostream>  // input/output
#include <fstream>   // external files support
#include <string>    // string
#include <vector>    // vector
#include <map>       // map

using namespace std; // saves the "std::" clutter


void swapNumbers(int* a, int* b) // function  that swaps two integers using pointers
{
    //cout << "Value of pointer ptr: " << *a << endl; // *check
    //cout << "Value of pointer ptr: " << *b << endl;

    int c = b; // bucket 1
    b = a; // bucket 2
    a = c; // bucket 3
}

int main()
{
    int value1; int value2; // simple input of two values
    cout << "Enter value 1: " << endl;
    cin >> value1;
    cout << "Enter value 2: " << endl;
    cin >> value2;

    cout << "Before swap: Value 1 = " << value1 << "  Value 2 = " << value2 << endl; // Printing before function

    swapNumbers(&value1, &value2); // Calling the function
    cout << "After swap: Value 1 = " << value1 << "  Value 2 = " << value2 << endl; // Printing after function

    return 0;
}