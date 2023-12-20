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

