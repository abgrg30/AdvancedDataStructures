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

int treesize(node* root)
{
    if(root == NULL)
    {
        return 0;
    }
    else
    {
        return treesize(root->left) + 1 + treesize(root->right);
    }
}

void printarr(int arr[], int start, int finish)
{
    for(int i=start;i<=finish;i++)
    {
        cout<<arr[i]<<"\t";
    }
    cout<<endl;
}

void root2leaf(node* root, int arr[], int pos)
{
    if(root == NULL)
    {
        return;
    }
    else
    {
        if(root->left == NULL && root->right == NULL)
        {
            arr[pos] = root->data;
            printarr(arr,0,pos);
        }
        else
        {
            arr[pos] = root->data;
            root2leaf(root->left,arr,pos+1);
            root2leaf(root->right,arr,pos+1);
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

    int n = treesize(root);
    //cout<<n<<endl;

    int arr[n];

    for(int i=0; i<n; i++)
    {
        arr[i] = 0;
    }

    root2leaf(root,arr,0);

    deltree(root);

    return 0;
}
