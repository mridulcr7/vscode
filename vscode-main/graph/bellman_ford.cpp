    #include<bits/stdc++.h>

using namespace std;

typedef long long ll;
long long inf=1e18;

struct edge{
    ll fr,to,cost;
};

int main()
{
    ll ans=0,x=-1,i;
    ll v,e;
	cin>>v>>e;
	vector<edge> adj(e);
	for(i = 0; i < e; i++){
		ll s,d,l;
		cin>>s>>d>>l;
        adj[i].fr=s;
        adj[i].to=d;
        adj[i].cost=l;
	}
    vector<ll> parent(v+1,-1);
    vector<ll> distance(v+1,inf);
    distance[1]=0;
   for(i=0;i<v;i++)
   {
       x=-1;
       bool tell=true;
       for(int j=0;j<e;j++)
       {
           if(distance[adj[j].fr]!=inf)
           {
               if( distance[adj[j].to]>distance[adj[j].fr]+adj[j].cost)
               {
                   distance[adj[j].to]=distance[adj[j].fr]+adj[j].cost;
                   parent[adj[j].to]=adj[j].fr;
                   x=0;
                   tell=false;
               }
           }
       }
       if(tell)
       break;
   }
   if(i==v && x==0)
   {
       cout<<"Negative cycle\n";
   }
    for(int i=1;i<=v;i++)
    {
        if(distance[i]!=inf)
        cout<<distance[i]<<" ";
        else
        cout<<"30000\n";
    } 
    cout<<"\n"; 
}