#include <fcntl.h>  // for open()
#include <unistd.h>
int main()
{
    int fd = open("output.txt", O_WRONLY | O_CREAT, 0644); 
    // kay7ll file write-only, wla ma kaynsh kaycreatih

    if (fd < 0) { // ila fd = -1, ma t7ellash
        write(2, "Error: Cannot open or create file\n", 34);
        return 1;
    }

    char *message = "Hello, File!\n";
    write(fd, message, 12); // ktb content f file

    close(fd); // sedd l-file
    return 0;
}
