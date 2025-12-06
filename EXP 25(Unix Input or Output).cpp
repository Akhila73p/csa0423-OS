#include <iostream>
#include <fcntl.h>
#include <unistd.h>
#include <sys/stat.h>
#include <dirent.h>
using namespace std;

int main() {
    struct stat st;

    stat("demo.txt", &st);
    cout << "File Size: " << st.st_size << " bytes\n";

    DIR *d = opendir(".");
    struct dirent *de;

    while((de = readdir(d)) != NULL)
        cout << de->d_name << endl;

    closedir(d);
    return 0;
}

