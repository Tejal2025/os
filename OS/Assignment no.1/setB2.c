#include<stdio.h>
#include<sys/wait.h>
#include<unistd.h>
void cp();
void pp();
int  main()
{
     pid_t pid;
     pid=fork();
     if (pid ==0 )
     {
        sleep(3);
        cp();
     }
     else
     {
         pp();
     }
     return 0;
}
void cp()
{
      printf("\nI am child Process: ");
     printf("\nParent id : %d\n",getpid());
}
void pp()
{
      printf("\nI am Parent Process: ");
     printf("\nChild id : %d\n",getppid());
}
   
/*
OUTPUT:-
ty8@pc41:~/Ty 8/OS/Assignment1$  I am Parent Process: 
Child id : 2194

*/
