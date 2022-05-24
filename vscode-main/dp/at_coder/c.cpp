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
    cin >> n;
    vector<vector<ll>> a(3, vector<ll>(n + 1, 0)), dp(3, vector<ll>(n + 1, 0));
    for (int i = 1; i <= n; i++)
        cin >> a[0][i] >> a[1][i] >> a[2][i];
    dp[0][1] = a[0][1], dp[1][1] = a[1][1], dp[2][1] = a[2][1];
    for (int i = 2; i <= n; i++)
    {
        dp[0][i] = a[0][i] + max(dp[1][i - 1], dp[2][i - 1]);
        dp[1][i] = a[1][i] + max(dp[2][i - 1], dp[0][i - 1]);
        dp[2][i] = a[2][i] + max(dp[1][i - 1], dp[0][i - 1]);
    }
    cout << max(dp[0][n], max(dp[1][n], dp[2][n])) << "\n";
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