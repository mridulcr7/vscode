#include<bits/stdc++.h>

using namespace std;

long long binpow(long long a, long long b, long long m) {
    a %= m;
    long long res = 1;
    while (b > 0) {
        if (b & 1)
            res = res * a % m;
        a = a * a % m;
        b >>= 1;
    }
    return res;
}

int main()
{
    //m should be prime
    int a,m,x;
    cin>>a>>m;
    cout<<binpow(a,m-2,m)<<"\n";
}