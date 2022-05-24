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
        ans.push_back(s[k]);
        generate(s,ans,n,k+1);
        if(s[k]>=97 && s[k]<=122)
        {
            ans.pop_back();
            ans.push_back(s[k]-32);
            generate(s,ans,n,k+1);
        }
        else if(s[k]>=65 && s[k]<=90)
        {
            ans.pop_back();
            ans.push_back(s[k]+32);
            generate(s,ans,n,k+1);
        }
        ans.pop_back();
    }
}

int main()
{
    string s,ans;
    cin>>s;
    int n=s.size();
    generate(s,ans,n,0);
}