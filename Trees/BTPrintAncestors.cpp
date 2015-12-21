#include<iostream>
using namespace std;

struct node
{
    int data;
    node* left;
    node* right;

    node(int d): data(0)
    {
        data = d;
        left = NULL;
        right = NULL;
    }

    ~node()
    {
        data = 0;
        left = NULL;
        right = NULL;
    }
};

node* gettreenode(int data)
{
    try
    {
        node* ptr = new node(data);
        cout<<"Node "<<data<<" Created!!\n";
        return ptr;
    }
    catch(...)
    {
        cout<<"EXCEPTION : Node Creation Failed!!\n";
        return NULL;
    }
}

void deltree(node* root)
{
    if(root)
    {
        deltree(root->left);
        deltree(root->right);
        cout<<"\nNode "<<root->data<<" deleted";
        delete root;
    }
    else
    {
        return;
    }
}

bool printancestors(node* root, int key)
{
    if(root == NULL)
    {
        return false;
    }

    if(key == root->data)
    {
        return true;
    }

    if(printancestors(root->left, key) || printancestors(root->right, key))
    {
        cout<<root->data<<"\t";
        return true;
    }

    return false;
}

int main()
{
    node* root = gettreenode(1);
    root->left = gettreenode(2);
    root->right = gettreenode(3);
    root->left->left = gettreenode(4);
    root->left->right = gettreenode(5);
    root->left->left->left = gettreenode(7);

    printancestors(root, 7);

    deltree(root);

    return 0;
}
