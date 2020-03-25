#include<iostream>
#include<string.h>
using namespace std;
class node{
	public:
	int data;
	node *next;
	node(){}
	node(int d)
	{
	data=d;
	}
	node(int d,node *n)
	{
		data=d;
		this->next=n;
	}
};
class Stack{
	public:
	node *head,*tail;
	Stack():head(0),tail(0){}
	void push(int x)
	{
		node *n;
		n=new node();
		n->data=x;	
		n->next=head;
		head=n;
	}
	
	int pop()
	{
		node *current;
		current=head->next;
		int x=head->data;
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
Stack s;
Stack &addition(Stack &s1,Stack &s2)
{
	int rA=0;
	bool carry=false;
	while(!s1.isEmpty() && !s2.isEmpty())
	{
		// add the head data of each of the stacks into a rA
		rA=s1.pop()+s2.pop();
		// if there was any carry by previous addition add one to the rA
		if(carry == true)
		{
			rA=rA+1;
		}
		carry=false;
		// if the value of result is greater 9 subtract 10 from it and initialise carry as true
		if(rA > 9)
		{
			rA=rA-10;
			carry=true;
		}
		// push the result into s
		s.push(rA);
	}
	return s;
}	
int main()
{
	Stack s1,s2,s3;

	s1.push(1);
	s1.push(2);
	s1.push(3);
	s2.push(1);
	s2.push(2);
	s2.push(7);
	s3=addition(s1,s2);
	s3.display();
}
