#include<iostream>
using namespace std;
class node
{
	public:
	int data;
	node *parent;
	node *lchild;
	node *rchild;
};

class btree
{
	public:
	node *root;
	int log[100];
	int l;
	btree()
	{
		root=NULL;
	}
	void addnode(int data)
	{
		node *temp=new node;
		temp->data=data;
		temp->parent=temp->lchild=temp->rchild=NULL;

		if(root==NULL)
		{
			root=temp;
		}
		else
		{ 
			node *curr=root;
			while(true)
			{
				if(data > curr->data)
				{
					if(curr->rchild !=NULL)
					{
						curr=curr->rchild;
					}
					else 
						break;
				}else
				{
					if(curr->lchild !=NULL)
					{
						curr=curr->lchild;
					}
					else
						break;
				}
			}
			if(data > curr->data)
			
				curr->rchild=temp;
			else
				curr->lchild=temp;

		}
	}
	void display(node *r)
	{
		l = 0;
		cout<<"---------------------------\n";
		d(r);
		cout<<"---------------------------\n";
	}
	void d(node *r)
	{
		if( r !=NULL)
		{
			d(r->lchild);
			cout<<r->data<<"\n";
			log[l]=r->data;
			l++;
			d(r->rchild);
		}
	}
	node* search(node *r,int key)
	{
		if( r==NULL)
			cout<<key<<" not found.\n";
		else if(r->data<key)
			  search(r->rchild,key);
		else if(r->data>key)
			  search(r->lchild,key);
		else
			 cout<<key<<" found.\n";
			 return r;
	}
	void deletenode(int key)     
	{	root = NULL;		     
		for(int i=0;i<=l;i++)
		{
			if(log[i]==key)
			{       cout<<"key= "<<key<<"\n";
				l--;
				for(int f=i;f<=l;f++)
				      {
					      log [f]=log [f+1];
				      }
			}
		}
		for(int f=0;f<=l;f++)
		{
			addnode(log[f]);
		}
	}
};
int main()
{
	int l,h,key;
	btree b;
	cout<<"no of units you need to enter\n";
	cin>>l;
	for(int i=1;i<=l;i++)
	{	cout<<"enter input\n";
		cin>>h;
		b.addnode(h);
	}
	b.display(b.root);
	cout<<"Insert key for search\n";
	cin>>key;
	b.search(b.root,key);
	cout<<"Insert key for deletion\n";
	cin>>key;
	b.deletenode(key);
	b.display(b.root);
}
