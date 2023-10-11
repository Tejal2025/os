#include<stdio.h>
#include<sys/types.h>
#include<unistd.h>
#include<sys/wait.h>

void childprocess(int);
void parentprocess(int);

int main()
{
 pid_t pid;
 pid=fork();
 
 if(pid==0)
 {
  sleep(3);
  parentprocess(pid);
 }
 else
    printf("\n unsuccessfull");
}

void childprocess(int pid)
{
  printf("I am a child process\n");
  printf("\n myid:%d\n",getpid());
  printf("my parent id:%d\n",getppid());
}
void parentprocess(int pid)
{
 printf(" I am parent process\n");
 printf("my id:%d\n",getpid());
 printf("my child id:%d\n",pid);
}
   
   
   
/*
OUTPUT:-
ty8@pc41:~/Ty 8/OS/Assignment1$  I am parent process
my id:17904
my child id:0
*/
