#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <dirent.h>
//#include <sys/wait.h>
#include <unistd.h>

void make_toks(char *s, char *tok[])
{
 int i=0;
 char *p;

 p = strtok(s," ");
 while(p!=NULL)
 {
  tok[i++]=p;
  p=strtok(NULL," ");
 }

 tok[i]=NULL;
}

void list(char *dn, char op)
{
 DIR *dp;
 struct dirent *entry;
 int dc=0,fc=0;

 dp = opendir(".");
 if(dp==NULL)
 {
  printf("Dir %s not found.\n",dn);
  return;
 }

 switch(op)
 {
 case 'f':
  while(entry=readdir(dp))
  {
   if(entry->d_type==DT_REG)
    printf("%s\n",entry->d_name);
  }
  break;
 case 'n':
  while(entry=readdir(dp))
  {
   if(entry->d_type==DT_DIR) dc++;
   if(entry->d_type==DT_REG) fc++;
  }
 
  printf("%d Dir(s)\t%d File(s)\n",dc,fc);
  break;
 case 'i':
  while(entry=readdir(dp))
  {
   if(entry->d_type==DT_REG)
    printf("%s\t%d\n",entry->d_name,entry->d_fileno);
  }
 }

 closedir(dp);
}

int main()
{
 char buff[80],*args[10];
 int pid;

 while(1)
 {
  printf("myshell$");
  fflush(stdin);
  fgets(buff,80,stdin);
  buff[strlen(buff)-1]='\0';
  make_toks(buff,args);
  if(strcmp(args[0],"list")==0)
   list(args[2],args[1][0]);
  else
  {
   pid = fork();
   if(pid>0)
    wait();
   else
   {
    if(execvp(args[0],args)==-1)
     printf("Bad command.\n");
   }
  }
 }

 return 0;
}

/*
Output :-
myshell$ list f
setA2.c
a.out
set.txt
setA1.c
myshell$ list n
2 Dir(s)	4 File(s)
myshell$ list i
setA2.c	52692051
a.out	52691004
set.txt	52692146
setA1.c	52692137
*/
