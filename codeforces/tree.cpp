#include <bits/stdc++.h>
using namespace std;

int main(){
    int t;cin>>t;
    while (t--)
    {
        int r,g,b;
        cin>>r>>g>>b;
        if (r+g<b)
        {
            cout<<-1<<endl;
            continue;
        }
        vector<char> vv;
        if (b==1)
        {
            for (int i = 0; i < r; i++)
            {
                vv.push_back('R');
            }
            for (int i = 0; i < g; i++)
            {
                vv.push_back('G');
            }
            vv.push_back('B');
            for(auto i:vv){
                cout<<i;
            }
            cout<<endl;
            for (int i = 0; i < r+g+b-1; i++)
            {
                cout<<i+1<<" "<<i+2<<endl;
            }
            continue;
        }
        vv.push_back('R');
        vv.push_back('B');
        vv.push_back('G');
        vv.push_back('B');
        for (int i = 0; i < r-1; i++)
        {
            vv.push_back('R');
        }
        for (int i = 0; i < g-1; i++)
        {
            vv.push_back('G');
        }
        for (int i = 0; i < b-2; i++)
        {
            vv.push_back('B');
        }
        for(auto i:vv){
            cout<<i;
        }
        cout<<endl;
        cout<<1<<" "<<2<<endl;
        cout<<1<<" "<<3<<endl;
        cout<<3<<" "<<4<<endl;
        int j=0;
        int gg=4+r-1+1,rr=5,bb=4+r-1+g-1+1,bbn;
        for (int i = rr; i < gg; i++)
        {
            cout<<3<<" "<<i<<endl;
        }
        int bc=0;
        for (int i = 0; i < r-1; i++)
        {
            if (bc<b-2)
            {
                cout<<i+rr<<" "<<bb+i<<endl;
                bbn=bb+i;
            }
                bc++;
        }
        // cout<<bc<<endl;
        // cout<<bbn<<endl;
        for (int i = gg; i < bb; i++)
        {
            cout<<1<<" "<<i<<endl;
        }
        for (int i = 0; i < g-1; i++)
        {
            if (bc<b-2)
            {
                cout<<i+gg<<" "<<i+bbn+1<<endl;
                bc++;
            }
            
        }
        
    }
    
    return 0;
}