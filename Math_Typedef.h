#ifndef TYPEDEF_H
#define TYPEDEF_H
#define _USE_MATH_DEFINES
#include <stdint.h>
#include <stdio.h>
#include <math.h>
#include <time.h>

typedef float float32_t;
typedef double float64_t;

typedef struct
{
    float32_t real;
    float32_t imag;
}complex64_t;

typedef enum
{
    ADD = 0,
    SUB,
    MUL,
    DIV
}calc_complex_e;

typedef union
{
    uint8_t     _uc[4];
    uint16_t    _us[2];
    uint32_t    _ui;
    float32_t   _f;
    int8_t      _sc[4];
    int16_t     _ss[2];
    int32_t     _si;
}byteTypeConv;




#endif