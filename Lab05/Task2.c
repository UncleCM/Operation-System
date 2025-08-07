#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <unistd.h>

// Global variables for thread communication
int child_result = 0;
pthread_mutex_t mutex = PTHREAD_MUTEX_INITIALIZER;

// Structure to pass data to child thread
typedef struct {
    int n;
} thread_data_t;

// Child thread function
void* child_thread(void* arg) {
    thread_data_t* data = (thread_data_t*)arg;
    int n = data->n;
    int result = 0;
    
    // Calculate summation from 1 to 2*N
    for (int i = 1; i <= 2 * n; i++) {
        result += i;
    }
    
    // Store result in shared variable with mutex protection
    pthread_mutex_lock(&mutex);
    child_result = result;
    pthread_mutex_unlock(&mutex);
    
    return NULL;
}

int main() {
    int n;
    pthread_t child_tid;
    thread_data_t thread_data;
    int parent_result = 0;
    int final_result;
    
    // Step 1: Input - Prompt user for positive integer
    printf("Enter a positive integer number: ");
    if (scanf("%d", &n) != 1 || n <= 0) {
        printf("Please enter a positive integer.\n");
        return 1;
    }
    
    // Step 2: Thread Creation - Create child thread
    thread_data.n = n;
    if (pthread_create(&child_tid, NULL, child_thread, &thread_data) != 0) {
        perror("Failed to create child thread");
        return 1;
    }
    
    // Step 3: Parent thread calculations - Sum from 1 to N
    for (int i = 1; i <= n; i++) {
        parent_result += i;
    }
    
    printf("Parent thread: summation 1 to %d → %d\n", n, parent_result);
    
    // Wait for child thread to complete
    if (pthread_join(child_tid, NULL) != 0) {
        perror("Failed to join child thread");
        return 1;
    }
    
    // Step 4: Result Combination
    final_result = parent_result + child_result;
    printf("Child thread: summation 1 to %d → %d\n", 2 * n, child_result);
    printf("Final result: %d + %d = %d\n", parent_result, child_result, final_result);
    
    // Clean up mutex
    pthread_mutex_destroy(&mutex);
    
    return 0;
} 