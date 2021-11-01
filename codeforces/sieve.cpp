#include <bits/stdc++.h> 

using namespace std;

vector<int> a;

void sieve(int n)
{
    bool prime[n+1];
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
            a.push_back(p);

}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
	int n;
    cin>>n;
    sieve(n);
    for(auto it=a.begin();it!=a.end();it++) 
    {
        cout<<*it<<"\n";
    }
}


