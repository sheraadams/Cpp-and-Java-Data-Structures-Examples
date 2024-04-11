//============================================================================
// Name        : VectorSorting.cpp
// Author      : Shera Adams
// Version     : 1.0
// Copyright   : Copyright © 2017 SNHU COCE
// Description : Vector Sorting Algorithms
//============================================================================
#include <algorithm>
#include <iostream>
#include <time.h>
#include <vector>
#include <iomanip>
#include <fstream>
#include <sstream>

using namespace std;

//============================================================================
// Global definitions visible to all methods and classes
//============================================================================

// forward declarations
double strToDouble(string str, char ch);

// define a structure to hold bid information
struct Bid {
    string bidId; // unique identifier
    string title;
    std::vector<std::string> prerequisites;
};

//============================================================================
// Static methods used for testing
//============================================================================

/**
 * Display the bid information to the console (std::out)
 *
 * @param bid struct containing the bid info
 */
void displayBid(Bid bid) {
    cout << bid.bidId << ", " << bid.title << endl;
    // if the prerequisites are not empty
    if (!bid.prerequisites.empty())
        // for to print prerequisites
        cout << "Prerequisites: ";
    for (const string& prerequisite : bid.prerequisites) {
        // if the prerequisite is the last in the vector
        if (prerequisite == bid.prerequisites.back()) {
            cout << prerequisite << endl;
        }
            // otherwise print separated by comma
        else {
            cout << prerequisite << ", ";
        }
    }
    return;
}
/**
 * Prompt user for bid information using console (std::in)
 *
 * @return Bid struct containing the bid info
 */
Bid getBid() {
    Bid bid;

    cout << "Enter Id: ";
    cin.ignore();
    getline(cin, bid.bidId);

    cout << "Enter title: ";
    getline(cin, bid.title);

    return bid;
}

/**
 * Load a CSV file containing bids into a container
 *
 * @param csvPath the path to the CSV file to load
 * @return a container holding all the bids read
 */
void loadBids(string filePath, vector<Bid> & bids) {
    cout << "Loading file " << filePath << endl;

    // Open the file for reading
    ifstream file(filePath);
    // Check if the file is open, handle error
    if (!file.is_open()) {
        cerr << "Failed to open file: " << filePath << endl;
        return;
    }
    string line;
    // while reading lines of the file
    while (getline(file, line)) {
        // define variables
        stringstream ss(line);
        string id, name, prerequisite;
        vector<string> prerequisites;
        // Read the id and name separated by a comma
        getline(ss, id, ',');
        getline(ss, name, ',');
        // Read the prerequisites separated by a comma
        while (getline(ss, prerequisite, ',')) {
            prerequisites.push_back(prerequisite);
        }
        // Create a bid
        Bid bid;
        bid.bidId = id;
        bid.title = name;
        bid.prerequisites = prerequisites;
        // Insert the bid into the bst
        bids.push_back(bid);
    }
    // Close the file
    file.close();
}

/**
 * Partition the vector of bids into two parts, low and high
 *
 * @param bids Address of the vector<Bid> instance to be partitioned
 * @param begin Beginning index to partition
 * @param end Ending index to partition
 */

/*
the partition() function to separates the data into a high and a 
low partition.
*/
// Zybooks Data Structures and Algorithms section 3.18.1
int partition(vector<Bid>& bids, int begin, int end) {
        // calculate midpoint between begin and end values of bid vector
        int midpoint = begin + (end - begin) / 2;
        // set middle element as pivot 
        Bid pivot = bids.at(midpoint);
        // set boolean to false
        bool done = false;
        // while not done 
        while (!done) {
            // increment begin until a value >= to pivot is found
            while (bids[begin].title < pivot.title) {
                begin += 1;
            }
            // decrement end until a value <less than <= to pivot is found
            while (pivot.title < bids[end].title) {
                end -= 1;
            }
            /* If there are zero or one elements remaining,
             all bids are partitioned.  */
            if (begin >= end) {
                done = true;
            }
            // otherwise swap low and high bids and decrement high/ increment low
            // repeat until the end and begin reach or pass eachother
            else {
                Bid temp = bids[begin];
                bids[begin] = bids[end];
                bids[end] = temp;
                // Update begin and end moving the values closer together
                begin += 1;
                end -= 1;
            }
        }
        //return high;
        return end;
}

/**
 * Perform a quick sort on bid title
 * Average performance: O(n log(n))
 * Worst case performance O(n^2))
 *
 * @param bids address of the vector<Bid> instance to be sorted
 * @param begin the beginning index to sort on
 * @param end the ending index to sort on
 */

/*
The function quicksort() function calls the partition() function to first 
separate the data into a high and a low partition. A mid variable is created 
from the last element of the low partition. The function recursively calls 
itself to sort the high and low partitions so long as the beginning is 
larger than the end bid and a sort is required.
*/
// Zybooks Data Structures and Algorithms section 3.18.4
void quickSort(vector<Bid>& bids, int begin, int end) {
    //set mid equal to 0
    int mid = 0;
    /* Base case: If there are 1 or zero bids to sort,
     partition is already sorted otherwise if begin is greater
     than or equal to end then return*/
     /* If the partition is already sorted, the recursive calls will
    not execute, otherwise the bids will be sorted. */
    if (begin >= end) {
        return;
    }
    /* Partition bids into low and high such that
     midpoint is location of last element in low */
    mid = partition(bids, begin, end);
    // recursively sort low partition 
    quickSort(bids, begin, mid);
    // recursively sort high partition 
    quickSort(bids, mid + 1, end);
}

