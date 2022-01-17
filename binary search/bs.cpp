//There are n ropes, you need to cut k pieces of the same length from them. Find the maximum length of pieces you can get.
//Output one real number, maximum length of pieces you can get. The answer will be considered correct if the relative or absolute error does not exceed 10−6.

#include<bits/stdc++.h>

using namespace std; 

typedef long long ll;

int main()
{
    ll n,k,ans;
    cin>>n>>k;
    ll l=1,h=1e18;
    while(l<=h)
    {
        ll m=(l+h)/2;
        ll d=(m/n)+(m%n);
        if(d==k)
        {
            if(m%n==0)
            ans=m-1;
            else
            ans=m;
            break;
        }
        else if(d>k)
        {
            h=m-1;
        }
        else
        {
            l=m+1;
        }
    }
    cout<<ans<<"\n";b
}