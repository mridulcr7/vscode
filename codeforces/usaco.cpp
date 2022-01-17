
#include <bits/stdc++.h> 

using namespace std;

typedef long long ll;
typedef pair<ll,ll> pr;


void solve()
{
    int n,p,l,r,ans=0,s=0;
    cin>>n>>p;
    vector<int> b(p+1,0),c(p+1,0),a(p+1,0);
    for(int i=0;i<n;i++)
    {
        cin>>l>>r;
        b[l]++;
        if(l+r+1<=p)
        b[l+r+1]--;
        c[l]++;
        if(l-(r+1)>=0)
        c[l-(r+1)]--;
        a[l]--;
    }
    for(int i=1;i<=p;i++)
    {
        b[i]+=b[i-1];
    }
    for(int i=p-1;i>=0;i--)
    {
        c[i]+=c[i+1];
    }
    for(int i=0;i<=p;i++)
    {
       a[i]=a[i]+b[i]+c[i];
       if(a[i]!=1)
       a[i]=0;
      // cout<<b[i]<<" "<<c[i]<<" "<<a[i]<<"\n";
       if(a[i]==0)
       s++;
       else
       {
           ans=max(ans,s);
           s=0;
       }
    }
    ans=max(ans,s);
    cout<<ans<<"\n";
}
   
       
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
	int t=1;
  //  cin>>t;
    while(t--)
    {
       solve();
    }    
}