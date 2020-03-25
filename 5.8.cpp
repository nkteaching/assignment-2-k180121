#include<iostream>
using namespace std;
int multiply(int n1,int n2)
{
	// loop runs 2 times
	if(n1==0)
	{
		return 0;
		
	}
	else
	{
		// adds 7 each time
		return multiply(n1-1,n2)+n2;
	}
}
int main()
{
	cout << multiply(2,7);
}
