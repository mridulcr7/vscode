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

bool dfs(vector<vector<ll>> &a, vector<ll> &vis, vector<ll> &par, ll curr, ll prev, ll &s, ll &e)
{
    vis[curr]=1;
    for (auto x : a[curr])
    {
        if (!vis[x])
        {
            par[x]=curr;
            if (dfs(a, vis, par, x, curr, s, e))
                return true;
        }
        else if(x!=prev)
        {
            par[x]=curr;
            s=curr;
            e=x;
            return true;
        }
    }
    return false;
}

void solve()
{
    ll n = 0, mod = 998244353, x, y, z = 0, d1 = 0, d2 = 0, r, ans = 0, m, k, o = 0, j = 0, u, v;
    string s, t = "", s1, s2, s3;
    char c1, c2, c3;
    bool tell = false;
    cin >> n >> m;
    vector<vector<ll>> a(n + 1);
    for (int i = 0; i < m; i++)
    {
        cin >> u >> v;
        a[u].push_back(v);
        a[v].push_back(u);
        //      cout<<a[i]<<"\n";
    }
    // cout<<x1<<" "<<y1<<"\n";
    // cout << d1 << " " << d2 << "\n";
    vector<ll> vis(n + 1, 0);
    vector<ll> par(n + 1, 0);
    ll cy_st = -1, cy_ed = -1;
    for (int i = 1; i <= n; i++)
    {
        if (!vis[i])
        {
            //vis[i] = 1;
            if (dfs(a, vis, par, i, -1, cy_st, cy_ed))
            {
                vector<ll> temp;
                ll curr=cy_st;
                while(curr!=cy_ed)
                {
                    temp.push_back(curr);
                    curr=par[curr];
                }
                temp.push_back(cy_ed);
                temp.push_back(cy_st);
                cout<<temp.size()<<"\n";
                for(auto x:temp)
                cout<<x<<" ";
                break;
            }
        }
    }
    if(cy_st==-1)
        cout << "IMPOSSIBLE"<<"\n";
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