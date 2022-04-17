#include<bits/stdc++.h>
#include<vector>
using namespace std;
int main()
{

 int n,diff,sum,maxi,mini=999,result;
 cin>>n;
 int a[n];
 vector<int> v;
 vector<int>v1;
 for(int i=0;i<n;i++)
 {
     cin>>a[i];
 }
 for(int i=0;i<n-1;i++)
 
 {
     diff=a[i+1]-a[i];
     v.push_back(diff);
     
 }


 
 for(int i=0;i<n-2;i++)
 {
     sum=v[i]+v[i+1];
     maxi = sum;
     for(int j=0;j<n-1;j++)
    {
        maxi = max(maxi, v[j]);
    }
    // cout<<maxi<<"\n";
     v1.push_back(maxi);
 
 
 
 
}

// cout<<endl;
// for(int i=0;i<n-2;i++)cout<<v1[i];

sort(v1.begin(),v1.end());
cout<<v1[0];
}