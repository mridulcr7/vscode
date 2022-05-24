//There are n ropes, you need to cut k pieces of the same length from them. Find the maximum length of pieces you can get.
//Output one real number, maximum length of pieces you can get. The answer will be considered correct if the relative or absolute error does not exceed 10−6.

#include<bits/stdc++.h>

using namespace std; 

typedef long long ll;

int main()
{
    int n,k;
    cin>>n>>k;
    vector<ll> a(n);
    for(int i=0;i<n;i++)
    cin>>a[i];

    //method 1:

    // double l=1,h=1e7,ans;
    // while(h-l>1e-6)
    // {
    //   double m=(l+h)/2;
    //   ll s=0;
    //   for(int i=0;i<n;i++)
    //   s=s+a[i]/m;
    //   if(s>=k)
    //   {
    //       ans=m;
    //       l=m;
    //   }
    //   else
    //   {
    //       h=m;
    //   }  
    // }
    // cout<<ans<<"\n";

    //method 2:
    double l=0,h=1e7,ans;
    for(int i=0;i<100;i++)
    {
        double m=(l+h)/2;
        ll s=0;
        for(int j=0;j<n;j++)
        s=s+a[j]/m;
        if(s>=k)
        {
          ans=m;
          l=m;
        }
        else
        {
          h=m;
        }  

    }
    cout<<fixed<<setprecision(6)<<ans<<"\n";

}