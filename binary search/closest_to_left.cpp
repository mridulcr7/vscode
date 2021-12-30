//Given an array of n numbers, sorted in non-decreasing order, and k queries. For each query, print the maximum index of an array element not greater than the given one.
//[T,T,T..T,F,F,F,F]-find the index of last T(similar varitaions)
#include<bits/stdc++.h>

using namespace std; 

typedef long long ll;

int main()
{
    int n,k,x;
    cin>>n>>k;
    vector<int> a(n);
    for(int i=0;i<n;i++)
    cin>>a[i];
    for(int i=0;i<k;i++)
    {
        cin>>x;
        int l=0,h=n-1,m,ans=-1;
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
        if(ans==-1)
        cout<<"0\n";
        else
        cout<<ans+1<<"\n";
    }
}