#include <unistd.h>
#include <fcntl.h> 
#include <ctype.h>

int main(int argc, char *argv[]) 
{
    char buf[2048];
    int fd;

    if (argc == 0) {
        fd = 0;
        toupper(write(fd, buf, 2048));
    }

    else {
        for (int i = 1; i < argc; i++) {
            fd = open(argv[i], O_RDWR);
            int sz = read(fd, buf, 2048);
            while (sz > 0) {
                sz = read(fd, buf, 2048);
                toupper(write(1, buf, sz));
            }
            close(fd);
        }
    }
}    
