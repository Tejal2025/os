#include<stdio.h>
main()
{
    int pid,retnice;
    printf("press DEL to stop process \n");
    pid=fork();
    for(;;)
    {
     if(pid==0)
     {
      retnice=nice(-5);
      printf("child gets higher CPU priority %d\n",retnice);
      exit(1);
     }
     else
     {
      retnice=nice(4);
      printf("Parents gets lower CPU priority %d\n",retnice);
      exit(1);
     }
    }
}

//Output:-
//press DEL to stop process 
//Parents gets lower CPU priority 4
//child gets higher CPU priority -1

