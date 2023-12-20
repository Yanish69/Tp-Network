#include <netdb.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <unistd.h>

#define BUF_SIZE 500
#define ERROR "Invalid command"
#define TFTP_SERVER_PORT 69

int main(int argc, char *argv[]) {

    if (argc != 3) {
        write(STDOUT_FILENO, ERROR, sizeof(ERROR) - 1);
        exit(EXIT_FAILURE);
    }

    const char *server = argv[1];
    const char *file = argv[2];

    write(STDOUT_FILENO, "Server address : ", 16);
    write(STDOUT_FILENO, server, strlen(server));
    write(STDOUT_FILENO, "\n", 1);
    write(STDOUT_FILENO, "File name : ", 14);
    write(STDOUT_FILENO, server, strlen(file));
    write(STDOUT_FILENO, "\n", 1);

    return 0;
}