//Implment LRU
#include<stdio.h>

struct frame {
    int pno;
    int counter;

} frames [5];

int ref_str[30];
int np, n, i, j, currtime;

int pagefound(int pno1) {
    int i;

    for (i = 0; i < n; i++)

        if (frames[i].pno == pno1)
            return i;
    return -1;

}//page_found

int get_lru() {
    int min = 0;

    for (i = 0; i < n; i++)

        if (frames[i].counter < frames[min].counter)
            min = i;
    return min;

}

int main() {
    int i, j, pno1, p, page_fault = 0, flag, cnt = 0;;
    float hr, mr;
    printf("\n Enter how many frames: ");
    scanf("%d", & n);
    printf("\n Enter  length of referencestring: ");
    scanf("%d", & np);
    int len = np;
    printf("\n Enter referencestring: ");
    for (i = 0; i < np; i++)
        scanf("%d", & ref_str[i]);

    for (i = 0; i < n; i++) {
        frames[i].pno = -1;
        frames[i].counter = -1;
    }
    printf("\n Page No.\tFrames\t\tPage Fault");
    printf("\n-------------------------------------------------");
    currtime = 1;
    for (p = 0; p < np; p++) {
        flag = 0;
        pno1 = ref_str[p];
        j = pagefound(pno1);
        if (j == -1) {
            page_fault++;

            j = get_lru();

            frames[j].pno = pno1;

            flag = 1;

        }
        frames[j].counter = currtime;
        currtime++;
        printf("\n%5d\t", pno1);
        for (i = 0; i < n; i++)
            printf("  %d ", frames[i]);


        if (flag == 1)
            printf("\t YES");
        else {
            printf("\t NO");
            cnt++;
        }

    }
    printf("\n--------------------------------------------------");
    // hr = ((page_fault)/np);
    // mr = ((cnt)/np);
    printf("\nNo. of page fault: %d ", page_fault);
    printf("\nNo. of page Hits: %d ", cnt);

    // printf("\nHit Ratio : %.3f ",hr);
    //printf("\nMis Ratio : %.3f  ",mr);
}




/* 
OUTPUT :->

ty8@pc40:~/Ty 8/OS/Assignment no.4$ gedit SetA2.c
ty8@pc40:~/Ty 8/OS/Assignment no.4$ cc SetA2.c
ty8@pc40:~/Ty 8/OS/Assignment no.4$ ./a.out

 Enter how many frames: 4

 Enter  length of referencestring: 16

 Enter referencestring: 12 15 12 18 6 8 11 12 19 12 6 8 12 15 19 8

 Page No.	Frames		Page Fault
-------------------------------------------------
   12	  12   -1   -1   -1 	 YES
   15	  12   15   -1   -1 	 YES
   12	  12   15   -1   -1 	 NO
   18	  12   15   18   -1 	 YESYES
    8	  12   8    18    6 	 YES
   11	  11   8    18    6 	 YES
   12	  11   8    12    6 	 YES
   19	  11   8    12   19 	 YES
   12	  11   8    12   19 	 NO
    6	  11   6    12   19 	 YES
    8	  8    6    12   19 	 YES
   12	  8    6    12   19 	 NO
   15	  8    6    12   15 	 YES
   19	  8   19    12   15 	 YES
    8	  8   19    12   15 	 NO
--------------------------------------------------
No. of page fault: 12 
No. of page Hits: 4 
*/
	
