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

int NodeLevel(node* root, int key, int level=0)
{
    if(root == NULL)
    {
        return 0;
    }
    else
    {
        level++;

        if(key == root->data)
        {
            return level;
        }
        else
        {
            int ll = NodeLevel(root->left, key, level);

            if(ll)
            {
                return ll;
            }
            else
            {
                int lr = NodeLevel(root->right, key, level);

                if(lr)
                {
                    return lr;
                }
                else
                {
                    return 0;
                }
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

    cout<<NodeLevel(root,6)<<endl;

    deltree(root);

    return 0;
}
