#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

// Function to display process information
void displayProcessInfo(pid_t pid, const char* name) {
    printf("Process ID: %d, Name: %s\n", pid, name);
}

int main() {
    pid_t child_pid;
    int status;

    // Fork a child process
    child_pid = fork();

    if (child_pid < 0) {
        perror("Fork failed");
        exit(EXIT_FAILURE);
    } else if (child_pid == 0) {
        // Child process
        printf("Child process executing...\n");
        // Simulate some work
        sleep(2);
        exit(EXIT_SUCCESS);
    } else {
        // Parent process
        printf("Parent process waiting for child...\n");
        waitpid(child_pid, &status, 0);
        printf("Child process terminated.\n");
    }

    // Display process IDs
    printf("Real User ID: %d, Effective User ID: %d\n", getuid(), geteuid());

    // Modify user IDs (for demonstration purposes)
    setuid(1001); // Change effective user ID
    printf("Modified Effective User ID: %d\n", geteuid());

    // Execute shell command
    system("ls -l");

    // Simulate zombie process
    child_pid = fork();
    if (child_pid == 0) {
        exit(EXIT_SUCCESS);
    }

    // Simulate orphan process
    if (fork() == 0) {
        sleep(2);
        printf("Orphan process executing...\n");
    }

    // Compilation steps (simplified)
    printf("Compilation Steps:\n");
    printf("1. Preprocessing\n");
    printf("2. Compiling\n");
    printf("3. Assembling\n");
    printf("4. Linking\n");

    return 0;
}
