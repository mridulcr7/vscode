#include <bits/stdc++.h> 

using namespace std;

int binarysearch1(vector<int> &a,int n,int x)
{
    int l=0,h=n-1,m;
    m=(l+h)/2;
    while(l<=h)
    {
        m=(l+h)/2;
        if(a[m]==x)
        {
            return m;
        }
        else if(x>a[m])
        {
            l=m+1;
        }
        else{
            h=m-1;
        }
       // cout<<l<<" "<<h<<"\n";
    }
    return -1;
}

int binarysearch2(vector<int>&a,int l,int h,int x)
{
    if(l>h)
    return -1;
    int m=(l+h)/2;
    if(a[m]==x)
    return m;
    else if(x>a[m])
    return binarysearch2(a,m+1,h,x);
    else
    return binarysearch2(a,l,m-1,x);
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n,i;
    cin>>n;
    vector<int> a(n);
    for(i=0;i<n;i++)
    {
        cin>>a[i];
    }
    cout<<binarysearch2(a,0,n-1,3);
}