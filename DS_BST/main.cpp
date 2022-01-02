#include <iostream>
using namespace std;

class BSTNode
{
public:
    int data;
    BSTNode *l;
    BSTNode *r;
    BSTNode(int data)
    {
        this->data = data;
        l = NULL;
        r = NULL;
    }
    ~BSTNode()
    {
        delete l;
        delete r;
    }
};

class BST
{
public:
    BSTNode *head;
    BST()
    {
        head = NULL;
    }
    ~BST()
    {
        delete head;
    }
    void insert(int);
    void del(int);
    bool has(int);
    void inOrder(BSTNode *);
};

BSTNode *insert_recursive(BSTNode *head, int data)
{

    if (head == NULL)
    {
        BSTNode *newNode = new BSTNode(data);
        return newNode;
    }
    if (data < head->data)
        head->l = insert_recursive(head->l, data);
    if (data > head->data)
        head->r = insert_recursive(head->r, data);
    return head;
}

void BST::insert(int data)
{
    head = insert_recursive(head, data);
}

void BST::inOrder(BSTNode *head)
{
    if (head == NULL)
    {
        return;
    }
    inOrder(head->l);
    cout << head->data << " ";
    inOrder(head->r);
}

BSTNode *getMin(BSTNode *root)
{
    if (root == NULL)
        return root;
    if (root->l)
    {
        return getMin(root->r);
    }
    else
    {
        return root;
    }
}

BSTNode *delete_node(BSTNode *root, int x)
{
    if (root == NULL)
        return NULL;
    else if (x > root->data)
    {
        root->r = delete_node(root->r, x);
    }
    else if (x < root->data)
    {
        root->l = delete_node(root->l, x);
    }
    else if (x == root->data)
    {
        if (root->l && root->r)
        {
            BSTNode *rightMin = getMin(root->r);
            root->data = rightMin->data;
            root->r = delete_node(root->r, rightMin->data);
        }
        else if (root->l)
        {
            return root->l;
        }
        else if (root->r)
        {
            return root->r;
        }
        else
        {
            delete root;
            return NULL;
        }
    }
    return root;
}

int main()
{
    BST b;
    // values 80, 35, 60, 50, 90, 40, 85, 30, 70
    b.insert(80);
    b.insert(35);
    b.insert(60);
    b.insert(50);
    b.insert(90);
    b.insert(85);
    b.insert(30);
    b.insert(40);
    b.insert(70);

    cout << "Initial BST\n";
    b.inOrder(b.head);

    // Delete 85
    cout << "\n\nBST after deleting 85\n";
    delete_node(b.head, 85);
    b.inOrder(b.head);

    // Insert 45
    b.insert(45);

    // inOrder of BST is sorted
    cout << "\n\nBST after inserting 45\n";
    b.inOrder(b.head);
    cout << "\n\nBy: Rhythm Shandlya\n";
    cout << "Eroll: 9920103062\n";
    return 0;
}