#include<iostream>
using namespace std;
class node
{
	public:
	int data;
	node *prev, *next;
};
class DLL
{
	private:
	node *head, *tail;
	public:
	DLL()                        // Default constructor for DLList
	{
		head=NULL;              // initializes the list with both
		tail=NULL;              //head and tail
	}
	void insert(int data)          // inserts Node with data at the end of the list
	{
		node *temp = new node;
		temp->data=data;
		temp->next=NULL;
		if(head==NULL)
		{
			head=temp;
			tail=temp;
		}
		else 
		{
			tail->next=temp;
			temp->prev=tail;
			tail=temp;
		}
	}
	void insertAt(int pos, int data)   // inserts Node with data at the pos
	{
		node *curr=new node;
		node *temp=new node;
		curr=head;
		temp->data=data;
		for(int i=1;i<pos;i++)
		{
			curr=curr->next;
		}
		temp->next=curr;
		temp->prev=curr->prev;
		curr->prev->next=temp;
		curr->prev=temp;
	}
	void deleteend()                // removes the last Node of the list
	{
                node *t=new node;
                t=tail;
		tail->prev->next=NULL;
		tail=tail->prev;
                delete t;
	}
	void deleteAt(int pos)         // removes the pos node
	{
		node *curr=new node;
		curr=head;
		for(int i=1;i<pos;i++)
		{
			curr=curr->next;
		}
		curr->prev->next=curr->next;
		curr->next->prev=curr->next;
	}
	int countitems()          // return the number of Nodes in the list
	{
		node *temp=new node;
		int i=1;
		temp=head;
		while(temp->next!=NULL)
		{
			temp=temp->next;
			i++;
		}
		return i;
	}
	void display()           //displays all the nodes
	{
		node *temp=new node;
		temp=head;
		while(temp!=NULL)
		{
			cout<<temp->data;
			cout<<"->";
			temp=temp->next;
		}
		cout<<"NULL\n";
	}
};
int main()
{
	DLL l;                        //creates an object under dlinkedlist (l)  
	l.insert(1);                         //creates nodes and inserts datas
	l.insert(2);
	l.insert(3);
	l.insert(4);
	l.display();                           //displays dll
	cout<<l.countitems()<<"\n";
	l.deleteend();                         //delets end node of dll
	l.display();
	l.insert(6);
	l.insertAt(4,5);
	l.insertAt(4,4);
	l.display();
}
