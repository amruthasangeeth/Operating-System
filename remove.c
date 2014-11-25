// Create a program to remove the file (rm command)

#include <stdio.h>
	#include <stdlib.h>
	#include <fcntl.h>
#define PERMS 0666
main(int argc,char *argv[]) {
int file; 
if (argc != 2) {
printf("need 1 argument for remove program\n"); 
}
file = open(argv[1],O_RDONLY); 
if (file == -1) {
exit(1);
printf("File %s does not exist.\n", argv[1]); 
exit(1);
}
unlink(argv[1]);
printf("File %s is deleted.\n", argv[1]);
	exit(0);
} 
