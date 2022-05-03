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
    ll n = 0, mod = 998244353, x, y, z = 0, d1 = 0, d2 = 0, r, ans = 0, m, k, o = 0, j = 0, q, x1, x2, y1, y2;
    string s, t = "", s1, s2, s3;
    char c1, c2, c3;
    bool tell = false;
    cin >> n >> m;
    vector<string> a(n);
    vector<pr> tt;
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
        for (int j = 0; j < m; j++)
        {
            if (a[i][j] == 'A')
            {
                x1 = i, y1 = j;
            }
            if (a[i][j] == 'M')
            {
                tt.push_back({i, j});
            }
        }
        //      cout<<a[i]<<"\n";
    }
    // cout<<x1<<" "<<y1<<"\n";
    // cout << d1 << " " << d2 << "\n";
    vector<vector<ll>> vis(n, vector<ll>(m, 0));
    vector<vector<ll>> dis(n, vector<ll>(m, 0));
    vector<vector<char>> par(n, vector<char>(m, '0'));
    vis[x1][y1] = 1;
    queue<pr> node;
    node.push({x1, y1});
    while (!node.empty())
    {
        x2 = node.front().first;
        y2 = node.front().second;
        node.pop();
        if (y2 != 0)
        {
            if (a[x2][y2 - 1] == '.' && vis[x2][y2 - 1] == 0)
            {
                dis[x2][y2 - 1] = dis[x2][y2] + 1;
                node.push({x2, y2 - 1});
                vis[x2][y2 - 1] = 1;
                par[x2][y2 - 1] = 'L';
            }
        }
        if (y2 != m - 1)
        {
            if (a[x2][y2 + 1] == '.' && vis[x2][y2 + 1] == 0)
            {
                dis[x2][y2 + 1] = dis[x2][y2] + 1;
                node.push({x2, y2 + 1});
                vis[x2][y2 + 1] = 1;
                par[x2][y2 + 1] = 'R';
            }
        }
        if (x2 != 0)
        {
            if (a[x2 - 1][y2] == '.' && vis[x2 - 1][y2] == 0)
            {
                dis[x2 - 1][y2] = dis[x2][y2] + 1;
                node.push({x2 - 1, y2});
                vis[x2 - 1][y2] = 1;
                par[x2 - 1][y2] = 'U';
            }
        }
        if (x2 != n - 1)
        {
            if (a[x2 + 1][y2] == '.' && vis[x2 + 1][y2] == 0)
            {
                dis[x2 + 1][y2] = dis[x2][y2] + 1;
                node.push({x2 + 1, y2});
                vis[x2 + 1][y2] = 1;
                par[x2 + 1][y2] = 'D';
            }
        }
    }
    vector<vector<ll>> vis1(n, vector<ll>(m, 0));
    vector<vector<ll>> dis1(n, vector<ll>(m, INT_MAX));
    queue<pr> b;
    for(auto x:tt)
    {
        b.push(x);
        vis1[x.first][x.second]=1;
        dis1[x.first][x.second]=0;
    }
    //    for(int i=0;i<n;i++)
    //    {
    //        for(int j=0;j<m;j++)
    //        cout<<par[i][j];
    //        cout<<"\n";
    //    }
    while (!b.empty())
    {
        x2 = b.front().first;
        y2 = b.front().second;

        b.pop();
        if (y2 != 0)
        {
            if (a[x2][y2 - 1] != '#' && vis1[x2][y2 - 1] == 0)
            {
                dis1[x2][y2 - 1] = dis1[x2][y2] + 1;
                b.push({x2, y2 - 1});
                vis1[x2][y2 - 1] = 1;
            }
        }
        if (y2 != m - 1)
        {
            if (a[x2][y2 + 1] != '#' && vis1[x2][y2 + 1] == 0)
            {
                dis1[x2][y2 + 1] = dis1[x2][y2] + 1;
                b.push({x2, y2 + 1});
                vis1[x2][y2 + 1] = 1;
            }
        }
        if (x2 != 0)
        {
            if (a[x2 - 1][y2] != '#' && vis1[x2 - 1][y2] == 0)
            {
                dis1[x2 - 1][y2] = dis1[x2][y2] + 1;
                b.push({x2 - 1, y2});
                vis1[x2 - 1][y2] = 1;
            }
        }
        if (x2 != n - 1)
        {
            if (a[x2 + 1][y2] != '#' && vis1[x2 + 1][y2] == 0)
            {
                dis1[x2 + 1][y2] = dis1[x2][y2] + 1;
                b.push({x2 + 1, y2});
                vis1[x2 + 1][y2] = 1;
            }
        }
    }
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (i == 0 || j == 0 || i == n - 1 || j == m - 1)
            {
                if(a[i][j]=='A')
                {
                    tell=true;
                }
                if (a[i][j] == '.' && dis[i][j] < dis1[i][j] && vis[i][j] == 1)
                {
                    tell = true;
                    d1 = i, d2 = j;
                }
            }
        }
    }
    // for (int i = 0; i < n; i++)
    // {
    //     for (int j = 0; j < m; j++)
    //     {
    //         cout << dis[i][j] << " ";
    //     }
    //     cout << "\n";
    // }
    // for (int i = 0; i < n; i++)
    // {
    //     for (int j = 0; j < m; j++)
    //     {
    //         cout << dis1[i][j] << " ";
    //     }
    //     cout << "\n";
    // }
    // cout << d1 << " " << d2 << "\n";
    if (tell)
    {
        cout << "YES\n";
        ll z1 = d1, z2 = d2;
        string t = "";
        while (par[z1][z2] != 48)
        {
            if (par[z1][z2] == 'L')
            {
                z2 = z2 + 1;
                t.push_back('L');
            }
            else if (par[z1][z2] == 'R')
            {
                z2 = z2 - 1;
                t.push_back('R');
            }
            else if (par[z1][z2] == 'U')
            {
                z1 = z1 + 1;
                t.push_back('U');
            }
            else if (par[z1][z2] == 'D')
            {
                z1 = z1 - 1;
                t.push_back('D');
            }
        }
        reverse(t.begin(), t.end());
        cout << t.size() << "\n"
             << t << "\n";
    }
    else
    {
        cout << "NO\n";
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