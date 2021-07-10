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
float32_t findMax(float32_t *arr, float32_t *size, float32_t *maxVal,float32_t *maxIdx)
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

float32_t findPeakIdx(float32_t *xData, float32_t *yData, float32_t size)
{
    
}