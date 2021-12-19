#include<bits/stdc++.h>

using namespace std;

vector<int> in,pre;

int k=0;

struct node
{
    int data;
    node* left;
    node* right;
}*root=NULL;

void print_post_order(int x,int l,int h)
{
    if(l>h)
    {
        k--;
        return;
    }
    int i;
    for(i=l;i<=h;i++)
    {
        if(in[i]==x)
        break;
    }
    k++;
    print_post_order(pre[k],l,i-1);
    k++;
    print_post_order(pre[k],i+1,h);
    cout<<x<<" ";
}

void inorder(node* temp)
{
    if(temp==NULL)
    return;
   
    inorder(temp->left);
     in.push_back(temp->data);
    inorder(temp->right);
}

void preorder(node* temp)
{
    if(temp==NULL)
    return;
   
    pre.push_back(temp->data);
    preorder(temp->left);
    preorder(temp->right);
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
    inorder(root);
    preorder(root);
    int l=0,h=in.size();
    cout<<h<<"\n";
    for(int i=0;i<h;i++)
    cout<<in[i]<<" ";
    cout<<"\n";
    for(int i=0;i<h;i++)
    cout<<pre[i]<<" ";
    cout<<"\n";
    print_post_order(pre[k],l,h-1);

}