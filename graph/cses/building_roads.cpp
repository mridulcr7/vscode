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
vector<ll> gdb(1001, INT_MAX);
void dfs(vector<vector<ll>> &adj, vector<ll> &vis, int curr)
{
    if (vis[curr])
        return;
    vis[curr] = 1;
    for (auto x : adj[curr])
    {
        if (!vis[x])
        {
            dfs(adj, vis, x);
        }
    }
}

void solve()
{
    ll n = 0, mod = 998244353, m = 0, k = 0, x = 0, y = 0, z = 0, r, ans = 0, o = 0, j = 0, u, v;
    string s, t = "", s1, s2, s3;
    char c1, c2, c3;
    cin >> n >> m;
    vector<vector<ll>> adj(n + 1);
    vector<ll> ans1;
    for (int i = 0; i < m; i++)
    {
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    vector<ll> vis(n + 1, 0);
    for (int i = 1; i <= n; i++)
    {
        if (vis[i] == 0)
        {
            ans1.push_back(i);
            dfs(adj, vis, i);
            ans++;
        }
    }
    cout << ans - 1 << "\n";
    for (int i = 1; i < ans; i++)
    {
        cout << ans1[i] << " " << ans1[i - 1] << "\n";
    }
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