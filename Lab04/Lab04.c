#include <stdio.h>
#include <stdlib.h>
#include <process.h>

int main() {
    int choice;
    int result;
    
    while (1) {
        // Display menu
        printf("\n=== MENU ===\n");
        printf("1. ls\n");
        printf("2. date\n");
        printf("3. ps\n");
        printf("0. exit\n");
        printf("Enter your choice: ");
        
        // Read user input
        scanf("%d", &choice);
        
        switch (choice) {
            case 1:
                // Execute ls command and wait for completion
                printf("Executing ls command:\n");
                result = system("ls");
                if (result == -1) {
                    perror("system call failed");
                }
                break;
                
            case 2:
                // Execute date command and wait for completion
                printf("Executing date command:\n");
                result = system("date");
                if (result == -1) {
                    perror("system call failed");
                }
                break;
                
            case 3:
                // Execute ps command and wait for completion
                printf("Executing ps command:\n");
                result = system("ps");
                if (result == -1) {
                    perror("system call failed");
                }
                break;
                
            case 0:
                printf("Exiting program...\n");
                exit(0);
                
            default:
                printf("Invalid choice! Please enter 0-3.\n");
                break;
        }
    }
    
    return 0;
}
