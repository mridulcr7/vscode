#include <bits/stdc++.h>
#include <string>
using namespace std;

void printSS(vector<int> a, vector <int>&ans,int i)
{
    // write your code here
    if (i==a.size())
    {
        if(ans.size()==3)
        {
            for(int i=0;i<3;i++)
            cout<<ans[i]<<" ";
            cout<<"\n";
        }
        return;
    }
    ans.push_back(a[i]);
    printSS(a,ans,i+1);
    ans.pop_back();
    printSS(a, ans,i+1);
}

int main()
{
    vector<int> a={1,2,3,4,5,6};
    vector<int> ans;
    printSS(a,ans,0);
}