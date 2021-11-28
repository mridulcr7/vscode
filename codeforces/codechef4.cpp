
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
    int a,b;
    cin>>a>>b;
    set<int> x,y;
    int m=a,n=b;
    while (m%2==0)
    {
        x.insert(2);
        m = m/2;
    }
    for (int i = 3;i*i<= m;i =i + 2)
    {
        while (m % i == 0)
        {
            x.insert(i);
            m = m/i;
        }
    }
    if (m > 2)
        x.insert(m);   
    m=1;
    for( auto p:x)
    {
        m=m*p;
    }
    if(b%m==0)
    cout<<"YES\n";
    else
    cout<<"NO\n";
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