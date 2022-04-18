#include <stdio.h>
void heap_sort(int a[],int n);
void maxheapify(int a[],int n,int);
void buildmaxheap(int a[],int n);
int swap(int *x,int *y);

int main()
{
  int i,n,m,a[20];
  printf("Enter the no.of elements in Array: ");
  scanf("%d",&n);
  for(i=1;i<=n;i++)
    scanf("%d",&a[i]);
    heap_sort(a,n);
  printf("After heapify");
  for(i=1;i<=n;i++)
    printf("%2d",a[i]);
  return 0;
} 

void maxheapify(int a[],int n,int i)
{
    int l,r,heap;
    int largest;
    l=2*i;
    r=2*i+1;
    if(a[l]>=a[i] && l<=n)
    {
    largest=l;
    }
    else
    {
        largest=i;
    }
    if(a[r]>=a[largest]&&r<=n)
    {
        largest=r;
    }
    if(largest!=i)
    {
        swap(&a[i],&a[largest]);
       
        maxheapify(a,n,largest);
    }
}


int swap(int *x,int *y)
{
    int temp;
    temp=*x;
    *x=*y;
    *y=temp; 
  
}


void buildmaxheap(int a[],int n)
{   
    for(int i=n/2;i>=1;i--){
        maxheapify(a,n,i);
    }
}

void heap_sort(int a[],int n)
{ 
    buildmaxheap(a,n);
    int heapsize=n;
    for(int i=n;i>=2;i--){
        swap(&a[i],&a[1]);
        heapsize--;
        maxheapify(a,heapsize,1);
    }
}