// TODO(1a):DONE Implement the selection sort logic over bid.title
/**
 * Perform a selection sort on bid title
 * Average performance: O(n^2))
 * Worst case performance O(n^2))
 *
 * @param bid address of the vector<Bid>
 *            instance to be sorted
 */

/*
The selectionSort() function loops through the bids vector, saving the minimum
value, min, and the index of the value to finally swap the variable min and the 
next index to the min index. 
*/
// Zybooks Data Structures and Algorithms section 3.16.1
void selectionSort(vector<Bid>& bids) {
    //define the variables, i for the all bids
    int i = 0;
    // j for unsorted
    int j = 0;
    int min = 0;
    int temp = 0;  // variable for swap
    
    //loop through the full vector
    for (i = 0; i < bids.size() -1; ++i) {     
        // min = index
        min = i;
        // loop through vector indicies to the right of i
        //searching for the minimum element 
        for (j = i + 1; j < bids.size(); ++j) {
            // if this element's title is less than minimum title
            if ( bids[j].title < bids[min].title ) {
                // stores the smallest element of the vector
                min = j;
            }
        }  
        // swap the current min with smaller value found
        Bid temp = bids[i];
        bids[i] = bids[min];
        // complete the swap and save 
        bids[min] = temp;
   }
}

/**
 * Simple C function to convert a string to a double
 * after stripping out unwanted char
 *
 * credit: http://stackoverflow.com/a/24875936
 *
 * @param ch The character to strip out
 */
double strToDouble(string str, char ch) {
    str.erase(remove(str.begin(), str.end(), ch), str.end());
    return atof(str.c_str());
}

/**
 * The one and only main() method
 */
int main(int argc, char* argv[]) {

    system("Color 0D");
    // process command line arguments
    string filePath, bidKey;
    switch (argc) {
        case 2:
            filePath = argv[1];
            bidKey = "CSCI400";
            break;
        case 3:
            filePath = argv[1];
            bidKey = argv[2];
            break;
        default:
            filePath = "bst.txt";
            bidKey = "CSCI400";
    }

    // Define a vector to hold all the bids
    vector<Bid> bids;

    // Define a timer variable
    clock_t ticks;

    int choice = 0;
    while (choice != 9) {
        cout << "\nMenu:" << endl;
        cout << "  1. Load Bids" << endl;
        cout << "  2. Display All Bids" << endl;
        cout << "  3. Selection Sort All Bids" << endl;
        cout << "  4. Quick Sort All Bids" << endl;
        cout << "  9. Exit" << endl;
        cout << "Enter choice:\n ";
        cin >> choice;

        switch (choice) {

        case 1:
            // Initialize a timer variable before loading bids
            ticks = clock();

            // Complete the method call to load the bids
            loadBids(filePath, bids);

            //print to console the size of the results read
            cout << bids.size() << " bids read" << endl;

            // Calculate elapsed time and display result
            ticks = clock() - ticks; // current clock ticks minus starting clock ticks
            cout << "time: " << ticks << " clock ticks" << endl;
            cout << "time: " << ticks * 1.0 / CLOCKS_PER_SEC << " seconds" << endl;

            break;

        case 2:
            // Loop and display the bids read
            for (int i = 0; i < bids.size(); ++i) {
                displayBid(bids[i]);
            }

            break;

        // TODO(1b): Invoke the selection sort and report timing results
        case 3:
            // Initialize a timer variable before loading bids
            ticks = clock();

            // Complete the method call to selection sort bids
            selectionSort(bids);

            //NOTE: this is printing to the console twice I am not sure why
            //print to console the size of the results read
            cout << "\n" << bids.size() << " bids read" << endl;

            // Calculate elapsed time and display result
            ticks = clock() - ticks; // current clock ticks minus starting clock ticks
            cout << "time: " << ticks << " clock ticks" << endl;
            cout << "time: " << ticks * 1.0 / CLOCKS_PER_SEC << " seconds" << endl;
            break;

        // TODO(2b): Invoke the quick sort and report timing results
        case 4:
            ticks = clock();

            // Complete the method call to quick sort bids
            quickSort(bids, 0, int(bids.size() - 1));

            //print to console the size of the results read
            cout << "\n" << bids.size() << " bids read" << endl;

            // Calculate elapsed time and display result
            ticks = clock() - ticks; // current clock ticks minus starting clock ticks
            cout << "time: " << ticks << " clock ticks" << endl;
            cout << "time: " << ticks * 1.0 / CLOCKS_PER_SEC << " seconds" << endl;
            break;
        }
    }

    cout << "Good bye." << endl;

    return 0;
}
