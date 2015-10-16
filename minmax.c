/*
 * Student ID: 13-9999-X
 * Name: Takuo Watanabe
 */

#include "types.h"
#include "stat.h"
#include "user.h"

#define BUFLEN 64

int main() {
    char buf[BUFLEN];
    int max = 0, min = 0;
    gets(buf, BUFLEN);
    while (strlen(buf) > 0) {
        int a = atoi(buf);
        min = a < min ? a : min;
        max = a > max ? a : max;
        gets(buf, BUFLEN);
    }
    printf(1, "min=%d, max=%d\n", min, max);
    exit();
}


/* For Emacs
 * Local Variables: ***
 * c-file-style: "gnu" ***
 * c-basic-offset: 4 ***
 * End: ***
 */
