#include <stdio.h>

int main() {
    int frames, pages, ref[50], mem[10], used[10], time = 0, faults = 0;

    printf("Enter number of frames: ");
    scanf("%d", &frames);

    printf("Enter number of pages: ");
    scanf("%d", &pages);

    printf("Enter reference string: ");
    for(int i=0;i<pages;i++) scanf("%d", &ref[i]);

    for(int i=0;i<frames;i++) mem[i] = -1;

    for(int i=0;i<pages;i++) {
        time++;
        int found = 0;

        for(int j=0;j<frames;j++) {
            if(mem[j] == ref[i]) {
                found = 1;
                used[j] = time;
                break;
            }
        }

        if(!found) {
            int lru = 0;
            for(int j=1;j<frames;j++)
                if(used[j] < used[lru]) lru = j;

            mem[lru] = ref[i];
            used[lru] = time;
            faults++;
        }

        printf("Frames: ");
        for(int j=0;j<frames;j++) printf("%d ", mem[j]);
        printf("\n");
    }

    printf("Total Page Faults = %d\n", faults);
    return 0;
}

