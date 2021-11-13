#include <bits/stdc++.h> 

using namespace std;

typedef long long ll;
typedef pair<ll,ll> pr;

void primeFactors(ll n)
{
    while (n%2==0)
    {
        cout << 2 << " ";
        n = n/2;
    }
 
    for (ll i = 3;i*i<= n;i =i + 2)
    {
        
        while (n % i == 0)
        {
            cout << i << " ";
            n = n/i;
        }
    }
 
    if (n > 2)
        cout << n << " ";
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
	ll t=1;
    cin>>t;
    primeFactors(t); 
}