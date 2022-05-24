#include<bits/stdc++.h>

using namespace std;

void sort(int *a,int n)
{
    if(n==1)     // Base case
    {
        return ;
    }
    sort(a,n-1);  // hypothesis

    int j=n-2,k=a[n-1];           //Inductive step
    while(a[j]>k && j>=0)
    {
        a[j+1]=a[j];
        j--;
    }
    a[j+1]=k;
}

int main()
{
    int n=6;
    int a[]={3,1,5,9,7,6};
    sort(a,n); //similar to insertion sort
    for(auto x:a)
    cout<<x<<" ";
}