#include <bits/stdc++.h>
using namespace std;

int main(){
    
    int n;
    cin>>n;
    vector<int> a(n),b(n,0);
    for(int i=0;i<n;i++)
    cin>>a[i];
    for(int i=n-2;i>=0;i--)
    {
        if(a[i]==0)
        {
            b[i]=-1;
            continue;
        }
        else if(a[i]+i>=n-1)
        {
            b[i]=1;
            continue;
        }
        int m=INT_MAX;
        for(int j=1;j<=a[i];j++)
        {
            
            if(b[j+i]!=-1)
            m=min(b[j+i],m);
           
        }
        if(m==INT_MAX)
        b[i]=0;
        else
        b[i]=m+1;
    }
    cout<<b[0]<<"\n";
}