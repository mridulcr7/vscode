#include <bits/stdc++.h> 
 
using namespace std;
 
 
typedef long long ll;
typedef pair<ll,ll> pr;
 
 
ll mridul=LLONG_MAX;
vector<int> adj[100001];
vector<bool> visited(100001,false);
 
bool compare(pair<ll,ll> &a, pair<ll,ll> &b)
{
    double a1=(1.0*a.first)/a.second;
    double a2=(1.0*b.first)/b.second;
    return a1>a2;
}
 
struct comp1{
    bool operator()(pair<ll,ll> a , pair<ll,ll> b){     
        if(a.first==b.first)
          return (a.second > b.second);
        return a.first < b.first;
    }
};    
 
 
int abs(int a,int b)
{
    if(a>b)
    return a-b;
    else
    return b-a;
} 
 
 
// int using_dfs(int current,int m)
// {
//     visited[current]=true;
//     m=min(m,a[current]);
//     for(int x:adj[current])
//     {
//        if(visited[x])
//        continue;
//        m=using_dfs(adj,a,visited,x,m); 
//     }
//     return m;
   
// }
 
 
void solve()
{
    ll mod= 1e9+7;
    ll n,t;
    cin>>n;
    vector<int> a(n);
    for(int i=0;i<n;i++)
    cin>>a[i];
    if(is_sorted(a.begin(),a.end()))
    {
        for(auto x:a)
        cout<<x<<" ";
        cout<<"\n";
        return;
    }
    int i=0;
    while(a[i]==i+1)
    {
        i++;
    }
    int j=i+1;;
    while(a[j]!=i+1)
    {
        j++;
    }
    int l=j-i+1;
    for(int k=i;k<i+(l+1)/2;k++)
    {
        swap(a[k],a[j]);
        j--;
    }
    for(auto x:a)
    cout<<x<<" ";
    cout<<"\n";
}    
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
	int t=1;
    cin>>t;
    while(t--)
    {
       solve();
    }    
}