#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<ll, ll> pr;

// ll mridul = LLONG_MAX;
// ll mod = 1e9 + 7;
// vector<int> adj[100001];
// // vector<bool> visited(100001,false);
// vector<ll> prime;
// vector<ll> no(10000);
// vector<ll> gdb(1001, INT_MAX);


void dfs(vector<string> &a, vector<vector<ll>> &vis, int i, int j, ll n, ll m)
{
    if (a[i][j] == '#' || vis[i][j])
        return;
    vis[i][j] = 1;
    if (j != 0)
    {
        dfs(a, vis, i, j - 1, n, m);
    }
    if (j != m - 1)
    {
        dfs(a, vis, i, j + 1, n, m);
    }
    if (i != 0)
    {
        dfs(a, vis, i - 1, j, n, m);
    }
    if (i != n - 1)
    {
        dfs(a, vis, i + 1, j, n, m);
    }
}

void solve()
{
    ll n = 0, mod = 998244353, x, y, z = 0, d1 = 0, d2 = 0, r, ans = 0, m, k, o = 0, j = 0, q;
    string s, t = "", s1, s2, s3;
    char c1, c2, c3;
    cin >> n >> m;
    vector<string> a(n);
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
        //  cout<<a[i]<<"\n";
    }
    vector<vector<ll>> vis(n, vector<ll>(m, 0));
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (vis[i][j] == 0)
            {

                if (a[i][j] == '.')
                {
                    //  cout << i << " " << j << "\n";
                    ans++;
                    dfs(a, vis, i, j, n, m);
                }
            }
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
    //  cin>>t;
    while (t--)
    {
        solve();
    }
}