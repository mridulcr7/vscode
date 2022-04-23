#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef pair<ll, ll> pr;

ll ar = LLONG_MAX;
ll mod = 1e9 + 7;
void solve()
{
    int n;
    bool tell=false;
    cin >> n;
    ll arr[n];
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    vector<ll> v;
    ll mini = 1e18;
    ll mini2 = 1e18;
    for (int i = 0; i < n; i++)
    {
        if (arr[i] <= 0)
        {
            v.push_back(arr[i]);
        }
    }
    if(v.size()==0)
    {
        cout<<"1"<<endl;
        return ;
    }
    for (int i = 0; i < n; i++)
    {
        if (arr[i] > 0)
        {
            if (arr[i] < mini)
            {
                mini = arr[i];
            }
        }
    }
    sort(v.begin(), v.end());
    vector<ll> v3;
    for (int i = 0; i < v.size() - 1; i++)
    {
        v3.push_back(abs(v[i] - v[i + 1]));
    }
    for (int i = 0; i < v3.size(); i++)
    {
        if (v3[i] < mini2)
        {
            mini2 = v3[i];
        }
    }
    // for(int i=0;i<n;i++)
    // {
    //     if(arr[i]>0)
    //     {
    //         if(arr[i]<=mini2)
    //         {
    //             tell=true;
    //         }
    //     }
    // }
    //   cout<<v.size()<<endl;
    if (tell)
    {
        cout << v.size() + 1 << endl;
    }
    else
    {
        cout << v.size() << endl;
    }
}

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        solve();
    }
    return 0;
}