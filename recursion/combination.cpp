#include<bits/stdc++.h>

using namespace std;

vector<int> inc(100,0);

void search(vector<int> &a,vector<int> &c,int n,int k)
{
    if(c.size()==k)
    { 
        for(int i=0;i<k;i++)
        cout<<c[i]<<" ";
        cout<<"\n";
        
    }
    else
    {
        int j=n-1;
        while(!inc[j])
        {
            j--;
        }
        for(int i=j+1;i<n;i++)
        {
            if(!inc[i])
            {
                inc[i]=1;
                c.push_back(a[i]);
                search(a,c,n,k);
                c.pop_back();
                inc[i]=0;
            }
        }
    }
}

int main()
{
    int n,k;
    cin>>n>>k;
    vector<int> a(n),c;
    for(int i=0;i<n;i++)
    {
        cin>>a[i];
    }
    search(a,c,n,k);
}