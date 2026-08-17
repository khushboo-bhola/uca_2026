#include <stdio.h>
#include <string.h>
#include <stddef.h>
typedef struct {
    int id;
    char name[50];
    float marks;
} Student;
void swap(void *a,void *b,size_t size){
    char temp[size];

    memcpy(temp,a,size);
    memcpy(a,b,size);
    memcpy(b,temp,size);
}
void heapify(void *arr,int n,int i,size_t size,int (*compare)(void *, void *)){
    int left = 2*i+1;
    int right = 2*i+2;
    int largest = i;

    if(left < n && compare((char *)arr + left*size,(char *)arr + largest*size) > 0){
        largest = left;
    }
    if(right < n && compare((char *)arr + right*size,(char *)arr + largest*size) > 0){
        largest = right;
    }
    if(largest != i){
        swap((char *)arr + largest*size,(char *)arr + i*size,size);
        heapify(arr,n,largest,size,compare);
    }
}
void heapSort(void *arr,int n,size_t size,int (*compare)(void *, void *)){
    for(int i=n/2-1;i>=0;i--){
        heapify(arr,n,i,size,compare);
    }
    for(int i=n-1;i>0;i--){
        swap(arr,(char *)arr + i*size,size);
        heapify(arr,i,0,size,compare);
    }
}
int compareInt(void *a, void *b){
    int x = *(int *)a;
    int y = *(int *)b;

    if(x > y){
        return 1;
    }
    else if(y > x){
        return -1;
    }
    return 0;
}
int compareFloat(void *a, void *b){
    float x = *(float *)a;
    float y = *(float *)b;
    if(x > y){
        return 1;
    }
    else if(y > x){
        return -1;
    }
    return 0;
}
int compareDouble(void *a, void *b){
    double x = *(double *)a;
    double y = *(double *)b;
    if(x > y){
        return 1;
    }
    else if(y > x){
        return -1;
    }
    return 0;
}
int compareStruct(void *a, void *b) {
    Student *x = (Student *)a;
    Student *y = (Student *)b;
    if (x->marks > y->marks){
        return 1;
    }
    if (x->marks < y->marks){
        return -1;
    }   
    return 0;
}
int main() {
    int intArr[3] = {45, 12, 78};
    float floatArr[3] = {5.6, 2.3, 9.8};
    double DoubleArr[3] = {25.55, 8.88, 14.44};
    Student students[] = {
        {4, "Riya", 88.5},
        {2, "Aditi", 95.0},
        {5, "Neha", 76.5}
    };
    int n = sizeof(DoubleArr) / sizeof(DoubleArr[0]);
    printf("Before Sorting:\n");
    for (int i = 0; i < n; i++) {
        printf("%lf ", DoubleArr[i]);
    }
    printf("\n");
    heapSort(DoubleArr, n, sizeof(DoubleArr[0]), compareDouble);
    printf("After Sorting:\n");
    for (int i = 0; i < n; i++) {
        printf("%lf ", DoubleArr[i]);
    }
    printf("\n");
    return 0;
}