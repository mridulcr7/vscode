
#include <bits/stdc++.h> 

using namespace std;

typedef long long ll;
typedef pair<ll,ll> pr;


void solve()
{
    ll n,m,ans=0;
    cin>>n>>m;
    vector<ll> a(n*m),c(n*m);
    for(int i=0;i<(n*m);i++)
    {
        cin>>a[i];
        c[i]=a[i];
    }
    vector<vector<ll>> b(n,vector<ll> (m));
    sort(a.begin(),a.end());
    ll j1=0,j2=0;
    for(int i=0;i<(n*m);i++)
    {
        if(j2==m)
        {
            j1++;
            j2=0;
        }
        b[j1][j2]=a[i];
        j2++;
    }
    for(int i=0;i<(n*m);i++)
    {
        ll k=LLONG_MAX,temp;
        j1=-1,j2=-1;
        for(int x=0;x<n;x++)
        {
            temp=0;
            for(int y=m-1;y>=0;y--)
            {
                if(b[x][y]!=0 && b[x][y]!=c[i])
                {
                    temp++;
                }
                if(b[x][y]==c[i])
                {
                    if(temp<k)
                    {
                        j1=x;
                        j2=y;
                        k=temp;
                    }
                    break;
                }
            }
        }
      //  cout<<k<<" "<<j1<<" "<<j2<<"\n";
        b[j1][j2]=0;
        ans=ans+k;
    }
    cout<<ans<<"\n";
}
   
       
int main() {
 //    freopen("hps.in", "r", stdin);
//	freopen("hps.out", "w", stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
	int t=1;
    cin>>t;
    while(t--)
    {
       solve();
    }    
}