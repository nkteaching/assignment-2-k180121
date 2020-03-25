#include<iostream>
using namespace std;
double series(double n,double a,int terms)
{

	if(terms == 0)
	{
		return 0;
	}
	else
	{
		a=1/n;
		// adds a in each time and 1 is added in n
		return series(n+1,a,terms-1)+a;
	}
}
int main()
{
	cout << series(1.0,1,3);
}
