// The idea is to calculate, for each array position, the maximum sum of a subarray that ends at that position.


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
	ll n,ans=LLONG_MIN;
    cin>>n;
    vector<ll> a(n),dp(n,0);
    for(int i=0;i<n;i++)
    {
        cin>>a[i];
    }
    dp[0]=a[0];
    ans=dp[0];
    for(int i=1;i<n;i++)
    {
        dp[i]=max(a[i],a[i]+dp[i-1]);
        ans=max(dp[i],ans);
    }
    cout<<ans<<"\n";
}