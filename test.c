#include <stdlib.h>
#include <stdio.h>


int main(void)
{
    int **s = malloc(5 * sizeof(int *));
    for (int i = 0; i < 5; i++)
        s[i] = malloc(5 * sizeof(int));


    s[4][3] = 100;
    puts("done");
}