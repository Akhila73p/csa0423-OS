#include <stdio.h>

struct emp { int id; char name[20]; float sal; };

int main() {
    FILE *fp = fopen("emp.dat","wb+");
    struct emp e;

    printf("Enter id name salary: ");
    scanf("%d %s %f",&e.id,e.name,&e.sal);

    fseek(fp,0,SEEK_SET);
    fwrite(&e,sizeof(e),1,fp);

    fseek(fp,0,SEEK_SET);
    fread(&e,sizeof(e),1,fp);

    printf("\nStored: %d %s %.2f",e.id,e.name,e.sal);
    fclose(fp);
}

