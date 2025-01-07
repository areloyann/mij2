#include <iostream>
using namespace std;

// Node structure for the Binary Search Tree
class Node {
public:
    int data;   // Data stored in the node
    Node* left; // Pointer to the left child
    Node* right; // Pointer to the right child

    Node(int value) {
        data = value;
        left = right = nullptr;
    }
};

// Binary Search Tree class
class BinarySearchTree {
private:
    Node* root; // Root of the tree

    // Recursive function to insert a node in the tree
    Node* insert(Node* root, int value) {
        if (root == nullptr) {
            return new Node(value); // Create a new node if root is null
        }

        // Recursively insert in the left or right subtree
        if (value < root->data) {
            root->left = insert(root->left, value);
        } else {
            root->right = insert(root->right, value);
        }

        return root;
    }

    // Recursive function for in-order traversal
    void inorderTraversal(Node* root) {
        if (root != nullptr) {
            inorderTraversal(root->left); // Traverse the left subtree
            cout << root->data << " "; // Print the node's data
            inorderTraversal(root->right); // Traverse the right subtree
        }
    }

    // Recursive function to search for a value in the tree
    Node* search(Node* root, int value) {
        if (root == nullptr || root->data == value) {
            return root; // Return node if found or null if not found
        }

        // Recur on the left or right subtree depending on the value
        if (value < root->data) {
            return search(root->left, value);
        } else {
            return search(root->right, value);
        }
    }

public:
    // Constructor to initialize the tree
    BinarySearchTree() {
        root = nullptr;
    }

    // Insert a new value into the tree
    void insert(int value) {
        root = insert(root, value);
    }

    // Perform in-order traversal and print the tree
    void inorderTraversal() {
        inorderTraversal(root);
        cout << endl;
    }

    // Search for a value in the tree
    bool search(int value) {
        Node* result = search(root, value);
        return result != nullptr; // Return true if found, false otherwise
    }
};

int main() {
    BinarySearchTree bst;

    // Insert values into the binary search tree
    bst.insert(50);
    bst.insert(30);
    bst.insert(20);
    bst.insert(40);
    bst.insert(70);
    bst.insert(60);
    bst.insert(80);

    // Perform in-order traversal (should print the sorted order)
    cout << "In-order traversal: ";
    bst.inorderTraversal(); // Output: 20 30 40 50 60 70 80

    // Search for a value in the tree
    cout << "Searching for 40: " << (bst.search(40) ? "Found" : "Not Found") << endl; // Output: Found
    cout << "Searching for 25: " << (bst.search(25) ? "Found" : "Not Found") << endl; // Output: Not Found

    return 0;
}
