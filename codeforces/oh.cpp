#include <bits/stdc++.h> 

using namespace std;

typedef long long ll;
typedef pair<ll,ll> pr;

bool compare(pair<ll,ll> &a, pair<ll,ll> &b)
{
    return (a.second < b.second);
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


void solve()
{
     return;
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