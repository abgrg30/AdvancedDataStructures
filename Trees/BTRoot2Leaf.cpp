#include<iostream>
#include<queue>
using namespace std;

struct node
{
    int data;
    node* left;
    node* right;

    node(int d)
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

void del(node* ptr)
{
    if(ptr)
    {
        del(ptr->left);
        del(ptr->right);
        delete ptr;
    }
}

vector<node*> q;

void printqueue()
{
    vector<node*>::iterator i;

    for(i=q.begin();i!=q.end();i++)
    {
        cout<<(*i)->data;
    }

    cout<<endl;
}

void roottoleaf(node* ptr)
{
    if(ptr)
    {
        q.push_back(ptr);

        if(!ptr->left && !ptr->right)
        {
            printqueue();
            q.pop_back();
        }
        else
        {
            roottoleaf(ptr->left);
            roottoleaf(ptr->right);
            q.pop_back();
        }
    }
}

int main()
{
    node* root = new node(10);
    root->left = new node(8);
    root->right = new node(2);
    root->right->left = new node(2);
    root->left->right = new node(5);
    root->left->left = new node(3);

    roottoleaf(root);

    del(root);
    return 0;
}
