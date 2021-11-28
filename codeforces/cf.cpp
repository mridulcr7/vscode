#include <bits/stdc++.h> 

using namespace std;

typedef long long ll;
typedef pair<ll,ll> pr;

bool compare(pair<ll,ll> &a, pair<ll,ll> &b)
{
    return (a.first < b.first);
}
 
struct comp1{
    bool operator()(pair<ll,ll> a , pair<ll,ll> b){     
        if(a.first==b.first)
          return (a.second < b.second);
        return a.first < b.first;
    }
};    
int mridul=200000;
vector <int> ans;
void sieve()
{
    bool prime[mridul+1];
    memset(prime,true,sizeof(prime));
    int i,p;
    for(p=2;p*p<=mridul;p++)
    {
        if(prime[p]==true)
        {
            for(i=p*p;i<=mridul;i+=p)
            {
                prime[i]=false;
            }
        }
    }
    for (p = 2; p <= mridul; p++)
        if (prime[p])
            ans.push_back(p);

} 

int msb(int n)
{
    int j,k=0;
      
    return k;
}

void solve()
{
    ll n,d,i,j,a=0,b=0,ans=0,m=INT_MIN,o;
    cin>>n>>d;
    string s;
    cin>>s;
    i=0,j=0,o=0;
    while(j<n)
    {
        if(s[j]=='b')
        {
            o++;
        }
        if(o>d)
        {
            while(o>d)
            {
                if(s[i]=='b')
                o--;
                i++;
            }
            a=j-i+1;
            if(a>m)
            m=a;
            j++;
        }
        else
        {
            a=j-i+1;
            if(a>m)
            m=a;
            j++;
        }
    }
    i=0,j=0,o=0;
    while(j<n)
    {
        if(s[j]=='a')
        {
            o++;
        }
        if(o>d)
        {
            while(o>d)
            {
                if(s[i]=='a')
                o--;
                i++;
            }
            b=j-i+1;
            if(b>m)
            m=b;
            j++;
        }
        else
        {
            b=j-i+1;
            if(b>m)
            m=b;
            j++;
        }
    }
    cout<<m<<"\n";
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
	int t=1,n,j,k=0;
  //  cin>>t;
   // sieve();
    while(t--)
    {
        solve();
    }
}