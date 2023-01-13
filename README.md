# timeout

Clone the repo and run:

```
make
```

## Description (by Prof. Henri)
[`timeout(1)`](https://www.man7.org/linux/man-pages/man1/timeout.1.html) is a command that runs othe commands until a specified time interval has passed.

```
timeout [--help] SECS COMMAND ARGS...
```
### How it works

1. The program gets the amount of seconds that the user is requesting.
2. Execute the requested command with arguments.
3. Handle command timeout 
    - [`waitpid(2)`](https://man7.org/linux/man-pages/man2/wait.2.html) with `WNOHANG` option
    - if `waitpid` returns 0 then child didn't exit.
    - wait some time using [`usleep(3)`](https://man7.org/linux/man-pages/man3/usleep.3.html).
    - Point is that using [`sleep(3)`](https://man7.org/linux/man-pages/man3/sleep.3.html) using full seconds means that you will always wait a second. But also, using too small `usleep` value you will loop a lot more than required.
    - repeat
4. Exit an error code on timeout or the program's error code on success.
