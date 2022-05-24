#include <bits/stdc++.h> 
 
using namespace std;
 
 
typedef long long ll;
typedef pair<ll,ll> pr;
 
 
ll mridul=LLONG_MAX;
ll mod= 1e9+7;
vector<int> adj[100001];
vector<bool> visited(100001,false);
 
bool compare(pair<ll,ll> &a, pair<ll,ll> &b)
{
    double a1=(1.0*a.first)/a.second;
    double a2=(1.0*b.first)/b.second;
    return a1>a2;
}
 
struct comp1{
    bool operator()(pair<ll,ll> a , pair<ll,ll> b){     
        if(a.first==b.first)
          return (a.second > b.second);
        return a.first < b.first;
    }
};    
 
 
int abs(int a,int b)
{
    if(a>b)
    return a-b;
    else
    return b-a;
} 
 
 
// int using_dfs(int current,int m)
// {
//     visited[current]=true;
//     m=min(m,a[current]);
//     for(int x:adj[current])
//     {
//        if(visited[x])
//        continue;
//        m=using_dfs(adj,a,visited,x,m); 
//     }
//     return m;
   
// }
 
int mem(int n,int t,vector<int> &a,vector<int> &dp,vector<bool> &vis)
{
    if(t==0)
    return 1;
    if(vis[t])
    return dp[t];
    int ans=0;
    for(int i=0;i<n;i++)
    {
        if(t-a[i]>=0)
        ans=(ans+mem(n,t-a[i],a,dp,vis))%mod;
    }
    vis[t]=true;
    dp[t]=ans;
    return ans;
}
 
void solve()
{
    ll n,t,c0,d0,k;
    ll m= 1e9+7;
    cin>>n>>k;
    vector<vector<ll>> a(n,vector<ll> (3,0));
    for(int i=0;i<n;i++)
    {
        cin>>a[i][0];
        ll m=a[i][0];
        while(m%2==0)
        {
            a[i][1]++;
            m=m/2;
        }
        for(ll j=3;j*j<=m;j=j+2)
        {
            while(m%j==0)
            {
                m=m/j;
                if(j==5)
                a[i][2]++;
            }
        }
        if(m==5)
        a[i][2]++;
        //cout<<a[i][0]<<" "<<a[i][1]<<" "<<a[i][2]<<"\n";
    }
   
    vector<vector<vector<ll>>> dp(n+1,vector<vector<ll>>(k+1,vector<ll>(100,-1)));
    for(int i=0;i<=n;i++)
    {
        for(int j=0;j<=k;j++)
        {
            for(int l=0;l<100;l++)
            {
                if(j==0 && l==0)
                dp[i][j][l]=0;
                if(i>0)
                {
                    if(a[i-1][2]>=l)
                    {
                        if(dp[i-1][j-1][l-a[i-1][2]]!=-1)
                        {
                            dp[i][j][l]=max(dp[i-1][j][l],dp[i-1][j-1][l-a[i-1][2]]+a[i-1][1]);
                        }
                        else
                        {
                            dp[i][j][l]=dp[i-1][j][l];
                        }
                    }
                    else
                    {
                        dp[i][j][l]=dp[i-1][j][l];
                    }
                }
            }
        }
    }
    ll ans=0;
    for(ll l=0;l<100;l++)
    {
        if(dp[n][k][l]!=-1)
        ans=max(ans,min(l,dp[n][k][l]));
    }
    cout<<ans<<"\n";
}    
int main() {
    ios::sync_with_stdio(0);
    cin.tie(NULL);
	int t=1;
    //cin>>t;
    while(t--)
    {
       solve();
    }    
}