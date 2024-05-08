#include <algorithm>
#include <climits>
#include <iostream>
#include <string>
#include <time.h>
#include <utility>
#include <fstream>
#include <sstream>
#include<vector>
using namespace std;

const unsigned int DEFAULT_SIZE = 179;

// define a structure to hold bid information
struct Bid {
    string bidId; // unique identifier
    string title;
    std::vector<std::string> prerequisites;
};

class HashTable {

private:
    // Define structures to hold bids
    struct Node {
        Bid bid;
        unsigned int key;
        Node *next;

        // default constructor
        Node() {
            key = UINT_MAX;
            next = nullptr;
        }

        // initialize with a bid
        Node(Bid aBid) : Node() {
            bid = aBid;
        }

        // initialize with a bid and a key
        Node(Bid aBid, unsigned int aKey) : Node(aBid) {
            key = aKey;
        }
    };

    vector<Node> nodes;

    unsigned int tableSize = DEFAULT_SIZE;

    unsigned int hash(int key);

public:
    HashTable();
    HashTable(unsigned int size);
    virtual ~HashTable();
    void Insert(Bid bid);
    void PrintAll();
    void Remove(string bidId);
    Bid Search(string bidId);
};

/**
 * Default constructor
 */
HashTable::HashTable() {
    // Initialize node structure by resizing tableSize
    nodes.resize(tableSize);
}

/**
 * Constructor for specifying size of the table
 * used to improve efficiency of hashing algorithm
 * by reducing collisions without wasting memory.
 */
HashTable::HashTable(unsigned int size) {
    // Initialize node structure by resizing tableSize
    nodes.resize(size);
}

HashTable::~HashTable() {
    // Loop through all nodes in the hash table
    for (Node& node : nodes) {
        // Pointer to the current node
        Node* current = &node;
        // Loop through the linked list starting from this node
        while (current != nullptr) {
            // Pointer to the next node
            Node* next = current->next;
            // Delete the current node
            delete current;
            // Move to the next node
            current = next;
        }
    }
}

unsigned int HashTable::hash(int key) {
    // return key tableSize
    return key % tableSize;
}

void HashTable::Insert(Bid bid) {
    // convert the string to an integer, calling the hash function
    //to calculate the key and save as key
    unsigned int key = hash(atoi(bid.bidId.c_str()));
    // Retrieve the node using key
    Node* theNode = &nodes.at(key);
    // if the key is empty
    if (theNode->key == UINT_MAX)
    {  // assign key and bid to calculated key and to the given bid
        theNode->key = key;
        theNode->bid = bid;
    }
    // if node is not empty and key is not empty
    else{
        // while not null
        while (theNode->next != nullptr) {
            // point to the next node
            theNode = theNode->next;
        }
        // Add a new node to the end of the linked list
        theNode->next = new Node(bid, key);
    }
}

void HashTable::PrintAll() {
    // loop through nodes of hash table
    for (auto& bidNode : nodes) {
        // skip empty keys
        if (bidNode.key != UINT_MAX) {
            Node* node = &bidNode;
            // print all nodes in the linked list
            while (node != nullptr) {
                cout << node->bid.bidId << ", " << node->bid.title << ", " << endl;
                // print prerequisites if not empty
                if (!node->bid.prerequisites.empty()) {
                    cout << "Prerequisites: ";
                    for (const string& prerequisite : node->bid.prerequisites) {
                        // print separated by comma
                        cout << prerequisite;
                        // if not the last prerequisite, print comma
                        if (&prerequisite != &node->bid.prerequisites.back()) {
                            cout << ", ";
                        }
                    }
                    cout << endl;
                }
                // move to the next node
                node = node->next;
            }
        }
    }
}

