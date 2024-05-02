#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>

using namespace std;

//============================================================================
// Global definitions visible to all methods and classes
//============================================================================
// define a structure to hold bid information
struct Bid {
    string bidId; // unique identifier
    string title;
    std::vector<std::string> prerequisites;
};

// Internal structure for tree node
struct Node {
    Bid bid;
    Node *left;
    Node *right;

    // default constructor
    Node() {
        left = nullptr;
        right = nullptr;
    }

    // initialize with a bid
    Node(Bid aBid) :
            Node() {
        bid = aBid;
    }
};

//============================================================================
// Binary Search Tree class definition
//============================================================================
class BinarySearchTree {

private:
    Node* root;

    void addNode(Node* node, Bid bid);
    void inOrder(Node* node);
    Node* removeNode(Node* node, string bidId);
    void postOrder(Node* node);
    void preOrder(Node* node);

public:
    BinarySearchTree();
    virtual ~BinarySearchTree();
    void DeleteTree(Node* node);
    void InOrder();
    void InOrder(Node* node);
    void PostOrder();
    void PreOrder();
    void Insert(Bid bid);
    void Remove(string bidId);
    Bid Search(string bidId);
};

/**
 * Default constructor
 */
BinarySearchTree::BinarySearchTree() {
    //root is equal to nullptr
    root = nullptr;
}

void BinarySearchTree::DeleteTree(Node* node) {
    if (node != nullptr) {
        // Recursively delete left and right subtrees
        DeleteTree(node->left);
        DeleteTree(node->right);
        // Delete the current node
        delete node;
    }
}

/**
 * Destructor
 */
BinarySearchTree::~BinarySearchTree() {
    // recurse from root deleting every node
    DeleteTree(root);
}

/**
 * Traverse the tree in order
 */
void BinarySearchTree::InOrder() {
    // set node to root
    Node* node = root;
    // call inOrder fuction and pass root 
    InOrder(root);
    return;
}

void BinarySearchTree::InOrder(Node* node) {
    // if node is not empty
    if (node != nullptr)
    {
        // recursively print left node
        InOrder(node->left);
        // print the current node
        cout << node->bid.bidId << ": " << node->bid.title << endl;
        // recursively print the right node
        InOrder(node->right);
    }
}

/**
 * Traverse the tree in post-order
 */
void BinarySearchTree::PostOrder() {
    // postOrder root
    Node* node = root;
    postOrder(root);
}
void BinarySearchTree::postOrder(Node* node) {
    //if node is not equal to null ptr
    if (node != nullptr) {
        // print output 
        cout << node->bid.bidId << ": " << node->bid.title << endl;
        // recursively order left
        postOrder(node->left);
        // recursively order right
        postOrder(node->right);
        // print in post order
    }

}
/**
 * Traverse the tree in pre-order
 */
void BinarySearchTree::PreOrder() {
    // preOrder root
    Node* node = root;
    preOrder(root);
}

//postOrder left
//postOrder right
//output bidID, title, amount, fund
void BinarySearchTree::preOrder(Node* node) {
    //if node is not equal to null ptr
    //     //if node is not equal to null ptr
    if (node != nullptr) {
        // print output 
        cout << node->bid.bidId << ": " << node->bid.title << endl;
        // recursively order left
        postOrder(node->left);
        // recursively order right
        postOrder(node->right);
    }
}
/**
 * Insert a bid
 */
void BinarySearchTree::Insert(Bid bid) {
    // if root equal to null ptr
    Node* node = new Node(bid);
    // if root is nullptr
    if (root == nullptr)
    {
        // root is equal to new node bid
        root = node;
        // set left and right to nullptr
        node->left = nullptr;
        node->right = nullptr;
    }
    else
    {
        Node* curr = root;
        // if root is not nullptr, insert bid
        while (curr != nullptr)
        {
            // if bid id is less than the current bid id 
            // go to the left subtree
            if (node->bid.bidId < curr->bid.bidId)
            {
                // if left is nullptr
                if (curr->left == nullptr)
                {
                    // assign the node as left child
                    curr->left = node;
                    // assign curr as nullptr to end loop
                    curr = nullptr;
                }
                // if it is not nullptr 
                else
                    //move to the left child and continue the loop
                    curr = curr->left;
            }
            //if the node id is greater or equal to the current bid id
            //go to right subtree
            else
                // if the right child of current node is null
                if (curr->right == nullptr)
                {
                    // assign the node as right child
                    curr->right = node;
                    // assign curr as nullptr to end loop
                    curr = nullptr;
                }
            // if the right child of the current is not null
                else
                    // move to the right child and continue the loop
                    curr = curr->right;
        }
    }
    // set the new node left and right pointers to nullptr 
    node->left = nullptr;
    node->right = nullptr;
    return;
}

/**
 * Remove a bid
 */
