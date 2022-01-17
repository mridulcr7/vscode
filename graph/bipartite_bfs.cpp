#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution {
public:
	bool isBipartite(int n, vector<int>adj[]){
	    // Code here
	    vector<int> color(n,-1);
	    for(int i=0;i<n;i++)
	    {
	        if(color[i]==-1)
	        {
	            if(!usingbfs(i,adj,color))
	            return 0;
	        }
	    }
	    return 1;
	}
	
	bool usingbfs(int current,vector<int> adj[],vector<int> &color)
	{
	    queue<int> nodes;
	    nodes.push(current);
	    color[current]=0;
	    while(!nodes.empty())
	    {
	        current=nodes.front();
	        nodes.pop();
	        for(auto x:adj[current])
	        {
	            if(color[x]!=-1)
	            {
	                if(color[x]==color[current])
	                return false;
	            }
	            else
	            {
	                color[x]=1-color[current];
	                nodes.push(x);
	            }
	        }
	    }
	    return true;
	}

};

// { Driver Code Starts.
int main(){
	int t;
	cin >> t;
	while(t--){
		int V, E;
		cin >> V >> E;
		vector<int>adj[V];
		for(int i = 0; i < E; i++){
			int u, v;
			cin >> u >> v;
			adj[u].push_back(v);
			adj[v].push_back(u);
		}
		Solution obj;
		bool ans = obj.isBipartite(V, adj);    
		if(ans)cout << "1\n";
		else cout << "0\n";  
	}
	return 0;
} 