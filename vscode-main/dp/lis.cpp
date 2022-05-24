#include <bits/stdc++.h> 

using namespace std;


typedef long long ll;
typedef pair<ll,ll> pr;


ll mridul=LLONG_MAX;
ll mod= 1e9+7;
vector<int> adj[100001];
vector<bool> visited(100001,false);


int main() {
    ios::sync_with_stdio(0);
    cin.tie(NULL);
	ll n=0,m=0,x=0,y=0,ans=0;
    cin>>n;
    vector<ll> a(n);
    for(int i=0;i<n;i++)
    {
        cin>>a[i];
    }
    vector<ll> d(n+1,1e18);
    d[0]=-1e18;
    for(int i=0;i<n;i++)
    {
        ll l=0,h=n,pos;
        while(l<=h)
        {
            ll mid=(l+h)/2;
            if(d[mid]<a[i])
            {
                pos=mid;
                l=mid+1;
            }
            else
            {
                h=mid-1;
            }
            
        }
       // cout<<pos<<"\n";
        d[pos+1]=a[i];
        ans=max(ans,pos+1);
    }
    cout<<ans;
    
}