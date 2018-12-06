/*
 * Name: Rachana Mandal
 * Student id: 950699300 
 * Assignment 4 (Resubmission): App to measure products scan using BST and Array
 * */

#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <time.h>
#include "Product.h"
#include "BinarySearchTree.h"
#include "BarcodeBSTScanner.h"
#include "BarcodeArrayScanner.h"
using namespace std;

int main()
{
    BSTScanner<Product> bstScanner;
    ArrayScanner<Product> arrayScanner;

    // open the file
    ifstream file;
    file.open("upc_corpus.txt");

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
        bstScanner.insert(p); // insert product into bst Scanner
        arrayScanner.insert(p); //  insert product into array scanner
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

            // Using BSTScanner, search for the upccode and measure the time taken to search
            clock_t t = clock();
            Product result = bstScanner.scan(productToSearch);
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


            // Using ArrayScanner, search for the upccode and measure the time taken to search
            clock_t t1 = clock();
            Product result1 = arrayScanner.scan(productToSearch);
            t1 = clock() - t1;

            // Print the description if the upc code is found
            if (result1.getDescription() != "")
            {
                cout << result1.getDescription() << endl;
            }
            else
            {
                cout << "Not Found" << endl;
            }

            cout << "Array time: " << t1 << " miliseconds" << endl;
        }

        cout << endl;
    } while (input != "Q"); // Quit program if user inputs "Q"

    return 0;
}
