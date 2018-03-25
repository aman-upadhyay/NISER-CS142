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
		if( r !=NULL)
		{
			display(r->lchild);
			cout<<r->data<<"\n";
			display(r->rchild);
		}
	}

};

int main()
{
	int l,h;
	btree b;
	cout<<"no of units you need to enter\n";
	cin>>l;
	for(int i=1;i<=l;i++)
	{	cout<<"enter input\n";
		cin>>h;
		b.addnode(h);
	}
	b.display(b.root);
}
