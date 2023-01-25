#include <unistd.h>
#include <fcntl.h> 

int main(int argc, char *argv[]) {

    for (int i = 1; i <= argc; i++) {
        int fd = open(argv[i], O_RDWR);

        int sz = read(fd, &argv[i], 2048);

        for (int j = 0; sz > 0; j++) {
            sz = read(fd, &argv[i]+2048*j, 2048);
            write(1, &argv[i]+2048*j, sz);
        }

        close(fd);
    }
}