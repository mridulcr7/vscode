
#include <bits/stdc++.h> 

using namespace std;

typedef long long ll;
typedef pair<ll,ll> pr;

ll mridul=INT_MAX;

ll mm=1e9;

bool compare(pair<string,ll> &a, pair<string,ll> &b)
{
    
    return a.second>b.second;
}
 
struct comp1{
    bool operator()(pair<ll,ll> a , pair<ll,ll> b){     
        if(a.first==b.first)
          return (a.second > b.second);
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

ll digit(ll n)
{
    ll s=0;
    while(n>0)
    {
        s=s+n%10;
        n/=10;
    }
    return s;
}

void solve()
{
    ll n,k,i,j,ans=1,pair=0,odd=0;
    cin>>n>>k;
    string s;
    cin>>s;
    vector<int> a(26,0);
    for(int i=0;i<n;i++)
    {
        a[s[i]-97]++;
    }
     for(int i=0;i<26;i++)
    {
        pair=pair+a[i]/2;
        if(a[i]%2!=0)
        odd++;
    }   
    ll l=2,h=n/k;
   // cout<<l<<" "<<h<<"\n";
    while(l<=h)
    {
        ll m=(l+h)/2;
        ll t=0,r,c;
        r=m/2;
        if(m%2==0)
        t=(2*pair)/m;
        else
        {
           int temp=pair/r;
           if(odd>=temp)
           t=temp;
           else
           {
               t=temp+(2*(pair-odd*r))/m;
           }
        }
        //cout<<m<<" "<<t<<"\n";
        if(t>=k)
        {
            ans=m;
            l=m+1;
        }
        else
        {
            h=m-1;
        }
    }
    cout<<ans<<"\n";
    
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