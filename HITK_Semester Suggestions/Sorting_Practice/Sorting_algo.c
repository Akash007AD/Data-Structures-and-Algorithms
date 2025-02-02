#include <stdio.h>
void swap(int *x, int *y)
{
    int temp = *x;
    *x = *y;
    *y = temp;
}
int *bubblesort(int *arr, int size)
{
    int comp=0;
    for (int i = 0; i < size; i++)
    {
        for (int j = i + 1; j < size; j++)
        {
            if (arr[i] > arr[j])
                swap(&arr[i], &arr[j]);
                comp++;
        }
        comp++;
    }
    printf("No of comparisons: %d\n",comp);
    return arr;
}
void display(int *arr, int size)
{
    for (int i = 0; i < size; i++)
    {
        printf("%d ", arr[i]);
    }
    printf("\n");
}
int* reverse(int* arr,int size){
    int i=0;
    int j=size-1;
    while(i<=j){
        swap(&arr[i],&arr[j]);
        i++;
        j--;
    }
    return arr;
}

int* insertion_sort(int* arr,int size){
    int key,j;
    for(int i=1;i<size;i++){
        key=arr[i];
        j=i-1;
        while(j>=0 && arr[j]>key){
            arr[j+1]=arr[j];
            j--;
        }
        arr[j+1]=key;
    }
}
int* selection_sort(int* arr,int size){
    for(int i=0;i<size;i++){
        int key=i;
        for(int j=i+1;j<size;j++){
            if(arr[j]<arr[key]) key=j;
        }
        swap(&arr[i],&arr[key]);
    }
    return arr;
}

int main()
{
    int arr[10] = {7, 5, 4, 9, 3, 6, 1, 2, 31, 24};
    int size=sizeof(arr)/sizeof(arr[0]);
    display(arr, size);
    //reverse(arr, size);
    // bubblesort(arr, size);
    // insertion_sort(arr,size);
    selection_sort(arr,size);
    display(arr,size);
}