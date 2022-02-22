#include<bits/stdc++.h>

using namespace std;

int main()
{
    int v,e;
	cin>>v>>e;
	vector<int> adj[v+1];
	for(int i = 0; i < e; i++){
		int u, v;
		cin>>u>>v;
		adj[u].push_back(v);
		adj[v].push_back(u);
	}
    bool visited[v+1]={false};
    vector<int> distance(v+1,0);
    queue<int> nodes;
    int k;
    cin>>k;
    for(int i=0;i<k;i++)
    {
        int u;
        cin>>u;
        visited[u]=true;
        nodes.push(u);
    }

    while (!nodes.empty()) {
    int curr = nodes.front();
    nodes.pop();
    for (int u : adj[curr]) {
        if (!visited[u]) {
            visited[u] = true;
            nodes.push(u);
            distance[u] = distance[curr] + 1;
    
        }
    }
}
    int ans=-1,node;
    for(int i=1;i<=v;i++)
    {
        if(distance[i]>ans)
        {
            ans=distance[i];
            node=i;
        }
    }
    cout<<ans<<"\n"<<node<<"\n";
    
}