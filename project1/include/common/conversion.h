#ifndef CONVERSION_H_INCLUDED
#define CONVERSION_H_INCLUDED

#include <stdio.h>
#include <stdint.h>
#include <math.h>



uint8_t my_itoa(int32_t data,uint8_t* ptr, uint32_t base);
/*{
    if((base<17)&&(base>1))
    {
       uint8_t s = 0;
        uint32_t l=0;

       if(data==0)
       {
           *ptr =48;
           l=l+1;
           return l;
       }

       if(data>0)
       {
           *ptr = 43;
           data = data;
           l=l+1;

       }

       else if(data<0)
       {
           *ptr = 45;
           data = -data;
           l=l+1;
       }


       while(data != 0)
       {
            ptr++;
            s = data%base;
            if(s>9)
            {
               s = s - 9;
               s = s + 64;
            }
            else
            {
               s = s + 48;
            }

            *ptr = s;
            data = data/base;
            l++;
       }

        ptr = ptr - l;

        uint8_t t;

        uint8_t i=2,j=l;

        while(i<j)
        {
            t= *(ptr+i);
            *(ptr+i)=*(ptr+j);
            *(ptr+j)=t;
            i++;
            j--;
        }

        return l;
    }

    else
    {
        printf("\nError: Invalid parameters\n");
        return 0;
    }
}*/




int32_t my_atoi(uint8_t *ptr, uint8_t digits, uint32_t base);
/*{
	if((base>1) && (base<17))
	{
		int32_t counter = 1;
		int32_t multiplier = 1;
		uint8_t sign = 0;

		int32_t value = 0;

		uint8_t t;

        uint8_t i=1,j=digits-1;

        if(*ptr == 43)
		{
			sign = 0;
		}

		else if(*ptr==45)
		{
			sign = 1;
		}

        while(i<j)
        {
            t= *(ptr+i);
            *(ptr+i)=*(ptr+j);
            *(ptr+j)=t;
            i++;
            j--;
        }

		while(counter < digits)
		{
			ptr++;
			uint8_t k = 0;
			k = *ptr;

			if((k > 47) && (k < 58))
			{
				k = k - 48;
			}

			else
			{
				k = k - 55;
			}

			uint8_t p;
			for(p = 1; p < counter; p++)
			{
				multiplier = multiplier*base;
			}

			value = value +k*multiplier;
			multiplier = 1;
			counter++;
		}

		if(sign == 0)
		{
			value = value;
		}

		else if(sign==1)
		{
			value = -value;
		}

		return value;
	}

	else
	{
		printf("\nError - Invalid Parameters\n");
		return 0;
	}
}*/



int8_t little_to_big32(uint32_t *data, uint32_t length);
/*{
    uint32_t b = 0;
    while(b < length)
    {
        uint32_t a = *(data + b);

        int8_t a1,a2,a3,a4;
        a1 = (a & 0x000000ff);
        a2 = (a & 0x0000ff00) >> 8;
        a3 = (a & 0x00ff0000) >> 16;
        a4 = (a & 0xff000000) >> 24;

        a = ((a1<<24)|(a2<<16)|(a3<<8)|(a4));

        *(data + b) = a;
        b++;

    }
    return 0;

}*/


int8_t big_to_little32(uint32_t *data, uint32_t length);
/*{
    uint32_t a = 0;
    while(a < length)
    {
        uint32_t b = *(data + a);//04_03_02_01

        int8_t b1,b2,b3,b4;
        b1 = (b & 0xff000000) >> 24;//00_00_00_04
        b2 = (b & 0x00ff0000) >> 16;//00_00_00_03
        b3 = (b & 0x0000ff00) >> 8; //00_00_00_02
        b4 = (b & 0x000000ff);      //00_00_00_01

        b = ((b1)|(b2<<8)|(b3<<16)|(b4<<24));//01_02_03_04

        *(data + a) = b;
        a++;

    }
    return 0;
}*/


#endif // CONVERSION_H_INCLUDED
