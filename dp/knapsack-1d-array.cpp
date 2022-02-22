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
    cin>>a[i].first;
    for(int i=0;i<n;i++)
    cin>>a[i].second;
    vector<ll> dp(w+1,0);
    for(int i=0;i<n;i++)
    {
        for(int j=w;j>=0;j--)
        {
            
            if(a[i].first<=j)
            {
               // cout<<a[i].second+dp[j-a[i].first]<<"\n";
                dp[j]=max(dp[j],a[i].second+dp[j-a[i].first]);
            }
        }
       // cout<<dp[w]<<"\n";
    }
    cout<<dp[w];
}