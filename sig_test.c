/*
 * R Jesse Chaney
 */

#ifndef _GNU_SOURCE
// This is so we can get to a couple helpful GNU-isms.
# define _GNU_SOURCE
#endif // _GNU_SOURCE

#include <stdio.h>
#include <signal.h>
#include <string.h>
#include <errno.h>
#include <stdlib.h>
#include <unistd.h>


int main(int argc, char *argv[])
{
    printf("This is my pid: %d\n", getpid());
}
