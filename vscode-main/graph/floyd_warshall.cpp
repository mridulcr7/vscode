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

void solve()
{
    ll n = 0, mod = 998244353, x, y, z = 0, u, v, r, ans = 0, m, k, o = 0, j = 0, q, x1, x2, y1, y2, INF = 1e18;
    string s, t = "", s1, s2, s3;
    char c1, c2, c3;
    bool tell = false;
    cin >> n >> m >> q;
    vector<vector<ll>> dis(n + 1, vector<ll>(n + 1, INF));
    for (int i = 0; i < m; i++)
    {
        cin>>u>>v>>r;
        dis[u][v]=min(dis[u][v],r);
        dis[v][u] = min(dis[v][u], r);
    }
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=n;j++)
        {
            if(i==j)
            {
                dis[i][j]=0;
            }
        }
    }
    for(int k=1;k<=n;k++)
    {
        for(int i=1;i<=n;i++)
        {
            for(int j=1;j<=n;j++)
            {
                dis[i][j]=min(dis[i][j],dis[i][k]+dis[k][j]);
            }
        }
    }
    for(int i=0;i<q;i++)
    {
        cin>>x1>>x2;
        if(dis[x1][x2]==INF)
        cout<<"-1\n";
        else
        cout<<dis[x1][x2]<<"\n";
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