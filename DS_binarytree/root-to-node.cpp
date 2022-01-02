// C++ implementation to print the path from root
// to a given node in a binary tree
#include <bits/stdc++.h>
using namespace std;

// structure of a node of binary tree
struct Node
{
    int data;
    Node *left, *right;
};

/*
   Helper function that allocates a new node with the
   given data and NULL left and right pointers.
*/
struct Node *getNode(int data)
{
    struct Node *newNode = new Node;
    newNode->data = data;
    newNode->left = newNode->right = NULL;
    return newNode;
}

// Returns true if there is a path from root
// to the given node. It also populates
// 'arr' with the given path
bool hasPath(Node *root, vector<int> &arr, int x)
{
    if (!root)
        return false;

    arr.push_back(root->data);

    if (root->data == x)
        return true;
    else if (!hasPath(root->left, arr, x) && !hasPath(root->right, arr, x))
    {
        arr.pop_back();
        return false;
    }
    else
    {
        return true;
    }
}

// function to print the path from root to the
// given node if the node lies in the binary tree
void printPath(Node *root, int x)
{
    // vector to store the path
    vector<int> arr;

    // if required node 'x' is present
    // then print the path
    if (hasPath(root, arr, x))
    {
        for (int i = 0; i < arr.size() - 1; i++)
            cout << arr[i] << "->";
        cout << arr[arr.size() - 1];
    }

    // 'x' is not present in the binary tree
    else
        cout << "No Path";
}

// Driver program to test above
int main()
{
    // binary tree formation
    struct Node *root = getNode(1);
    root->left = getNode(2);
    root->right = getNode(3);
    root->left->left = getNode(4);
    root->left->right = getNode(5);
    root->right->left = getNode(6);
    root->right->right = getNode(7);

    int x = 5;
    printPath(root, x);
    return 0;
}