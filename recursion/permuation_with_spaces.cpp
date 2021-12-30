#include<bits/stdc++.h>

using namespace std;

void generate(string &s,string &ans,int n,int k)
{
    if(k==n)
    {
        int m=ans.size();
       // cout<<m<<" ";
        for(int i=0;i<m;i++)
        cout<<ans[i];
        cout<<"\n";
        
    }
    else
    {
        ans.push_back(' ');
        ans.push_back(s[k]);
        generate(s,ans,n,k+1);
        ans.pop_back();
        ans.pop_back();
        ans.push_back(s[k]);
        generate(s,ans,n,k+1);
        ans.pop_back();
    }
}

int main()
{
    string s,ans;
    cin>>s;
    ans.push_back(s[0]);
    int n=s.size();
    generate(s,ans,n,1);
}