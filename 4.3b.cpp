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
		// until length equals zero
		while(l != 0)
		{
		
			node *current = head;
			int loop = l;
			// current reaches the second last element of stack
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
	Stack s1,s2;
	s1.push(5);
	s1.push(3);
	s1.push(8);
	s1.push(2);
	s1.display();
	
	cout << endl;
	
	// s2 is in original order
	s2= s1.reverse(s1,s1.length);
	cout << "s2:" << endl;
	s2.display();

	
}
