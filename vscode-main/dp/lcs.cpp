#include <bits/stdc++.h> 

using namespace std;


typedef long long ll;
typedef pair<ll,ll> pr;


ll mridul=LLONG_MAX;
ll mod= 1e9+7;
vector<int> adj[100001];
vector<bool> visited(100001,false);


int main() {
    ios::sync_with_stdio(0);
    cin.tie(NULL);
	string s,t;
    cin>>s>>t;

    vector<vector<ll>> dp(s.size()+1,vector<ll>(t.size()+1,0));
    vector<vector<ll>> idx(s.size()+1,vector<ll>(t.size()+1,0));
    string ans="";
    for(int i=1;i<=s.size();i++)
    {
        for(int j=1;j<=t.size();j++)
        {
            if(s[i-1]==t[j-1])
            {
                dp[i][j]=dp[i-1][j-1]+1;
                idx[i][j]=1;
            }
            else
            {
                dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
                if(dp[i-1][j]>dp[i][j-1])
                idx[i][j]=2;
                else
                idx[i][j]=3;
            }
        }
    }
    //cout<<dp[s.size()][t.size()]<<"\n";
    ll i=s.size(),j=t.size();
    while(idx[i][j]!=0)
    {
        if(idx[i][j]==1)
        {
            ans=ans+s[i-1];
            i=i-1;
            j=j-1;
        }
        else if(idx[i][j]==2)
        {
            i=i-1;
        }
        else if(idx[i][j]==3)
        {
            j=j-1;
        }

    }
    reverse(ans.begin(),ans.end());
    cout << "matching words in the name\n";
    cout << ans << "\n";
}