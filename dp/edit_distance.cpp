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
    ll n = 0, mod = 1e9 + 7, m, k, x = INT_MAX, y = 0, ans = 0, z = 0, tot = 0, ev = 0, od = 0, r;
    string s, t = "", s2 = "", s3;
    cin >> s >> t;
    n = s.size();
    m = t.size();
    vector<vector<ll>> dp(n + 1, vector<ll>(m + 1));
    for (int i = 0; i <= n; i++)
    {
        for (int j = 0; j <= m; j++)
        {
            if (i == 0 || j == 0)
                dp[i][j] = max(i, j);
            else if (s[i - 1] == t[j - 1])
                dp[i][j] = dp[i - 1][j - 1];
            else
                                         //replace        //delete       //insert
                dp[i][j] = 1 + min(dp[i - 1][j - 1], min(dp[i - 1][j], dp[i][j - 1]));
           // cout << dp[i][j] << " ";
        }
        //cout << "\n";
    }
    cout << dp[n][m] << "\n";
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