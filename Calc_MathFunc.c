#include "Calc_MathFunc.h"

float32_t degToRad(float32_t angle)
{
    angle = angle / 180.0 * M_PI;
    return angle;
}
float32_t radToDeg(float32_t angle)
{
    angle = angle / M_PI * 180.0;
    return angle;
}

void findMax(const float32_t *arr, const float32_t size, float32_t *maxVal,float32_t *maxIdx)
{
    uint32_t dataIdx = 0U, tempIdx = 0U;
    float32_t tempMax = -9999.9999f;
    
    for(dataIdx = 0; dataIdx < size; dataIdx++)
    {
        if(tempMax < arr[dataIdx])
        {
            tempMax = arr[dataIdx];
            tempIdx = dataIdx;
        }       
    }

    *maxVal = tempMax;
    *maxIdx = tempIdx;

}

float32_t findPeakIdx(const float32_t *xData, const float32_t *yData, float32_t size)
{
    float32_t peakVal = 0.0f;


    return peakVal;
}

float32_t euclideanDist(const float32_t x1, const float32_t y1, const float32_t x2, const float32_t y2)
{
    float32_t dx = x1 - x2;
    float32_t dy = y1 - y2;
    float32_t output = sqrt((dx * dx) + (dy * dy));
    return output;
}

void arrLinspace(float32_t *xData, uint32_t xLen, uint32_t stepSize, float32_t *output)
{
    uint32_t dataIdx = 0U;
    float32_t stepVal = 0.0f;
    if(stepSize < 1 || xLen < 2)
    {
        (void *)0;
    }
    stepVal = (xData[xLen - 1] - xData[0]) / (float32_t)(stepSize - 1);

    for(dataIdx = 0U; dataIdx < xLen - 1; dataIdx++)
    {
        output[dataIdx] = xData[0] + dataIdx * stepVal;
    }
    /* endpoint = true */
    output[xLen - 1] = xData[xLen - 1];

}
void linspace(float32_t start, float32_t stop, uint32_t num, float32_t *output)
{
    float32_t stepSize = 0.0f;
    uint32_t  dataIdx  = 0U;
    if(stop - start == 0 || num < 1)
    {
        (void *)0;
    }
    stepSize = (stop - start) / (num - 1);
  
    for(dataIdx = 0; dataIdx < num - 1; dataIdx++)
    {
        output[dataIdx] = start + stepSize * dataIdx;
      
    }
    /* endpoint = true */
    output[dataIdx] = stop;
    
}