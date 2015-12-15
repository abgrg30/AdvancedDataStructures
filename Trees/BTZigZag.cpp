#include<iostream>
#include<stack>
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

void zigzag(node* ptr)
{
    if(ptr)
    {
        stack<node*> s1;
        stack<node*> s2;
        node* temp = NULL;

        s1.push(ptr);

        while(!s1.empty() || !s2.empty())
        {
            while(!s1.empty())
            {
                temp = s1.top();
                cout<<temp->data;
                s1.pop();

                if(temp->right)
                {
                    s2.push(temp->right);
                }
                if(temp->left)
                {
                    s2.push(temp->left);
                }
            }

            cout<<endl;

            while(!s2.empty())
            {
                temp = s2.top();
                cout<<temp->data;
                s2.pop();

                if(temp->left)
                {
                    s1.push(temp->left);
                }
                if(temp->right)
                {
                    s1.push(temp->right);
                }
            }

            cout<<endl;
        }
    }
    else
    {
        cout<<"\n Tree Empty! \n";
    }
}

int main()
{
    node* root = new node(1);
    root->left = new node(2);
    root->right = new node(3);
    root->right->right = new node(4);
    root->right->left = new node(5);
    root->left->right = new node(6);
    root->left->left = new node(7);

    zigzag(root);

    del(root);
    return 0;
}
