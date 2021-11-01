class Solution {
public:
    int findMin(vector<int>& a) {
        int l=0,h=a.size()-1,m,ans;
        int k=h;
        while(l<=h)
        {
            m=l+(h-l)/2;
            if(a[m]<=a[k])
            {
                h=m-1;
                ans=a[m];
            }
            else
            {
                l=m+1;
            }
        }
        return ans;
    }
};