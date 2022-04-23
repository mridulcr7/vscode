#include <bits/stdc++.h> 
 
using namespace std;
 
 
typedef long long ll;
typedef pair<ll,ll> pr;
 
 
ll mridul=LLONG_MAX;
ll mod= 1e9+7;
vector<int> adj[100001];
//vector<bool> visited(100001,false);
vector<ll> prime;
vector<ll> no(10000);
vector<ll> gdb(1001,INT_MAX);
 
bool comp(const vector<ll>& v1, const vector<ll>& v2)
{
    return v1[2]<v2[2];
}

bool comp1(const pair<string,int>& v1, const pair<string,int>& v2)
{
    v1.second>v2.second;
}
 
struct comp1{
    bool operator()(pair<ll,ll> a , pair<ll,ll> b){     
        if(a.first==b.first)
          return (a.second > b.second);
        return a.first < b.first;
    }
};    
 
 
ll abs(ll a,ll b)
{
    if(a>b)
    return a-b;
    else
    return b-a;
} 
 
 
// int using_dfs(int current,int m)
// { rn m;
   
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

 
bool check_prime(ll n)
{
    for(ll i=2;i*i<=n;i++)
    {
        if(n%i==0)
        return false;
    }
    return true;
}

ll cd(ll n)
{
    ll cnt = 0;
    for (ll i = 1; i <= sqrt(n); i++) {
        if (n % i == 0) {
            // If divisors are equal,
            // count only one
            if (n / i == i)
                cnt++;
 
            else // Otherwise count both
                cnt = cnt + 2;
        }
    }
    return cnt;
}

ll rec(vector<bool> &vis,vector<ll> &d,ll n,ll m)
{
  //  cout<<"\n"<<n<<"\n";
    if(n==m)
        return d[m];
    if(vis[n])
        return d[n];
    vis[n]=true;
    if(n>m)
    {
        d[n]=1+rec(vis,d,n-1,m);
    }
    else if(n==1)
    {
        d[n]=1+rec(vis,d,2*n,m);
    }
    else
    {
        d[n]=1+min(rec(vis,d,n-1,m),rec(vis,d,2*n,m));
    }
   // cout<<n<<" "<<d[n]<<"\n";
    return d[n];
}

void solve()
{
    ll n=0,m=0,k=0,o=0,x=0,y=0,z=0,mod=1e9+7,sm=1,df=0,ans=INT_MAX,l,r;
    string s,t="",s2="",s3;
    cin>>n>>m;
    cin>>s;

    vector<string> zz ={"abc","acb","bac","bca","cab","cba"};
    // cout<<s;
    // for(int i=0;i<6;i++)
    //     cout<<zz[i]<<"\n";
    vector<vector<ll>> dp(n,vector<ll> (6,0));
    for(int i=0;i<6;i++)
    {
        int k=0;
        for(int j=0;j<n;j++)
        {
            if(j>0)
                dp[j][i]+=dp[j-1][i];
            if(zz[i][k%3]!=s[j])
            {
                dp[j][i]++;
            }
            k++;
        }
    }
    for(int i=0;i<m;i++)
    {
        cin>>l>>r;
        ans=INT_MAX;
        for(int j=0;j<6;j++)
        {
            ll k1=dp[r-1][j],k2=0;
            if(l>1)
                k2=dp[l-2][j];
            ans=min(ans,k1-k2);
        }
        cout<<ans<<"\n";
    }
}


int main() {
    //  #ifndef ONLINE_JUDGE
    // fropen("input.txt","r",stdin);
    // fropen("output.txt","w",stdout);
    // #endif
    ios::sync_with_stdio(0);
    cin.tie(NULL);
    gdb[1]=0;
    ll t=1; 
     //sieve();
   // cin>>t;
    // for(int i=1;i<=999;i++)
    // {
    //     for(int j=1;j<=i;j++)
    //     {
    //         int m=i+i/j;
    //         if(m<=1000)
    //             gdb[m]=min(gdb[m],gdb[i]+1);
    //     }
    //    // cout<<i<<" "<<gdb[i]<<"\n";
    // }
    while(t--)
    {
        solve();
    }    
}