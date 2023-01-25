#include <unistd.h>
#include <fcntl.h> 

int main(int argc, char *argv[]) {
    (void) argc;
    char buf[2048];

    int fd = open(argv[1], O_RDWR | O_EXCL);
    int sz = read(fd, buf, 2048);
    write(1, buf, sz);
    close(fd);
}