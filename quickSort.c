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



int main(){
    int arr[7] = {1,5,2,9,7,0,8};
    quickSort(arr, 0, 6);
    for(int i =0;i<7;i++){
        printf("%d\n", arr[i]);
    }

return 0;
}