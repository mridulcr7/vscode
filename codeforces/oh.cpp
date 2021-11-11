
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
    int n,x=0,y=0;
    cin>>n;
    vector<pr> a;
    for(int i=0;i<n;i++)
    {
        cin>>x>>y;
        a.push_back(make_pair(x,y));
    }
    sort(a.begin(),a.end());
    x=a[0].second;
    int i=0,ans=0,t=x;
   while(x>0)
   {
       if(a[i].second==x)
       {
           i++;
           ans++;
       }
       else
       break;
       x--;
   }
   if(ans==t)
   {
       cout<<"NO\n";
       return;
   }
   x=a[n-1].second;
   i=n-1,ans=0,t=n-x+1;
   while(x<=n)
   {
     
       if(a[i].second==x)
       {
           i--;
           ans++;
       }
       else
       break;
         x++;
   }
    if(ans==t)
   {
       cout<<"NO\n";
       return;
   }
   cout<<"YES\n";
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