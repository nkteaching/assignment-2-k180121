#include<iostream>
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
	
	
	char *a;
	a=new char[5];
	// push first string in one stack
	for(int i=0;i<5;i++)
	{
		cin >> a[i];
		s1.push(a[i]);
	}
	char *b;
	b=new char[5];
	// push second string in second stack
	for(int i=0;i<5;i++)
	{
		cin >> b[i];
		s2.push(b[i]);
	}
	s1.display();
	cout << endl;
	s2.display();
	// compare the two stacks
	if(s1 == s2)
	{
		cout << "Palindrome";
	}
	else 
	{
		cout << "not palindrome";
	}
	
}
