#include<bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<ll, ll> pr;

// ll mridul = LLONG_MAX;
// ll mod = 1e9 + 7;
// vector<int> adj[100001];
// // vector<bool> visited(100001,false);
// vector<ll> prime;
// vector<ll> no(10000);
// vector<ll> gdb(1001, INT_MAX);

int main()
{
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
    vector<int> distance(v,0);// minimum distance from source vertex to destination
    vector<int> parent(v); //parents of each veretx to get trace the shortest path
    queue<int> nodes;
    nodes.push(0);
    visited[0]=true;
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
    int u;
    cin>>u;
    if (!visited[u]) {
    cout << "No path!";   //not  in same component
} else {
    vector<int> path;
    for (int v = u; v != -1; v = parent[v])
        path.push_back(v);
    reverse(path.begin(), path.end()); //source to some vertex u
    cout << "Path: ";
    for (int v : path)
        cout << v << " ";
}
    
}