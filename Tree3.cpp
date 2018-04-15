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
	void arr(node *r)
	{
		if(r!=NULL)
		{
			arr(r->lchild);
			log[l]=r->data;
			l++;
			arr(r->rchild);
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
	{
		l=0;
		arr(root);
		root = NULL;		     
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
	void count(node *r)
	{
		l=0;
		arr(root);
		cout<<"No of nodes in this tree is "<<l<<"\n";
	}
	void rangesearch(node *r,int k1,int k2)
	{
		l=0;
		arr(root);
		cout<<"--------------------------\n";
		for(int h=0;h<l;h++)
		{
			if(log[h]>=k1 && log[h]<=k2)
			{
				cout<<log[h]<<"\n";
			}
		}
		cout<<"--------------------------\n";
	}
};
int main()
{
	int l,h,key,k1,k2;
	btree b;
	cout<<"no of units you need to enter\n";
	cin>>l;
	for(int i=1;i<=l;i++)
	{	cout<<"enter input\n";
		cin>>h;
		b.addnode(h);
	}
	b.display(b.root);
	b.count(b.root);
	cout<<"Insert first key for range search\n";
	cin>>k1;
	cout<<"Insert second key for range search\n";
	cin>>k2;
	b.rangesearch(b.root,k1,k2);

}
