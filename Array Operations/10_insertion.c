/*This C code is an example of array manipulation that demonstrates how to insert an element into a specific position within an array, as well as how to display the contents of an array. Let's break down each part of the code:*/
#include<stdio.h>
/*This line includes the standard input-output library in C, which is necessary for using the printf function.*/
int insert(int arr[],int index,int element,int capacity,int size){
    if(size>=capacity){
        return -1;
    }
    else{
        for(int i=size-1;i>=index;i--){
            arr[i+1]=arr[i];
        }
        arr[index]=element;
        return 1;
    }
}
/*Parameters:

arr[]: The array into which the element will be inserted.
index: The position at which the new element will be inserted.
element: The value of the new element to be inserted.
capacity: The maximum size of the array.
size: The current number of elements in the array.*/

/*Functionality:

The function checks if the array has enough capacity to insert a new element. If the size is equal to or greater than the capacity, it returns -1, indicating failure.
If there is enough capacity, it shifts elements to the right from the specified index to make room for the new element.
It then inserts the new element at the specified index.
Finally, it returns 1, indicating success.*/
void display(int arr[],int n){
    //Traversal 
    for (int i=0;i<n;i++){
        printf("%d\n",arr[i]);
    }
}
/*Parameters:

arr[]: The array to be displayed.
n: The number of elements in the array.
Functionality:

The function loops through the array and prints each element followed by a space.*/
int main(){
    int arr[100]={2,3,5,15};
    int size=4;
    display(arr,size);
    insert(arr,1,45,100,4);
    size++;
    display(arr,size);
    
}
/*Array Initialization:

int arr[100] = {2, 3, 5, 15}; initializes an array with a capacity of 100 elements and sets the first four elements to 2, 3, 5, 15.
Initial Display:

display(arr, size); displays the initial elements of the array (2 3 5 15).
Insert Operation:

insert(arr, 2, 45, 100, 4); attempts to insert the element 45 at index 2 (the third position) in the array.
Since there is enough capacity and the index is valid, the function will shift the elements from index 2 to the right and insert 45.
Size Increment:

size++; increments the size of the array to account for the newly inserted element.
Final Display:

display(arr, size); displays the array after the insertion (2 3 45 5 15).*/

/*Summary
The code effectively demonstrates how to insert an element into a specified position in an array and how to display the array's contents before and after the insertion. The insert function handles the insertion process, including shifting elements and checking for capacity constraints, while the display function handles printing the array's contents.

*/