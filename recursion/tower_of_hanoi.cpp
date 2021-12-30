#include<bits/stdc++.h>

using namespace std;

void toh(int s,int d,int h,int n)
{
    if(n==0)     // Base case
    {
        return;
    }
    toh(s,h,d,n-1);  // hypothesis
    
    cout<<"Moving disc "<<n<<" from plate "<<s<<" to "<<d<<"\n";          //Inductive step
    
    toh(h,d,s,n-1);  // hypothesis
}

int main()
{
    int n,s=1,h=2,d=3;
    cin>>n;
    toh(s,d,h,n); 
    
}