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
    ll n = 0, m = 1e9 + 7, k, x = INT_MAX, y = 0, ans = 0, z = 0, tot = 0, ev = 0, od = 0, r, w;
    string s, t = "", s2 = "", s3;
    cin >> n >> w;
    vector<ll> wt(n + 1, 0), val(n + 1, 0);
    for (int i = 1; i <= n; i++)
        cin >> wt[i] >> val[i];
    vector<vector<ll>> dp(n + 1, vector<ll>(w + 1, 0));
    // dp[i][j]=maximum value of first i items with weight equal to exactly j

    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= w; j++)
        {
            if (j >= wt[i])
                dp[i][j] = max(dp[i - 1][j], dp[i - 1][j - wt[i]] + val[i]);
            else
                dp[i][j] = dp[i - 1][j];
        }
    }
    cout << dp[n][w] << "\n";
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