/*
 * Student ID: 13-9999-X
 * Name: Takuo Watanabe
 */

#include "types.h"
#include "stat.h"
#include "user.h"

int main(int argc, char *argv[]) {
    if (argc < 2) {
        printf(2, "usage: %s prog arg...\n", argv[0]);
        exit();
    }
    char *prog = argv[1];
    int p[2];
    pipe(p);
    if (fork() == 0) {
        close(0);
        dup(p[0]);
        close(p[0]);
        close(p[1]);
        char *argv[] = { prog, 0 };
        exec(prog, argv);
    }
    close(p[0]);
    int i;
    for (i = 2; i < argc; i++)
        printf(p[1], "%s\n", argv[i]);
    close(p[1]);
    wait();
    exit();
}


/* For Emacs
 * Local Variables: ***
 * c-file-style: "gnu" ***
 * c-basic-offset: 4 ***
 * End: ***
 */
