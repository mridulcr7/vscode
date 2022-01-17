#include<bits/stdc++.h>

using namespace std;

void dfs(vector<int> a[],vector<bool> &v,int current,int prev,bool &ans)
{
    v[current]=true;
  //  cout<<current+1<<"\n";
    for(auto x:a[current])
    {
        if(v[x])
        {
            if(x!=prev)
            {
                ans=true;
            }
        }
        else
        dfs(a,v,x,current,ans);
    }
}


int main()
{
    bool ans=false;
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

    vector<bool> visited(6,false);
    
    visited[1]=true;
    dfs(adj,visited,1,-1,ans);
    if(ans)
    cout<<"cycle hai\n";
    else
    cout<<"nahi hai\n";
    
}