//Implement MFU
#include<stdio.h>

struct frame
{
    int pno;
    int freq;

} frames [5];

int ref_str[30];
int np,n,i,j,frequency,currtime;

int pagefound (int pno1)
{
    int i;

    for(i=0; i<n; i++)

        if (frames[i].pno==pno1)
            return i;
    return -1;

}

int free_fr()
{
    for(i=0; i<n; i++)
        if (frames[i].pno==-1)
            return i;
    return -1;

}

int get_mfu()
{
    int max=0;

    for(i=0; i<n; i++)

        if(frames[i].freq > frames[max].freq)
            max=i;
    return max;

}

int main()
{
    int i,j,pno1,p,page_fault=0, flag,cnt=0;;
    float hr,mr;
    printf("\n Enter how many frames: ");
    scanf("%d",&n);
    printf("\n Enter  length of referencestring: ");
    scanf("%d",&np);
    int len=np;
    printf("\n Enter referencestring: ");
    for(i=0; i<np; i++)
        scanf("%d",&ref_str[i]);

    for(i=0; i<n; i++)
    {
        frames[i].pno=-1;
        frames[i].freq=0;
    }
    printf("\n Page No.\tFrames\t\tPage Fault");
    printf("\n---------------------------------------------------");
    currtime=1;
    for (p=0; p<np; p++)
    {
        flag=0;
        frequency=0;
        pno1=ref_str[p];
        j=pagefound (pno1);
        if(j==-1)
        {
            page_fault++;
            j=free_fr();
            if (j==-1)
                j=get_mfu();
            frames[j].pno=pno1;
            frames[j].freq=1;
            flag=1;

        }
        else
            frames[j].freq++;
        printf("\n%5d\t",pno1);
        for (i=0; i<n; i++)
            printf("  %d ", frames[i].pno);


        if(flag==1)
            printf("\t YES");
        else
        {
            printf("\t NO");
            cnt++;
        }

    }
    printf("\n-------------------------------------------------");
    // hr = ((page_fault)/np);
    // mr = ((cnt)/np);
    printf("\nNo. of page fault: %d ",page_fault);
    printf("\nNo. of page Hits: %d ",cnt);

    // printf("\nHit Ratio : %.3f ",hr);
    //printf("\nMis Ratio : %.3f  ",mr);
}

/* 
OUTPUT:->

ty8@pc40:~/Ty 8/OS/Assignment no.4$ cc SetB2.c
ty8@pc40:~/Ty 8/OS/Assignment no.4$ ./a.out

 Enter how many frames: 4

 Enter  length of referencestring: 16

 Enter referencestring: 12 15 12 18 6 8 11 12 19 12 6 8 12 15 19 8

 Page No.	Frames		Page Fault
---------------------------------------------------
   12	  12   -1   -1   -1 	 YES
   15	  12   15   -1   -1 	 YES
   12	  12   15   -1   -1 	 NO
   18	  12   15   18   -1 	 YES
    6	  12   15   18    6 	 YES
    8	   8   15   18    6  	 YES
   11	  11   15   18    6 	 YES
   12	  12   15   18    6 	 YES
   19	  19   15   18    6 	 YES
   12	  12   15   18    6 	 YES
    6	  12   15   18    6 	 NO
    8	  12   15   18    8 	 YES
   12	  12   15   18    8 	 NO
   15	  12   15   18    8 	 NO
   19	  19   15   18    8 	 YES
    8	  19   15   18    8 	 NO
-------------------------------------------------
No. of page fault: 11 
No. of page Hits: 5
*/
