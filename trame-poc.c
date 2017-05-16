/*
* =====================================================================================
*
*       Filename:  struct.c
*
*    Description:  
*
*        Version:  1.0
*        Created:  05/02/2017 01:09:39 PM
*       Revision:  none
*       Compiler:  gcc
*
*         Author:  Zakaria ElQotbi (zakariae), zakaria.elqotbi@derbsellicon.com
*        Company:  Derb.io 
*
* =====================================================================================
*/
#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include <string.h>

#define HBITFILED 4
#define SBITFILED 1

typedef struct {
    uint32_t timestamp;
    int32_t  gpslt; 
    int32_t  gpslg;

    uint16_t gyrx;
    uint16_t gyry;
    uint16_t gyrz;

    uint16_t accelx;
    uint16_t accely;
    uint16_t accelz;

    uint16_t magnx;
    uint16_t magny;
    uint16_t magnz;

    uint8_t  highgyrx:HBITFILED;
    uint8_t  highgyry:HBITFILED;
    uint8_t  highgyrz:HBITFILED;

    uint8_t  highaccelx:HBITFILED;
    uint8_t  highaccely:HBITFILED;
    uint8_t  highaccelz:HBITFILED;

    uint8_t  highmagnx:HBITFILED;
    uint8_t  highmagny:HBITFILED;
    uint8_t  highmagnz:HBITFILED;

    uint8_t  signgyrx:SBITFILED;
    uint8_t  signgyry:SBITFILED;
    uint8_t  signgyrz:SBITFILED;

    uint8_t  signaccelx:SBITFILED;
    uint8_t  signaccely:SBITFILED;
    uint8_t  signaccelz:SBITFILED;

    uint8_t  signmagnx:SBITFILED;
    uint8_t  signmagny:SBITFILED;
    uint8_t  signmagnz:SBITFILED;

} __attribute__((packed)) fxtelemetry_t;

#define MASK0 0x0000ffff
#define MASK1 0x000f0000

#define SET(tm, comp, val) { \
	int32_t tval = val; \
        if(val<0){ \
            tm->sign##comp = 1; \
            tval = -val; \
        } \
        tm->comp       = tval&MASK0; \
        tm->high##comp = (tval&MASK1)>>16; \
    }

#define GET(tm, comp, val) { \
	val = tm->comp + (tm->high##comp<<16); \
	if(tm->sign##comp) \
	val = -val; \
    }

#define SETT(p, tm, X, Y, Z) { \
    SET(tm, p##x, X); \
    SET(tm, p##y, Y); \
    SET(tm, p##z, Z); \
}

#define GETT(p, tm, X, Y, Z) { \
    GET(tm, p##x, X); \
    GET(tm, p##y, Y); \
    GET(tm, p##z, Z); \
}

int main()
{
   fxtelemetry_t* tm = (fxtelemetry_t*) malloc(sizeof(fxtelemetry_t));

   tm->timestamp =  33551998;
   tm->gpslt     = -40741895; 
   tm->gpslg     = -73989308; 

   int32_t iaccel[3] = {-74189, -99999, 2345};
   int32_t oaccel[3] = {0,0,0};

   SETT(accel, tm,  iaccel[0],  iaccel[1],  iaccel[2]);
   GETT(accel, tm,  oaccel[0],  oaccel[1],  oaccel[2]);

   printf("iaccel[0]:%d, iaccel[1]:%d, iaccel[2]:%d\n", iaccel[0],  iaccel[1],  iaccel[2]);
   printf("oaccel[0]:%d, oaccel[1]:%d, oaccel[2]:%d\n", oaccel[0], oaccel[1], oaccel[2]);

   getchar();
}

