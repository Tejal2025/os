#include<stdio.h>
#include<sys/types.h>
void ChildProcess();
void ParentProcess();
int main()
{
  pid_t pid;
  pid=fork();
  if(pid==0)
     ChildProcess(pid);
  else
     if(pid>0)
        ParentProcess(pid);
        else
            printf("\n unsuccessful");
}

void ChildProcess(int pid)
{
  printf("\n child created \n");
  printf("myid:%d\n",getpid());
  printf("my parent id:%d\n",getppid());
}
void ParentProcess(int pid)
{
   printf("parent\n");
   printf("my id:%d\n",getpid());
   printf("my child id:%d\n",pid);
}

//Output:-
//parent
//my id:17174
//my child id:17175

 //child created 
//myid:17175
//my parent id:3560
