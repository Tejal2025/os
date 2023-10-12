#include<stdio.h>
#include<sys/wait.h>
#include<unistd.h>
int n,a[10];
void bubble();
void insertion();
int main()
{
     int i;
     printf("\nEnter array size: ");
     scanf("%d",&n);
     for (i=0;i<n;i++)
     {
          scanf("%d",&a[i]);
     }
     int pid=fork();
     if (pid==0)
     {
          printf("Child id : %d\n",getpid());
          insertion();
          printf("\n Sorted array elements are: ");
          for (i=0;i<n;i++)
              printf("\t%d",a[i]);
          printf("\n");    
     }
     else
     {
         wait(NULL);
         printf("Parent Process id : %d\n",getppid());
         bubble();
         printf("\n Sorted array Elements are :");
         for (i=0;i<n;i++)
              printf("\t%d",a[i]);
          printf("\n"); 
     }
}

void bubble()
{
     int i,j,temp;
     for (i=0;i<n;i++)
         for (j=i+1;j<n;j++)
             if (a[i]>a[j])
             {
                temp=a[i];
                a[i]=a[j];
                a[j]=temp;
             }
}

void insertion()
{
     int i,j,k;
     for(i=1;i<n;i++)
     {
        k=a[i];
        j=i-1;
        while(j>=0 && a[j]>k)
        {
             a[j+1]=a[j];
             j--;
        }
        a[j+1]=k; 
     }
}

/*
Enter array size: 5
8 9 0 2 4
Child id : 1187

 Sorted array elements are:     0       2       4       8       9
Parent Process id : 1182

 Sorted array Elements are :    0       2       4       8       9
*/
