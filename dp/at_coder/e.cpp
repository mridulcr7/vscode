#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<ll, ll> pr;

const ll INF = LLONG_MAX;
ll mod = 1e9 + 7;
vector<int> adj[100001];
// vector<bool> visited(100001,false);
vector<ll> prime;
vector<ll> no(10000);

void solve()
{
    ll n = 0, mod = 1e9 + 7, k, x = 0, y = 0, ans = 0, z = 0, tot = 0, ev = 0, od = 0, r, w, m;
    string s, t = "", s2 = "", s3 = "";
    cin >> n >> w;
    vector<ll> wt(n + 1, 0), val(n + 1, 0);
    for (int i = 1; i <= n; i++)
        cin >> wt[i] >> val[i];
    vector<vector<ll>> dp(n + 1, vector<ll>(n * 1000 + 1, INF));
    // dp[i][j]=minimum weight of first i items with value equal to exactly j(INF wt. means value is not possible)
    dp[0][0] = 0;
    for (int i = 1; i <= n; i++)
    {
        dp[i][0] = 0;
        for (int j = 1; j <= n * 1000; j++)
        {
            if (j >= val[i] && dp[i - 1][j - val[i]] != INF)
                dp[i][j] = min(dp[i - 1][j], dp[i - 1][j - val[i]] + wt[i]);
            else
                dp[i][j] = dp[i - 1][j];
        }
    }
    for (int i = 1; i <= n * 1000; i++)
    {
        if (dp[n][i] <= w)
            ans = i;
    }
    cout << ans << "\n";
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