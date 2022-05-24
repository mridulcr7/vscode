
#include <bits/stdc++.h> 

using namespace std;

typedef long long ll;
typedef pair<ll,ll> pr;

ll mridul=INT_MAX;

bool compare(pair<string,ll> &a, pair<string,ll> &b)
{
    // if(a.second==b.second)
    // {
    //     int l=a.first.size(),z1=a.second,z2=a.second,ans1=0,ans2=0;
    //     for(int i=0;i<l;i++)
    //     {
    //         if(a.first[i]=='1')
    //         {
    //             ans1=ans1+z1;
    //         }
    //         else
    //         {
    //             z1--;
    //         }
    //         if(b.first[i]=='1')
    //         {
    //             ans2=ans2+z2;
    //         }
    //         else
    //         {
    //             z2--;
    //         }
    //     }
    //     if(ans1<ans2)
    //         {
    //             return a.second>b.second;
    //         }
    //         else
    //         {
    //             return a.second<b.second;
    //         }
    // }
    return a.second>b.second;
}
 
struct comp1{
    bool operator()(pair<ll,ll> a , pair<ll,ll> b){     
        if(a.first==b.first)
          return (a.second > b.second);
        return a.first < b.first;
    }
};    
ll mod=1000000007;

int abs(int a,int b)
{
    if(a>b)
    return a-b;
    else
    return b-a;
} 

int msb(ll n)
{
    int i=63;
    while((n&(1ll<<i))==0 && i>0)
    {
        i--;
    }
    return i;
}

// void generate(vector<int> &a,vector<int> &c,ll n,ll z,int k)
// {
//     if(k==n)
//     {
//         ll ans=1,v;
//         ll m=c.size();
//         if(m==0)
//         {
//             return;
//         }
//        // cout<<m<<" ";
//         for(int i=0;i<m;i++)
//         ans=ans*c[i];
//         // cout<<m<<" "<<n<<" "<<ans<<" "<<n/ans<<" "<<mridul<<" ";
//         if(ans>z/ans)
//         {
//             v=ans;
//         }
//         else
//         {
//             v=z/ans;
//         }
//         if(v<mridul)
//         mridul=v;
//         //cout<<mridul<<"\n";
//     }
//     else
//     {
//         c.push_back(a[k]);
//         generate(a,c,n,z,k+1);
//       //  cout<<"Deleted element-"<<a[k]<<"\n";
//         c.pop_back();
//         generate(a,c,n,z,k+1);
//     }
// }

void solve()
{
    int n,ans=0;
    cin>>n;
    string s;
    cin>>s;
    vector<int> a(26,0),b(26,0);
    for(int i=0;i<n;i++)
    {
        if(s[i]>=65 && s[i]<=90)
        {
            a[s[i]-65]++;
        }
        else
        {
            b[s[i]-97]++;
        }
    }
    for(int i=0;i<26;i++)
    {
        if(a[i]>0)
        {
            a[i]=0;
            ans++;
        }
        if(b[i]>0)
        {
            b[i]=0;
            ans++;
        }
    }
    int j=0,i=0,o=0,t=0,m=INT_MAX;
    while(j<n)
    {
        if(s[j]>=65 && s[j]<=90)
        {
            a[s[j]-65]++;
            if(a[s[j]-65]==1)
            t++;
        }
        else
        {
            b[s[j]-97]++;
            if(b[s[j]-97]==1)
            t++;
        }
        if(j-i>0 && s[j]==s[i])
        {
            i++;
        }
        if(t==ans)
        {
            m=min(m,j-i+1);
            j++;
            i=j;
            for(int z=0;z<26;z++)
            {
                a[z]=0;
                b[z]=0;
            }
            t=0;
        }
        else
        {
            j++;
        }
    }
    cout<<m<<"\n";    
}        
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
	int t=1;
   // cin>>t;
    while(t--)
    {
       solve();
    }    
}