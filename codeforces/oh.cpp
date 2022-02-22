
#include <bits/stdc++.h> 
 
using namespace std;
 
 
typedef long long ll;
typedef pair<ll,ll> pr;
 
 
ll mridul=LLONG_MAX;
ll mod= 1e9+7;
vector<int> adj[100001];
vector<bool> visited(100001,false);
vector<ll> prime;
vector<ll> no(10000);
 
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

// void sieve()
// {
    
//     bool vis[10001];

//     memset(vis, true, sizeof(vis));
 
//     for (ll p = 2; p * p <= 10000; p++)
//     {
        
//         if (vis[p] == true)
//         {
            
//             for (ll i = p * p; i <= 10000; i += p)
//                 vis[i] = false;
//         }
//     }
 
    
//     for (ll p = 2; p <= 10000; p++)
//         if (vis[p])
//            prime.push_back(p);
// }
       
// }
 
// bool check_prime(ll n)
// {
//     for(ll i=2;i*i<=n;i++)
//     {
//         if(n%i==0)
//         return false;
//     }
//     return true;
// }

void solve()
{
    ll n,k;
    cin>>n;
    string s;
    cin>>s;
    if(s[0]=='0' || s[1]=='0' || s[n]=='0')
    {
        cout<<"No\n";
        return;
    }
    cout<<"Yes\n";
    vector<ll> a(n);
    a[0]=0;
    a[1]=1;
    for(int i=2;i<n;i++)
    {
        a[i]=i;
        if(s[i]=='0')
        {
            swap(a[i],a[i-1]);
        }
    }
    for(auto x:a)
    cout<<x<<" ";
    cout<<"\n";
}    
int main() {
    ios::sync_with_stdio(0);
    cin.tie(NULL);
	int t=1;
     //sieve();
    cin>>t;
    while(t--)
    {
       solve();
    }    
}