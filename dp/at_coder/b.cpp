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
    ll n = 0, m = 1e9 + 7, k, x = INT_MAX, y = 0, ans = 0, z = 0, tot = 0, ev = 0, od = 0, r;
    string s, t = "", s2 = "", s3;
    cin >> n >> k;
    vector<ll> a(n + 1), dp(n + 1, 0);
    for (int i = 1; i <= n; i++)
        cin >> a[i];
    dp[2] = abs(a[2] - a[1]);
    for (int i = 3; i <= n; i++)
    {
        dp[i] = dp[i - 1] + abs(a[i] - a[i - 1]);
        for (int j = 2; j <= k; j++)
        {
            if (i - j >= 1)
                dp[i] = min(dp[i], dp[i - j] + abs(a[i] - a[i - j]));
            else
                break;
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