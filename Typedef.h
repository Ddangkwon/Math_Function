#ifndef TYPEDEF_H
#define TYPEDEF_H
#define _USE_MATH_DEFINES
#include <stdint.h>
#include <stdio.h>
#include <math.h>

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
complex64_t compCalculator(uint32_t calcType, complex64_t a, complex64_t b);
complex64_t addComp(const complex64_t *z1, const complex64_t *z2);
complex64_t subComp(const complex64_t *z1, const complex64_t *z2);
complex64_t mulComp(const complex64_t *z1, const complex64_t *z2);
complex64_t divComp(const complex64_t *z1, const complex64_t *z2);
complex64_t conjComp(const complex64_t *z1);
float32_t absComp(const complex64_t *z1);

float32_t degToRad(float32_t angle);
float32_t radToDeg(float32_t angle);
complex64_t phaseToComp(float32_t phase);
float32_t compToPhase(complex64_t z);
#endif