#include <stdio.h>

int main() {
    int frames, i, j, k, pageFaults = 0;
    
    int ref[] = {7, 0, 1, 2, 0, 3, 0, 4};
    int n = sizeof(ref) / sizeof(ref[0]);

    printf("Enter number of frames: ");
    scanf("%d", &frames);

    int f[frames];

    for(i = 0; i < frames; i++)
        f[i] = -1;

    int front = 0; 

    for(i = 0; i < n; i++) {
        int found = 0;

        for(j = 0; j < frames; j++) {
            if(f[j] == ref[i]) {
                found = 1;
                break;
            }
        }

        if(!found) {
            f[front] = ref[i];        
            front = (front + 1) % frames;
            pageFaults++;
        }

        printf("\nAfter inserting %d: ", ref[i]);
        for(k = 0; k < frames; k++) {
            if(f[k] != -1)
                printf("%d ", f[k]);
            else
                printf("- ");
        }
    }

    printf("\n\nTotal Page Faults = %d\n", pageFaults);

    return 0;
}