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
 
bool comp(const pr& v1, const pr& v2)
{
    if(v1.first-v1.second==v2.first-v2.second)
    {
        return v1.first<v2.first;
    }
    return v1.first-v1.second<v2.first-v2.second;
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

void rec(vector<string> &s,vector<string> &ffs,ll c,ll k,ll n,ll &ans)
{
  //  cout<<"\n"<<n<<"\n";
    if(c==n)
    {
        ll zz,t=0;
            for(char i='a';i<='z';i++)
            {
                zz=0;
                for(auto x:ffs)
                {
                    for(char y:x)
                    {
                        if(y==i)
                            zz++;
                    }

                }
                if(zz==k)
                    t++;
            }
            ans=max(t,ans);
        return;
    }
    ffs.push_back(s[c]);
    rec(s,ffs,c+1,k,n,ans);
    ffs.pop_back();
    rec(s,ffs,c+1,k,n,ans);
}

void solve()
{
    ll n=0,mod=998244353,x,y,z=0,d1=0,d2=0,r,ans=0,m=INT_MAX,k,o=0,j=0,q;
    string s,t="",s1,s2,s3;
    char c1,c2,c3;
    cin>>n>>r;
     vector<pr> a(n);
     for(int i=0;i<n;i++)
        cin>>a[i].first;
     for(int i=0;i<n;i++)
        cin>>a[i].second;
    sort(a.begin(),a.end(),comp);
    j=0;
    while(j<n)
    {
        x=a[j].first-a[j].second;
        if(a[j].first<=r)
        {
            d1=r-a[j].first;
            d2=d1/x+1;
            ans=ans+d2;
            r=r-d2*x;
        }
        j++;
    }
    cout<<ans<<"\n";
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
    cin>>t;
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