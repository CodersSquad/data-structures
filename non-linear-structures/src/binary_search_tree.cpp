#include <iostream>
using namespace std;

struct Node {
    int key;
    Node* left;
    Node* right;    
    Node(int item) {
        key = item;
        left = NULL;
        right = NULL;
    }
};

// A utility function to insert a new node with 
// the given key
Node* insert(Node* node, int key) {
  
    // If the tree is empty, return a new node
    if (node == NULL) 
        return new Node(key);    
    
    // If the key is already present in the tree,
    // return the node
    if (node->key == key) 
        return node;
    
    // Otherwise, recur down the tree/ If the key
    // to be inserted is greater than the node's key,
    // insert it in the right subtree
    if (node->key < key) 
        node->right = insert(node->right, key);
    
    // If the key to be inserted is smaller than 
    // the node's key,insert it in the left subtree
    else 
        node->left = insert(node->left, key);
    
    // Return the (unchanged) node pointer
    return node;
}


// Function to find the in-order successor (smallest in right subtree)
Node* findMin(Node* node) {
    Node* current = node;
    while (current && current->left != nullptr) {
        current = current->left;
    }
    return current;
}

// Function to delete a node from the BST
Node* deleteNode(Node* root, int key) {
    // Base case: tree is empty or key not found
    if (root == nullptr) {
        return root;
    }

    // Traverse the tree to find the node to delete
    if (key < root->key) {
        root->left = deleteNode(root->left, key);
    } else if (key > root->key) {
        root->right = deleteNode(root->right, key);
    } else { // Node with the key is found
        // Case 1: Node with 0 or 1 child
        if (root->left == nullptr) {
            Node* temp = root->right;
            delete root;
            return temp;
        } else if (root->right == nullptr) {
            Node* temp = root->left;
            delete root;
            return temp;
        }

        // Case 2: Node with two children
        Node* temp = findMin(root->right); // Find in-order successor
        root->key = temp->key;          // Copy successor's key
        root->right = deleteNode(root->right, temp->key); // Delete successor
    }
    return root;
}

// Function to search for a value in the BST
Node* search(Node* root, int val) {
    // Base case: If the tree is empty or the value is found at the root
    if (root == nullptr || root->key == val) {
        return root;
    }

    // If the value is less than the root's data, search in the left subtree
    if (val < root->key) {
        return search(root->left, val);
    } 
    // If the value is greater than the root's data, search in the right subtree
    else {
        return search(root->right, val);
    }
}


// A utility function to do inorder tree traversal
void inorder(Node* root) {
    if (root != NULL) {
        inorder(root->left);
        cout << root->key << ",";
        inorder(root->right);
    }
}

// Driver program to test the above functions
int main() {
    // Creating the following BST
    //      50
    //     /  \
    //    30   70
    //   / \   / \
    //  20 40 60 80

    Node* root = new Node(50);
    root = insert(root, 30);
    root = insert(root, 20);
    root = insert(root, 40);
    root = insert(root, 70);
    root = insert(root, 60);
    root = insert(root, 80);
    root = deleteNode(root, 70);

    // Print inorder traversal of the BST
    inorder(root);

    return 0;
}
