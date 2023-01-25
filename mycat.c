#include <unistd.h>
#include <fcntl.h> 

int main(int argc, char *argv[]) 
{
    char buf[2048];
    int fd;

    if (argc == 1) {
        fd = 0;
        int sz = read(fd, buf, 2048);
        while (sz > 0) {
            write(1, buf, sz);
            sz = read(fd, buf, 2048);
        }
    }

    else {
        for (int i = 1; i < argc; i++) {
            fd = open(argv[i], O_RDWR);
            while (1) {
                int sz = read(fd, buf, 2048);
                if (sz == 0)
                    break;
                write(1, buf, sz);
            }
        }
    }
    
    close(fd);
}    
