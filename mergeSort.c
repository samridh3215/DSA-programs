#include <stdio.h>


void Merge(int arr[], int left, int mid,int right){
    int i = 0,j=0,k;
    int n1 = mid-left+1, n2= right-mid;
    int L[n1], R[n2]; 
    
    //filling arrays in left
    for (i = 0; i < n1; i++){
        L[i] = arr[left + i];
        }
    //filling arrays in right
    for (j = 0; j < n2; j++){
        R[j] = arr[mid + 1 + j];
        }
    //initialising the variables for merging
    i=0;j=0;k=left;
    //comparing and filling in elements accordingly
    while (i<n1&&j<n2)
    {
        if(L[i]<R[j]){
            arr[k]=L[i];
            i++;
            k++;
        }
        else{
            arr[k] = R[j];
            j++;
            k++;
        }
    }
    //checking if any elements were left out in the left subarray
    while(i<n1){
        arr[k]= L[i];
        i++;
        k++;
    }
    //checking if any elements were left out in the left subarray
    while(j<n2){
        arr[k]= R[j];
        j++;
        k++;
    }
}
void mergeSort(int arr[], int left, int right){
    
    
    if (left < right) {

    // m is the point where the array is divided into two subarrays
    int mid = (right +left) / 2;

    mergeSort(arr, left, mid);
    mergeSort(arr, mid + 1, right);

    // Merge the sorted subarrays
    Merge(arr, left, mid, right);
  }
}

void printArray(int arr[]){
    for(int i = 0; i<10; i++){
        printf("%d-", arr[i]);
    }
    printf("\n");
}

void main(){
    int arr[10] = {10,5,1,53,12,4,2,7,6,35};
    printArray(arr);
    mergeSort(arr, 0, 9);
    printArray(arr);
    
}