#include<iostream>
#include<string.h>
using namespace std;

template <class t>
t commas(t number,int i,int length)
{
	
	if(i == 0)
	{
		return number;
	}
	else
	{
		if(i != 9)
		{	// makes spac for comma
			for(int j=length;j > i;j--)
			{
				number[j]=number[j-1];
			}
			// insert comma
			number[i]=',';
		}
		
	// decreses to every 3rd number
		return commas(number,i-3,length);
	}
}
int main()
{
//	string a="1265323021";
	
	char a[15]={'2','3','4','5','2','1','3','5','3'};
//	int length= sizeof(a) / sizeof(a[0]);
//	cout << length;
	int length = sizeof(a);
	
	cout << commas(a,length,length);
}
