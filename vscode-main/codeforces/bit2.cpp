#include <bits/stdc++.h> 

using namespace std;

typedef long long ll;

int main()
{
    //1.generating subsets through bit manipulation
    int a[]={1,2,3};
    for(int i=0;i<(1<<3);i++)
    {
        for(int j=0;j<3;j++)
        {
            if(i&(1<<j))
            {
                cout<<a[j]<<" ";
            }
        }
        if(i==0)
        cout<<"NULL";
        cout<<"\n";
    }
}