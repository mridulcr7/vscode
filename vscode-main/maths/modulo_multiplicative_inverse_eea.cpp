#include<bits/stdc++.h>

using namespace std;

int gcd(int a, int b, int& x, int& y) {
    if (b == 0) {
        x = 1;
        y = 0;
        return a;
    }
    int x1, y1;
    int d = gcd(b, a % b, x1, y1);
    x = y1;
    y = x1 - y1 * (a / b);
    return d;
}

int main()
{

    //a and m should be co-prime
    int a,m,x,y;
    cin>>a>>m;
    int g=gcd(a,m,x,y);
    cout<<x<<"\n";
    x=(x%m+m)%m;//for negative values of x
    cout<<x<<"\n"<<a*x<<"\n"<<(a*x)%m<<"\n";
}    