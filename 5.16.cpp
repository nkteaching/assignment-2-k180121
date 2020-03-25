#include<iostream>
#include<string.h>
using namespace std;
bool palindromeword(int s,int e,string a)
{
	// if the sth and eth element are not same 
	if(a[s] != a[e])
	{
		return false;
	}
	else
	{
		// keeps adding 1 from start and decrementing 1 from back
		palindromeword(s+1,e-1,a);
	}
	// if string ends return true
	return true;
	
}
bool palindromesentence(int s,int e,string a)
{
	// of string ends return true
	if( s== e)
	{
		return true;
	}
	// if sth element is any other character other than an alphabet add one to s
	if (a[s] <= '97' || a[s] >= '122' )
	{
		palindromesentence(s+1,e,a);
	}
	// if eth element is any other character other than an alphabet decrement one to e
	else if (a[e] <= '97' || a[e] >= '122' )
	{
		palindromesentence(s,e-1,a);
	}
	// if the corresponding sth and eth element are not same return false
	else if(a[s] != a[e])
	{
		return false;
	}
	else
	{
		palindromesentence(s+1,e-1,a);
	}
}
int main()
{
	string a;
	int i=5;
	cin >> a;
	
	cout << palindromeword(0,i-1,a) << endl;
	i=20;
	cin >> a;
	cout << palindromesentence(0,i-1,a);
	
}
