// Create a program which does the function of move (mv command).

#include <stdio.h> 
#include <stdlib.h> 
#include <fcntl.h> 
#define PERMS 0666 /* RW for owner, group, others */ 
char buffer[2048]; 

main(argc,argv) 
  int argc; 
  char *argv[]; 
{ 
   int fdold, fdnew; 
	 
	if (argc != 3) 
	{ 
 		printf("need 2 arguments for copy program\n"); 
		exit(1); 
	} 
	fdold = open(argv[1],O_RDONLY);//read only file 
	if (fdold == -1) 
	{ 
		printf("The file %s does not exixts",argv[1]);  
		exit(1); 
	} 
	fdnew = creat(argv[2],PERMS); 
	copy(fdold, fdnew); 
	unlink(argv[1]); 
	printf("File is moved from %s to %s",argv[1],argv[2]); 
	exit(0); 
} 

copy(old,new) 
	int old,new; 
{ 
	int count; 
	 
	while ((count = read(old,buffer,sizeof(buffer))) > 0) 
		write(new,buffer,count); 
} 
 
