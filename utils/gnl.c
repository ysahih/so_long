#include <unistd.h>
#include <stdlib.h>
#include <fcntl.h>
#include <stdio.h>
#include "../so_long.h"

size_t ft_strlen(char *s)
{
    int i;

    i = 0;
    while(s[i])
        i++;
    return (i);
}

char    *join(char *s, char c)
{
    char *ret;
    if (!s){
        s = malloc(2);
        if (!s)
            return 0;
        if (c == '\n'){
            puts("invalid map");
            // return 0;
            free(s);
            exit (0);
        }
        *s = c;
        s[1] = 0;
        return s;
    }
    int i = 0;
    for (; s[i]; i++){
        ;
    }
    ret  = malloc(i + 2);
    i = 0;
    for (; s[i]; i++)
        ret[i] = s[i];
    if (c == '\n'){
        ret[i] = 0;
        free(s);
        return ret;
    }
    else { 
        ret[i++] = c;
        ret[i] = 0;
    }
    free(s);
    return ret;
}
char *gnl(int fd)
{
    char r;
    int ret;
    char *buff = 0;
    static char last_char = 0;

    ret = 1;

    while (1)
    {
        ret  = read(fd, &r, 1);
        if (ret == -1)
            return 0;
        else if (ret == 0){
            if (last_char == '\n')
            {
            printf("error: empty line\n");
                exit(0);
            }
            break;
        }
        buff = join(buff, r);
        last_char  = r;
        if (r == '\n'){
            break;
        }
    }
    if (!buff || *buff == '\0'){
        free(buff);
        return 0;
    }
    return buff;
}
