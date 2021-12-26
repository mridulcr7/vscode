
#include <bits/stdc++.h> 

using namespace std;

typedef long long ll;
typedef pair<ll,ll> pr;


void solve()
{
    int n,m;
    cin>>n>>m;
    vector<ll> a(n);
    for(int i=0;i<n;i++)
    {
        cin>>a[i];
    }
    int i=0,j=0;
    ll s=0,ans=0;
    while(j<n)
    {
        if(s+a[j]>m)
        {
            s=s-a[i];
            i++;
        }
        else
        {
            s=s+a[j];
            j++;
        }
        if(s>ans)
        ans=s;
    }
    cout<<ans<<"\n";
}
   
       
int main() {
 //    freopen("hps.in", "r", stdin);
//	freopen("hps.out", "w", stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
	int t=1;
  //  cin>>t;
    while(t--)
    {
       solve();
    }    
}