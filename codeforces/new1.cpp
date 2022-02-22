#include <bits/stdc++.h>

using namespace std;

int main(){
   int n,fans=0,ans=0;
   cin>>n;
   vector<int> val(n),wt(n);
   vector<double> ratio(n,0);
   for(int i=0;i<n;i++)
   cin>>val[i];
   for(int i=0;i<n;i++)
   cin>>wt[i];
   for(int i=0;i<n;i++)
  {
      ratio
  }
   int min=dp[0];
   for(int i=1;i<n;i++)
   {
       if(dp[i]<=min)
       {
           min=dp[i];
           fans+=ans;
           ans=0;
       }
       else
       {
           ans=max(dp[i]-min,ans);
       }
       cout<<ans<<" "<<min<<" "<<fans<<"\n";
   }
     fans+=ans;
   cout<<fans<<"\n";
}