#include<bits/stdc++.h>

using namespace std;

int main()
{
    int ans=0;
    vector<int> adj[6];
    adj[1].push_back(2);
    adj[1].push_back(3);
    adj[2].push_back(1);
    adj[2].push_back(5);
    adj[3].push_back(4);
    adj[3].push_back(1);
    adj[4].push_back(3);
    adj[5].push_back(2);
    adj[5].push_back(4);

    bool visited[6]={false};

    vector<int> parent(6,-1);
    queue<int> nodes;
    nodes.push(1);
    visited[1]=true;
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