/* Write a program which runs the following command with the command arguments given below from the terminal. (a.out is your program executable).
Note : use pipe, dup and execlp system calls.
	a.out who wc
	*/
#include <stdio.h> 
#include <unistd.h> 
#include <sys/ipc.h> 
int main(int argc,char * argv[]) 
{ 
   int fd[2]; 

   pipe(fd); 

 
   if (fork() == 0) 
   { 
	/* Child process */ 
	close(1) ; 
	dup(fd[1]) ; /* Redirect the stdout of this */ 
			/* process to the pipe. */ 
	close(fd[0]); 
	 
	execlp(argv[1],"argv[1]",0); 
      } 
   else 
     { 
       /* Parent process */ 
       close(0) ; 
       dup(fd[0]) ; /* Redirect the stdin of this 
                     /*   process to the pipe */ 
       close(fd[1]); 
	   execlp(argv[2],"argv[2]",0); 
     sleep(1); 
    } 
} 