#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>
#include <stdlib.h>

int main() {
	pid_t pid;

	printf("Parent Process PID : %d\n", getpid());
	pid = fork();

	if (pid < 0) {
		perror("fork failed");
		exit(1);
	}
	else if (pid == 0) {
		printf("Child Process PID : %d (Parent PID : %d)\n", getpid(), getppid());
		printf("Child : Executing 'ls -l' ... \n");

		execlp("ls", "ls", "-l", NULL);
		perror("exec failed");
		exit(1);
	}
	else {
		printf("Parent : Waiting for child process... \n");
		wait(NULL);
		printf("Parent : Child process finished.\n");
	}
	return 0;
}

