
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

string convert_word(ll n)
{
    string ans="";
    string result[]={"zero ","one ","two ","three ","four ","five ","six ","seven ","eight ","nine "};
    while(n>0)
    {
        ans=ans+result[n%10];
        n=n/10;
    }
    ans[0]=ans[0]-32;
    return ans;
}
 
bool check_prime(ll n)
{
    for(ll i=2;i*i<=n;i++)
    {
        if(n%i==0)
        return false;
    }
    return true;
}

int power(int n)
{
    if(n%2==0)
    {
        return 1;
    }
    else
    {
        return -1;
    }
}

ll count_vowel(string s)
{
    int ans=0;
    int n=s.size();
    for(int i=0;i<n;i++)
    {
        if(s[i]=='A' || s[i]=='a' || s[i]=='E' || s[i]=='e' || s[i]=='O' || s[i]=='o' || s[i]=='U' || s[i]=='u' || s[i]=='I' || s[i]=='i')
        ans++;
    }
    return ans;
}

 bool isp(string &s, int low, int high) {
        while (low < high) {
            if (s[low++] != s[high--]) return false;
        }
        return true;
    }
void rec(string s,int n,bool &ans,int i)
{
	if(i==n)
	{
		bool temp=false;
		for(int j=5;j<=n;j++)
		{
			for(int k=0;k<n-j+1;k++)
			{
				if(isp(s,k,k+j-1))
				{
					temp=true;
				}
			}
		}
		if(!temp)
		{
			ans=true;
			//cout<<s<<"\n";
		}
		return;
	}
	if(s[i]=='?')
	{
		s[i]='0';
		rec(s,n,ans,i+1);
		s[i]='1';
		rec(s,n,ans,i+1);
	}
	else
	{
		rec(s,n,ans,i+1);
	}
}
void solve(int t)
{
    int n=0,m=0,x=0,y=0;
    cin>>n;
    string s,p="";
    cin>>s;
	bool ans=false;
	rec(s,n,ans,0);
	if(ans)
	cout<<"Case #"<<t<<": POSSIBLE\n";
	else
	cout<<"Case #"<<t<<": IMPOSSIBLE\n";
}


int main() {
    //  #ifndef ONLINE_JUDGE
    // fropen("input.txt","r",stdin);
    // fropen("output.txt","w",stdout);
    // #endif
    ios::sync_with_stdio(0);
    cin.tie(NULL);
    int t=1; 
     //sieve();
    cin>>t;
    int i=1;
    while(i<=t)
    {
       solve(i);
       i++;
    }    
}