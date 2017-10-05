#ifndef DEBUG_H_INCLUDED
#define DEBUG_H_INCLUDED

#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
//#include <math.h>


void print_memory(uint8_t *start, uint32_t length);
/*{
    uint8_t a = 0;
    printf("\n\n");
    while(a < length)
    {
        printf("%x",*(start + a));
        a++;
    }
}*/

#endif // DEBUG_H_INCLUDED
