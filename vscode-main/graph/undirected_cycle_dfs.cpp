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
	vector<int>adj[v];
	for(int i = 0; i < e; i++){
		int u, v;
		cin>>u>>v;
		adj[u].push_back(v);
		adj[v].push_back(u);
	}
    vector<bool> visited(v,false);
    vector<int> parent(v,-1);
    int cycle_start=-1, cycle_end=-1;
    for(int i=0;i<v;i++)
    {
        if(!visited[i])
        {
            if(using_dfs(adj,visited,parent,i,parent[i],cycle_start,cycle_end))
            break;
        }
    }
    if (cycle_start == -1) {
        cout << "Nahi hai bhai\n" << endl;
    } else {
        vector<int> cycle;
        cycle.push_back(cycle_start);
        for (int v = cycle_end; v != cycle_start; v = parent[v])
            cycle.push_back(v);
        cycle.push_back(cycle_start);
        cout << "Mil gyi,khush ho jao\n ";
        for (int v : cycle)
            cout << v << " ";
        cout << "\n";
    }

}