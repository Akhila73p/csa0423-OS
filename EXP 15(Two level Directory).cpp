#include <stdio.h>

int main() {
    int users, files;
    char uname[10][20], fname[10][10][20];

    printf("Enter number of users: ");
    scanf("%d", &users);

    for(int i=0;i<users;i++) {
        printf("Enter user %d name: ", i+1);
        scanf("%s", uname[i]);
        printf("Enter number of files: ");
        scanf("%d", &files);

        for(int j=0;j<files;j++) {
            printf("Enter file %d: ", j+1);
            scanf("%s", fname[i][j]);
        }
    }

    printf("\nTwo Level Directory:\n");
    for(int i=0;i<users;i++) {
        printf("User: %s\n", uname[i]);
        for(int j=0;j<3;j++)
            printf("   %s\n", fname[i][j]);
    }
    return 0;
}

