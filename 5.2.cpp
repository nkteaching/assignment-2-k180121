//Write a recursive function that calculates and returns the length of a linked list.
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
class SLL{
	public:
	node *head,*tail;
	SLL(): head(0), tail(0){}
	void insert(node *n)
	{
		if(head==0)
		{
			head=n;
			tail=n;
		}
		else
		{
			n->next=head;
			head=n;
		}
	}
	 void display()
	 {
	 	node *current;
	 	current=head;
	 	while(current != tail->next)
	 	{
	 		cout << current->data << endl;
	 		current=current->next;
		}
	 	
	 }
	 int length(node *n1)
	 {
	 	
	 	if(n1 == tail->next)
	 	{
	 		// returns 0
	 		return 0;
		}
		else
		{
			// moves to the next node and adds 1
			return length(n1->next)+1;
		}
	 	
	 }

};


main()
{
	// node n1(17),n2(15),n3(12),n4(10),n5(8),n6(7),n7(6),n8(5),n9(2),n10(1);
	node n1(1),n2(2),n3(5),n4(6),n5(7),n6(8),n7(10),n8(12),n9(15),n10(17);
	SLL s1,s2;
	s1.insert(&n1);
	s1.insert(&n2);
	s1.insert(&n3);
	s1.insert(&n4);
	s1.insert(&n5);
	s1.insert(&n6);
	s1.insert(&n7);
	s1.insert(&n8);
	s1.insert(&n9);
	s1.insert(&n10);
	
	cout << s1.length(&n10) << endl; 
	
	
}
