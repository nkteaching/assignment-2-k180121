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
			n=new node(x);
			if(tail == 0)
			{
				head=n;
				tail=n;
			}
//			n->data=x;
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
Queue & push(int x,Queue &q)
{
	Queue q1;
	node *h,*t;
	h=q.head;
	t=q.tail;
	// if queue is empty insert x	
	if(t == NULL)
	{
		q.enqueue(x);
		return q;
	}
	// transfer all data of q into a q1
	while(h != t->next)
	{	
		q1.enqueue(q.dequeue());
		h=h->next;
		q1.display();
	}
	// enqueue x
	q.enqueue(x);
	node *qh,*qt;
	qh=q1.head;
	qt=q1.tail;
	// transfer all data back to q
	while(qh != qt->next)
	{	
		q.enqueue(q1.dequeue());
		qh=qh->next;
	}
	return q;		
}

int main()
{
	Queue q;
	q=push(3,q);
	q=push(2,q);
	q=push(1,q);
	q.display();
}
