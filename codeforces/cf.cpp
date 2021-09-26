#include <bits/stdc++.h> 

using namespace std;

typedef long long ll;
typedef pair<ll,ll> pr;

ll mod=1000000007;

int abs(int a,int b)
{
    if(a>b)
    return a-b;
    else
    return b-a;
} 


void solve()
{
   ll n,i,j,m,k1=0,k2=0,l,ans=0;
   cin>>n;
   map<ll,ll> a;
   vector<ll> b;
   for(i=0;i<n;i++)
   {
      cin>>l;
      a[l]++;
   }
   for(auto it=a.begin();it!=a.end();it++)
   {
      k1=it->first;
      k2=it->second;
      l=k2/2;
      a[2*k1]=a[2*k1]+l;
      if(k2%2!=0)
      {
         ans++;
         b.push_back(k1);
      }
   }
   cout<<ans<<"\n";
   for(i=0;i<ans;i++)
   cout<<b[i]<<" ";
   cout<<"\n";
}
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
	int t=1;
    //cin>>t;
    while(t--)
    {
       solve();
    }    
}