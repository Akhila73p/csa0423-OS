#include <stdio.h>

int main() {
    char dirname[20], files[10][20];
    int n;

    printf("Enter directory name: ");
    scanf("%s", dirname);

    printf("Enter number of files: ");
    scanf("%d", &n);

    for(int i=0;i<n;i++){
        printf("Enter file %d name: ", i+1);
        scanf("%s", files[i]);
    }

    printf("\nDirectory: %s\nFiles:\n", dirname);
    for(int i=0;i<n;i++)
        printf("%s\n", files[i]);

    return 0;
}

