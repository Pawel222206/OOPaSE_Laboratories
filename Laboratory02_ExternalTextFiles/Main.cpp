#include <iostream>  // input/output
#include <string>    // string
#include <vector>    // vector
#include <map>       // map
#include <fstream>   // external files support
using namespace std; // saves the "std::" clutter


int math(int x, int y) // function declaration & definition
{
    return x - y;
}

// Not my code, but it works
//#include <unordered_map> // they are both from vector to map, not needed?
//#include <algorithm>
template<typename K, typename V>
vector<pair<K, V>> mapToVector(const map<K, V>& map)
{
    vector<pair<K, V>> v;

    for (auto it = map.cbegin(); it != map.cend(); ++it) {
        v.push_back(*it);
    }

    return v;
}

int main()
{
    vector<string>fileContent; // setting up vector to save data from file
    fstream file; // declaring file variable
    ifstream fin("textfile.txt"); // Open the file for reading
    string word; // declaring string variable

    if (file.good() == true)
    {
        while (fin >> word) // inputs the data from file into vector
        {
            //cout << "while works" << endl; // *check
            fileContent.push_back(word);
        }
        fin.close(); // Close the file
    }

    //cout << fileContent[1] << endl; // set vector output

    //for (string in_fileContent : fileContent) // whole vector output
    //{
    //    cout << in_fileContent << endl;
    //}

    //int u = stoi(fileContent[1]); // string to int
    //string z = fileContent[2];

    // Lab 1 code starts
    cout << "Welcome to my shop!" << endl; // Printing introduction

    /* this is an ugly ass way to do this, shame:
    map<string, int> products = { {z, u} };// storing products and amounts
    */

    // Restructuring vector into vector pair
    vector< pair <string, int> > values = { {fileContent[0], stoi(fileContent[1])},{fileContent[2], stoi(fileContent[3])}, { fileContent[4], stoi(fileContent[5]) },{fileContent[6], stoi(fileContent[7])}, {fileContent[8], stoi(fileContent[9])} };

    map<string, int> products; // map variable

    // Vector into map
    copy(values.begin(), values.end(),inserter(products, products.begin()));

    // Yes, I do create a vector from text file, then change it into another vector to change it into map.
    //AAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAA
    //The given example did not work...

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

    /* printing map
    cout << endl << "List of products with updated stock value:" << endl;
    for (map<string, int>::const_iterator it = products.begin(); it != products.end(); ++it)
    {
        cout << it->first << " " << it->second << endl;
    }
    */

    vector<pair<string, int>> v = mapToVector(products); // map to vector

    cout << endl << "Left in stock:" << endl;
    for (pair<string, int> p : v) { // printing vecotr
        cout << p.first << " " << p.second << endl;
    }

    /* Make it save the correct thing: it cant save word as some things in the vector are int...
    ofstream outputFile("testOutput.txt"); // setting up the file to be saved
    for (const auto& word : fileContent) // saves the vector to txt, but wrong
    {
        outputFile << word << endl;
    }
    */

    return(0);
}