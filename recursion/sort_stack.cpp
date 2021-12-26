#include<bits/stdc++.h>

using namespace std;

void insert(stack<int> &a,int k)
{
    if(a.empty() || a.top()<=k)
    {
        a.push(k);
        return;
    }

    int m=a.top();
    a.pop();

    insert(a,k);

    a.push(m);
}

void sort(stack<int> &a)
{
    if(a.size()==1)     // Base case
    {
        return;
    }

    int k=a.top();
    a.pop();

    sort(a);  // hypothesis

    insert(a,k);  //induction

    
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
    sort(a); 
    while(!a.empty())
    {
        cout<<a.top()<<" ";
        a.pop();
    }
}