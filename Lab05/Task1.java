import java.util.Scanner;

public class Task1 {
    // Shared variable to store child thread result
    private static int childResult = 0;
    private static final Object lock = new Object();
    
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        
        // Step 1: Input - Prompt user for positive integer
        System.out.print("Enter a positive integer number: ");
        int n = scanner.nextInt();
        
        if (n <= 0) {
            System.out.println("Please enter a positive integer.");
            scanner.close();
            return;
        }
        
        // Step 2: Thread Creation - Create child thread
        Thread childThread = new Thread(new ChildThread(n));
        
        // Start the child thread
        childThread.start();
        
        // Step 3: Parent thread calculations - Sum from 1 to N
        int parentResult = 0;
        for (int i = 1; i <= n; i++) {
            parentResult += i;
        }
        
        System.out.println("Parent thread: summation 1 to " + n + " → " + parentResult);
        
        // Wait for child thread to complete
        try {
            childThread.join();
        } catch (InterruptedException e) {
            System.out.println("Parent thread interrupted while waiting for child thread.");
            return;
        }
        
        // Step 4: Result Combination
        int finalResult = parentResult + childResult;
        System.out.println("Child thread: summation 1 to " + (2 * n) + " → " + childResult);
        System.out.println("Final result: " + parentResult + " + " + childResult + " = " + finalResult);
        
        scanner.close();
    }
    
    // Child thread class
    static class ChildThread implements Runnable {
        private int n;
        
        public ChildThread(int n) {
            this.n = n;
        }
        
        @Override
        public void run() {
            // Step 3: Child thread calculations - Sum from 1 to 2*N
            int result = 0;
            for (int i = 1; i <= 2 * n; i++) {
                result += i;
            }
            
            // Store result in shared variable
            synchronized (lock) {
                childResult = result;
            }
        }
    }
} 