#pragma once

#define EXIT_SUCCESS     0    // exits successfully
#define EXIT_FAILURE_124 124  // command times out :)
#define EXIT_FAILURE_125 125  // timeout program fails - cmd line input not formatted well
#define EXIT_FAILURE_126 126  // command is found but cannot be invoked - cmd args not formatted well
#define EXIT_FAILURE_127 127  // command cannot be found in path

int timeout(const int secs, char **argv, const int signal);