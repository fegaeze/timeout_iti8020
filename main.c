#include <stdlib.h>
#include <getopt.h>
#include <stdio.h>

#include "options.h"
#include "timeout.h"


int main(int argc, char **argv) {

    uint8_t signal = SIGTERM;

    parse_cmdline(argc, argv);
    int secs = atoi(argv[optind]);

    argv += optind + 1;
    timeout(secs, argv, signal);
}