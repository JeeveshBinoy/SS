#include <stdio.h>

void main() {
    int i, j, k, y, np, nr, alloc[10][10], avail[50], need[10][10], max[10][10], work[50], finish[50], safe[50], ind = 0;
    
    printf("Enter the number of processes: ");
    scanf("%d", &np);
    
    printf("Enter the number of resources: ");
    scanf("%d", &nr);
    
    printf("Enter the allocation matrix\n");
    for(i = 0; i < np; i++) {
        for(j = 0; j < nr; j++) {
            scanf("%d", &alloc[i][j]);
        }
    }
    
    printf("Enter the max matrix\n");
    for(i = 0; i < np; i++) {
        for(j = 0; j < nr; j++) {
            scanf("%d", &max[i][j]);
        }
    }
    
    printf("Enter the available matrix\n");
    for(i = 0; i < nr; i++) {
        scanf("%d", &avail[i]);
    }

    // Calculate the need matrix
    for(i = 0; i < np; i++) {
        for(j = 0; j < nr; j++) {
            need[i][j] = max[i][j] - alloc[i][j];
        }
    }
    
    printf("Need Matrix\n");
    for(i = 0; i < np; i++) {
        for(j = 0; j < nr; j++) {
            printf("%d\t", need[i][j]);
        }
        printf("\n");
    }

    // Initialize work with available resources
    for(i = 0; i < nr; i++) {
        work[i] = avail[i];
    }

    // Initialize all processes as unfinished
    for(i = 0; i < np; i++) {
        finish[i] = 0;
    }

    // Find the safe sequence
    for(k = 0; k < np; k++) {
        for(i = 0; i < np; i++) {
            if(finish[i] == 0) {
                int flag = 0;
                for(j = 0; j < nr; j++) {
                    if(need[i][j] > work[j]) {
                        flag = 1;
                        break;
                    }
                }
                if(flag == 0) {
                    safe[ind++] = i;
                    for(y = 0; y < nr; y++) {
                        work[y] += alloc[i][y];
                    }
                    finish[i] = 1;
                }
            }
        }
    }

    // Print the safe sequence
    printf("\nSafe Sequence: ");
    for(i = 0; i < ind; i++) {
        printf("P%d", safe[i]);
        if (i != ind - 1) printf(" -> ");
    }

    // Print processes not in the safe sequence
    printf("\nProcesses that are not in the safe sequence: ");
    for(i = 0; i < np; i++) {
        if(finish[i] == 0) {
            printf("P%d ", i);
        }
    }
}

