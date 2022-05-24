#include<bits/stdc++.h>

using namespace std;

void insert(stack<int> &a,int k)
{
    if(a.empty())
    {
        a.push(k);
        return;
    }

    int m=a.top();
    a.pop();

    insert(a,k);

    a.push(m);
}

void reverse(stack<int> &a)
{
    if(a.empty())
    {
        return;
    }

    int m=a.top();
    a.pop();

    reverse(a);

    insert(a,m);
}



int main()
{
    stack<int> a;
    a.push(6);
    a.push(2);
    a.push(5);
    a.push(1);
    a.push(4);
    a.push(3);
   // cout<<a.size();
    reverse(a); 
    while(!a.empty())
    {
        cout<<a.top()<<" ";
        a.pop();
    }
}