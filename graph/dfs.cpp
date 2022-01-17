#include<bits/stdc++.h>

using namespace std;

void dfs(vector<int> a[],bool *v,int current)
{
    if(v[current])
    return;
    v[current]=true;
    cout<<current+1<<"\n";
    for(auto x:a[current])
    dfs(a,v,x);
}

int main()
{
    vector<int> adj[5];
    adj[0].push_back(1);
    adj[0].push_back(2);
    adj[1].push_back(0);
    adj[1].push_back(3);
    adj[1].push_back(4);
    adj[2].push_back(0);
    adj[2].push_back(3);
    adj[3].push_back(1);
    adj[3].push_back(2);
    adj[3].push_back(4);
    adj[4].push_back(1);
    adj[4].push_back(3);

    bool visited[5]={false};

    dfs(adj,visited,0);
    
}