void BinarySearchTree::Remove(string bidId) {
    // set  parent node of the current node to null
    Node* par = nullptr;
    // set current to the root
    Node* cur = root;
    // Search for node while cur is not nullptr
    while (cur != nullptr) {
        //If current node bid id is the searched bid id
        if (cur->bid.bidId == bidId) {
            // remove node with no children
            if (cur->left == nullptr && cur->right == nullptr) {
                // if parent is null (is root)
                if (par == nullptr)
                    // set root to nullptr
                    root = nullptr;
                // if current node is left parent
                else if (par->left == cur)
                    // set left parent to null ptr
                    par->left = nullptr;
                // if node is right parent
                else
                    // set right parent to null ptr
                    par->right = nullptr;
            }
            // Remove node with only left child
            else if (cur->right == nullptr) {
                // if parent is null (is root)
                if (par == nullptr)
                    // set the root to the left child
                    root = cur->left;
                // if node's left parrent is the current 
                else if (par->left == cur)
                    // set the parent's left pointer to the left child
                    par->left = cur->left;
                // if the node's right parent is the current
                else
                    //set the parents right to the right child
                    par->right = cur->left;
            }
            // Remove node with only right child
            else if (cur->left == nullptr) {
                // if parent is null (is root)
                if (par == nullptr)
                    // set the root to the right child
                    root = cur->right;
                // if the left parent is the current
                else if (par->left == cur)
                    // set the parent's left pointer to the  right child
                    par->left = cur->right;
                else
                    // set the parent's right pointer to the  right child
                    par->right = cur->right;
            }
            // Remove node with two children
            else {
                // Assign right child of current node as successor
                Node* suc = cur->right;
                // Find successor (the left child of right subtree)
                // while successor is not null
                while (suc->left != nullptr)
                {
                    //move the left child of the current node
                    suc = suc->left;
                    // create a copy of the succesor
                    Node* successorCopy = suc;
                    // recursively remove successor
                    Remove(suc->bid.bidId);
                    // set the current node as a copy of the successor
                    cur = successorCopy;
                }
            }
            // Node found and removed
            return;
        }
        // Search right subtree
        // if current bid id is less than the searched bid id
        else if (cur->bid.bidId < bidId) {
            // set parent node to current
            par = cur;
            // point current right child
            cur = cur->right;
        }
        // Search left subtree
        //if current bid id is greater than the searched bid id
        else {
            // set parent node to current
            par = cur;
            // point current left child
            cur = cur->left;
        }
    }
    return;
}

/**
 * Search for a bid
 */
Bid BinarySearchTree::Search(string bidId) {
    // set current node equal to root
    Node* curr = root;
    // while current node is not empty
    while (curr != nullptr) {
        // if cirrent bid id matches the searched id
        if (curr->bid.bidId.compare(bidId) == 0)
            // return the matching bid
            return curr->bid;
        // if bid is smaller than current node search left
        else if (bidId.compare(curr->bid.bidId) < 0)
            // point current to the left child
            curr = curr->left;
        // else larger and search right
        else
            // point current to the right child
            curr = curr->right;
    }
    // return bid object
    Bid bid;
    return bid;
}

/**
 * Add a bid to some node (recursive)
 * @param node Current node in tree
 * @param bid Bid to be added
 */
void BinarySearchTree::addNode(Node* node, Bid bid) {
    // set current node equal to root
    Node* cur = root;
    // if current is empty
    if (cur == nullptr)
    {    // set node as root
        root = node;
        node->left = nullptr;
        node->right = nullptr;

    }
    else {
        // set current as root
        cur = root;
        // while current is not empty
        while (cur != nullptr) {
            // if node is larger then add to left
            if (node->bid.bidId < cur->bid.bidId)
            {   // if no left node
                if (cur->left == nullptr) {
                    // this node becomes left
                    cur->left = node;
                    cur = nullptr;
                }
                // else recurse down the left node
                else
                    cur = cur->left;

            }
            // if node is smaller than add to right
            else {
                // if no right node
                if (cur->right == nullptr) {
                    // this node becomes right
                    cur->right = node;
                    cur = nullptr;
                }
                else
                    // recurse down the left node
                    cur = cur->right;
            }
            // set the left and right to null
            node->left = nullptr;
            node->right = nullptr;
        }
    }
}

//============================================================================
// Static methods used for testing
//============================================================================

/**
 * Display the bid information to the console (std::out)
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
 * Load a CSV file containing bids into a container
 * @param csvPath the path to the CSV file to load
 * @return a container holding all the bids read
 */
void loadBids(string filePath, BinarySearchTree* bst) {
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
        bst->Insert(bid);
    }
    // Close the file
    file.close();
}

// main() method
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

    // Define a binary search tree to hold all bids
    BinarySearchTree* bst;
    bst = new BinarySearchTree();
    Bid bid;

    int choice = 0;
    while (choice != 9) {
        cout << "\n  1. Load Data Structure" << endl;
        cout << "  2. Print Course List" << endl;
        cout << "  3. Print Course" << endl;
        cout << "  9. Exit \n" << endl;
        cout << "What would you like to do?  ";
        cin >> choice;
        if ((choice != 1) && (choice != 2) && (choice != 3) && (choice != 9) && (choice != 0))
            cout << "That is not a valid option.\n" << endl;
       
        switch (choice) {

        case 1:      
            // Complete the method call to load the bids
            loadBids(filePath, bst);
            break;

        case 2:
            cout << "Here is an example schedule : \n\n";
            bst->InOrder();
            break;

        case 3:
            cout << "What course would you like to know about?  ";
            cin >> bidKey;
            bid = bst->Search(bidKey);

            if (!bid.bidId.empty()) {
                displayBid(bid);
            } else {
            	cout << "Course " << bidKey << " not found." << endl;
            }
            break;
        }
    }

    cout << "Thank you for using the course planner!" << endl;

	return 0;
}
