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
ll mod=1000000007;

int abs(int a,int b)
{
    if(a>b)
    return a-b;
    else
    return b-a;
} 

int msb(int n)
{
    int j,k=0;
      
    return k;
}

void solve()
{
    ll n,j,k=INT_MIN,i,l,r,m=0,t,rem,p1,p2,s;
    cin>>n;
    vector<int> arr(n),ans(n);
    vector<pr> a;
      for(i=0;i<n;i++)
      cin>>arr[i];
        for(i=0;i<n;i++)
        {
            a.push_back(make_pair(msb(arr[i]),arr[i]));
        }
        sort(a.begin(),a.end());
        for(i=0;i<n;i++)
                        {
                           cout<<a[i].first<<" "<<a[i].second<<"\n";
                            ans[i]=a[i].second;
                        }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
	int t=1,n,j,k=0;
    cin>>n;
    for(j=0;j<=31;j++){
         if((n&(1<<j))!=0)
           {
              cout<<"1\n";
              k++;
           }
           else
           {
              cout<<"0\n";
           }
     }  
}