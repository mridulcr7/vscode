#include<bits/stdc++.h>

using namespace std;

int main()
{
    int v,source,dest;
	cin>>v>>source>>dest;
	vector<vector<int>> adj(v+1,vector<int> (v+1));
	for(int i = 1; i <=v; i++){
		for(int j=1;j<=v;j++){
            cin>>adj[i][j];
        }
	}

    bool visited[v+1]={false};
    vector<int> distance(v+1,0);// minimum distance from source vertex to destination
    
    queue<int> nodes;
    nodes.push(source);
    visited[source]=true;
    while (!nodes.empty()) {
    int curr = nodes.front();
    nodes.pop();
    for (int i=1;i<=v;i++) {
        if(adj[curr][i]==1)
        {
            if (!visited[i]) {
            visited[i] = true;
            nodes.push(i);
            distance[i] = distance[curr] + 1;
    
          }
        }
    }
}
    cout<<distance[dest];
    
}