/* stack.c */

#include <stdio.h>

#define MAXVAL 100        /* 栈val的最大深度 */

int sp = 0;               /* 下一个空闲栈位置 */
double val[MAXVAL];       /* 值栈 */

void push(double f)
{
    if (sp < MAXVAL)
        val[sp++] = f;
    else
        printf("error: stack full, can't push %g\n", f);
}


double pop(void)
{
    if (sp > 0)
        return val[--sp];
    else {
        printf("error: stack empty\n");
        return 0.0;
    }
}

