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

// bool comp(const pr &v1, const pr &v2)
// {
//     if (v1.first == v2.first)
//     {
//         return v1.second > v2.second;
//     }
//     return v1.first < v2.first;
// }

// bool comp1(const pair<string, int> &v1, const pair<string, int> &v2)
// {
//     v1.second > v2.second;
// }

// struct comp1
// {
//     bool operator()(pair<ll, ll> a, pair<ll, ll> b)
//     {
//         if (a.first == b.first)
//             return (a.second > b.second);
//         return a.first < b.first;
//     }
// };

// ll abs(ll a, ll b)
// {
//     if (a > b)
//         return a - b;
//     else
//         return b - a;
// }

// // int using_dfs(int current,int m)
// // { rn m;

// // }

// int mem(int n, int t, vector<int> &a, vector<int> &dp, vector<bool> &vis)
// {
//     if (t == 0)
//         return 1;
//     if (vis[t])
//         return dp[t];
//     int ans = 0;
//     for (int i = 0; i < n; i++)
//     {
//         if (t - a[i] >= 0)
//             ans = (ans + mem(n, t - a[i], a, dp, vis)) % mod;
//     }
//     vis[t] = true;
//     dp[t] = ans;
//     return ans;
// }

// // void sieve()
// // {

// //     bool vis[10001];

// //     memset(vis, true, sizeof(vis));

// //     for (ll p = 2; p * p <= 10000; p++)
// //     {

// //         if (vis[p] == true)
// //         {

// //             for (ll i = p * p; i <= 10000; i += p)
// //                 vis[i] = false;
// //         }
// //     }

// //     for (ll p = 2; p <= 10000; p++)
// //         if (vis[p])
// //            prime.push_back(p);
// // }

// // }

// bool check_prime(ll n)
// {
//     for (ll i = 2; i * i <= n; i++)
//     {
//         if (n % i == 0)
//             return false;
//     }
//     return true;
// }

// ll cd(ll n)
// {
//     ll cnt = 0;
//     for (ll i = 1; i <= sqrt(n); i++)
//     {
//         if (n % i == 0)
//         {
//             // If divisors are equal,
//             // count only one
//             if (n / i == i)
//                 cnt++;

//             else // Otherwise count both
//                 cnt = cnt + 2;
//         }
//     }
//     return cnt;
// }

// void rec(vector<string> &s, vector<string> &ffs, ll c, ll k, ll n, ll &ans)
// {
//     //  cout<<"\n"<<n<<"\n";
//     if (c == n)
//     {
//         ll zz, t = 0;
//         for (char i = 'a'; i <= 'z'; i++)
//         {
//             zz = 0;
//             for (auto x : ffs)
//             {
//                 for (char y : x)
//                 {
//                     if (y == i)
//                         zz++;
//                 }
//             }
//             if (zz == k)
//                 t++;
//         }
//         ans = max(t, ans);
//         return;
//     }
//     ffs.push_back(s[c]);
//     rec(s, ffs, c + 1, k, n, ans);
//     ffs.pop_back();
//     rec(s, ffs, c + 1, k, n, ans);
// }

void dfs(vector<string> &a, vector<vector<ll>> &vis, ll i, ll j, ll n, ll m, string &t, string &ffs, ll &l)
{
    if (a[i][j] == 'B')
    {
        if (t.size() < l)
        {
            l = t.size();
            ffs = t;
        }
        return;
    }
    if (a[i][j] == '#' || vis[i][j])
        return;
    
    if (j != 0)
    {
        t.push_back('L');
        dfs(a, vis, i, j - 1, n, m, t, ffs, l);
        t.pop_back();
    }
    if (j != m - 1)
    {
        t.push_back('R');
        dfs(a, vis, i, j + 1, n, m, t, ffs, l);
        t.pop_back();
    }
    if (i != 0)
    {
        t.push_back('U');
        dfs(a, vis, i - 1, j, n, m, t, ffs, l);
        t.pop_back();
    }
    if (i != n - 1)
    {
        t.push_back('D');
        dfs(a, vis, i + 1, j, n, m, t, ffs, l);
        t.pop_back();
    }
    vis[i][j] = 1;
}

void solve()
{
    ll n = 0, mod = 998244353, x, y, z = 0, d1 = 0, d2 = 0, r, ans = 0, m, k, o = 0, j = 0, q, x1, x2, y1, y2;
    string s, t = "", s1, s2, s3;
    char c1, c2, c3;
    cin >> n >> m;
    vector<string> a(n);
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
        for (int j = 0; j < m; j++)
        {
            if (a[i][j] == 'A')
            {
                x1 = i, y1 = j;
            }
        }
        //      cout<<a[i]<<"\n";
    }
    // cout<<x1<<" "<<x2<<"\n";
    string ffs;
    ll l = INT_MAX;
    vector<vector<ll>> vis(n, vector<ll>(m, 0));
    vis[x1][y1]=1;
    dfs(a, vis, x1, y1, n, m, t, ffs, l);
    if (l != INT_MAX)
    {
        cout << "YES\n"
             << l << "\n"
             << ffs;
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