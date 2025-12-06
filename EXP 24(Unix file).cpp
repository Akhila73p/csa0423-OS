#include <iostream>
#include <fcntl.h>
#include <unistd.h>
using namespace std;

int main() {
    int fd = open("demo.txt", O_CREAT | O_RDWR, 0644);

    write(fd, "Hello OS Lab\n", 13);

    lseek(fd, 0, SEEK_SET);

    char buffer[50];
    int n = read(fd, buffer, 50);

    buffer[n] = '\0';
    cout << buffer;

    close(fd);
}

