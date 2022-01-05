//There are n ropes, you need to cut k pieces of the same length from them. Find the maximum length of pieces you can get.
//Output one real number, maximum length of pieces you can get. The answer will be considered correct if the relative or absolute error does not exceed 10−6.

#include<bits/stdc++.h>

using namespace std; 

typedef long long ll;

int main()
{
    int n,d;
    cin>>n>>d;
    vector<int> a(n);
    for(int i=0;i<n;i++)
    {
        cin>>a[i];
    }
    double l=0,h=100,ans;
    for(int j=0;j<100;j++)
    {
        double m=(l+h)/2;
        vector<double> b(n),c(n);
        for(int i=0;i<n;i++)
        {
            b[i]=a[i]-m;
            if(i==0)
            c[i]=b[i];
            else
            c[i]+=c[i-1]+b[i];
        }
    }
    cout<<ans<<"\n";
}