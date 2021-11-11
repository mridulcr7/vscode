#include <iostream>
using namespace std;
 
void fun(int x)
{
    if(x > 0)
    {
        fun(--x);
        cout << x <<" ";
        fun(--x);
    }
}
 
int main()
{
    int a = 4;
    fun(a);
    return 0;
}