
// node has child less than 2 it will be 1 ,2 or NULL
#include <bits/stdc++.h>

using namespace std;

template <typename T>

class binaryTreeNode
{
public:
    T data;
    binaryTreeNode<T> *left;
    binaryTreeNode<T> *right;
    // constructor
    binaryTreeNode(T data)
    {
        this->data = data;
        left = NULL;
        right = NULL;
    }
    // deconstructor
    ~binaryTreeNode()
    {
        delete left;
        delete right;
    }
};
// taking input in the tree
binaryTreeNode<int> *levelWiseInput()
{
    queue<binaryTreeNode<int> *> pendingNode;

    cout << "enter the root data " << endl;

    int rootdata;

    cin >> rootdata;

    binaryTreeNode<int> *root = new binaryTreeNode<int>(rootdata);

    pendingNode.push(root);

    while (pendingNode.size() != 0)

    {

        binaryTreeNode<int> *current = pendingNode.front();

        pendingNode.pop();

        // take element in left child

        cout << "enter the left child data of " << current->data << endl;

        int leftchilddata;

        cin >> leftchilddata;

        if (leftchilddata != -1)
        {
            binaryTreeNode<int> *leftchild = new binaryTreeNode<int>(leftchilddata);

            current->left = leftchild;

            pendingNode.push(leftchild);
        }

        // taking element in right child

        cout << "enter the right child data " << current->data << endl;

        int rightchilddata;

        cin >> rightchilddata;

        if (rightchilddata != -1)
        {
            binaryTreeNode<int> *rightchild = new binaryTreeNode<int>(rightchilddata);

            current->right = rightchild;

            pendingNode.push(rightchild);
        }
    }
    return root;
}

// string tobeprinted;
void printLevelWise(binaryTreeNode<int> *root)
{
    queue<binaryTreeNode<int> *> pending;
    pending.push(root);
    while (pending.size() != 0)
    {
        binaryTreeNode<int> *front = pending.front();
        pending.pop();
        cout << front->data << ":";
        if (front->left)
        {
            pending.push(front->left);
            cout << "L:" << front->left->data;
        }
        else
        {
            cout << "L: -1";
        }
        cout << ",";
        if (front->right)
        {
            pending.push(front->right);
            cout << "R:" << front->right->data << endl;
        }
        else
        {
            cout << "R:-1" << endl;
        }
    }
}
int main()
{
    binaryTreeNode<int> *root = levelWiseInput();
    cout << "total number of element in the tree is" << endl;
    printLevelWise(root);
}
