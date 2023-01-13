#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <signal.h>

#include "timeout.h"


int timeout(const int secs, char **argv, const int signal) {
    int wait_status;
    pid_t pid = fork();

    switch (pid) {
        case -1: 
            fprintf(stderr, "\nERROR: child process could not be created\n");
            exit(EXIT_FAILURE_125);
        case 0: 
            execvp(argv[0], argv);  
            fprintf(stderr, "ERROR: failed to run command \"%s\": No such file or directory\n", argv[0]);
            exit(EXIT_FAILURE_127);
        default:
            for(int i = 0; i < secs; i++) {
                if(waitpid(pid, &wait_status, WNOHANG) != 0) {    
                    if(WIFEXITED(wait_status) && WEXITSTATUS(wait_status) == 0) {
                        exit(EXIT_SUCCESS); 
                        break;
                    }
                    exit(EXIT_FAILURE_126);
                } else {
                    usleep(1000000);
                }
            }

            kill(pid, signal);
            exit(EXIT_FAILURE_124);
    }
}

