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
    ll n = 0, m = 1e9 + 7, x = INT_MAX, y = 0, ans = 0, z = 0, tot = 0, ev = 0, od = 0, r;
    string s, t = "", s2 = "", s3;
    cin >> n >> x;
    vector<ll> a(n + 1);
    for (int i = 1; i <= n; i++)
        cin >> a[i];
    vector<vector<ll>> dp(n + 1, vector<ll>(x + 2, 0));
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= x; j++)
        {
            if (i == 1)
            {
                if (a[i] == j || a[i] == 0)
                    dp[i][j] = 1;
            }
            else
            {
                if (a[i] == j || a[i] == 0)
                    dp[i][j] = ((dp[i - 1][j - 1] + dp[i - 1][j]) % m + dp[i - 1][j + 1]) % m;
            }
            if (i == n)
                ans = (ans + dp[i][j]) % m;
        }
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