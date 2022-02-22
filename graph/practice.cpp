#include<bits/stdc++.h>

using namespace std;

int main()
{
    int v,e,a,b;
	cin>>v>>e>>a>>b;
	vector<int> adj[v+1];
	for(int i = 0; i < e; i++){
		int u, v;
		cin>>u>>v;
		adj[u].push_back(v);
		adj[v].push_back(u);
	}

    bool visited[v+1]={false};
    vector<int> distance(v+1,-1);// minimum distance from source vertex to destination
    vector<int> parent(v+1,-1); //parents of each veretx to get trace the shortest path
    queue<int> nodes;
    nodes.push(a);
    visited[a]=true;
    distance[a]=0;
    while (!nodes.empty()) {
    int curr = nodes.front();
    nodes.pop();
    for (int u : adj[curr]) {
        if (!visited[u]) {
            visited[u] = true;
            nodes.push(u);
            distance[u] = distance[curr] + 1;
            parent[u] = curr;
        }
    }
}
   if (!visited[b]) {
    cout << "-1";   //not  in same component
} else {
    cout<<distance[b]<<"\n";
    vector<int> path;
    for (int i = b; i != -1; i = parent[i])
        path.push_back(i);
    reverse(path.begin(), path.end()); //source to some vertex b
    for (int i : path)
        cout << i << " ";
}
    
}