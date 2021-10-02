#include <bits/stdc++.h> 

using namespace std;

typedef long long ll;
typedef pair<ll,ll> pr;

bool compare(pair<ll,ll> &a, pair<ll,ll> &b)
{
    if(a.second!=b.second)
    return (a.second > b.second);
    else
    return (a.first<b.first);
}
 
struct comp1{
    bool operator()(pair<ll,ll> a , pair<ll,ll> b){     
        if(a.first==b.first)
          return (a.second < b.second);
        return a.first < b.first;
    }
};    
ll mod=1000000007;

int abs(int a,int b)
{
    if(a>b)
    return a-b;
    else
    return b-a;
} 

int msb(ll n)
{
    int i=63;
    while((n&(1ll<<i))==0 && i>0)
    {
        i--;
    }
    return i;
}


void solve()
{
    ll n,j,k,i,l=1,m=-1,t,sum=0,s=0;
    cin>>n;
    t=n;
    map<ll,ll> a;
    while (n % 2 == 0)
    {
        a[2]++;
        n = n/2;
     
    }
    for (ll i = 3; i *i<= n; i = i + 2)
    {
        
        while (n % i == 0)
        {
            a[i]++;
            n = n/i;
        }
    }
    if (n > 2)
        a[n]++;
    for(auto it=a.begin();it!=a.end();it++)
    {
       // cout<<it->first<<" "<<it->second<<"\n";
         l=l*(it->first);
        if(it->second>m)
        m=it->second;
    }
    j=msb(m);
    k=(1ll>>j)*1;
    cout<<m<<" "<<k<<"\n";
    if(k!=m)
    {
        sum++;
        j++;
    }
    else
    for(auto it=a.begin();it!=a.end();it++)
    {
        if(it->second!=k)
        s++;
    }
    if(s>0)
    sum++;
    sum=sum+j;
    cout<<l<<" "<<sum<<"\n";

}
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
	int t=1;
   // cin>>t;
    while(t--)
    {
       solve();
    }    
}