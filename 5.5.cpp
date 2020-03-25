#include<iostream>
using namespace std;
void recursion1n(int a,int n)
{
	// runs until a is greater than n
	if(a > n)
	{

		return;
	}
	else
	{
		// if a is a negative interger print a
		if(a%2 != 0)
		{
			cout << a << endl;
		}
		// a goes to next number
		recursion1n(a+1,n) ;
	}
}
void recursionn1(int a,int n)
{
	// loop ends when n is smaller than a
	if(n < a)
	{
		return;
	}
	else
	{
		// prints n when n is odd
		if(n%2 != 0)
		{
			cout << n << endl;
		}
		// n is decremented by 1
		recursionn1(a,n-1) ;
	}
}
int main()
{
	recursion1n(1,6);
	cout << endl;
	recursionn1(1,6);

}
