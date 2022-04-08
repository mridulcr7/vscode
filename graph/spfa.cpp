    #include<bits/stdc++.h>

using namespace std;

typedef long long ll;
long long inf=1e18;

// struct edge{
//     ll fr,to,cost;
// };

int main()
{
    ll ans=0,x=-1,i;
    ll v,e;
	cin>>v>>e;
	vector<pair<int,int>> adj[v+1];
	for(i = 0; i < e; i++){
		ll s,d,l;
		cin>>s>>d>>l;
        adj[s].push_back({d,l});
	}
    queue<ll> p;
    vector<bool> q(v+1,false);
    vector<ll> parent(v+1,-1);
    vector<ll> distance(v+1,inf);
    vector<ll> count(v+1,0);
    distance[1]=0;
    count[1]=1;
    p.push(1);
    q[1]=true;
   while(!p.empty())
   {
        ll curr = p.front();
        p.pop();
        q[curr] = false;
        q[v]=false;
        for(auto x:adj[curr])
        {
            ll to=x.first;
            ll cost=x.second;
            if(distance[to]>distance[curr]+cost)
            {
                distance[to]=distance[curr]+cost;
                if(!q[to])
                {
                    q[to]=true;
                    p.push(to);
                    count[to]++;
                    if(count[to]==v)
                    {
                        cout<<"Negative cycle\n";
                    }
                }
            }
        }
   }
    for(int i=1;i<=v;i++)
    {
        if(distance[i]!=inf)
        cout<<distance[i]<<" ";
        else
        cout<<"30000 ";
    } 
    cout<<"\n"; 
}