#include<stdio.h>
#include<stdlib.h>
#include<string.h>

void main()
{
  int i,n;
  float avwt=0,avtat=0;
  
  printf("\n Enter no. of process");
  scanf("%d",&n);
  int at[n],bt[n],wt[n],tat[n];
  printf("\n Enter arrival time:");
  for(i=0;i<n;i++)
      scanf("%d",&at[i]);
  for(i=0;i<n;i++)
  {
    bt[i]=rand()%10;
  }
  
  int start[n];
  start[0]=0;
  for(i=1;i<n;i++)
  {
    start[i]=start[i-1]+bt[i-1];
  }
  for(i=0;i<n;i++)
  {
    wt[i]=start[i]-at[i];
    avwt+=wt[i];
  }
    avwt/=n;
    for(i=0;i<n;i++)
    {
      tat[i]=wt[i]+bt[i];
      avtat+=tat[i];
    }
    avtat/=n;
    printf("pro\tat\tbt\twt\ttat :");
    for(i=0;i<n;i++)
    {
      printf("\n%d\t%d\t%d\t%d\t%d\t",i+1,at[i],bt[i],wt[i],tat[i]);
    }
    printf("\n average waiting time is:%f",avwt);
    printf("\n average turnaround time is:%f",avtat);
}
/*
 ./a.out

 Enter no. of process4

 Enter arrival time:0
1
2
3
pro	at	bt	wt	tat :
1	0	3	0	3	
2	1	6	1	7	
3	2	7	2	9	
4	3	5	3	8	
 average waiting time is:1.500000
 average turnaround time is:6.750000
*/
