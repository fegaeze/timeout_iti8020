
#include <stdio.h>
#include <getopt.h>
#include <stdlib.h>

#include "timeout.h"

static struct option long_options[] = {
    {"help", no_argument, 0, 'h'},
    {0, 0, 0, 0}
};

static int usage(char *program, int exit_code) {
    fprintf(stderr,
        "\n"
        "Usage: %s DURATION COMMAND [ARG]\n"
        "Description: Start COMMAND, and kill it if still running after DURATION (in seconds)\n"
        "Options:\n"
        " -h, --help  Show this usage info\n"
        "\n", program);
    exit(exit_code);
}

void parse_cmdline(int argc, char **argv) {
    int opt;
    int option_index = 0;

    while ((opt = getopt_long(argc, argv, "h", long_options, &option_index)) != -1) {
        switch (opt) {
            case 'h': 
                usage(argv[0], EXIT_SUCCESS);
                break;
            default:
                usage(argv[0], EXIT_FAILURE_125);
        }
    }

    if ((argc -= optind) <= 1) {
        fprintf(stderr, "\nERROR: missing name argument\n");
        usage(argv[0], EXIT_FAILURE_125);
    }

    if (atoi(argv[optind]) == 0 && *argv[optind] != '0') {
        fprintf(stderr, "\nERROR: duration should be a number\n");
        usage(argv[0], EXIT_FAILURE_125);
    }
}

