#include <bits/stdc++.h> 

using namespace std;

vector<int> a;

int sieve(int n)
{
    bool prime[n+1];
    int c=0;
    memset(prime,true,sizeof(prime));
    int i,p;
    for(p=2;p*p<=n;p++)
    {
        if(prime[p]==true)
        {
            for(i=p*p;i<=n;i+=p)
            {
                prime[i]=false;
            }
        }
    }
    for (p = 2; p <= n; p++)
        if (prime[p])
            {
                c++;
            }
            return c;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
	int n;
    cin>>n;
    cout<<sieve(n);
    // for(auto it=a.begin();it!=a.end();it++) 
    // {
    //     cout<<*it<<"\n";
    // }
}


