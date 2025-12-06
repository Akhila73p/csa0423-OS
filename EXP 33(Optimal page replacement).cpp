#include <stdio.h>

int main() {
    int frames, pages, ref[50], mem[10], faults = 0;

    printf("Enter number of frames: ");
    scanf("%d", &frames);

    printf("Enter number of pages: ");
    scanf("%d", &pages);

    printf("Enter reference string: ");
    for(int i=0;i<pages;i++) scanf("%d", &ref[i]);

    for(int i=0;i<frames;i++) mem[i] = -1;

    for(int i=0;i<pages;i++) {
        int found = 0;
        for(int j=0;j<frames;j++)
            if(mem[j] == ref[i]) found = 1;

        if(!found) {
            int pos = -1, far = -1;

            for(int j=0;j<frames;j++) {
                int k;
                for(k=i+1; k<pages; k++)
                    if(mem[j] == ref[k]) break;

                if(k == pages) { pos = j; break; }
                if(k > far) { far = k; pos = j; }
            }

            mem[pos] = ref[i];
            faults++;
        }

        printf("Frames: ");
        for(int j=0;j<frames;j++) printf("%d ", mem[j]);
        printf("\n");
    }

    printf("Total Page Faults = %d\n", faults);
    return 0;
}

