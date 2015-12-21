#include<iostream>
#include<map>
#include<queue>
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

struct event
{
    node* address;
    int h;

    event()
    {
        address = NULL;
        h = 0;
    }

    ~event()
    {
        address = NULL;
        h = 0;
    }
};

map<int,int> m;
queue<event> q;

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

void bottomview(node* root, int h)
{
    if(root == NULL)
    {
        return;
    }
    else
    {
        event e,e1;
        e.address = root;
        e.h = h;
        q.push(e);
        //e.address = NULL;
        //q.push(e);
        while(!q.empty())
        {
            e = q.front();
            q.pop();

            m[e.h] = (e.address)->data;

            if((e.address)->left)
            {
                e1.address = (e.address)->left;
                e1.h = (e.h)-1;
                q.push(e1);
            }

            if((e.address)->right)
            {
                e1.address = (e.address)->right;
                e1.h = (e.h)+1;
                q.push(e1);
            }
        }
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

    bottomview(root, 0);

    map<int,int>::iterator i;

    for(i = m.begin();i!=m.end();i++)
    {
        cout<<i->second<<"\t";
    }

    deltree(root);

    return 0;
}
