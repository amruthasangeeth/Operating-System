//Enhance the program to concatenate to the output file if the file already exists.


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
		printf("cannot open file %s\n",argv[1]);  
		exit(1); 
	} 
	fdnew = open(argv[2],PERMS); 
	if (fdnew != -1) 
	{ 
		lseek(fdnew,0,2); 
	} 
	else 
	{ 
	fdnew=creat(argv[2],O_WRONLY); 
	if(fdnew==-1) 
	{ 
	  printf("cannot create file %s \n",argv[2]); 
	} 
	} 

	copy(fdold, fdnew); 
	exit(0); 
} 

copy(old,new) 
	int old,new; 
{ 
	int count; 
	 
	while ((count = read(old,buffer,sizeof(buffer))) > 0) 
		write(new,buffer,count); 
}  
