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
	s1.push(3);
	s1.push(4);
	s1.push(10);
	s1.push(8);
	s1.display();
	cout << endl;
	//s is in reverse order
	s=reverse(s1,s);
	//s2 is now in original order
	s2=reverse(s,s2);
	s2.display();
	

}
