#ifndef CALC_MATHFUNC_H
#define CALC_MATHFUNC_H
#include "Typedef.h"


float32_t degToRad(float32_t angle);
float32_t radToDeg(float32_t angle);
void findMax(const float32_t *arr, const float32_t size, float32_t *maxVal,float32_t *maxIdx);
float32_t findPeakIdx(const float32_t *xData, const float32_t *yData, float32_t size);
float32_t euclideanDist(const float32_t x1, const float32_t y1, const float32_t x2, const float32_t y2);
void arrLinspace(float32_t *xData, uint32_t xLen, uint32_t stepSize, float32_t *output);
void linspace(float32_t start, float32_t stop, uint32_t num, float32_t *output);
#endif
