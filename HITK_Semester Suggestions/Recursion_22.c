/*Discuss the key features of tail recursion. Explain with suitable example how it is different from a
normal recursive function.*/
#include <stdio.h>

// Function to calculate factorial using tail recursion
int tail_recursive_factorial(int n, int accumulator) {
    if (n == 0) {
        return accumulator; // Base case
    }
    return tail_recursive_factorial(n - 1, accumulator * n); // Tail recursive call
}
// Function to calculate factorial using normal recursion
int factorial(int n) {
    if (n == 0) {
        return 1; // Base case
    }
    return n * factorial(n - 1); // Recursive call
}
int main() {
    int n = 5;
    printf("Factorial of %d is %d\n", n, tail_recursive_factorial(n, 1)); // Example usage
    printf("Factorial of %d is %d\n", n, factorial(n)); // Example usage
    return 0;
}
