#include <stdio.h>
#include <stdlib.h>

void quickSort(int arr[], int low, int high){
    int mid = (low+high)/2;
    int temp;
    int l = low;
    int h = high;
    int pivot = arr[mid];
    do{
        while(pivot>arr[low]){
        low++;
    }
    while(pivot<arr[high]){
        high--;
    }
    if(low<=high){
        temp = arr[low];
        arr[low++]=arr[high];
        arr[high--]=temp;
    }
} while(low<=high);
        if(l<high)
            quickSort(arr,l,high);
        if(low<h)
            quickSort(arr, low, h);
    }


void main() {
  int n ;
  scanf("%d", &n);
  int arr[n];
  for(int i=0; i<n; i++){
      scanf("%d ",&arr[i]);
  }

  quickSort(arr, 0, n - 1);
    for (int i = 0; i < n-1; ++i) {
        printf("%d  ", arr[i]);
    }
    printf("%d", arr[n-1]);
}
