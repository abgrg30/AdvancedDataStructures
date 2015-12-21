
#include<iostream>
using namespace std;

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

int logic(treenode* p, int level, int maxi)
{
    if(p)
    {
        if(level > maxi)
        {
            cout<<endl<<p->data;
            maxi = level;
        }

        maxi = logic(p->right,level+1,maxi);
        maxi = logic(p->left,level+1,maxi);
    }

    return maxi;
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
    root->left->right->left = new treenode(8);

    cout<<"\nmax level = "<<logic(root,0,-1);

    deltree(root);
    return 0;
}
