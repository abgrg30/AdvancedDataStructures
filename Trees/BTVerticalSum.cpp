#include<iostream>
#include<map>
#include<queue>
using namespace std;

map< int,int > m;

struct treenode
{
    int data;
    treenode* left;
    treenode* right;

    treenode(int d)
    {
        data = d;
        left = NULL;
        right = NULL;
    }

    ~treenode()
    {
        data = 0;
        left = NULL;
        right = NULL;
    }
};

void deltree(treenode* p)
{
    if(p)
    {
        deltree(p->left);
        deltree(p->right);
        //cout<<endl<<"deleting "<<p->data<<endl;
        delete p;
    }
}

void logic(treenode* p, int state)
{
    if(p)
    {
        m[state] += (p->data);
        logic(p->left, state-1);
        logic(p->right, state+1);
    }
}

int main()
{
    treenode* root = new treenode(1);
    root->left = new treenode(2);
    root->right = new treenode(3);
    root->left->left = new treenode(4);
    root->left->right = new treenode(5);
    root->right->left = new treenode(6);
    root->right->right = new treenode(7);
    root->right->left->right = new treenode(8);
    root->right->right->right = new treenode(9);

    logic(root,0);

    map< int,int >::iterator it;

    for(it = m.begin(); it != m.end(); it++)
    {
        //cout<<endl<<it->first<<endl;
        cout<<it->second<<endl;
    }

    deltree(root);
    return 0;
}
