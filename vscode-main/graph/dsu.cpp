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

void make_set(int v)
{
    parent[v] = v;
    rnk[v] = 0;
}

int find_set(int v)
{
    if (v == parent[v])
        return v;
    return parent[v] = find_set(parent[v]);
}

void union_sets(int a, int b)
{
    a = find_set(a);
    b = find_set(b);
    if (a != b)
    {
        if (rnk[a] < rnk[b])
            swap(a, b);
        parent[b] = a;
        if (rnk[a] == rnk[b])
            rnk[a]++;
    }
}