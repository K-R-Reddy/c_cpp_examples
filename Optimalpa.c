#include <stdio.h>

int main() {
    int rs[25], frames[10], n, f, i, j, k, pageFaults = 0, flag, farthest, index, found;
    printf("Enter the length of reference string: ");
    scanf("%d", &n);
    printf("Enter the reference string: ");
    for (i = 0; i < n; i++) {
        scanf("%d", &rs[i]);
    }
    printf("Enter the number of frames: ");
    scanf("%d", &f);
    for (i = 0; i < f; i++) {
        frames[i] = -1;
    }

    printf("\nThe Page Replacement Process is:\n");
    for (i = 0; i < n; i++) {
        flag = 0;
        for (j = 0; j < f; j++) {
            if (frames[j] == rs[i]) {
                flag = 1; 
                break;
            }
        }

        // If page is not found (Page Fault)
        if (flag == 0) {
            for (j = 0; j < f; j++) {
                if (frames[j] == -1) {
                    frames[j] = rs[i];
                    pageFaults++;
                    flag = 1;
                    break;
                }
            }
        }

        if (flag == 0) {
            farthest = -1, index = -1;
            for (j = 0; j < f; j++) {
                found = 0;
                for (k = i + 1; k < n; k++) {
                    if (frames[j] == rs[k]) {
                        found = 1;
                        if (k > farthest) {
                            farthest = k;
                            index = j;
                        }
                        break;
                    }
                }
                if (found == 0) {
                    index = j;
                    break;
                }
            }
            frames[index] = rs[i];
            pageFaults++;
        }
        for (j = 0; j < f; j++) {
            if (frames[j] != -1)
                printf("\t%d", frames[j]);
            else
                printf("\t-");
        }
        printf("\n");
    }
    printf("\nTotal Page Faults using Optimal: %d\n", pageFaults);

    return 0;
}

