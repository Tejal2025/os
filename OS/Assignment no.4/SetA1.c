//Implement FIFO
#include<stdio.h>
#include<stdlib.h>

struct fnode
{

    int pno;

};

struct fnode frames[10];
int fr;
int pagefound (int pno1)
{

    for (int i=0; i<fr; i++)
        if(frames[i].pno==pno1)
            return 1;
    return 0;


}

void main()
{
    int ref_str[30];
    int pfct=0,i,pno1, p, flag=0;
    int len,cnt=0;
    printf("\n Enter no. of frames: ");
    scanf("%d", &fr);
    printf("\n Enter length of referencestring: ");
    scanf("%d",&len);
    printf("\n Enter  referencestring: ");
    for (i=0; i<len; i++)
        scanf("%d",&ref_str[i]);

    for (i=0; i<fr; i++)
        frames[i].pno=-1;

    printf("\nPageNo\t  pageframes\t\tpagefault");

    printf("\n-----------------------------------------");
    for (p=0; p<len; p++)
    {
        pno1=ref_str[p];
        flag=0;

        if (pagefound (pno1)==0)
        {
            frames[pfct%fr].pno=pno1;

            pfct++;

            flag=1;

        }

        printf("\n %d\t",pno1);
        for (i=0; i<fr; i++)
            printf("  %d ", frames[i]);


        if(flag==1)
            printf("\t\t YES");

        else
        {
            printf("\t\t  NO");
            cnt++;
        }
        //  printf("\t%d",pfct);

    }

    printf("\n-----------------------------------------");

    printf("\n Total No. of page fault : %d", pfct);
    printf("\n Total No. of page Hits : %d", cnt);

}

/*
OUTPUT :->

ty8@pc40:~/Ty 8/OS/Assignment no.4$ cc SetA1.c
ty8@pc40:~/Ty 8/OS/Assignment no.4$ ./a.out

 Enter no. of frames: 3

 Enter length of referencestring: 16

 Enter  referencestring: 12 15 12 18 6 8 11 12 19 12 6 8 12 15 19 8

PageNo	  pageframes		pagefault
-----------------------------------------
 12	  12   -1   -1 		 YES
 15	  12   15   -1 		 YES
 12	  12   15   -1 		  NO
 18	  12   15   18 		 YES
 6	  6    15   18 		 YES
 8	  6     8   18 		 YES
 11	  6     8   11 		 YES
 12	  12    8   11 		 YES
 19	  12   19   11 		 YES
 12	  12   19   11 		  NO
 6	  12   19   6 		 YES
 8	  8    19   6 		 YES
 12	  8    12   6 		 YES
 15	  8    12   15 		 YES
 19	  19   12   15 		 YES
 8	  19    8   15 		 YES
-----------------------------------------
 Total No. of page fault : 14
 Total No. of page Hits : 2 
 */

