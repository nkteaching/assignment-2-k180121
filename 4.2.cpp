#include<iostream>
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
	int length;
	Stack():head(0),tail(0),length(0){}
	void push(int x)
	{
		node *n;
		n=new node();
		n->data=x;	
		n->next=head;
		head=n;
		length++;
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
	int peek()
	{
		
		return head->data;
		
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
Stack &ascending(Stack &s,Stack &s1)
{

	int temp=0,temp2=0;
	while(!s.isEmpty())
	{
		//2 8 3 5
		temp=s.pop();
		while(temp > s.peek() )
		{
			s1.push(temp);
			temp=s.pop();
		}
		if(s.peek() > temp)
		{
			temp2=s.pop();
			while(temp< temp2 )
			{
				s1.push(temp2);
				
				temp2=s.pop();
				
			}
		}
		s1.display();
		
//		while(temp > s.peek() && !s.isEmpty())
//		{	
//			s1.push(temp);
//			temp=s.pop();
//			if(temp < s.peek())
//			{
//				temp=temp2;
//				temp2=s.pop();
//				while(temp > temp2 && !s1.isEmpty())
//				{
//					s1.push(temp2);
//					temp2=s.pop();
//					
//				}
//			}
//		}	
		
	
		
		
		
	}
	return s1;
	
}	
int main()
{
	Stack s,s1;
	s.push(5);
	s.push(3);
	s.push(8);
	s.push(2);
	while(!s.isEmpty())
	{
		s1.push(s.pop());
	}
	s1.display();
	s= ascending(s1,s);
	cout << "s:" << endl;
	s.display();
}
