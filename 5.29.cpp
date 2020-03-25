#include<iostream>
using namespace std;
// i 0 to 4
void recurse(int i)
{
	if(i > 5)
	{
		return;
	}
	else
	{
		cout << i << endl;
		recurse(i+1) ;
		
	}
	
}
int main()
{
	int i=0;
	recurse(i);
}
