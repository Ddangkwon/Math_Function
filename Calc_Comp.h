#ifndef CALC_COMP_H
#define CALC_COMP_H
#include "Typedef.h"

complex64_t compCalculator(uint32_t calcType,const complex64_t *a, const complex64_t *b);
complex64_t addComp(const complex64_t *z1, const complex64_t *z2);
complex64_t subComp(const complex64_t *z1, const complex64_t *z2);
complex64_t mulComp(const complex64_t *z1, const complex64_t *z2);
complex64_t divComp(const complex64_t *z1, const complex64_t *z2);
complex64_t conjComp(const complex64_t *z1);
float32_t absComp(const complex64_t *z1);
complex64_t phaseToComp(float32_t phase);
float32_t compToPhase(complex64_t z);

#endif