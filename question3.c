#include <unistd.h>
#include <string.h>
#include <stdlib.h>
#include <netdb.h>

#define PORT "1069"

void extract_info(const char *command, const char *argument) {
    write(STDOUT_FILENO, "Command: ", 9);
    write(STDOUT_FILENO, command, strlen(command));
    write(STDOUT_FILENO, "\n", 1);
    write(STDOUT_FILENO, "Argument: ", 10);
    write(STDOUT_FILENO, argument, strlen(argument));
    write(STDOUT_FILENO, "\n", 1);

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

    if (strcmp(command, "gettftp") != 0 && strcmp(command, "puttftp") != 0) {
        write(STDERR_FILENO, "Invalid command: ", 17);
        write(STDERR_FILENO, command, strlen(command));
        write(STDERR_FILENO, "\n", 1);
        exit(EXIT_FAILURE);
    }

    struct addrinfo hints;
    struct addrinfo *result, *rp;
    int status;
    int client_socket;

    memset(&hints, 0, sizeof(struct addrinfo));
    hints.ai_family = AF_UNSPEC;    // IPv4 or IPv6
    hints.ai_socktype = SOCK_STREAM; // Stream socket (TCP)

    status = getaddrinfo("srvtpinfo1.ensea.fr", PORT, &hints, &result);
    if (status != 0) {
        write(STDERR_FILENO, "getaddrinfo: ", 13);
        write(STDERR_FILENO, gai_strerror(status), strlen(gai_strerror(status)));
        write(STDERR_FILENO, "\n", 1);
        exit(EXIT_FAILURE);
    }


    for (rp = result; rp != NULL; rp = rp->ai_next) {
        client_socket = socket(rp->ai_family, rp->ai_socktype, rp->ai_protocol);
        if (client_socket == -1) {
            perror("socket");
            continue;
        }
        if (connect(client_socket, rp->ai_addr, rp->ai_addrlen) != -1) {
            // Success connection
            break;
        }

        close(client_socket);
    }

    freeaddrinfo(result);
    if (rp == NULL) {
        write(STDERR_FILENO, "Impossible to connect\n", 37);
        exit(EXIT_FAILURE);
    }

    extract_info(command, argument);

    close(client_socket);

    return 0;
}