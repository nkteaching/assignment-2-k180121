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
	Stack &reverse(Stack &s1,int l)
	{
		// runs to the length of stack
		while(l != 0)
		{
		
			node *current = head;
			int loop = l;
			// makes the current pointer reach the second last element of stack
			while(loop != 0)
			{
				current= current->next;
				loop--;
			}	
			l--;
			int x=pop();
			s1.push(x);
		
		}
		return s1;
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
	Stack s,s1;
	s.push(5);
	s.push(3);
	s.push(8);
	s.push(2);
	s.display();
	
	cout << endl;
	// s is pushed into s1
	while(!s.isEmpty())
	{
		s1.push(s.pop());
	}
	// s is in reverse order
	s= s1.reverse(s1,s1.length);
	cout << "s:" << endl;
	s.display();

	
}
