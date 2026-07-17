#include<stdio.h>
#include<stdlib.h>
#include<time.h>

#define ITERATIONS 8

// ARRAY GENERATION FUNCTIONS

void generateRandom(int arr[],int n){
    for(int i=0;i<n;i++)
        arr[i]=rand()%100000;
}

void generateAscending(int arr[],int n){
    for(int i=0;i<n;i++)
        arr[i]=i+1;
}

void generateDescending(int arr[],int n){
    for(int i=0;i<n;i++)
        arr[i]=n-i;
}

// UTILITY FUNCTIONS

void copyArray(int source[],int destination[],int n){
    for(int i=0;i<n;i++)
        destination[i]=source[i];
}

void swap(int *a,int *b){
    int temp=*a;
    *a=*b;
    *b=temp;
}

// BUBBLE SORT

void bubbleSort(int arr[],int n){
    for(int i=0;i<n-1;i++){
        int swapped=0;
        for(int j=0;j<n-i-1;j++){
            if(arr[j]>arr[j+1]){
                swap(&arr[j],&arr[j+1]);
                swapped=1;
            }
        }
        if(swapped==0)
            break;
    }
}

// INSERTION SORT

void insertionSort(int arr[],int n){
    for(int i=1;i<n;i++){
        int key=arr[i];
        int j=i-1;
        while(j>=0 && arr[j]>key){
            arr[j+1]=arr[j];
            j--;
        }
        arr[j+1]=key;
    }
}

// SELECTION SORT

void selectionSort(int arr[],int n){
    for(int i=0;i<n-1;i++){
        int minIndex=i;
        for(int j=i+1;j<n;j++){
            if(arr[j]<arr[minIndex])
                minIndex=j;
        }
        if(minIndex!=i)
            swap(&arr[i],&arr[minIndex]);
    }
}

// QUICK SORT

int partition(int arr[],int low,int high){
    int pivot=arr[high];
    int i=low-1;

    for(int j=low;j<high;j++){
        if(arr[j]<=pivot){
            i++;
            swap(&arr[i],&arr[j]);
        }
    }

    swap(&arr[i+1],&arr[high]);
    return i+1;
}

void quickSort(int arr[],int low,int high){
    if(low<high){
        int pi=partition(arr,low,high);

        quickSort(arr,low,pi-1);
        quickSort(arr,pi+1,high);
    }
}

// MERGE SORT

void merge(int arr[],int left,int mid,int right){
    int n1=mid-left+1;
    int n2=right-mid;

    int L[n1],R[n2];

    for(int i=0;i<n1;i++)
        L[i]=arr[left+i];

    for(int i=0;i<n2;i++)
        R[i]=arr[mid+1+i];

    int i=0,j=0,k=left;

    while(i<n1 && j<n2){
        if(L[i]<=R[j])
            arr[k++]=L[i++];
        else
            arr[k++]=R[j++];
    }

    while(i<n1)
        arr[k++]=L[i++];

    while(j<n2)
        arr[k++]=R[j++];
}

void mergeSort(int arr[],int left,int right){
    if(left<right){
        int mid=left+(right-left)/2;

        mergeSort(arr,left,mid);
        mergeSort(arr,mid+1,right);

        merge(arr,left,mid,right);
    }
}

// HEAP SORT

void heapify(int arr[],int n,int i){
    int largest=i;
    int left=2*i+1;
    int right=2*i+2;

    if(left<n && arr[left]>arr[largest])
        largest=left;

    if(right<n && arr[right]>arr[largest])
        largest=right;

    if(largest!=i){
        swap(&arr[i],&arr[largest]);
        heapify(arr,n,largest);
    }
}

void heapSort(int arr[],int n){
    for(int i=n/2-1;i>=0;i--)
        heapify(arr,n,i);

    for(int i=n-1;i>0;i--){
        swap(&arr[0],&arr[i]);
        heapify(arr,i,0);
    }
}
