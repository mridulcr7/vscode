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
 
 
int abs(int a,int b)
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

void rec(string t,ll p,ll z,ll &num,ll &den,ll cur)
{
    if(cur==p+z)
    {
        ll p1=0,z1=0;
        for(int i=0;i<t.size();i++)
        {
            if(t[i]=='+')
            p1++;
            else
            z1++;
        }
        if(p1==p && z1==z)
        num++;
        den++;
        return;
    }
    if(t[cur]=='?')
    {
        t[cur]='+';
        rec(t,p,z,num,den,cur+1);
        t[cur]='-';
        rec(t,p,z,num,den,cur+1);
    }
    else
    {
        rec(t,p,z,num,den,cur+1);
    }
}

void solve()
{
    string s;
    cin>>s;
    string ans="";
    int n=s.size();
    for(int i=0;i<n;i++)
    {
        if (s[i] != 'A' && s[i] != 'a' && s[i] != 'E' && s[i] != 'e' && s[i] != 'I' && s[i] != 'i' && s[i] != 'O' && s[i] != 'o' && s[i] != 'U' && s[i] != 'u' && s[i] != 'Y' && s[i] != 'y')
        {
            ans.push_back('.');
            if(s[i]>=65 && s[i]<=90)
            {
                s[i]=s[i]+32;
            }
            ans.push_back(s[i]);
        }
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
    ll t=1; 
     //sieve();
   // cin>>t;
  
    while(t--)
    {
        solve();
    }    
}