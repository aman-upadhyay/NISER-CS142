#include <iostream>
using namespace std;
int l=0;
class arrays
{
public:
    int arr[100];
    void insert(int a)
    {
           arr[l]=a;
        int k=a;
        int j=l;
            while(k!=0)
            {
                k=(k-1)/2;
                if(arr[k]<arr[j]){
                    int p=arr[k];
                arr[k]=arr[j];
                arr[j]=p;
                    j=k;
                }
            }
        l++;
    }
    void display()
    {
        for(int i=0;i<l;i++)
        {
            cout<<arr[i]<<endl;
        }
    }
    void deelete()
    {
        arr[0]=arr[l-1];
        arr[l-1]=arr[l];
        l--;
        int i=0;
        int lc=2*i+1;
        while(lc<=l)
        {
         lc=2*i+1;
            int rc=2*i+2;
            if(rc==arr[i])
            {
                if(lc>arr[i]){
                    int w=arr[lc];
                arr[lc]=arr[i];
                arr[i]= w;
                    i=lc;
                }
            else
                break;
            }
        else
        {
            if(arr[lc]<arr[rc]&&arr[i]<arr[rc])
            {
                int w=arr[rc];
               arr[rc]=arr[i];
                arr[i]=w;
                i=rc;
            }
            else if(arr[rc]<arr[lc]&&arr[lc]>arr[i])
            {
                int w=arr[lc];
                arr[lc]=arr[i];
                arr[i]=w;
                i=lc;
            }
            else
                break;
        }
        }
    }
};
int main()
{
    arrays obj;
    obj.insert(2);
    obj.insert(8);
    obj.insert(10);
   obj.insert(5);
    obj.insert(3);
   obj.insert(4);
    obj.insert(6);
    obj.deelete();
    obj.deelete();
   obj.display();
    
}
