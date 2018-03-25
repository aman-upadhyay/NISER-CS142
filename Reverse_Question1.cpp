#include<iostream>
using namespace std;

class node
{
public:
int data;
node *next;
};

class linkedlist
{
private:
node *head, *tail;
public:
linkedlist()
{
head=NULL;
tail=NULL;
}
void addnode(int data)
{
node *temp=new node();
temp->data=data;

if(head==NULL)
{
head=temp;
tail=temp;
tail->next=NULL;
}
else
{
tail->next=temp;
tail=temp;
tail->next=NULL;
}
}

  void insert_position(int pos, int value)
  {
    node *pre=new node;
    node *cur=new node;
    node *temp=new node;
    cur=head;
    for(int i=1;i<pos;i++)
    {
      pre=cur;
      cur=cur->next;
    }
    temp->data=value;
    pre->next=temp;	
    temp->next=cur;
  }
 void deletenode(int pos)
{
node *current=new node;
node *previous=new node;
current=head;
for(int i=1;i<pos;i++)
{
previous=current;
current=current->next;
}
previous->next=current->next;
}
void display()
{
cout<<"------------------------------------\n";
node *temp=new node;
temp=head;
while(temp!=NULL)
{cout<<temp->data<<"\n";
temp=temp->next;
}
cout<<"------------------------------------\n";
}
void reverse()
{
	node *p=head;
	node *c=p->next;
	node *r=c->next;
	head->next=NULL;
	while(r->next != NULL)
	{
		c->next=p;
		p=c;
		c=r;
		r=r->next;
	}
	r->next=c;
	c->next=p;
	tail=head;
	head=r;
}
};

int main()
{
 int data1,data2,data3,data4,data5,d,n1,n2;
 linkedlist l;
 cout<<"Please enter the data to be added\n";
 cin>>data1;
 l.addnode(data1);
 cout<<"Please enter the data to be added\n";
 cin>>data2;
 l.addnode(data2);
 cout<<"Please enter the data to be added\n";
 cin>>data3;
 l.addnode(data3);
 cout<<"Please enter the data to be added\n";
 cin>>data4;
 l.addnode(data4);
 cout<<"Please enter the data to be added\n";
 cin>>data5;
 l.addnode(data5);
 l.display();
 l.reverse();
 l.display();
}
