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
    ll n = 0, m = 0, x = INT_MAX, y = 0, ans = 0, z = 0, tot = 0, ev = 0, od = 0, r;
    string s, t = "", s2 = "", s3;
    cin >> n;
    vector<ll> a(n), dp(n + 1, 0);
    for (int i = 1; i <= n; i++)
    {
        if (i < 10)
            dp[i] = 1;
        else
        {
            m = i, ans = INT_MAX;
            while (m)
            {
                r = m % 10;
                if (r != 0)
                    ans = min(ans, dp[i - r] + 1);
                m = m / 10;
            }
            dp[i] = ans;
        }
    }
    cout << dp[n] << "\n";
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