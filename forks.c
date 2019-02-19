#include <stdio.h>
#include <stddef.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

void run();

int main(int argc, char** argv){
	run();
	printf("Pid %d is exiting main.\n", getpid());
}

void run(){
	pid_t pid = fork();
	
	if (pid==0){
		printf("\tChild process with pid %d.\n",getpid());
		printf("\tChild process calling another child.\n");
		pid = fork();
		if (pid==0){
			printf("\t\tGrandchild process  with pid %d.\n",getpid());
			printf("\t\tGrandchild is leaving run().\n");
			return;
		} else if (pid<0){
			perror("\t\tGrandchild could not be forked. Exiting...\n");
			exit(EXIT_FAILURE);
		}
		printf("\tChild process is calling EXIT.\n");
		exit(EXIT_SUCCESS);
	} else if (pid<0){
		perror("\tChild process could not be forked. Exiting...\n");
		exit(EXIT_FAILURE);
	} else {
		printf("Parent process with pid %d.\n",getpid());
		
	}
	return;
}
