#include<bits/stdc++.h>
#include<vector>
using namespace std;
int main()
{
    string s;
    cin>>s;
    int n=s.size();
    string ans="";
    int i=0,space=1;
    while(i<n)
    {
        if(i+2<n && s[i]=='W' && s[i+1]=='U' && s[i+2]=='B')
        {
            i=i+3;
            if(space==0)
            {
                ans.push_back(' ');
                space=1;
            }
        }
        else
        {
            ans.push_back(s[i]);
            i++;
            space=0;
        }
    }
    cout<<ans<<"\n";
}