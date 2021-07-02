#ifndef TYPEDEF_H
#define TYPEDEF_H

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

complex64_t addComp(const complex64_t *z1, const complex64_t *z2);
complex64_t subComp(const complex64_t *z1, const complex64_t *z2);
complex64_t mulComp(const complex64_t *z1, const complex64_t *z2);
complex64_t divComp(const complex64_t *z1, const complex64_t *z2);
complex64_t conjComp(const complex64_t *z1);
#endif