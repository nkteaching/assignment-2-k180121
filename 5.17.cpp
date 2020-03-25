#include<iostream>
#include<string.h>
using namespace std;
bool check(char c,string s,int i)
{
	// if character c is present return true
	if(c == s[i])
	{
		return true;
		
	}
	// check element c in the string
	else
	{
		check(c,s,i-1);
	}
	// returns false otherwise
	return false;
}
int count(char c,string s,int i)
{
	if(i == 0)
	{
		return 0;
	}
	// if character found add one
	if (c == s[i])
	{
		return count(c,s,i-1)+1;
	}
	// if character not found keep searching
	else
	{
		return count(c,s,i-1);
	}
}
string remove(char c,string s,int i)
{
	
	
	if ( i<= 0)
	{
		
		return s;
	}
	// if character found remove it and move forward
	else
	{
		if(s[i] == c)
		{
			int j;
			for(j=i;j<s.length();j++)
			{
				s[j]=s[j+1];
			}
			s[j]='\0';
		}
		return remove(c,s,i-1);	
	}
	
}
int main()
{
	
	char a;
	string s;
	cin >> s;
	cin >> a;
	int i=s.length()-1;
	cout << endl << check(a,s,i-1) << endl;
	cout << endl << count(a,s,i-1) << endl;
	
	s= remove(a,s,i-1);
	cout << s;
}
