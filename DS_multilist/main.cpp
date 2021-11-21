#include <iostream>
#include <vector>
#include <string>
#include <cmath>

using namespace std;

class Node
{
public:
    int data;
    Node *next;
    Node *down;

    Node(int data, Node *next = NULL, Node *down = NULL)
    {
        this->data = data;
        this->next = next;
        this->down = down;
    }
};
class MultiList
{
    Node *head;
    MultiList()
    {
        head = NULL;
    }
    MultiList(int data)
    {
        head = new Node(data);
    }
    Node *getHead()
    {
        return head;
    }
    void insertList(Node *, vector<int>);
    void makeList(vector<int>);
};

void MultiList::insertList(Node *node, vector<int> vec)
{
    node->data = vec[0];
    for (int i = 1; i < vec.size(); i++)
    {
        Node *newNode = new Node(vec[i]);
        node->down = newNode;
        node = newNode;
    }
}
void MultiList::makeList(vector<int> vec)
{
    head->data = vec[0];
    Node *temp = head;
    for (int i = 1; i < vec.size(); i++)
    {
        Node *newNode = new Node(vec[i]);
        temp->next = newNode;
        temp = newNode;
    }
}

int main()
{

    return 0;
}