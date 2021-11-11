#include<bits/stdc++.h>

using namespace std;

void generate(vector<int> &a,vector<int> &c,int n,int k)
{
    if(k==n)
    {

    }
    else
    {
        c.push_back(a[k++]);
        generate(a,c,n,k);

    }
}

int main()
{
    int n;
    cin>>n;
    vector<int> a(n),c;
    for(int i=0;i<n;i++)
    {
        cin>>a[i];
    }
    generate(a,c,n,0);
}