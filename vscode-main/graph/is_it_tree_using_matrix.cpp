//An undirected graph is a tree if it has properties mentioned below

//There is no cycle present in the graph.
//The graph is connected. (All the vertices in the graph are connected)

#include<bits/stdc++.h>

using namespace std;

bool dfs(vector<vector<int>> a,vector<bool> &v,int current,int prev)
{
    v[current]=true;
  //  cout<<current+1<<"\n";
    for(int i=0;i<a[0].size();i++)
    {
        if(a[current][i]==1)
        {
            if(v[i])
          {
            if(i!=prev)
            {
               // cout<<x<<" "<<prev<<"\n";
               return true;
            }
          }
        else
        if(dfs(a,v,i,current))
        return true;
        }
    }
    return false;
}


int main()
{
    int n;
    cin>>n;
    vector<vector<int>> a(n,vector<int> (n));
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        cin>>a[i][j];
    }

    vector<bool> visited(n,false);
    
    if(dfs(a,visited,0,-1))//There is no cycle present in the graph.
    {
        cout<<"NO\n";
        return 0;
   }
   for(int i=0;i<n;i++)
   {
       if(!visited[i])//The graph is connected. (All the vertices in the graph are connected)
       {
           cout<<"NO\n";
           return 0;
       }
   }
   cout<<"YES\n";
    
}