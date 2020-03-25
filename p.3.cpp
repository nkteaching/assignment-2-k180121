#include<iostream>
#include<string.h>
using namespace std;
class node{
	public:
	char data;
	node *next;
	node(){}
	node(char d)
	{
	data=d;
	}
	node(char d,node *n)
	{
		data=d;
		this->next=n;
	}
};
class Stack{
	public:
	node *head,*tail;
	int length;
	Stack():head(0),tail(0),length(0){}
	void push(char x)
	{
		node *n;
		n=new node();
		n->data=x;	
		n->next=head;
		head=n;
		length++;
	}
	
	char pop()
	{
		node *current;
		current=head->next;
		char x=head->data;
		head->next=0;
		head=current;
	
		return x;
	}
	
	
	int isEmpty()
	{
		return head==NULL;
	}

	bool operator == (Stack &s2)
		{
			
			while (!isEmpty())
			{
				if(head->data != s2.head->data)
				{
					return false;
					
				}
				head=head->next;
				s2.head=s2.head->next;
					
				
			}
			return true;
		}
	void display()
	{
		
		node *cur;
		cur=head;
		if(isEmpty())
		{
			cout << "Stack empty" << endl;
			return;
		}
		while(cur != tail)
		{
			cout << cur->data << endl;
			cur=cur->next;
			
		}
		cout << endl;
	}
};
	
int main()
{
	Stack s1,s2;
	
	string s;
	cout << "enter string";
	cin >> s;
	int length=s.length();
	for(int i=0;i<length;i++)
	{
		// if its opening parenthesis push it into stack1
		if((s[i] == '(') || (s[i] == '[') || s[i] == '{')
		{
			s1.push(s[i]);
		}
		// closing parenthesis intoe second stack
		if((s[i] == ')') || (s[i] == ']') || s[i] == '}')
		{
			s2.push(s[i]);
		}
	}
	bool flag=false;
	while(!s1.isEmpty())
	{
		flag=false;
		node *current;
		current=s2.head;
		// pop each opening parenthesis at a time and compare it to stack2 elements to find its matching closing parenthesis
		int temp=s1.pop();
		if(temp == '(')
		{
			while(!s2.isEmpty())
			{
				if(current->data == ')')
				{
					cout << s2.pop();
					flag=true;
					break;
				}
				current=current->next;
			}
			
		}
		else if(temp == '[')
		{
			while(!s2.isEmpty())
			{
				if(current->data == ']')
				{
					cout << s2.pop();
					flag=true;
					break;
				}
				current=current->next;
			}
			
		}
		else if(temp == '{')
		{
			while(!s2.isEmpty())
			{
				if(current->data == '}')
				{
					cout << s2.pop();
					flag=true;
					break;
				}
				current=current->next;
			}
			
		}
		// not found then its false
		if(flag==false)
		{
			cout << "false" << endl;
			exit(1);
		}
	}
	cout << "true";
	
	
	
}
