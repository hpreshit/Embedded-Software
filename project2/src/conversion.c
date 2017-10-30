
#include <stdlib.h>
#include <stdio.h>
#include <stdint.h>
#include <math.h>


uint32_t *little_to_big32(uint32_t *data, uint32_t length)
{
    if(data==NULL)
   	return NULL;

    else
    {
    uint32_t b = 0; // variable b initialized for loop condition
    while(b < length) //loop condition for data conversion till all 32-bit words are converted.
    {
        uint32_t a = *(data + b); // variable a initialized to store data of *(data + b)

        int8_t a1,a2,a3,a4; //variables declared to break and shift 32-bit data in a
        a1 = (a & 0x000000ff); // a1 stores last byte of a
        a2 = (a & 0x0000ff00) >> 8; // a2 stores 3rd byte of a
        a3 = (a & 0x00ff0000) >> 16; //a3 stores 2nd byte of a
        a4 = (a & 0xff000000) >> 24; // a4 stores 1st byte of a

        a = ((a1<<24)|(a2<<16)|(a3<<8)|(a4)); //data shifted and bitwise OR operation performed.

        *(data + b) = a; //data after conversion stored in *(data+b)
        b++; //Incrementing b
    }
    return data;
    }
}


uint32_t *big_to_little32(uint32_t *data, uint32_t length)
{
    if(data==NULL)
	return NULL;

    else
    {
    uint32_t a = 0;  // variable a initialized for loop condition
    while(a < length)  //loop condition for data conversion till all 32-bit words are converted.
    {
        uint32_t b = *(data + a); // variable b initialized to store data of *(data + a)

        int8_t b1,b2,b3,b4;  //variables declared to break and shift 32-bit data in b
        b1 = (b & 0xff000000) >> 24; // b1 stores 1st byte of b
        b2 = (b & 0x00ff0000) >> 16; // b2 stores 2nd byte of b
        b3 = (b & 0x0000ff00) >> 8; // b3 stores 3rd byte of b
        b4 = (b & 0x000000ff); // b4 stores last byte of b

        b = ((b1)|(b2<<8)|(b3<<16)|(b4<<24)); //data shifted and bitwise OR operation performed.

        *(data + a) = b; //data after conversion stored in *(data+a)
        a++; // Incrementing a
    }
    return data;
    }
}


