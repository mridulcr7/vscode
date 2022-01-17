//Given an array of n numbers, sorted in non-decreasing order, and k queries. For each query, print the maximum index of an array element not greater than the given one.
//[T,T,T..T,F,F,F,F]-find the index of last T(similar varitaions)
#include<bits/stdc++.h>

using namespace std; 

typedef long long ll;

int main()
{
    int n,k,x;
    cin>>n>>k;
    vector<int> a(n+1);
    a[0]=-1;
    for(int i=1;i<=n;i++)
    cin>>a[i];
    for(int i=0;i<k;i++)
    {
        cin>>x;
        int l=0,h=n,m,ans;
        while(l<=h)
        {
            m=l+(h-l)/2;
            if(a[m]<=x)
            {
                ans=m;
                l=m+1;
            }
            else
            {
                h=m-1;
            }
        }
        
        cout<<ans<<"\n";
    }
}