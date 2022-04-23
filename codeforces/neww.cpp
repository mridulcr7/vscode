#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef pair<ll, ll> pr;

ll ar = LLONG_MAX;
ll mod = 1e9 + 7;
void solve()
{
    ll n,m,k,ans=0;
    cin >> n>>m>>k;
    ll arr[n];
    vector<ll> b;
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
        ll r=arr[i]%m;
        if(r==0)
        r=m;
        r=m-r;
        b.push_back(r);
    }
    sort(b.begin(),b.end());
    ll j=0;
    while(j<n)
    {
        if(b[j]<=k)
        {
            ans++;
            k=k-b[j];
        }
        else
        {
            break;
        }
        j++;
    }
    cout<<ans;
}

int main()
{
    int t=1;
   // cin >> t;
    while (t--)
    {
        solve();
    }
    return 0;
}