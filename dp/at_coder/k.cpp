#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<ll, ll> pr;

const ll INF = LLONG_MAX;
ll mod = 1e9 + 7;
vector<int> adj[100001];
// vector<bool> visited(100001,false);
vector<ll> prime;
vector<ll> no(10000);

void solve()
{
    ll n = 0, mod = 1e9 + 7, k, x = 0, y = 0, ans = 0, z = 0, tot = 0, ev = 0, od = 0, r, w, m;
    string s, t = "", s2 = "", s3 = "";
    cin >> n >> k;
    vector<ll> a(n + 1, 0), dp(k + 1, 1);
    for (int i = 0; i < n; i++)
        cin >> a[i];
       //dp[i]=1,if winner is First player and 0, if winner is second player with i stones remaining
    dp[0] = 0;
    for (int i = 1; i <= k; i++)
    {
        int np = 1;
        bool win = false;
        for (auto x : a)
        {
            if (i - x >= 0 && dp[i - x] == 0)
            {
                win = true;
            }
        }

        if (win)
            dp[i] = 1;
        else
            dp[i] = 0;

        // cout<<dp[i]<<"\n";
    }
    if (dp[k])
        cout << "First";
    else
        cout << "Second";
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