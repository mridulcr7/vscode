#include<bits/stdc++.h>
using namespace std;

bool using_dfs(vector<int>adj[],vector<int> &color,vector<int> &parent,int current,int par,int &cycle_start,int &cycle_end)
{
    color[current]=1;// node in current dfs call
    for(int x:adj[current])
    {
        if(color[x]==1) // cycle found
        {
            cycle_start=x;
            cycle_end=current;
            return true;
        }
        else if(color[x]==0) //unvisited node
        {
            parent[x]=current;
            if(using_dfs(adj,color,parent,x,parent[x],cycle_start,cycle_end))
            return true;
        }
        // no need to check 3rd condition, since node is already visited and there is no cyle through vit
    }
    color[current]=2;//all neighours visited, no cycle through it
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

    //0-node unvisited
    //1-node is in current dfs call
    //2-visited node and no cycle through it
    vector<int> color(v,0); // all nodes unvisited
    vector<int> parent(v,-1);
    int cycle_start=-1, cycle_end=-1;
    for(int i=0;i<v;i++)
    {
        if(color[i]==0)
        {
            if(using_dfs(adj,color,parent,i,parent[i],cycle_start,cycle_end))
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