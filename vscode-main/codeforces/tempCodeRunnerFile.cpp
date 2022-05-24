#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<ll, ll> pr;

ll mridul = LLONG_MAX;
ll mod = 1e9 + 7;
vector<ll> adj[200001];
vector<ll> adj1[200001];
// vector<bool> visited(100001,false);
vector<ll> prime;
vector<ll> vis(200001, 0);
vector<ll> gdb(1001, INT_MAX);

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

// int using_dfs(int current,int m)
// { rn m;

// }

int mem(int n, int t, vector<int> &a, vector<int> &dp, vector<bool> &vis)
{
    if (t == 0)
        return 1;
    if (vis[t])
        return dp[t];
    int ans = 0;
    for (int i = 0; i < n; i++)
    {
        if (t - a[i] >= 0)
            ans = (ans + mem(n, t - a[i], a, dp, vis)) % mod;
    }
    vis[t] = true;
    dp[t] = ans;
    return ans;
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

bool check_prime(ll n)
{
    for (ll i = 2; i * i <= n; i++)
    {
        if (n % i == 0)
            return false;
    }
    return true;
}

ll cd(ll n)
{
    ll cnt = 0;
    for (ll i = 1; i <= sqrt(n); i++)
    {
        if (n % i == 0)
        {
            // If divisors are equal,
            // count only one
            if (n / i == i)
                cnt++;

            else // Otherwise count both
                cnt = cnt + 2;
        }
    }
    return cnt;
}

ll bfs(vector<vector<ll>> &adj, ll n)
{

    queue<ll> nod;
    nod.push(1ll);
    vector<ll> vis(n + 1, 0);
    vector<ll> dis(n + 1, -1);
    dis[1] = 0;
    ll ans = 0;
    vis[1] = 1;
    while (!nod.empty())
    {
        ll curr = nod.front();
        nod.pop();

        for (auto x : adj[curr])
        {
            if (!vis[x])
            {
                vis[x] = 1;
                nod.push(x);
                dis[x] = dis[curr] + 1;
            }
        }
    }
    return dis[n];
}

bool dfs(ll curr, stack<ll> &tp)
{
    //  cout<<"\n"<<n<<"\n";
    vis[curr] = 1;

    for (auto x : adj[curr])
    {
        if (vis[x] == 1)
        {
            return false;
        }
        else if (vis[x] == 0)
        {
            if (!dfs(x, tp))
                return false;
        }
    }
    vis[curr] = 2;
    tp.push(curr);
    return true;
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
    ll n = 0, mod = 1e9 + 7, x = 0, u, v, y = 0, z = 0, d1 = 0, d2 = 0, l, r = 0, ans = 0, m = 1e9, k, j = 0, q = 0, i, sum = 0, p = 0;
    string s, t = "", s1, s2, s3;
    char c1, c2, c3;
    bool tell = false;
    cin >> n >> x >> y;
    // if(x==y==1)
    // {
    //     if(n==1)
    //     cout<<
    // }
    
    if (x > 2 * y || (x == 1 && y == 1 && n > 2))
    {
        cout << "-1\n";
        return;
    }
    for (int i = 1; i <= y; i++)
    {
        adj[i].push_back(i + 1);
    }
    j = y;
    if(x==y)
    {
        for (int i = y + 1; i < n;i++)
            adj[j].push_back(i + 1);
    }
    else{
        for (int i = y+1; i <= x; i++)
        {
            if (i == y+1)
                adj[1].push_back(i + 1);
            else
                adj[i].push_back(i + 1);
        }
        for (int i = x + 2; i <= n; i++)
        {
            adj[1].push_back(i);
        }
    }
    
    for (int i = 1; i <= n;i++)
    {
        for(auto x:adj[i])
            cout << i << " "<<x<<"\n";

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
    gdb[1] = 0;
    ll t = 1;
    // sieve();
    // cin >> t;
    while (t--)
    {
        solve();
    }
}