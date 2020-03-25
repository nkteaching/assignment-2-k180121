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
class Queue{
	public:
		node *head,*tail;
		Queue():head(0),tail(0){}
		void enqueue(int x)
		{
			node *n;
			n=new node();
			if(tail == 0)
			{
				head=n;
				tail=n;
			}
			n->data=x;
			tail->next=n;
			tail=tail->next;
			
		}
		int dequeue()
		{
			node *temp;
			temp=head;
			int x=temp->data;
			head=head->next;
			
//			delete(temp);
			return x;
			

			
		}
		
		void display()
		{
			node *current;
			current = head;
			if(head == 0)
			{
				cout << "Queue empty";
				return;
			}
			while(current != tail->next)
			{
				cout << current->data << endl;
				current=current->next;
			}
			cout << endl;
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
	s.push(3);
	s.push(4);
	s.push(10);
	s.push(8);
	s.display();
	cout << endl;	
	
	
	Queue q;
	// pops into queue in original order
	while(!s.isEmpty())
	{
		q.enqueue(s.pop());
	}
	
	node *h,*t;
	h=q.head;
	t=q.tail;
	// dequeued into stack in reverse order
	while(h != t->next)
	{	
		int x= q.dequeue();
		s.push(x);
		h=h->next;
		
	}
	s.display();

}
