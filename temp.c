
#include "get_next_line.h"

void push(int x, int y, char **map , node *queue)
{
    point p1;
    p1.x = x;
    p1.y = y;
    enqueue(&queue, p1);
}
