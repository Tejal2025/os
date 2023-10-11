#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct process_info
{
 char pname[20];
 int at,bt,ct,bt1,p;
 struct process_info *next;
}NODE;

int n;
NODE *first,*last;

void accept_info()
{
 NODE *p;
 int i;

 printf("Enter no.of process:");
 scanf("%d",&n);

 for(i=0;i<n;i++)
 {
  p = (NODE*)malloc(sizeof(NODE));

  printf("Enter process name:");
  scanf("%s",p->pname);

  printf("Enter arrival time:");
  scanf("%d",&p->at);

  printf("Enter first CPU burst time:");
  scanf("%d",&p->bt);

  printf("Enter priority:");
  scanf("%d",&p->p);

  p->bt1 = p->bt;
  
  p->next = NULL;

  if(first==NULL)
   first=p;
  else
   last->next=p;

  last = p;
 }
}

void print_output()
{
 NODE *p;
 float avg_tat=0,avg_wt=0;

 printf("pname\tat\tbt\tp\ttct\ttat\twt\n");

 p = first;
 while(p!=NULL)
 {
  int tat = p->ct-p->at;
  int wt = tat-p->bt;
  
  avg_tat+=tat;
  avg_wt+=wt;

  printf("%s\t%d\t%d\t%d\t%d\t%d\t%d\n",
   p->pname,p->at,p->bt,p->p,p->ct,tat,wt);
  
  p=p->next;
 }

 printf("Avg TAT=%f\tAvg WT=%f\n",
   avg_tat/n,avg_wt/n);
}

void print_input()
{
 NODE *p;

 p = first;
 
 printf("pname\tat\tbt\tp\n");
 while(p!=NULL)
 {
  printf("%s\t%d\t%d\t%d\n",
   p->pname,p->at,p->bt1,p->p);
  p = p->next;
 }
}

void sort()
{
 NODE *p,*q;
 int t;
 char name[20];

 p = first;
 while(p->next!=NULL)
 {
  q=p->next;
  while(q!=NULL)
  {
   if(p->at > q->at)
   {
    strcpy(name,p->pname);
    strcpy(p->pname,q->pname);
    strcpy(q->pname,name);

    t = p->at;
    p->at = q->at;
    q->at = t;
    
    t = p->bt;
    p->bt = q->bt;
    q->bt = t;

    t = p->ct;
    p->ct = q->ct;
    q->ct = t;

    t = p->bt1;
    p->bt1 = q->bt1;
    q->bt1 = t;
   
    t = p->p;
    p->p = q->p;
    q->p = t;
   }

   q=q->next;
  }
 
  p=p->next;
 }
}

int time;

NODE * get_p()
{
 NODE *p,*min_p=NULL;
 int min=9999;

 p = first;
 while(p!=NULL)
 {
  if(p->at<=time && p->bt1!=0 &&
   p->p<min)
  {
   min = p->p;
   min_p = p;
  }
  p=p->next;
 }

 return min_p;
}

struct gantt_chart
{
 int start;
 char pname[30];
 int end;
}s[100],s1[100];

int k;

void pnp()
{
 int prev=0,n1=0;
 NODE *p;

 while(n1!=n)
 {
  p = get_p();

  if(p==NULL)
  {
   time++;
   s[k].start = prev;
   strcpy(s[k].pname,"*");
   s[k].end = time;

   prev = time;
   k++;
  }
  else
  {
   time+=p->bt1;
   s[k].start = prev;
   strcpy(s[k].pname, p->pname);
   s[k].end = time;

   prev = time;
   k++;

   p->ct = time;
   p->bt1 = 0;

   n1++;
  }

  print_input(); 
  sort();
 }
}

void print_gantt_chart()
{
 int i,j,m;

 s1[0] = s[0];
 
 for(i=1,j=0;i<k;i++)
 {
  if(strcmp(s[i].pname,s1[j].pname)==0)
   s1[j].end = s[i].end;
  else
   s1[++j] = s[i];
 }

 printf("%d",s1[0].start);
 for(i=0;i<=j;i++)
 {
  m = (s1[i].end - s1[i].start);

  for(k=0;k<m/2;k++)
   printf("-");

  printf("%s",s1[i].pname);

  for(k=0;k<(m+1)/2;k++)
   printf("-");

  printf("%d",s1[i].end);
 }
}

int main()
{
 accept_info();
 sort();
 pnp();
 print_output();
 print_gantt_chart();

 return 0;
}


/*
OUTPUT-
./a.out
Enter no.of process:3
Enter process name:p1
Enter arrival time:2
Enter first CPU burst time:3
Enter priority:1
Enter process name:p2
Enter arrival time:1
Enter first CPU burst time:3
Enter priority:2
Enter process name:p3
Enter arrival time:2
Enter first CPU burst time:4
Enter priority:5
pname	at	bt	p
p2	1	3	2
p1	2	3	1
p3	2	4	5
pname	at	bt	p
p2	1	0	2
p1	2	3	1
p3	2	4	5
pname	at	bt	p
p2	1	0	2
p1	2	0	1
p3	2	4	5
pname	at	bt	p
p2	1	0	2
p1	2	0	1
p3	2	0	5
pname	at	bt	p	tct	tat	wt
p2	1	3	2	4	3	0
p1	2	3	1	7	5	2
p3	2	4	5	11	9	5
Avg TAT=5.666667	Avg WT=2.333333
0*-1-abcd-3--yhj---8-cdb--11
*/  
