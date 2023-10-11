#include<stdio.h>
#include<sys/types.h>
#include<unistd.h>
#include<sys/wait.h>
void bubble_sort();
void insertion_sort();
int n,a[10];
int main()
{
  int i;
  printf("\n Enter size of array:");
  scanf("%d",&n);
  printf("\n Enter the size of element:");
  for(i=0;i<n;i++)
  scanf("%d",&a[i]);
  printf("Enter size of array:");
  for(i=0;i<n;i++)
  printf("%d\t",a[i]);
  scanf("%d\t",a[i]);
  pid_t pid;
  pid=fork();
      if (pid==0)
      {
        printf("\n Child created");
        printf("\n my id %d\n",getpid());
        bubble_sort();
        printf("\n sorted array element");
        for(i=0;i<n;i++)
            printf("%d\t",a[i]);
            printf("\n");
      }
      else
         if(pid>0)
         {
           wait(NULL);
           printf("\n parenr \n");
           printf("\n myid %d\n",getpid());
           insertion_sort();
           printf("\n sorted array element:");
           for(i=0;i<n;i++)
               printf("%d\t",a[i]);
         }
         else
             printf("\n unsuccessful process");
}
void bubble_sort()
{
  int i,j,temp;
  for(i=0;i<n;i++)
      for(j=0;j<n-1-i;j++)
      {
         if(a[j]>a[j+1])
         {
            temp=a[j];
            a[j]=a[j+1];
            a[j+1]=temp;
         }
      }
}
void insertion_sort()
{
 int i,j,temp;
 for(i=0;i<n;i++)
 {
  temp=a[i];
  j=i-1;
  for(j>=0;a[j]>temp;j--)
  {
     a[j+1]=a[j];
  }
  a[j+1]=temp;
 }
}

