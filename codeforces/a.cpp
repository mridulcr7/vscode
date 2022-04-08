#include<bits/stdc++.h>
#include<vector>
using namespace std;
int main()
{
    int n,temp;
    cin>>n;
    int a[n];
    int v[n];
    for(int i=0;i<n;i++)
    {
        cin>>a[i];
    }
    
    for(int i=0;i<n;i++)
    {
        temp=i+1;
        if(a[i]==temp)
        {
            v[i]=i+1;
        }
        
    }
     for(int i=0;i<n;i++)
     {
        cout<<v[i]<<endl; 
     }
    
}