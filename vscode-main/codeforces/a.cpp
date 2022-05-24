#include <bits/stdc++.h>
using namespace std;

int task(vector<int> &vec, int idx)
{
    int nsum = 0, psum = 0;
    for (int i = 0; i <= idx; i++)
    {
        nsum += vec[i];
    }
    psum = vec[idx] * (vec.size() - idx + 1);
    return (psum - nsum);
}

int main()
{
    int n;
    cin >> n;
    vector<int> vec(n, 0);
    for (int i = 0; i < n; i++)
    {
        cin >> vec[i];
    }
    int max = 0, res = INT_MIN,previous=0;
    sort(vec.begin(), vec.end());
    int sum = 0;
    for (int i = 0; i < n; i++)
    {
        cout << vec[i];
    }
  
    return 0;
}