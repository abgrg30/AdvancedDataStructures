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

int diameter = 0;

int treediameter(node* root)
{
    if(root == NULL)
    {
        return 0;
    }
    else
    {
        int lh = treediameter(root->left);
        int rh = treediameter(root->right);

        if(lh+rh >= diameter)
        {
            diameter = lh+rh+1;
        }

        return ((lh>rh)?lh+1:rh+1);
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

    treediameter(root);
    cout<<diameter<<endl;

    deltree(root);

    return 0;
}
