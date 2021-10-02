#include <bits/stdc++.h> 

using namespace std;

typedef long long ll;
typedef pair<ll,ll> pr;

ll mod=1000000007;

ll binpow1(ll a,ll b)
{
    ll res=1;
    while(b>0)
    {
        if(b&1)
        res=res*a;
        a=a*a;
        b=b>>1;
    }
    return res;
}

ll binpow2(ll a,ll b)
{
    if(b==1)
    return a;
    if(b%2==0)
    {
        return binpow2(a*a,b/2);
    }
    else
    {
        return binpow2(a*a,(b-1)/2)*a;
    }
}

ll binpow3(ll a,ll b)
{
    ll res=1;
    a=a%mod;
    while(b>0)
    {
        if(b&1)
        res=res*a%mod;
        a=a*a%mod;
        b=b>>1;
    }
    return res;
}


int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
	ll a,b;
    cin>>a>>b;
    cout<<binpow3(a,b); 
}