#include <stdio.h>

int main() {
    int frames, pages, ref[50], mem[10], pos = 0, faults = 0;

    printf("Enter number of frames: ");
    scanf("%d", &frames);

    printf("Enter number of pages: ");
    scanf("%d", &pages);

    printf("Enter reference string: ");
    for(int i = 0; i < pages; i++)
        scanf("%d", &ref[i]);

    for(int i = 0; i < frames; i++)
        mem[i] = -1;

    for(int i = 0; i < pages; i++) {
        int found = 0;

        // check if page exists
        for(int j = 0; j < frames; j++) {
            if(mem[j] == ref[i]) {
                found = 1;
                break;
            }
        }

        // if not found -> page fault
        if(!found) {
            mem[pos] = ref[i];
            pos = (pos + 1) % frames;
            faults++;
        }

        // print frames
        printf("Frames: ");
        for(int j = 0; j < frames; j++)
            printf("%d ", mem[j]);
        printf("\n");
    }

    printf("\nTotal Page Faults = %d\n", faults);

    return 0;
}