void HashTable::Remove(string bidId) {
    // Call hash function to get the key
    unsigned key = hash(atoi(bidId.c_str()));

    // Retrieve the node at the specified key
    Node *node = &nodes.at(key);

    // If the first node matches the bidId
    if (node->bid.bidId == bidId) {
        // If there's only one node at this key, erase it
        if (node->next == nullptr) {
            nodes.erase(nodes.begin() + key);
        } else {
            // If there are multiple nodes, replace the current node with the next one
            Node* nextNode = node->next;
            *node = *nextNode;
            // Delete the next node to avoid memory leaks
            delete nextNode;
        }
        return;
    }

    // If the first node didn't match, search through the linked list for the bidId
    while (node->next != nullptr) {
        // If the next node's bidId matches, remove it
        if (node->next->bid.bidId == bidId) {
            Node* nextNode = node->next;
            // Remove the next node from the list
            node->next = node->next->next;
            // Delete the removed node to avoid memory leaks
            delete nextNode;
            return;
        }
        // Move to the next node
        node = node->next;
    }
}

Bid HashTable::Search(string bidId) {
    // create the key for the given bid
    unsigned key = hash(atoi(bidId.c_str()));   
    // create node object at the key position
    Node* node = &nodes.at(key); 
    // while node not equal to null
    while (node != nullptr) {
        // if bidid of node  matches the searched value & is not empty
        if ( node->bid.bidId == bidId && node->key != UINT_MAX) {
            // return the bid
            return node->bid;
        }
        // node is equal to next node
        node = node->next;
    }    
    // return value if one exists otherwise return empty Bid() object
    return Bid();
}

void displayBid(Bid bid) {
    cout << bid.bidId << ": " << bid.title << endl;
    return;
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

void loadBids(string filePath, HashTable *HashTable) {
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
        HashTable->Insert(bid);
    }
    // Close the file
    file.close();
}

int main(int argc, char* argv[]) {
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

    // Define a timer variable
    clock_t ticks;

    // Define a hash table to hold all the bids
    HashTable* bidTable;

    Bid bid;
    bidTable = new HashTable();
    
    int choice = 0;
    while (choice != 9) {
        cout << "\nMenu:" << endl;
        cout << "  1. Load Bids" << endl;
        cout << "  2. Display All Bids" << endl;
        cout << "  3. Find Bid" << endl;
        cout << "  4. Remove Bid" << endl;
        cout << "  5. Insert Bid" << endl;
        cout << "  9. Exit" << endl;
        cout << "Enter choice: ";
        cin >> choice;
        cout << endl;
        switch (choice) {

            case 1: {

                // Initialize a timer variable before loading bids
                ticks = clock();

                // Complete the method call to load the bids
                loadBids(filePath, bidTable);

                // Calculate elapsed time and display result
                ticks = clock() - ticks; // current clock ticks minus starting clock ticks
                cout << "time: " << ticks << " clock ticks" << endl;
                cout << "time: " << ticks * 1.0 / CLOCKS_PER_SEC << " seconds" << endl;
            }
                break;

            case 2: {
                bidTable->PrintAll();
            }
                break;

            case 3: {
                ticks = clock();
                // added necessary input to search bid by key
                cout << "Enter id of bid to search:" << endl;
                cin >> bidKey;
                bid = bidTable->Search(bidKey);

                ticks = clock() - ticks; // current clock ticks minus starting clock ticks

                if (!bid.bidId.empty()) {
                    displayBid(bid);
                } else {
                    cout << "Bid Id " << bidKey << " not found." << endl;
                }

                cout << "time: " << ticks << " clock ticks" << endl;
                cout << "time: " << ticks * 1.0 / CLOCKS_PER_SEC << " seconds" << endl;
            }
                break;

            case 4: {
                    cout << "Enter id of bid to remove:" << endl;
                    cin >> bidKey;
                    bidTable->Remove(bidKey);
            }
                break;

            case 5: {
                    cout << "Enter id of bid to insert:" << endl;
                    Bid bidToInsert= getBid();
                    bidTable->Insert(bidToInsert);
            }
                    break;
        }
    }
    cout << "Good bye." << endl;
    return 0;
}
