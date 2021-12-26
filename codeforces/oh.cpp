
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
    ll n,i,j,m=0,t,q,l,r;
    cin>>n>>q;
    vector<ll> a(n+1),x(n+1,0),y(n+1,0),z(n+1,0);
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
        x[i]+=x[i-1];
        y[i]+=y[i-1];
        z[i]+=z[i-1];
        if(a[i]==1)
        x[i]+=1;
        else if(a[i]==2)
        y[i]+=1;
        else
        z[i]+=1;
    }
    for(int i=0;i<q;i++)
    {
        cin>>l>>r;
        cout<<x[r]-x[l-1]<<" "<<y[r]-y[l-1]<<" "<<z[r]-z[l-1]<<"\n";
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