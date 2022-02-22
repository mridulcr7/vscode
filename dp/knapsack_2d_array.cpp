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
	ll n,t,ans=INT_MIN,w;
    cin>>n>>w;
    vector<pr> a(n);
    for(int i=0;i<n;i++)
    cin>>a[i].first>>a[i].second;
    vector<vector<ll>> dp(n+1,vector<ll> (w+1,0));
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=w;j++)
        {
            if(j-a[i-1].first>=0)
            {
                dp[i][j]=max(dp[i-1][j],dp[i-1][j-a[i-1].first]+a[i-1].second);
            }
            else
            {
                dp[i][j]=dp[i-1][j];
            }
 
        }
    }
    cout<<dp[n][w];
}