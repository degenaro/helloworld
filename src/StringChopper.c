#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*
 * function declaration
 */
void chop(char string[], int start, int skip);

/*
 * main
 */
int main(void) {
    printf ("********** TEST #1\n");
    char string1[] =  "abcdefghijklmnopqrstuvwxyz";
    chop(string1, 10, 5);
    printf ("********** TEST #2\n");
    char string2[] =  "abcdefghijklmnopqrstuvwxyz";
    chop(string2, 10, 100);
    printf ("********** TEST #3\n");
    char string3[] =  "abcdefghijklmnopqrstuvwxyz";
    chop(string3, 10, 0);
	return EXIT_SUCCESS;
}

/*
 * chop
 */
void chop(char string[], int start, int skip) {
    /* display the inputs */
    printf ("string: %s\nstart: %d\nskip: %d\n", string, start, skip);
    /* last possible char address */
    char *lastchar = string+strlen(string);
    /* start copying to here */
    char *dest = string+start;
    /* start copying from here */
    char *src = string+start+skip;
    /* handle case where source is beyond end of string */
    if(src > lastchar) {
        long unsigned int diff = lastchar-dest;
        printf ("warning: skip too big, changed to: %lu.\n", diff);
        src = lastchar;
    }
    /* copy chars one by one until last source char is reached */
    while(src <= lastchar) {
        /* display old char and new char that replaces it */
        printf ("%c <- %c\n", dest[0], src[0]);
        dest[0] = src[0];
        dest++;
        src++;
    }
    /* display the result */
    printf ("result: %s\n", string);
    return;
}
