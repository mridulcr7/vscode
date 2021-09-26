#include <bits/stdc++.h> 

using namespace std;

typedef long long ll;
typedef pair<ll,ll> pr;

ll mod=1000000007;

bool compare(pair<ll,ll> &a, pair<ll,ll> &b)
{
    return (a.second < b.second);
}

struct comp1{
    bool operator()(pair<ll,ll> a , pair<ll,ll> b){     
        if(a.second==b.second)
          return (a.first < b.first);
        return a.second < b.second;
    }
};    
double p=3.14159265358979323846;

int abs(int a,int b)
{
    if(a>b)
    return a-b;
    else
    return b-a;
} 


void solve()
{
   ll n,k,s=0,i,m1=INT_MIN,m2=INT_MIN,c1,c2;
   cin>>n;
   char t;
   for(i=0;i<n;i++)
   {
       cin>>t;
       if(t=='+')
       {
           cin>>c1>>c2;
           k=min(c1,c2);
           if(k>m1)
           m1=k;
           k=max(c1,c2);
           if(k>m2)
           m2=k;
       }
       else
       {
           s=0;
           cin>>c1>>c2;
           k=min(c1,c2);
           if(k>=m1)
           s++;
           k=max(c1,c2);
           if(k>=m2)
           s++;
           if(s==2)
           cout<<"YES\n";
           else
           cout<<"NO\n";
       }
   }
  
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