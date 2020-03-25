#include<iostream>
using namespace std;
int cube(int b,int e)
{
	if(e==1)
	return b;
	else
	// multiplies b thrice
	return b*cube(b,e-1);
}
int main()
{
	int c=3;
	cout << cube(2,c);
	
}

