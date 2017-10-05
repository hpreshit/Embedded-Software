//#ifndef MEMORY_H_INCLUDED
//#define MEMORY_H_INCLUDED

#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>




//MY_MOVE
uint8_t *my_memmove(uint8_t * src, uint8_t * dst, size_t length)
{
    size_t i;
    uint8_t *temp=malloc(length);
    for(i=0;i<length;i++)
    {
        *(temp+i)=*(src+i);
    }

    for(i=0;i<length;i++)
    {
        *(dst+i)=*(temp+i);
    }

    return dst;
}


//MY_CPY
uint8_t * my_memcpy(uint8_t * src, uint8_t * dst, size_t length)
{
    int i;
    if (src == dst)
    {
        return dst;
    }
    else if(src > dst)
    {
        for( i = 0; i < length-1; i ++)
        {
            *(dst+i) = *(src+i);

        }

    }
    else if(src < dst)
    {
        for ( i = length-1; i >= 0; i--)
        {
            *(dst+i) = *(src+i);
        }
    }
    return dst;
}


//MY_SET
int8_t * my_memset(uint8_t * src, size_t length, uint8_t value)
{
    int i;

    for(i=0;i<length;i++)
    {
        *(src+i)=value;
    }
    //return src;
    return 0;
}


//MY_SETZERO
uint8_t * my_memzero(uint8_t * src, size_t length)
{
    int i;

    for(i=0;i<length;i++)
    {
        *(src+i)=0;
    }
    return src;
}


//MY_REVERSE
uint8_t * my_reverse(uint8_t * src, size_t length)
{
    int i;
    size_t j=length;
    int k=0;
    uint8_t *temp=malloc(j*sizeof(size_t));

    for(i=0;i<length;i++)
    {
        *(temp+i)=*(src+i);
    }

    for(i=0;i<length;i++)
    {
        j--;
        *(src+j)=*(temp+i);
    }

    j=length;

    for(i=0;i<length;i++)
    {
        j--;
        if(*(src+i)==*(temp+j))
        {
            k++;
        }
    }

    if (k==length)
    {
        return src;
    }
    else return 0;
}


//RESERVE_WORDS
uint8_t * reserve_words(size_t length)
{
    //printf("%d\n",length);
    //uint8_t a[length];
    //uint8_t *temp=a;
    uint8_t *temp = malloc(length*sizeof(size_t));

    return (temp);
}


//FREE WORDS
void free_words(uint32_t * src)
{
    free(src);
}


//#endif // MEMORY_H_INCLUDED
