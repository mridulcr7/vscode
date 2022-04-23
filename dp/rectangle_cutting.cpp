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

void solve()
{
    ll n = 0, mod = 1e9 + 7, x = INT_MAX, y = 0, ans = 0, z = 0, tot = 0, ev = 0, od = 0, r, m, a, b;
    string s, t = "", s2 = "", s3;
    cin >> a >> b;
    if (b > a)
        swap(a, b);
    vector<vector<ll>> dp(a + 1, vector<ll>(a + 1,INT_MAX));
    for (int i = 1; i <= a; i++)
    {
        for (int j = i; j <= a; j++)
        {
            if (i == j)
                dp[i][j] = 0;
            else
            {
                for(int z=1;z<i;z++)
                {
                    dp[i][j]=min(dp[i][j],1+dp[z][j]+dp[i-z][j]);
                }
                for(int z=1;z<j;z++)
                {
                    dp[i][j]=min(dp[i][j],1+dp[i][z]+dp[i][j-z]);
                }
            }
            dp[j][i]=dp[i][j];
        }
    }
    cout<<dp[a][b];
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