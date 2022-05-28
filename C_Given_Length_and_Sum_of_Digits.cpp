#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<ll, ll> pr;

ll mridul = INT_MAX;

bool compare(pair<string, ll> &a, pair<string, ll> &b)
{

    return a.second > b.second;
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
ll mod = 1000000007;

int abs(int a, int b)
{
    if (a > b)
        return a - b;
    else
        return b - a;
}

int msb(ll n)
{
    int i = 63;
    while ((n & (1ll << i)) == 0 && i > 0)
    {
        i--;
    }
    return i;
}

void solve()
{
    int m, s, k = 0, n, z;
    cin >> m >> s;
    n = m, z = s;
    if (s > m * 9 || (s == 0 && m != 1))
    {
        cout << "-1 -1\n";
        return;
    }
    string ans;
    while (m != 0)
    {
        int r = (m - 1) * 9;
        if (s <= r)
        {
            if (k == 0)
            {
                ans.push_back('1');
                s--;
                k++;
            }
            else
            {
                ans.push_back('0');
            }
        }
        else
        {
            int t = s - r;
            char c = t + 48;
            ans.push_back(c);
            s = s - t;
        }
        // cout<<s<<"\n";
        m--;
    }
    if (n == 1 and z == 0)
        ans = "0";
    string ans1;
    while (n != 0)
    {
        if (z > 9)
        {
            ans1.push_back('9');
            z = z - 9;
        }
        else
        {
            char c = z + 48;
            ans1.push_back(c);
            z = 0;
        }
        n--;
    }
    cout << ans << " " << ans1 << "\n";
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