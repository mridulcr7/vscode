#include <bits/stdc++.h>
using namespace std;

void printDivisors(int n)
{
	
	for (int i=1; i<=sqrt(n); i++)
	{
		if (n%i == 0)
		{
			if (n/i == i)
				cout <<" "<< i;

			else 
				cout << " "<< i << " " << n/i;
		}
	}
}


int main()
{
    int n;
	printDivisors(n);
	return 0;
}


