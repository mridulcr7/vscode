#include <bits/stdc++.h> 

using namespace std;

typedef long long ll;
typedef pair<ll,ll> pr;

ll binpow1(ll a,ll b)
{
    ll res=1;
    while(b>0)
    {
        if(b&1)
        res=res*a;
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
	ll a,b;
    cin>>a>>b;
    binpow1(a,b); 
}