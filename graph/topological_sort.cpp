#include<bits/stdc++.h>
using namespace std;

void topo_sort(vector<int> adj[],vector<int> &visited,stack<int> &ans,int current)
	{
	    visited[current]=1;
	    for(int x:adj[current])
	    {
	        if(!visited[x])
	        topo_sort(adj,visited,ans,x);
	    }
	    ans.push(current);
	}
int main()
{
    int v,e;
	cin>>v>>e;
	vector<int>adj[v];
	for(int i = 0; i < e; i++){
		int u, v;
		cin>>u>>v;
		adj[u].push_back(v);
		adj[v].push_back(u);
	}
    vector<int> visited(v,0);
    stack<int> ans;
    for(int i=0;i<v;i++)
    {
        if(!visited[i])
        {
           topo_sort(adj,visited,ans,i);
        }
    }
    while(!ans.empty())
    {
        cout<<ans.top()<<"\n";
        ans.pop();
    }

}