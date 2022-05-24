#include<bits/stdc++.h>

using namespace std;

typedef long long ll;

int main()
{
    ll ans=0;
    ll v,e;
	cin>>v>>e;
	vector<pair<ll, ll>> adj[v+1];
	for(int i = 0; i < e; i++){
		ll s, d, l;
		cin>>s>>d>>l;
		adj[s].push_back(make_pair(d,l));
	}
    priority_queue<pair<ll,ll>,vector<pair<ll,ll>>,greater<pair<ll,ll>>> p;
    vector<ll> parent(v+1,-1);
    vector<ll> distance(v+1,LONG_LONG_MAX);
    p.push(make_pair(0,1));
    distance[1]=0;
    while(!p.empty())
    {
        ll curr=p.top().second;
        ll l=p.top().first;
        p.pop();
        if(distance[curr]!=l)
        {
            continue;
        }
        for(auto x:adj[curr])
        {
            ll d=x.first;
            ll len=x.second;
            if(distance[d]>len+distance[curr])
            {
                distance[d]=len+distance[curr];
                parent[d]=curr;
                p.push(make_pair(distance[d],d));
            }
        }
    }
    for(int i=1;i<=v;i++)
    {
        cout<<distance[i]<<" ";
    } 
    cout<<"\n"; 
}