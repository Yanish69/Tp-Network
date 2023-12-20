//#include <iostream>
#include <sys/socket.h>
#include <netdb.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <netinet/in.h>
#include <unistd.h>
#include <string.h>
#include <stdlib.h>

    void extract_info(const char *command, const char *argument) {
        write(STDOUT_FILENO, "Command: ", 9);
        write(STDOUT_FILENO, command, strlen(command));
        write(STDOUT_FILENO, "\n", 1);

        write(STDOUT_FILENO, "Argument: ", 10);
        write(STDOUT_FILENO, argument, strlen(argument));
        write(STDOUT_FILENO, "\n", 1);

        // Vous pouvez ajouter le code pour extraire davantage d'informations si nécessaire
    }

int main(int argc, char *argv[]) {
    if (argc < 3) {
        write(STDERR_FILENO, "Usage: ", 7);
        write(STDERR_FILENO, argv[0], strlen(argv[0]));
        write(STDERR_FILENO, " <command> <argument>\n", 22);
        exit(EXIT_FAILURE);
    }

    const char *command = argv[1];
    const char *argument = argv[2];

    if (strcmp(command, "gettftp") == 0 || strcmp(command, "puttftp") == 0) {
        extract_info(command, argument);
    } else {
        write(STDERR_FILENO, "Invalid command: ", 17);
        write(STDERR_FILENO, command, strlen(command));
        write(STDERR_FILENO, "\n", 1);
        exit(EXIT_FAILURE);
    }

    return 0;
}










    // Initialize character arrays to store host and file information
/*
    char host[20], file[20];

    // Copy command line arguments to the host and file arrays

    strcpy(host, argv[1]);

    strcpy(file, argv[2]);

    // Display host information on the standard output

    write(STDOUT_FILENO, "Host : ", 7);

    write(STDOUT_FILENO, host, strlen(host));

    write(STDOUT_FILENO, "\n", 1);


    // Display file information on the standard output

    write(STDOUT_FILENO, "File : ", 7);

    write(STDOUT_FILENO, file, strlen(file));

    write(STDOUT_FILENO, "\n", 1);

    // Declare variables for address information

    int n_bytes;

    struct addrinfo hints;

    struct addrinfo *res;



    // Initialize the hints structure to zero

    memset(&hints, 0, sizeof(struct addrinfo));

    // Specify the socket type, address family, and protocol for address information

    hints.ai_socktype = SOCK_DGRAM;

    hints.ai_family = AF_INET;

    hints.ai_protocol = IPPROTO_UDP;

// Call getaddrinfo to obtain address information for the specified host and port

    int en = getaddrinfo(host, "1069", &hints, &res);

    // Check for errors in getaddrinfo

    if (en == -1) {

        perror("getaddrinfo");

        exit(EXIT_FAILURE);

    }


    // Program execution success

    return 0;
*/

