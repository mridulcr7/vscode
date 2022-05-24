#include<bits/stdc++.h>

using namespace std;

vector<int> in;

int k=1;

struct node
{
    int data;
    node* left;
    node* right;
}*root=NULL;

void inorder1(node* temp)
{
    if(temp==NULL)
    return;
   
    inorder1(temp->left);
    in.push_back(temp->data);
    inorder1(temp->right);
}

void inorder2(node* temp)
{
    if(temp==NULL)
    return;
   
    inorder2(temp->left);
    temp->data=in[k-1]+in[k+1];
    k++;
    inorder2(temp->right);
}

void inorder3(node* temp)
{
    if(temp==NULL)
    return;
   
    inorder3(temp->left);
    cout<<temp->data<<" ";
    inorder3(temp->right);
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
    inorder3(root);
    cout<<"\n";
    in.push_back(0);
    inorder1(root);
    in.push_back(0);
    inorder2(root);
    inorder3(root);
    cout<<"\n";
}