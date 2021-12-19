#include <bits/stdc++.h> 

using namespace std;

typedef long long ll;

int main()
{
    //1.__bulltin_clz and  __builtin_clzll-no. of zeroes at beginning of the number 

    int x=17,y=38; //17-000..0010001
    
    // msb can be found
    cout<< __builtin_clz(x)<<"\n";
    int m=31-__builtin_clz(x);
    cout<<"msb of 17 is:"<<m<<"\n";//counted from 0
    //shortcut for 2^msb
    int t=(1<<m);
    cout<<"2^msb:"<<t<<"\n";
    // for  long long 
    ll a=11;
    cout<< __builtin_clzll(a)<<"\n";
    ll k=63-__builtin_clzll(a);
    cout<<"msb of 11 is:"<<k<<"\n";
    ll j=(1ll<<k);
    cout<<"2^msb:"<<j<<"\n\n";


     //2.__bulltin_ctz and  __builtin_ctzll-no. of zeroes at end of the number 

     ll b=18,c;
     cout<<__builtin_ctzll(a)<<"\n"<<__builtin_ctzll(b)<<"\n\n";

     //3.__bulltin_popcount and  __builtin_popcountll-no. of ones in the number 
     cout<<__builtin_popcountll(a)<<"\n"<<__builtin_popcountll(b)<<"\n\n";

     //4.to check or convert a particular bit of a no.
     if(a&(1ll<<3))
     cout<<"1\n";
     else
     cout<<"0\n";
     b=a;
     b=b|(1<<2);//converts a partciular to 1
     cout<<b<<"\n";
     b=b&~(1<<3);//converts a partciular to 0
     cout<<b<<"\n";
     b=b^(1<<3);//inverts a particular bit
     cout<<b<<"\n";
     b=16;
     if((b&(b-1))==0)//check a number is power of two
     {
         cout<<"Power of 2\n";
     }
    
     
}