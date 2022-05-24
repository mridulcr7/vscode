#include<bits/stdc++.h>

using namespace std;

void print(int n)
{
    if (n==0)
    {
        return;
    }
    for(int i=1;i<=n;i++)
    {
        cout<<i<<" ";
    }
    cout<<"\n";
    print(n-1);
    
}

int main()
{
    int n=5;
    print(n);
}