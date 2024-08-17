#include<stdio.h>
#include<stdlib.h>
/*total_size: This variable holds the total number of elements that can be stored in the array (i.e., the capacity).
used_size: This variable holds the number of elements currently being used in the array.
ptr: This is a pointer to the dynamically allocated array of integers*/

//ADT--->It is a custom Data type

struct myArray
{
    int total_size;
    int used_size;
    int* ptr;
};
/*This function initializes the myArray struct.
Parameters:
struct myArray *a: A pointer to the myArray struct to be initialized.
int tsize: The total size (capacity) of the array.
int usize: The number of elements to be used initially.
It sets the total_size and used_size fields and allocates memory for the array using malloc.*/
void createarray(struct myArray * a,int tsize,int usize){
    (*a).total_size=tsize;
    (*a).used_size=usize;
    (*a).ptr=(int*) malloc(tsize*sizeof(int)); //It allocates memory from heap memory
   /* a->total_size=tsize;
    a->used_size=usize;
    a->ptr=(int*) malloc(tsize*sizeof(int));*/
}
/*This function fills the array with values provided by the user.
Parameters:
struct myArray *a: A pointer to the myArray struct.
It prompts the user to enter values and stores them in the array up to used_size.*/
void setval(struct myArray *a){
    int n;
    for (int i=0;i<a->used_size;i++){
        printf("Enter a element: %d",i);
        scanf("%d",&n);
        (a->ptr)[i]=n;
    }
}
/*This function displays the elements of the array.
Parameters:
struct myArray *a: A pointer to the myArray struct.
It prints all the elements currently in use (up to used_size)*/
void show(struct myArray *a){
    for (int i=0;i<a->used_size;i++){
        printf("%d\n",(a->ptr)[i]);
    }
}
/*struct myArray marks: Declares a variable marks of type struct myArray.
createarray(&marks, 100, 20): Initializes marks with a total size of 100 and an initial used size of 20.
setval(&marks): Prompts the user to enter 20 values and stores them in marks.
show(&marks): Displays the 20 values stored in marks*/

int main(){
    struct myArray marks; //It creates the space for the arrays in the memory using the structure names total_size,used_size and a pointer ptr
    createarray(&marks,100,20);//it carries the address and allocates memory according to the size provided
    printf("We are running setval now");
    setval(&marks);
    printf("We are running show now");
    show(&marks);
    return 0;
}
/*Summary
The program defines a structure to represent a dynamic array.
Functions are provided to initialize the array, set values, and display values.
In the main function, an instance of the array is created, values are set by user input, and then the values are displayed.
This approach allows for flexible array management, where the array size can be determined at runtime, and only a portion of the allocated array might be used at any given time*/