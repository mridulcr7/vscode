#include<bits/stdc++.h>

using namespace std;

struct node
{
    int data;
    node* left;
    node* right;
}*root=NULL;

void inorder(node* temp)
{
    if(temp==NULL)
    return;
   
    inorder(temp->left);
     cout<<temp->data<<" ";
    inorder(temp->right);
}

void inorder_stack()
{
    node*temp=root;
    stack<node*> a;
    a.push(temp);
    temp=temp->left;
    while(!a.empty() || temp!=NULL)
    {
        if(temp!=NULL)
        {
            a.push(temp);
            temp=temp->left;
        }
        else
        {
            cout<<a.top()->data<<" ";
            temp=a.top()->right;
            a.pop();
        }
    }
}



void create_bt()
{
    int t;
    queue<node*> a; 
    cout<<"Enter data\n";
    cin>>t;
    if(t==-1)
    return;
    node* temp=new node;
    temp->data=t;
    temp->left=NULL;
    temp->right=NULL;
    root=temp;
    a.push(root);
    while(!a.empty())
    {
        cin>>t;
        if(t!=-1)
        {
            node* temp=new node;
            temp->data=t;
            temp->left=NULL;
            temp->right=NULL;
            a.front()->left=temp;
            a.push(temp);
        }
        cin>>t;
        if(t!=-1)
        {
            node* temp=new node;
            temp->data=t;
            temp->left=NULL;
            temp->right=NULL;
            a.front()->right=temp;
            a.push(temp);
        }
        a.pop();
    }
}

int main()
{
    create_bt();
   // cout<<root->data;
    // inorder(root);
    // cout<<"\n";
    inorder_stack();
}