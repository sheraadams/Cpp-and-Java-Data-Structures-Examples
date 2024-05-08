#include <algorithm>
#include <iostream>
#include <time.h>
#include <vector>
#include <iomanip>
#include <fstream>
#include <sstream>
#include <memory>

using namespace std;

// Structure to hold bid information
struct Bid {
    string bidId;
    string title;
    std::vector<std::string> prerequisites;
};

// Display the bid information to the console
void displayBid(Bid bid) {
    cout << bid.bidId << ", " << bid.title << endl;
    if (!bid.prerequisites.empty()) {
        cout << "Prerequisites: ";
        for (const string& prerequisite : bid.prerequisites) {
            cout << prerequisite;
            if (&prerequisite != &bid.prerequisites.back()) {
                cout << ", ";
            }
        }
        cout << endl;
    }
}

// Prompt user for bid information
Bid getBid() {
    Bid bid;

    cout << "Enter Id: ";
    cin.ignore();
    getline(cin, bid.bidId);

    cout << "Enter title: ";
    getline(cin, bid.title);

    return bid;
}

// Load bids from a CSV file into a container
void loadBids(string filePath, vector<Bid>& bids) {
    cout << "Loading file " << filePath << endl;

    // Open the file for reading using ifstream
    ifstream file(filePath);
    if (!file.is_open()) {
        cerr << "Failed to open file: " << filePath << endl;
        return;
    }

    string line;
    while (getline(file, line)) {
        stringstream ss(line);
        string id, name, prerequisite;
        vector<string> prerequisites;

        getline(ss, id, ',');
        getline(ss, name, ',');
        while (getline(ss, prerequisite, ',')) {
            prerequisites.push_back(prerequisite);
        }

        Bid bid;
        bid.bidId = id;
        bid.title = name;
        bid.prerequisites = prerequisites;

        bids.push_back(bid);
    }

    //  ifstream will automatically close the file when it goes out of scope
}

// Insert a bid into the vector
void insertBid(vector<Bid>& bids, Bid bid) {
    bids.push_back(bid);
    cout << "Bid inserted successfully." << endl;
}

// Remove a bid from the vector
void removeBid(vector<Bid>& bids, Bid bidToRemove) {
    if (bids.empty()) {
        cout << "No bids to remove." << endl;
        return;
    }

    auto it = find_if(bids.begin(), bids.end(), [&](const Bid& bid) { return bid.bidId == bidToRemove.bidId; });

    if (it != bids.end()) {
        bids.erase(it);
        cout << "Bid removed successfully." << endl;
    } else {
        cout << "Bid with Id " << bidToRemove.bidId << " not found." << endl;
    }
}

// Partition the vector of bids into two parts, low and high
int partition(vector<Bid>& bids, int begin, int end) {
    int midpoint = begin + (end - begin) / 2;
    Bid pivot = bids.at(midpoint);
    bool done = false;

    while (!done) {
        while (bids[begin].title < pivot.title) {
            begin += 1;
        }
        while (pivot.title < bids[end].title) {
            end -= 1;
        }
        if (begin >= end) {
            done = true;
        } else {
            Bid temp = bids[begin];
            bids[begin] = bids[end];
            bids[end] = temp;
            begin += 1;
            end -= 1;
        }
    }
    return end;
}

// Perform a quick sort on bid title
void quickSort(vector<Bid>& bids, int begin, int end) {
    if (begin >= end) {
        return;
    }
    int mid = partition(bids, begin, end);
    quickSort(bids, begin, mid);
    quickSort(bids, mid + 1, end);
}

// Perform a selection sort on bid title
void selectionSort(vector<Bid>& bids) {
    for (int i = 0; i < bids.size() - 1; ++i) {
        int min = i;
        for (int j = i + 1; j < bids.size(); ++j) {
            if (bids[j].title < bids[min].title) {
                min = j;
            }
        }
        Bid temp = bids[i];
        bids[i] = bids[min];
        bids[min] = temp;
    }
}

// Main method
int main(int argc, char* argv[]) {
    // Process command line arguments
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
        cout << "  5. Insert a Bid" << endl;
        cout << "  6. Remove a Bid" << endl;
        cout << "  9. Exit" << endl;
        cout << "Enter choice:\n ";
        cin >> choice;

        switch (choice) {
            case 1:
            {
                ticks = clock();
                loadBids(filePath, bids);
                cout << bids.size() << " bids read" << endl;
                ticks = clock() - ticks;
                cout << "time: " << ticks << " clock ticks" << endl;
                cout << "time: " << ticks * 1.0 / CLOCKS_PER_SEC << " seconds" << endl;
            }
                break;
            case 2:
            {
                for (int i = 0; i < bids.size(); ++i) {
                    displayBid(bids[i]);
                }
            }
                break;
            case 3:
            {
                ticks = clock();
                selectionSort(bids);
                cout << "\n" << bids.size() << " bids read" << endl;
                ticks = clock() - ticks;
                cout << "time: " << ticks << " clock ticks" << endl;
                cout << "time: " << ticks * 1.0 / CLOCKS_PER_SEC << " seconds" << endl;
            }
                break;
            case 4:
            {
                ticks = clock();
                quickSort(bids, 0, int(bids.size() - 1));
                cout << "\n" << bids.size() << " bids read" << endl;
                ticks = clock() - ticks;
                cout << "time: " << ticks << " clock ticks" << endl;
                cout << "time: " << ticks * 1.0 / CLOCKS_PER_SEC << " seconds" << endl;
            }
                break;
            case 5:
            {
                ticks = clock();
                Bid newBid = getBid();
                insertBid(bids, newBid);
                ticks = clock() - ticks;
                cout << "time: " << ticks << " clock ticks" << endl;
                cout << "time: " << ticks * 1.0 / CLOCKS_PER_SEC << " seconds" << endl;
            }
                break;
            case 6:
            {
                ticks = clock();
                Bid bidToRemove = getBid();
                removeBid(bids, bidToRemove);
                ticks = clock() - ticks;
                cout << "time: " << ticks << " clock ticks" << endl;
                cout << "time: " << ticks * 1.0 / CLOCKS_PER_SEC << " seconds" << endl;
            }
                break;
        }
    }

    cout << "Good bye." << endl;

    return 0;
}
