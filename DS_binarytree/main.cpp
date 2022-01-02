#include <iostream>
#include <vector>
#include <string>
#include <cmath>

using namespace std;

template <typename T>
class BTNode
{
public:
    T data;
    BTNode *l;
    BTNode *r;
    BTNode(T data)
    {
        this->data = data;
        l = NULL;
        r = NULL;
    }
    ~BTNode()
    {
        delete l;
        delete r;
    }
};

template <typename N>
class BinaryTree
{
    BTNode<N> *head;

public:
    void level_wise_input();
};

template <typename T>
void BinaryTree<T>::level_wise_input()
{
    if (head != NULL)
        return;
    int data;
    cin << data;
    BTNode head = new BTNode();
}

int main()
{

    return 0;
}