#include <bits/stdc++.h> 

using namespace std;

typedef long long ll;
typedef pair<ll,ll> pr;

int msb(ll n)
{
    int i=63;
    while((n&(1ll<<i))==0 && i>0)
    {
        i--;
    }
    return i;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
	ll t=1;
    cin>>t;
    cout<<msb(t); 
}