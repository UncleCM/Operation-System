#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {
    // Check if exactly 2 arguments are provided
    if (argc != 3) {
        fprintf(stderr, "Usage: %s <number1> <number2>\n", argv[0]);
        exit(1);
    }
    
    // Convert command line arguments to integers
    int num1 = atoi(argv[1]);
    int num2 = atoi(argv[2]);
    
    // Calculate the sum
    int sum = num1 + num2;
    
    printf("Child process: %d + %d = %d\n", num1, num2, sum);
    
    // Return the result via exit system call
    exit(sum);
}