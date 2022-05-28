#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<ll, ll> pr;

ll mridul = LLONG_MAX;
ll mod = 1e9 + 7;
vector<int> adj[100001];
vector<bool> visited(100001, false);
vector<ll> prime;
vector<ll> no(10000);

bool comp(const vector<ll> &v1, const vector<ll> &v2)
{
    return v1[2] < v2[2];
}

bool comp1(const pair<string, int> &v1, const pair<string, int> &v2)
{
    v1.second > v2.second;
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

// void sieve()
// {

//     bool vis[10001];

//     memset(vis, true, sizeof(vis));

//     for (ll p = 2; p * p <= 10000; p++)
//     {

//         if (vis[p] == true)
//         {

//             for (ll i = p * p; i <= 10000; i += p)
//                 vis[i] = false;
//         }
//     }

//     for (ll p = 2; p <= 10000; p++)
//         if (vis[p])
//            prime.push_back(p);
// }

// }

bool check_prime(ll n)
{
    for (ll i = 2; i * i <= n; i++)
    {
        if (n % i == 0)
            return false;
    }
    return true;
}

void rec(string t, ll p, ll z, ll &num, ll &den, ll cur)
{
    if (cur == p + z)
    {
        ll p1 = 0, z1 = 0;
        for (int i = 0; i < t.size(); i++)
        {
            if (t[i] == '+')
                p1++;
            else
                z1++;
        }
        if (p1 == p && z1 == z)
            num++;
        den++;
        return;
    }
    if (t[cur] == '?')
    {
        t[cur] = '+';
        rec(t, p, z, num, den, cur + 1);
        t[cur] = '-';
        rec(t, p, z, num, den, cur + 1);
    }
    else
    {
        rec(t, p, z, num, den, cur + 1);
    }
}

void solve()
{
    ll n = 0, m = 0, x = 0, y = 0, ans = 0, z = 0, p = 0, tot = 0, c, k, r;
    string s, t, s2, s3;
    cin >> n;
    vector<int> a(n + 1, 0), dp(n + 1, 0);
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
    }
    // cout<<dp[0]<<"\n";
    for (int i = 1; i <= n; i++)
    {
        if (a[i] == 1 && a[i] != dp[i - 1])
        {
            dp[i] = 1;
        }
        else if (a[i] == 2 && a[i] != dp[i - 1])
        {
            dp[i] = 2;
        }
        else if (a[i] == 3)
        {
            if (dp[i - 1] == 2)
                dp[i] = 1;
            else if (dp[i - 1] == 1)
                dp[i] = 2;
            else
                dp[i] = 3;
        }
        // cout<<dp[i]<<" ";
        if (dp[i] == 0)
            ans++;
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