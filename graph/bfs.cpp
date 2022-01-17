#include<bits/stdc++.h>

using namespace std;

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

    queue<int> nodes;
    nodes.push(0);
    visited[0]=true;
    cout<<nodes.front()+1<<"\n";
    while(!nodes.empty())
    {
        int current=nodes.front();
        nodes.pop();
        for(auto x:adj[current])
        {
            if(visited[x])
            continue;
            visited[x]=true;
            cout<<x+1<<"\n";
            nodes.push(x);
        }
    }
    
}