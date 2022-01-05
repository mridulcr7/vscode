
#include <bits/stdc++.h> 

using namespace std;

//typedef long long ll;
//typedef pair<ll,ll> pr;


void solve()
{
    int n,k,m=0,ans=INT_MIN,j,l;
    cin>>n>>k;
    vector<int> a(n),b(n);
    b[0]=0,b[n-1]=0;
    for(int i=0;i<n;i++)
    {
        cin>>a[i];
    }
    l=a[0];
    for(int i=1;i<n-1;i++)
    {
        if(a[i]>a[i-1] && a[i]>a[i+1])
        b[i]=1;
        else
        b[i]=0;
    }
    for(int i=1;i<k-1;i++)   
    {
        if(b[i]==1)
        m++;
    }
   // cout<<m<<"\n";
    ans=max(ans,m);
    j=1;
    for(int i=k;i<n;i++)
    {
        if(b[i-k+1]==1)
        m--;
        if(b[i-1]==1)
        m++;
       // cout<<m<<"\n";
        if(m>ans)
        {
            ans=m;
            j=i-k+2;
        }
    }
    cout<<ans+1<<" "<<j<<"\n";
}
   
       
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
	int t=1;
    cin>>t;
    while(t--)
    {
       solve();
    }    
}