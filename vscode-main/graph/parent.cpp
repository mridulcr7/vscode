

#include<bits/stdc++.h>

using namespace std;

bool dfs(vector<int> adj[],int current,int dest)
{
    
    for(auto x:adj[current])
    {
        if(x==dest)
        return true;
        else if(dfs(adj,x,dest))
        return true;
    }
    return false;
}


int main()
{
    int n,m;
    cin>>n;
    vector<int> adj[n+1];
    for(int i=0;i<n;i++)
    {
        int u;
        cin>>u;
        adj[u].push_back(i+1);
    }
    cin>>m;
    for(int i=0;i<m;i++)
    {
        int u,v;
        cin>>u>>v;
        if(dfs(adj,u,v))
        cout<<"1\n";
        else
        cout<<"0\n";
    }    
}