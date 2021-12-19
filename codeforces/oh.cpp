
#include <bits/stdc++.h> 

using namespace std;

typedef long long ll;
typedef pair<ll,ll> pr;

ll mridul=INT_MAX;

ll mm=1e9;

bool compare(pair<string,ll> &a, pair<string,ll> &b)
{
    
    return a.second>b.second;
}
 
struct comp1{
    bool operator()(pair<ll,ll> a , pair<ll,ll> b){     
        if(a.first==b.first)
          return (a.second > b.second);
        return a.first < b.first;
    }
};    
ll mod=1000000007;

int abs(int a,int b)
{
    if(a>b)
    return a-b;
    else
    return b-a;
} 

int msb(ll n)
{
    int i=63;
    while((n&(1ll<<i))==0 && i>0)
    {
        i--;
    }
    return i;
}

ll digit(ll n)
{
    ll s=0;
    while(n>0)
    {
        s=s+n%10;
        n/=10;
    }
    return s;
}

void solve()
{
    ll n,i,j,m=0,t;
    cin>>n;
    vector<vector<ll>> a(n,vector<ll>(n));
    for(int i=0;i<n;i++)
    {
        if(i%2==0)
        m=i*n+1;
        else
        m=(i+1)*n;
        for(int j=0;j<n;j++)
        {
            a[j][i]=m;
            if(i%2==0)
            m++;
            else
            m--;
        }
    }
    for(i=0;i<n;i++)
    {
        for(j=0;j<n;j++)
        cout<<a[i][j]<<" ";
        cout<<"\n";
    }
}
   
       
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
	int t=1;
  //  cin>>t;
    while(t--)
    {
       solve();
    }    
}