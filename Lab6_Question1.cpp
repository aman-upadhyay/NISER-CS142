#include <iostream>
using namespace std;

/*
Implement Binary search function. Include:
1. Function that takes in array, size of array and element to be searched. Returns the index of the array where the element is found or -1 if the element is not found. 
2. Function that takes in linked list and element to be searched. Returns the index of the array where the element is found or -1 if the element is not found. 
*/


class Node
{  
   public:
   int num;
   Node* next;
   Node()
   {
	   num=0;
	   next=NULL;
   }
};
class SLL
{
   public:
   Node* head;
   Node* tail;
   int size;

   SLL()
   {
	   size=0;
	   head=NULL;
	   tail=NULL;
   }
   void insert(int n);
   void deleten();
   int countItems();
   void display();
};


   
   //Adds a new element to the end of the linked list.
   void SLL::insert(int n)
   {
      
      Node *tmp=new Node;
      tmp->num=n;
      tmp->next=NULL;
      if(head==NULL)                           // Steps to perform when the list is empty.
      {
         head=tmp;
         
      }
      else
      {
         tail->next=tmp;
        
      }
      tail=tmp;
      size++;
   }
	
	
	
//Deletes the element at the end of the list 
   void SLL::deleten()
   {
                Node* traverse = head;
		//goes to the 2nd last element
	        int count=0;
		while(count<size-2)
		{
			traverse = traverse->next;
			count++;
		}
		
		tail = traverse;
		traverse->next = NULL;
		size--;

   }
	
	
  
	   

   //Returns the number of items in the linked list. 
   int SLL::countItems()
   {
      //using size variable
	  int s=size;
	   return s; 
   }
   
   
	
	
//Displays all the elements in the linked list. Format should be followed as “1 -> 2 -> 3 -> 4 -> NULL” for a linked list holding integers in the order 1,2,3,4. 
void SLL::display()
   {
    if(head==NULL)
      cout << "\n \nNULL \n \nThe List is empty";             // Steps to perform when the list is empty.
    else
    {
      Node *temp = head;
      cout<<"\n \n";
      while(temp != NULL)
      {
       cout << temp->num;
       cout<<"  -->  ";
       temp = temp->next;
      }
      cout<<"NULL \n";
     }
    }
class array
{
    public:
    int *arr;
    int len;
    array()
    {
        len=1;
        arr=new int[len];
    }
};
//function to search a sorted array via binarysearch

int binarySearch(int *L,int x, int first, int last)
{
   if (last >= first)  //first > last)
    {
      int middle = (first + last) / 2;

      if (x == L[middle])
        return middle;
      else if (x < L[middle])
        return binarySearch(L, x, first, middle - 1);
      else 
        return binarySearch(L, x, middle + 1, last);
    }
  return -1;    // failed to find key
}


//this function implements binaryserch of linked list through array
int binSrcLL(SLL l, int key)
{
    array a;
    a.len=l.countItems();
    Node* n=l.head;
    for(int i=0;i<a.len;i++)
    {
     a.arr[i]=n->num;
     n=n->next;
    }
    int p=binarySearch(a.arr,key,0,a.len-1);
    return p;
}
int main()
{
    cout<<"\nEnter the number of array elements: ";
    int s;
    cin>>s;
    array A;
    A.len=s;
    cout<<"\nInput the array in an ascending order: ";
    for(int i=0;i<s;i++)
    {
     cin>>A.arr[i];
    }
    //sortArray(A.arr);
    cout<<"\nEnter the element to be searched: ";
    int key;
    cin>>key;
    int pos=binarySearch(A.arr, key, 0, s-1);
    if(pos==-1)
    {
        cout<<"\nElement not found !";
    }
    else
    {
        cout<<"\nElement found at position: "<<pos+1;
    }
    
    
    //TEST CODE FOR LINKED LIST
    
    SLL l1;
    l1.insert(12);
    l1.insert(34);
    l1.insert(43);
    l1.insert(51);
    l1.insert(62);
    l1.insert(70);
    l1.insert(97);
    //l1.sort()
	
    cout<<"\n \nEXECUTING TEST CODE FOR LINKED LIST";    
   
    int pos2=binSrcLL(l1, 51);
        if(pos2==-1)
    {
        cout<<"\nElement not found !";
    }
    else
    {
        cout<<"\nElement found at position: "<<pos2+1;
    }
    //Let the key be 51
    
    return 0;
}

