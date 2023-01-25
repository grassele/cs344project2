#include <unistd.h>
#include <fcntl.h> 

int main(int argc, char *argv[]) {
    int fd = open(argv[1], O_RDWR | O_EXCL);
    int sz = read(fd, &argv[1], 2048);
    write(1, &argv[1], sz);
    close(fd);
}