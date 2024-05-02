/*
* Singly linked list implementation example.
*/
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

// define a structure to hold bid information
struct Bid {
    string bidId; // unique identifier
    string title;
    std::vector<std::string> prerequisites;
};

//============================================================================
// Linked-List class definition
//============================================================================

/**
 * Define a class containing data members and methods to
 * implement a linked-list.
 */
class LinkedList {

private:
    //Internal structure for list entries, housekeeping variables
    struct Node {
        Bid bid;
        Node *next;

        // default constructor
        Node() {
            next = nullptr;
        }

        // initialize with a bid
        Node(Bid aBid) {
            bid = aBid;
            next = nullptr;
        }
    };

    Node* head;
    Node* tail;
    int size = 0;

public:
    LinkedList();
    virtual ~LinkedList();
    void Append(Bid bid);
    void Prepend(Bid bid);
    void PrintList();
    void Remove(string bidId);
    Bid Search(string bidId);
    int Size();
};

/**
 * Default constructor
 */
LinkedList::LinkedList() {
    //set head and tail equal to null
    head = nullptr;
    tail = nullptr;


}

/**
 * Destructor
 */
LinkedList::~LinkedList() {
    // start at the head
    Node* current = head;
    Node* temp;

    // loop over each node, detach from list then delete
    while (current != nullptr) {
        temp = current; // hang on to current node
        current = current->next; // make current the next node
        delete temp; // delete the orphan node
    }
}

/**
 * Append a new bid to the end of the list
 */
void LinkedList::Append(Bid bid) {
    //Create new node
    Node *newNode = new Node(bid);
    //if there is nothing at the head (list is empty)
    if (this->head == nullptr) {
        // point head to new node
        this->head = newNode;
        //point tail to new new node
        this->tail = newNode;
    }
    else {
        // make tail node's next pointer point to new node
        this->tail->next = newNode;
        //point tail to new new node
        this->tail = newNode;
    }
    //increment size
    size++;
}

/**
 * Prepend a new bid to the start of the list
 */
void LinkedList::Prepend(Bid bid) {
    // Create newnode object calling the Node() 
    // function passing bid as parameter
    Node* newNode = new Node(bid);
    // if list is empty
    if (this->head == nullptr) { 
        // set the head and tail pointer to the new node
        this->head = newNode;
        this->tail = newNode;
    }
    // if list is not empty
    else {
        // new node points to current head as its next node
        newNode->next = this->head;
        // set head as the new node
        this->head = newNode;
    }
    //increment size
    size++;
}

/**
 * Simple output of all bids in the list
 */
void LinkedList::PrintList() {
    // create current Node object and set as head node
    // start at the head
    Node* current = this->head;
    // while not the end of the list
    while (current != nullptr) {
        //output current bidID, title, amount and fund
        std::cout << current->bid.bidId << " " << current->bid.title <<endl;
        //point current to next element
        current = current->next;
    }
}

/**
 * Remove a specified bid
 * @param bidId The bid id to remove from the list
 */
void LinkedList::Remove(string bidId) {
    // Define variables to traverse list
    // Start at the head
    Node* curNode = head;
    Node* prevNode = nullptr;

    // Special case: if matching node is the head
    if (curNode != nullptr && curNode->bid.bidId == bidId) {
        // Make head point to the next node in the list
        head = curNode->next;

        // If head is also the tail
        if (curNode == tail) {
            tail = nullptr;
        }

        // Delete the current node
        delete curNode;
        // Decrement the size count
        --size;
        return;
    }

    // Traverse the list to find the node to remove
    while (curNode != nullptr && curNode->bid.bidId != bidId) {
        prevNode = curNode;
        curNode = curNode->next;

        if (curNode == nullptr) {
            return;
        }

        prevNode->next = curNode->next;

        if (curNode == tail) {
            tail = prevNode;
        }
    }

    // Delete the current node
    delete curNode;

    // Decrement size
    --size;
    return;
}

/**
 * Search for the specified bidId
 * @param bidId The bid id to search for
 */
Bid LinkedList::Search(string bidId) {
    // start at the head of the list
    Node* curNode = this->head;      
    // while current node is not empty
    while (curNode != nullptr) {
        // special case if matching node is the head
        if (curNode->bid.bidId == bidId) {
            //decrease size count
            --size;
            return curNode->bid;
        }
        // point current node to the next node
        curNode = curNode->next;
        }
     //return bid if a match or empty bid if none
     return Bid();
}

/**
 * Returns the current size (number of elements) in the list
 */
int LinkedList::Size() {
    return size;
}

//============================================================================
// Static methods used for testing
//============================================================================

/**
 * Display the bid information
 *
 * @param bid struct containing the bid info
 */
void displayBid(Bid bid) {
    cout << bid.bidId << ", " << bid.title << endl;
    // if the prerequisites are not empty
    if (!bid.prerequisites.empty())
        // for to print prereq
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
 * Prompt user for bid information
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
 * Load a CSV file containing bids into a LinkedList
 *
 * @return a LinkedList containing all the bids read
 */
void loadBids(string filePath, LinkedList *LinkedList) {
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
        LinkedList->Append(bid);
    }
    // Close the file
    file.close();
}

/**
 * main() method
 * @param arg[1] path to CSV file to load from (optional)
 * @param arg[2] the bid Id to use when searching the list (optional)
 */
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

    clock_t ticks;

    LinkedList bidList;

    Bid bid;

    int choice = 0;
    while (choice != 9) {
        cout << "\nMenu:" << endl;
        cout << "  1. Enter a Bid" << endl;
        cout << "  2. Load Bids" << endl;
        cout << "  3. Display All Bids" << endl;
        cout << "  4. Find Bid" << endl;
        cout << "  5. Remove Bid" << endl;
        cout << "  9. Exit" << endl;
        cout << "Enter choice: ";
        cin >> choice;

        switch (choice) {
        case 1:
            bid = getBid();
            bidList.Append(bid);
            displayBid(bid);

            break;

        case 2:
            ticks = clock();

            loadBids(filePath, &bidList);

            cout << bidList.Size() << " bids read" << endl;

            ticks = clock() - ticks; // current clock ticks minus starting clock ticks
            cout << "time: " << ticks << " milliseconds" << endl;
            cout << "time: " << ticks * 1.0 / CLOCKS_PER_SEC << " seconds" << endl;

            break;

        case 3:
            bidList.PrintList();
            break;

        case 4:
            ticks = clock();
            // added necessary input to search bid by key
            cout << "Enter bid id to search:" << endl;
            cin >> bidKey;
            bid = bidList.Search(bidKey);

            ticks = clock() - ticks; // current clock ticks minus starting clock ticks

            if (!bid.bidId.empty()) {
                displayBid(bid);
            } else {
            	cout << "Bid Id " << bidKey << " not found." << endl;
            }

            cout << "time: " << ticks << " clock ticks" << endl;
            cout << "time: " << ticks * 1.0 / CLOCKS_PER_SEC << " seconds" << endl;

            break;

        case 5:
            // added necessary input to remove bid by key
            cout << "Enter bid id of bid to remove:" << endl;
            cin >> bidKey;
            bidList.Remove(bidKey);

            break;
        }
    }

    cout << "Good bye." << endl;

    return 0;
}
