#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <math.h>


uint8_t *my_memmove(uint8_t * src, uint8_t * dst, size_t length)
{
    if (src==NULL)
        return NULL;
    else
    {
    size_t i; // variable i declared for loop condition
    uint8_t *temp=malloc(length); // length of bytes allocated starting from temp
    for(i=0;i<length;i++) // loop condition to copy bytes of data from src to temp
    {
        *(temp+i)=*(src+i);//Copying each byte consecutively.
    }

    for(i=0;i<length;i++) // loop condition to copy bytes of data from temp to dst.
    {
        *(dst+i)=*(temp+i); // Copying each byte consecutively.
    }
    return dst; // Returning destination location.
    }
}


uint8_t * my_memset(uint8_t * src, size_t length, uint8_t value)
{
    int i; // variable i declared for loop condition
    if(src==NULL)
       return NULL;
    else
    {
  	for(i=0;i<length;i++) // loop condition to set a length of bytes to specified value.
    	{
            *(src+i)=value; //  setting each byte consecutively to the specified value.
    	}
    	return src;
    }
}



uint8_t * my_memzero(uint8_t * src, size_t length)
{
    int i; // variable i declared for loop condition
    if (src==NULL)
	return NULL;

    else
    {
    for(i=0;i<length;i++) // loop condition to set a length of bytes to zero.
    {
        *(src+i)=0; //  setting each byte consecutively to zero.
    }
    return src;
    }
}


uint8_t * my_reverse(uint8_t * src, size_t length)
{
    
    if(src == NULL)
     	return NULL;

    else
    {
    int i; // variable i declared for loop condition.
    size_t j=length; // variable j declared and initialized to length
    int k=0; // variable k declared and initialized to zero for checking length
    uint8_t *temp=malloc(j*sizeof(size_t)); // memory of size of integer value of j allocated.

    for(i=0;i<length;i++)
    {
        *(temp+i)=*(src+i); //consecutively copying each data byte from src to temp
    }

    for(i=0;i<length;i++)
    {
        j--;
        *(src+j)=*(temp+i); //consecutively copying each data byte from temp to src.
    }

    j=length; // assigning j the value of length

    for(i=0;i<length;i++)
    {
        j--;
        if(*(src+i)==*(temp+j)) //comparing data in reversed bytes
        {
            k++; // incrementing k for each successful comparison.
        }
    }

    if (k==length)
    {
        return src; // returning source location if data successfully reversed.
    }
    else return 0; // returning zero if not reversed successfully.
    }
}



