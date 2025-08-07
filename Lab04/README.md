# Lab04 - Process Management Programs

This directory contains three C programs demonstrating process management concepts:

## Program 1: Menu-driven Parent Process (`Lab04.c`)

A parent process that displays a menu and executes commands using child processes.

**How to run:**
```bash
gcc -o menu Lab04.c
./menu.exe
```

**Features:**
- Displays a menu with options: ls, date, ps, exit
- Uses `system()` calls to execute commands
- Waits for each command to complete before showing the menu again

## Program 2: Child-Parent Communication (`child.c` and `parent.c`)

Demonstrates inter-process communication using process spawning and exit codes.

**How to compile:**
```bash
gcc -o child child.c
gcc -o parent parent.c
```

**How to run:**
```bash
# Test child program directly
./child.exe 5 3
# Output: Child process: 5 + 3 = 8
# Exit code: 8

# Test parent program with 4 numbers
./parent.exe 10 20 30 40
# Expected: 
# - First child: 10 + 20 = 30
# - Second child: 30 + 40 = 70  
# - Final result: 30 + 70 = 100
```

**How it works:**
1. `child.c` takes 2 integers as command line arguments
2. Adds them together and returns the sum via `exit()`
3. `parent.c` takes 4 integers as command line arguments
4. Spawns two child processes using `_spawnl()`
5. Each child executes the child program with 2 numbers
6. Parent waits for both children and collects their results
7. Adds the results together and prints the final sum

## Windows Compatibility Notes

These programs have been adapted for Windows/MinGW environment:
- Uses `process.h` instead of `sys/wait.h`
- Uses `system()` and `_spawnl()` instead of `fork()` and `exec()`
- Compatible with Git Bash on Windows