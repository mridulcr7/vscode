#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<ll, ll> pr;

ll mridul = LLONG_MAX;
ll mod = 1e9 + 7;

vector<ll> adj[200001];
vector<ll> prime;
vector<ll> vis(200001, 0);
vector<ll> rnk(200001);
vector<ll> parent(200001);
vector<ll> rnk1(200001);
vector<ll> parent1(200001);

bool comp(const pr &v1, const pr &v2)
{

    return v1.first < v2.first;
}

bool comp1(const pair<string, int> &v1, const pair<string, int> &v2)
{
    return v1.second > v2.second;
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

ll abs(ll a, ll b)
{
    if (a > b)
        return a - b;
    else
        return b - a;
}

ll gcd(ll a, ll b)
{
    if (b == 0)
        return a;
    else
        return gcd(b, a % b);
}

void sieve()
{

    bool vis[10001];

    memset(vis, true, sizeof(vis));

    for (ll p = 2; p * p <= 10000; p++)
    {

        if (vis[p] == true)
        {

            for (ll i = p * p; i <= 10000; i += p)
                vis[i] = false;
        }
    }

    for (ll p = 2; p <= 10000; p++)
        if (vis[p])
            prime.push_back(p);
}

void bfs(ll curr, vector<ll> &col, vector<ll> &p)
{

    queue<ll> nod;
    nod.push(curr);
    vis[curr] = 1;
    col[curr] = 1;
    while (!nod.empty())
    {
        ll cur = nod.front();
        nod.pop();
        ll j = 1;
        for (auto x : adj[cur])
        {
            if (!vis[x])
            {
                if (j == p[cur])
                {
                    j++;
                    if (j == col[cur])
                        j++;
                }
                if (j == col[cur])
                {
                    j++;
                    if (j == p[cur])
                        j++;
                }
                col[x] = j;
                p[x] = col[cur];
                vis[x] = 1;
                nod.push(x);
                j++;
            }
        }
    }
}

void dfs1(vector<ll> &nodes, ll curr)
{
    // cout<<"\n"<<n<<"\n";

    vis[curr] = 1;
    for (auto x : adj[curr])
    {
        if (!vis[x])
        {
            dfs1(nodes, x);
            nodes[curr] += nodes[x];
        }
    }
    nodes[curr] += 1;
}

void dfs(vector<ll> &b, vector<ll> &a, map<ll, ll> &idx, vector<ll> &vis, ll i, vector<ll> &ffs)
{
    //  cout<<"\n"<<n<<"\n";
    if (vis[i])
        return;
    vis[i] = 1;
    ffs.push_back(i + 1);
    dfs(b, a, idx, vis, idx[b[i]], ffs);
}

ll binpow1(ll a, ll b)
{
    ll res = 1;
    while (b > 0)
    {
        if (b & 1)
            res = res * a;
        a = a * a;
        b = b >> 1;
    }
    return res;
}

void solve()
{
    ll n = 0, mod = 1e9 + 7, x = 0, u, v, y = 0, z = 0, d1 = 0, d2 = 0, l, r = 0, ans = 0, m = 1e9, k = 0, j = 0, q = 0, i, sum = 1, p = 0;
    string s, t = "", s1, s2, s3;
    char c1, c2, c3;
    bool tell = false;
    cin >> n;
    vector<ll> a(n + 1), b(n), vis(n, 0);
    map<ll, ll> idx;
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
    }
    for (ll i = 1; i <= n; i++)
    {
        x = a[i];
        while (x <= 2 * n)
        {
            ll k = x / a[i];
            j = x - i;
            if (j > i && j <= n)
            {
                if (a[j] == k)
                    ans++;
            }
            x = x + a[i];
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
    cin >> t;
    while (t--)
    {
        solve();
    }
}