#include <bits/stdc++.h> 

using namespace std;

vector<int> a(1000001,0);

void sieve()
{
    a[1]=1;
    int i,p;
    for(p=2;p*p<=100001;p++)
    {
       
        if(a[p]==0)
        {
             a[p]=p;
            for(i=p*p;i<=100001;i+=p)
            {
                if(a[i]==0)
                a[i]=p;
            }
        }
    }
}

void pfs(int n)
{
    int t=n;
    while(t!=1)
    {
        cout<<a[t]<<" ";
        t=t/a[t];
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
	int n;
    cin>>n;
    sieve();
    pfs(n);
}


