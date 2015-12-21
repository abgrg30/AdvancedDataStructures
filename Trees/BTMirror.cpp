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

void mirror(node* root)
{
    if(root == NULL)
    {
        return;
    }
    else
    {
        mirror(root->left);
        mirror(root->right);
        node* temp = root->left;
        root->left = root->right;
        root->right = temp;
    }
}

void inorder(node* root)
{
    if(root == NULL)
    {
        return;
    }
    else
    {
        inorder(root->left);
        cout<<root->data<<"\t";
        inorder(root->right);
    }
}

int main()
{
    node* root = gettreenode(20);
    root->left = gettreenode(8);
    root->right = gettreenode(22);
    root->right->right = gettreenode(25);
    root->left->left = gettreenode(5);
    root->left->right = gettreenode(3);
    root->left->right->left = gettreenode(10);
    root->left->right->right = gettreenode(14);

    inorder(root);
    cout<<endl;
    mirror(root);
    inorder(root);
    cout<<endl;
    mirror(root);
    inorder(root);

    deltree(root);

    return 0;
}
