//The connected undirected graph without loops and multiple edges is given. You are allowed to remove the edges from it. Obtain a tree from the graph.

#include<bits/stdc++.h>
using namespace std;

bool using_dfs(vector<int>adj[],vector<bool> &visited,vector<int> &parent,int current,int par,int &cycle_start,int &cycle_end)
{
    visited[current]=true;
    for(int x:adj[current])
    {
        if(visited[x])
        {
            if(x==par)
            continue;
            else
            {
                cycle_start=x;
                cycle_end=current;
                return true;
            }
        }
        parent[x]=current;
        if(using_dfs(adj,visited,parent,x,parent[x],cycle_start,cycle_end))
        return true;
    }
    return false;
}

int main()
{
    int v,e;
	cin>>v>>e;
	vector<int>adj[v+1];
    vector<pair<int,int>> c(e);
	for(int i = 0; i < e; i++){
		int u, v;
		cin>>u>>v;
        c[i].first=u;
        c[i].second=v;
		adj[u].push_back(v);
		adj[v].push_back(u);
	}
    vector<bool> visited(v+1,false);
    vector<int> parent(v+1,-1);
    int cycle_start=-1, cycle_end=-1;
    for(int i=1;i<v;i++)
    {
        if(!visited[i])
        {
            if(using_dfs(adj,visited,parent,i,parent[i],cycle_start,cycle_end))
            break;
        }
    }
    for(int i=0;i<e;i++)
    {
        if(cycle_start==c[i].first && cycle_end==c[i].second  || cycle_end==c[i].first && cycle_start==c[i].second)
        continue;
        else
        cout<<c[i].first<<" "<<c[i].second<<"\n";
    }
}