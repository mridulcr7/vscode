#include <bits/stdc++.h> 

using namespace std;

typedef long long ll;
typedef pair<ll,ll> pr;

bool compare(pair<ll,ll> &a, pair<ll,ll> &b)
{
    if(a.second!=b.second)
    return (a.second > b.second);
    else
    return (a.first<b.first);
}
 
struct comp1{
    bool operator()(pair<ll,ll> a , pair<ll,ll> b){     
        if(a.first==b.first)
          return (a.second < b.second);
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


void solve()
{
    ll k,n,t,max,min,d;
    cin>>n>>k;
    t=n*(n-1);
    max=2*(n-1);
    d=k/2;
    cout<<max-d*2<<"\n";
}
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
	int t=1;
     cin>>t;
    while(t--)
    {
       solve();
    }    
}