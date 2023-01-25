#include <ctype.h>
#include <unistd.h>
#include <fcntl.h> 

void bufupper(char buf[], int sz) {
    for (int i = 0; i < sz; i++) {
        buf[i] = toupper(buf[i]);
    }
}

int main(int argc, char *argv[]) 
{
    char buf[2048];
    int fd;

    if (argc == 1) {
        fd = 0;
        int sz = read(fd, buf, 2048);
        while (sz > 0) {
            bufupper(buf, sz);
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
                bufupper(buf, sz);
                write(1, buf, sz);
            }
        }
    }
    
    close(fd);
}      
