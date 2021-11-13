
#include <bits/stdc++.h> 

using namespace std;

typedef long long ll;
typedef pair<ll,ll> pr;

ll mridul=INT_MAX;

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

void generate(vector<int> &a,vector<int> &c,ll n,ll z,int k)
{
    if(k==n)
    {
        ll ans=1,v;
        ll m=c.size();
        if(m==0)
        {
            return;
        }
       // cout<<m<<" ";
        for(int i=0;i<m;i++)
        ans=ans*c[i];
        // cout<<m<<" "<<n<<" "<<ans<<" "<<n/ans<<" "<<mridul<<" ";
        if(ans>z/ans)
        {
            v=ans;
        }
        else
        {
            v=z/ans;
        }
        if(v<mridul)
        mridul=v;
        //cout<<mridul<<"\n";
    }
    else
    {
        c.push_back(a[k]);
        generate(a,c,n,z,k+1);
      //  cout<<"Deleted element-"<<a[k]<<"\n";
        c.pop_back();
        generate(a,c,n,z,k+1);
    }
}

void solve()
{
    ll x,y,n,ans=1,i,a,b,p,m,e=0,o=0;
    cin>>n;
    if(n==1)
    {
        cout<<"1 1\n";
        return;
    }
    vector<int> f,c;
    a=n;
    while (n%2==0)
    {
        ans=ans*2;
        n = n/2;
    }
    if(ans>1)
    f.push_back(ans);
    for ( i = 3;i*i<= n;i =i + 2)
    {
        ans=1;
        while (n % i == 0)
        {
            ans=ans*i;
            n = n/i;
        }
        if(ans>1)
        f.push_back(ans);
    }
 
    if (n > 2)
        f.push_back(n);
    n=a;
    a=f.size();
    if(a==1)
    {
        cout<<1<<" "<<n<<"\n";
        return;
    }
    // for(i=0;i<a;i++)
    // cout<<f[i]<<" ";
    // cout<<n<<"\n";
     generate(f,c,a,n,0);   
     cout<<n/mridul<<" "<<mridul<<"\n";
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