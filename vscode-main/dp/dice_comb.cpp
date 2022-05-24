#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<ll, ll> pr;

ll mridul = LLONG_MAX;
ll mod = 1e9 + 7;
vector<int> adj[100001];
vector<bool> visited(100001, false);

bool compare(pair<ll, ll> &a, pair<ll, ll> &b)
{
    double a1 = (1.0 * a.first) / a.second;
    double a2 = (1.0 * b.first) / b.second;
    return a1 > a2;
}

struct comp1
{
    bool operator()(pair<ll, ll> a, pair<ll, ll> b)
    {
        if (a.first == b.first)
            return (a.second > b.second);
        return a.first < b.first;
    }
};

int abs(int a, int b)
{
    if (a > b)
        return a - b;
    else
        return b - a;
}

// int using_dfs(int current,int m)
// {
//     visited[current]=true;
//     m=min(m,a[current]);
//     for(int x:adj[current])
//     {
//        if(visited[x])
//        continue;
//        m=using_dfs(adj,a,visited,x,m);
//     }
//     return m;

// }

void solve()
{
    ll n, m = 1e9 + 7;
    cin >> n;
    // vector<int> a(6);
    vector<int> dp(n + 1, 0);
    dp[0] = 1;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= 6; j++)
        {
            if (i - j >= 0)
                dp[i] = (dp[i] + dp[i - j]) % m;
        }
    }
    cout << dp[n];
}
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int t = 1;
    // cin>>t;
    while (t--)
    {
        solve();
    }
}