//Implement OPT
#include<stdio.h>
 
int main()
{
    int fr, np, frames[10], pages[30], temp[10], flag1, flag2, flag3;
    int i, j, k, pos, max, faults = 0;
    printf("Enter number of frames: ");
    scanf("%d", &fr);
    
    printf("Enter number of pages: ");
    scanf("%d", &np);
    
    printf("Enter page reference string: ");
    
    for(i = 0; i < np; ++i){
        scanf("%d", &pages[i]);
    }
    
    for(i = 0; i < fr; ++i){
        frames[i] = -1;
    }
    printf(" \n------------Page Frames-------------\n ");
    printf(" \nFr1\tFr2\tFr3\n");
    printf("\n------------------------------------");
    for(i = 0; i < np; ++i){
        flag1 = flag2 = 0;
        
        for(j = 0; j < fr; ++j){
            if(frames[j] == pages[i]){
                   flag1 = flag2 = 1;
                   break;
               }
        }
        
        if(flag1 == 0){
            for(j = 0; j < fr; ++j){
                if(frames[j] == -1){
                    faults++;
                    frames[j] = pages[i];
                    flag2 = 1;
                    break;
                }
            }    
        }
        
        if(flag2 == 0){
        	flag3 =0;
        	
            for(j = 0; j < fr; ++j){
            	temp[j] = -1;
            	
            	for(k = i + 1; k < np; ++k){
            		if(frames[j] == pages[k]){
            			temp[j] = k;
              
            			break;
            		}
            	}
            }
            
            for(j = 0; j < fr; ++j){
            	if(temp[j] == -1){
            		pos = j;
            		flag3 = 1;
            		break;
            	}
            }
            
            if(flag3 ==0){
            	max = temp[0];
            	pos = 0;
            	
            	for(j = 1; j < fr; ++j){
            		if(temp[j] > max){
            			max = temp[j];
            			pos = j;
            		}
            	}            	
            }
			
			frames[pos] = pages[i];
			faults++;
        }//if
        
        printf("\n");
        //for(j = 0; j < np; ++j)
            //printf("\n%d", pages[j]);
        for(j = 0; j < fr; ++j){
            printf("%d\t", frames[j]);
        }
    }
    printf("\n------------------------------------");
    int hit=np-faults;
    printf("\n\nTotal Page Faults = %d", faults);
    printf("\n\nTotal Page Hits = %d", hit);
    
    return 0;
}


/*

OUTPUT:->

ty8@pc40:~/Ty 8/OS/Assignment no.4$ gedit SetB1.c
ty8@pc40:~/Ty 8/OS/Assignment no.4$ cc SetB1.c
ty8@pc40:~/Ty 8/OS/Assignment no.4$ ./a.out
Enter number of frames: 3
Enter number of pages: 16
Enter page reference string: 12 15 12 18 6 8 11 12 19 12 6 8 12 15 19 8
 
------------Page Frames-------------
  
Fr1	Fr2	Fr3

------------------------------------
12	-1	-1	
12	15	-1	
12	15	-1	
12	15	18	
12	15	6	
12	8	6	
12	11	6	
12	11	6	
12	19	6	
12	19	6	
12	19	6	
12	19	8	
12	19	8	
15	19	8	
15	19	8	
15	19	8	
------------------------------------

Total Page Faults = 9

Total Page Hits = 7
*/
