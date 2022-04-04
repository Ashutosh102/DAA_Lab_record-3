#include <stdio.h>
void swap(int *a, int *b);
void quickSort(int array[], int low, int high);
int partition(int array[], int low, int high);
int main() {
  int a[20], n;
  printf("Input\n");
  scanf("%d",&n);
  printf("Enter into array\n");
  for(int i=0; i<n; i++){
      scanf("%d",&a[i]);
  }
  printf("\n");
  printf("Unsorted Array\n");
  for(int i=0; i<n; i++){
      printf("%d ",a[i]);
  }
  printf("\n");
  quickSort(a,0,n-1);
  int part=partition(a,0,n-1);
  printf("\n%d is the partition number",part);
  printf("\nSorted array\n");
  for(int i=0; i<n; i++){
      printf("%d ",a[i]);
  }
  printf("\n");
  return 0;
}
int partition(int array[], int low, int high) {
  int t, *a, *b;  
  int pivot = array[high];
  int i = (low - 1);
  for (int j = low; j < high; j++) {
    if (array[j] <= pivot) {
      i++;
      swap(&array[i], &array[j]);
    }
  }
  swap(&array[i + 1], &array[high]);
  return (i + 1);
}
void swap(int *a, int *b) {
  int t = *a;
  *a = *b;
  *b = t;
}
void quickSort(int array[], int low, int high) {
  int pi;
  if (low < high) {
    pi = partition(array, low, high);
    quickSort(array, low, pi - 1);
    quickSort(array, pi + 1, high);
  }
}
