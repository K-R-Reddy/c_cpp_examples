#include<stdio.h>
void main() {
    int i, j, hit=0, min, p[25], frames[10], count[10], flag, n, f, fault=0, t = 1; 
    printf("Enter no of pages :: "); 
    scanf("%d", &n);
    printf("Enter page numbers :: "); 
    for(i = 0; i < n; i++)
        scanf("%d", &p[i]);
    printf("Enter no of frames :: "); 
    scanf("%d", &f);
    for(i = 0; i < f; i++) {
        frames[i] = -1; 
        count[i] = 0;
    }
    for(i = 0; i < n; i++) {
        flag=0;
        for(j = 0; j < f; j++) {
            if(frames[j] == p[i]) {
                flag = 1; 
                count[j] = t;
                hit++;
                t++;
            }
        }
        if(flag == 0) {
            if(i < f) {
                frames[i] = p[i];  
                count[i] = t;
                t++;
            }
            else {
                min = 0;
                for(j = 1; j < f; j++) 
                    if(count[min] > count[j]) 
                        min = j;

                frames[min] = p[i]; 
                count[min] = t;
                t++;
            }
            fault++; 
        }
    }
    printf("Page faults : %d\n",fault);
    printf("Page Hits : %d\n",hit);
} 
