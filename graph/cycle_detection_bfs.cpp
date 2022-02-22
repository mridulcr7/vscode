#include<bits/stdc++.h>

using namespace std;

int main()
{
    int ans=0;
    int v,e;
	cin>>v>>e;
	vector<int> adj[v];
	for(int i = 0; i < e; i++){
		int u, v;
		cin>>u>>v;
		adj[u].push_back(v);
		adj[v].push_back(u);
	}

    bool visited[v]={false};

    vector<int> parent(v,-1);
    queue<int> nodes;
    nodes.push(0);
    visited[0]=true;
   // cout<<nodes.front()+1<<"\n";
    while(!nodes.empty())
    {
        int current=nodes.front();
        nodes.pop();
        for(auto x:adj[current])
        {
            if(visited[x])
            {
                if(parent[current]!=x)
               {
                   cout<<"cycle detected\n"; 
                   return 0;
               }
               else
               continue;
            }
            visited[x]=true;
            parent[x]=current;
           // cout<<x+1<<"\n";
            nodes.push(x);
        }
    }
    cout<<"no cycle detected\n"; 
    
}