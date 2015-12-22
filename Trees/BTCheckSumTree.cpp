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

bool CheckSumTree(node* root)
{
    if(root == NULL || (root->left == NULL && root->right == NULL))
    {
        return true;
    }
    else
    {
        if(CheckSumTree(root->left) && CheckSumTree(root->right))
        {
            int ll=0, lr=0;

            if(root->left)
            {
                ll = root->left->data;
            }

            if(root->right)
            {
                lr = root->right->data;
            }

            if(ll+lr == root->data)
            {
                return true;
            }
            else
            {
                return false;
            }
        }
        else
        {
            return false;
        }
    }
}

int main()
{
    node* root = gettreenode(20);
    root->left = gettreenode(8);
    root->right = gettreenode(12);
    root->right->right = gettreenode(12);
    root->left->left = gettreenode(5);
    root->left->right = gettreenode(3);
    root->left->right->left = gettreenode(1);
    root->left->right->right = gettreenode(2);

    cout<<CheckSumTree(root)<<endl;

    deltree(root);

    return 0;
}
