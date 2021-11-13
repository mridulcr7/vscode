#include<bits/stdc++.h>

using namespace std;

void generate(vector<int> &a,vector<int> &c,int n,int k)
{
    if(k==n)
    {
        int m=c.size();
        if(m==0)
        {
            cout<<"NULL\n";
            return;
        }
       // cout<<m<<" ";
        for(int i=0;i<m;i++)
        cout<<c[i]<<" ";
        cout<<"\n";
        
    }
    else
    {
        c.push_back(a[k]);
        generate(a,c,n,k+1);
      //  cout<<"Deleted element-"<<a[k]<<"\n";
        c.pop_back();
        generate(a,c,n,k+1);
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