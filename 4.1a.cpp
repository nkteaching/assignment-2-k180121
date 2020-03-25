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
	void display()
	{
		
		node *cur;
		cur=head;
		while(cur != tail)
		{
			cout << cur->data << endl;
			cur=cur->next;
			
		}
		cout << endl;
	}
};
Stack &reverse(Stack &s,Stack &s1)
{
	while(!s.isEmpty())
	{
		s1.push(s.pop());
	}
	return s1;
}
int main()
{
	Stack s,s1,s2;
	s.push(3);
	s.push(4);
	s.push(10);
	s.push(8);
	s.display();
	cout << endl;
	//stack reverses
	s1=reverse(s,s1);
	// back to original stack
	s2=reverse(s1,s2);
	// reverses
	s=reverse(s2,s);
	s.display();

}
