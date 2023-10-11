#include<stdio.h>
#include<stdlib.h>


void main()
{
     int i,n;
     float avwt=0,avtat=0;
     printf("Enter the Number of process : ");
     scanf("%d",&n);
     
     int p[n],at[n],bt[n],wt[n],tat[n];
     printf("Enter the process : ");
     for (i=0;i<n;i++)
          scanf("%d",&p[i]);
      
     printf("Enter arrival time : ");
     for (i=0;i<n;i++)
         scanf("%d",&at[i]);
             
     printf("Enter the Burst time : ");
     for (i=0;i<n;i++)
         scanf("%d",&bt[i]);
         
             
     int j,temp;          
    
     for (i=0;i<n;i++)
         for (j=0;j<n-1-i;j++)
         {
             if (bt[j] > bt[j+1])
             {
                 temp=bt[j];
                 bt[j]=bt[j+1];
                 bt[j+1]=temp;
                 temp=p[j];
                 p[j]=p[j+1];
                 p[j+1]=temp;
             }   
         }
      int start[10];
      start[0]=0;
      for (i=1;i<n;i++)
      {
          start[i]=start[i-1]+bt[i-1];
      }
      for (i=0;i<n;i++)
      {
           wt[i]=start[i]-at[i];
           avwt+=wt[i];
      }
      avwt/=n;  
      for (i=0;i<n;i++)
      {
           tat[i]=wt[i]+bt[i];
           avtat+=tat[i];
      }
      avtat/=n;                
      printf("\npro\tat\tbt\twt\ttat :\n");   
      for (i=0;i<n;i++)
      {
        printf("\n p[%d]\t%d\t%d\t%d\t %d",p[i],at[i],bt[i],wt[i],tat[i]);
      }
      printf("\n Average Waiting Time : %f\n Average Turn Around Time : %f\n\n",avwt,avtat);
}


/*
./a.out
Enter the Number of process : 4
Enter the process : 1 2 3 4
Enter arrival time : 0 0 0 0
Enter the Burst time : 3 2 5 7           

pro	at	bt	wt	tat :

 p[2]	0	2	0	 2
 p[1]	0	3	2	 5
 p[3]	0	5	5	 10
 p[4]	0	7	10	 17
 Average Waiting Time : 4.250000
 Average Turn Around Time : 8.500000


*/
