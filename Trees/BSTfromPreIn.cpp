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

int searchin(int key, int in[], int start, int finish)
{
    if(finish < start)
    {
        return -1;
    }

    for(int i=start;i<=finish;i++)
    {
        if(key == in[i])
        {
            return i;
        }
    }

    return -1;
}

node* maketree(int in[], int pre[], int start, int finish)
{
    static int precount = 0;

    if(finish < start)
    {
        return NULL;
    }
    else
    {
        node* ptr = gettreenode(pre[precount++]);

        if(start == finish)
        {
            return ptr;
        }
        else
        {
            int inpos = searchin(ptr->data, in, start, finish);
            ptr->left = maketree(in,pre,start,inpos-1);
            ptr->right = maketree(in,pre,inpos+1,finish);
            return ptr;
        }
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

void postorder(node* root)
{
    if(root)
    {
        postorder(root->left);
        postorder(root->right);
        cout<<root->data<<"\t";
    }
}

int main()
{
    int in[] = {4,2,5,1,6,3};
    int pre[] = {1,2,4,5,3,6};

    int n = sizeof(in)/sizeof(int);

    node* root = maketree(in, pre, 0, n-1);

    postorder(root);
    deltree(root);

    return 0;
}
