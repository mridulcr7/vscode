#include <bits/stdc++.h>
using namespace std;

int main(){
    
    string s="lllrulluu",str="";
    char p=s[0];
    for(int i=1;i<s.length();i++)
    {
        if(s[i]!=p)
        {
            str=str+p;
            p=s[i];
        }
    }
    str=str+p;
    cout<<str; 
}