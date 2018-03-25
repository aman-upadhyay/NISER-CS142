#include<iostream>                     //Includes iostream library
using namespace std;
class node                             //Creates Node
{
public:
int data;
node *next;                            //Node contains two parts data and a pointer
};

class linkedlist                       //defines linkedlist
{
private:
node *head, *tail;                     // creates pointer  head and tail
public:
linkedlist()
{
head=NULL;                             // initilises head and tail to NULL
tail=NULL;
}
void insert(int data)                  // creates function to insert node to end
{
node *temp=new node();                 
temp->data=data;                       //feeds data in temps data and points it to NULL
temp->next=NULL;
if(head==NULL)                         //checks if Linked list is empty
{
head=temp;                             //creates first node
tail=temp;
}
else
{
tail->next=temp;                      //insert at the end of the linked list
tail=temp;
}
}

void insertAt(int pos, int data)     //inserts at a pos
{
node *pre=new node;
node *cur=new node;
node *temp=new node;
cur=head;
for(int i=1;i<pos;i++)              //takes cur to the pos where we have to insert the new node
{
pre=cur;
cur=cur->next;
}
temp->data=data;
pre->next=temp;	
temp->next=cur;
}
void deleteend()                   //deletes at the end of the ll
{
node *current=new node;
current=head;
while(current->next!=tail)         //takes current to the second last node of ll
{current=current->next;
}
current->next=NULL;
}
void deleteAt(int pos)             //deletes at a pos
{
node *current=new node;
node *previous=new node;
current=head;
for(int i=1;i<pos;i++)              //takes cur to the pos where we have to delete the node
{
previous=current;
current=current->next;
}
previous->next=current->next;
}
void display()                       //displays the ll
{
node *temp=new node;
temp=head;
while(temp!=NULL)                    //takes temp to each and every node of the ll
{cout<<temp->data;
cout<<"->";
temp=temp->next;
}
cout<<"NULL\n";
}
int countItems()                    //counts node in a ll
{
node *temp=new node;
temp=head;
int x = 0;
while(temp!=NULL)                   //takes temp to each and every node of the ll
{x++;
temp=temp->next;
}
return x;                            //returns the value of size of ll
}
};

int main()
{
 linkedlist l;                        //creates an oblect under linkedlist (l)  
 l.insert(1);                         //creates nodes and inserts datas
 l.insert(2);
 l.insert(3);
 l.insert(4);
 l.display();                           //displays ll
 cout<<l.countItems()<<"\n";
 l.deleteend();                         //delets end node of ll
 l.display();
}
