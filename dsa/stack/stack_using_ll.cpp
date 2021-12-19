#include<bits/stdc++.h>

using namespace std;

class stack_node
{
    public:
    int data;
    stack_node *next;
}*top=NULL;

void push(int x)
{
    stack_node *temp=new stack_node;
    temp->data=x;
    temp->next=top;
    top=temp;
}

int pop()
{
    if(top==NULL)
    {
        cout<<"Underflow\n";
        return -1;
    }
    stack_node *temp=top;
    top=top->next;
    int x=temp->data;
    temp->next=NULL;
    delete(temp);
    return x;
}

bool empty()
{
    if(top==NULL)
    {
        return true;
    }
    else
    {
        return false;
    }
}

int peek()
{
    if(top==NULL)
    {
        return -1;
    }
    else
    {
        return top->data;
    }
}
int main()
{
    int x;
    push(10);
    push(2);
     x=peek();
    if(x!=-1)
    cout<<x<<"\n";
    x=pop();
    if(x!=-1)
    cout<<x<<"\n";
    x=pop();
    if(x!=-1)
    cout<<x<<"\n";
    x=pop();
    if(x!=-1)
    cout<<x<<"\n";
    if(empty())
    cout<<"YES\n";
    else
    cout<<"NO\n";
    push(7);
    x=peek();
    if(x!=-1)
    cout<<x<<"\n";


}