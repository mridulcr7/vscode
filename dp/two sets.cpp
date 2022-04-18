#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<ll, ll> pr;

ll mridul = LLONG_MAX;
ll mod = 1e9 + 7;
vector<int> adj[100001];
// vector<bool> visited(100001,false);
vector<ll> prime;
vector<ll> no(10000);

void solve()
{
    ll n = 0, mod = 1e9 + 7, x = INT_MAX, y = 0, ans = 0, z = 0, tot = 0, ev = 0, od = 0, r, m;
    string s, t = "", s2 = "", s3;
    cin >> n;
    vector<ll> a(n + 1);
    r = (n * (n + 1)) / 2;
    if (r % 2 != 0)
    {
        cout << "0\n";
        return;
    }
    r=r/2;
    vector<ll> dp(r + 1, 0);
    dp[0] = 1;
    for(int i=1;i<=n;i++)
    {
        for(int j=r;j>=0;j--)
        {
            if(j-i>=0 && dp[j-i]>=0)
            {
                dp[j]=(dp[j]+dp[j-i])%mod;
            }
        }
    }
    cout << dp[r]/2 << "\n";
}

int main()
{
    //  #ifndef ONLINE_JUDGE
    // fropen("input.txt","r",stdin);
    // fropen("output.txt","w",stdout);
    // #endif
    ios::sync_with_stdio(0);
    cin.tie(NULL);
    ll t = 1;
    // sieve();
    // cin>>t;

    while (t--)
    {
        solve();
    }
}