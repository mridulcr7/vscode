//How many numbers' values are between l and r

#include<bits/stdc++.h>

using namespace std; 

typedef long long ll;

int main()
{
    int n,k,x1,x2;
    cin>>n;
    vector<int> a(n);
    for(int i=0;i<n;i++)
    cin>>a[i];
    sort(a.begin(),a.end());
    cin>>k;
    for(int i=0;i<k;i++)
    {
        cin>>x1>>x2;
        int l=0,h=n-1,m,ans1=n,ans2=-1;
        while(l<=h)
        {
            m=l+(h-l)/2;
            if(a[m]>=x1)
            {
                ans1=m;
                h=m-1;
            }
            else
            {
                l=m+1;
            }
        }
        l=0,h=n-1;
        while(l<=h)
        {
            m=l+(h-l)/2;
            if(a[m]<=x2)
            {
                ans2=m;
                l=m+1;
            }
            else
            {
                h=m-1;
            }
        }
        if(ans1<=ans2)
        cout<<ans2-ans1+1<<" ";
        else   // no possible segment
        cout<<"0 ";
    }
}    