/*
 * Name: Rachana Mandal
 * Student id: 950699300 
 * Assignment 4: Barcode scanner using Array
 * */
#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <time.h>
#include "Product.h"
using namespace std;

int main()
{
    // open the file
    ifstream file;
    file.open("upc_corpus.txt");

    Product *products = new Product[2000000];
    int productCount = 0;

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
            // First poistion is the upc code
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

        // Add the product to array
        Product p(upcCode, description);
        products[productCount++] = p;
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
            Product result;

            // search for the upccode and measure the time taken to search
            clock_t t = clock();
            for (int i = 0; i < productCount; i++)
            {
                if (products[i] == productToSearch)
                {
                    result = products[i];
                    break;
                }
            }

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

            cout << "Array time: " << t << " miliseconds" << endl;
        }

        cout << endl;
    } while (input != "Q"); // Quit program if user inputs "Q"

    return 0;
}
