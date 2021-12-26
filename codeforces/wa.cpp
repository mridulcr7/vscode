#include <bits/stdc++.h>
//#include <math.h>
using namespace std;
long no_ofdigit(long n)
{
    long count = 0;
    while (n != 0)
    {
        count++;
        n = n / 10;
    }
    return count;
}
long wrongAddition(long a, long b)
{
    int sum = 0;
    while (a && b)
    {
        long p = 1;
        long dig = no_ofdigit(sum);
        for (long i = 1; i <= dig; i++)
        {
            p = p * 10;
        }
        sum = sum + (a % 10 + b % 10) * p;
        a /= 10;
        b /= 10;
    }
    while (a)
    {
        long p = 1;
        long dig = no_ofdigit(sum);
        for (long i = 1; i <= dig; i++)
        {
            p = p * 10;
        }
        sum = sum + ((a % 10) * p);
        a /= 10;
    }
    while (b)
    {
        long p = 1;
        long dig = no_ofdigit(sum);
        for (long i = 1; i <= dig; i++)
        {
            p = p * 10;
        }
        sum = sum + ((b % 10) * p);
        b /= 10;
    }
    // cout<<sum<<endl;
    return sum;
}

int main()
{
    int t;
    cin >> t;
    string s="",s1="";
    char temp;
    while (t--)
    {
        int a, s;
        cin >> a >> s;
        int A = a;
        int S = s;
        int b = 0;
        while (s != 0)
        {
            if (s % 10 <= a % 10)
            {
                int p = 1;
                int dig = no_ofdigit(b);
                for (int i = 1; i <= dig; i++)
                {
                    p = p * 10;
                }
                b = b + ((s % 100 - a % 10) * p);
                temp='0'+(s%100-a%10);
                s=s1+temp;
                s1="";
                s = s / 100;
                a = a / 10;
            }
            else
            {
                long p = 1;
                long dig = no_ofdigit(b);
                for (long i = 1; i <= dig; i++)
                {
                    p = p * 10;
                }
                if(s%10-a%10!=0)
                {
                    `b = b + ((s % 10 - a % 10) * p);
                     temp='0'+(s%10-a%10);
                     s=s1+temp;
                     s1="";
                }
                else
                {
                    s1=s1+'0';
                }
                s = s / 10;
                a = a / 10;
            }
        }
       // b=stoi(s);
        if (S == wrongAddition(A, b))
        {
            cout << b << endl;
        }
        else
        {
            cout << -1 << endl;
        }
    }
    return 0;
}