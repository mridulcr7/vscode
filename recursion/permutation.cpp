#include<bits/stdc++.h>

using namespace std;

vector<int> inc(100,0);

void search(vector<int> &a,vector<int> &c,int n)
{
    int k=c.size();
    if(k==n)
    { 
        for(int i=0;i<k;i++)
        cout<<c[i]<<" ";
        cout<<"\n";
        
    }
    else
    {
        for(int i=0;i<n;i++)
        {
            if(!inc[i])
            {
                inc[i]=1;
                c.push_back(a[i]);
                search(a,c,n);
                c.pop_back();
                inc[i]=0;
            }
        }
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
    search(a,c,n);
}