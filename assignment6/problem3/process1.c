#include <stdio.h>
#include <unistd.h>

int main() {
	int pid;
	printf("[%d] 프로세스 시작\n", getpid());
	pid = fork();
	printf("[%d] 프로세스 : 반환값 %d\n", getpid(), pid);
	pid = fork();
	printf("[%d] 프로세스 : 반환값 %d\n", getpid(), pid);
}
