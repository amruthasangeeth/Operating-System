#include<stdio.h>
#include<fcntl.h>
#include<sys/stat.h>
#include<sys/types.h>
#include<string.h>

int main(){
  pid_t childid;
  int fd[2];
  int fdtwo[2];
  
  pipe(fd);
  pipe(fdtwo);
  
  char parentstring[10];
  char childstring[10];
  
  childid=fork();
  while(1){
    if(childid==0){
    close(fd[1]);
    read(fd[0],parentstring,10);
    printf("CONTACT2: received string is %s \n",parentstring);
    
    printf("CONTACT2>>");
    scanf("%s",childstring);
    write(fdtwo[1],childstring,10);
  }
  else{
    close(fd[0]);
    printf("CONTACT1>>");
    scanf("%s",parentstring);
    write(fd[1],parentstring,10);
    
    read(fdtwo[0],childstring,10);
    printf("CONTACT1: received string is %s \n",childstring);
  }
  }
  
  return 0;
}s 
