/*
 * Name: Rachana Mandal
 * Student id: 950699300 
 * Assignment 4: Barcode scanner using BinarySearchTree
 * */

#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <time.h>
#include "Product.h"
#include "BinarySearchTree.h"
using namespace std;

int main()
{
    // open the file
    ifstream file;
    file.open("upc_corpus.txt");

    BinarySearchTree<Product> bst;

    // read products from the file one line at a time
    string line;
    while (getline(file, line))
    {
        string upcCode, description;

        istringstream ss(line);
        string token;

        int position = 0;
        while (getline(ss, token, ',')) //uses , as splitter instead of white space
        {
            if (position == 0)
            {
                upcCode = token;
            }
            else
            {
                description = token;
            }
            position++;
        }
        Product p(upcCode, description);
        bst.insert(p);
    }

    // close the file
    file.close();

    string input;

    do
    {
        cout << "UPC Code: ";
        cin >> input;

        if (input != "Q")
        {
            Product productToSearch(input, "");

            // search for the upccode and measure the time taken to search
            clock_t t = clock();
            Product result = bst.search(productToSearch);
            t = clock() - t;

            // Print the description if the upc code is found
            if (result.getDescription() != "")
            {
                cout << result.getDescription() << endl;
            }
            else
            {
                cout << "Not Found" << endl;
            }

            cout << "BST time: " << t << " miliseconds" << endl;
        }

        cout << endl;
    } while (input != "Q"); // Quit program if user inputs "Q"

    return 0;
}
