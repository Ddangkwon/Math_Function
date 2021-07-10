#include "Calc_Comp.h"
/***********************************************************************************************
 * Function Declaration
 ***********************************************************************************************/

complex64_t compCalculator(uint32_t calcType, const complex64_t *a, const complex64_t *b)
{
    complex64_t z;
    switch(calcType)
    {
        case ADD:
            z = addComp(a, b);
            break;
        case SUB:
            z = subComp(a, b);
            break;
        case MUL:
            z = mulComp(a, b);
            break;
        case DIV:
            z = divComp(a, b);
            break;
        default:
            /* NOP */
            break;
    }
    printf("real : %f, imag : %f\n", z.real, z.imag);
    return z;
}
complex64_t addComp(const complex64_t *z1, const complex64_t *z2)
{
    complex64_t output;
    output.real = z1->real + z2->real;
    output.imag = z1->imag + z2->imag;
    return output;
}

complex64_t subComp(const complex64_t *z1, const complex64_t *z2)
{
    complex64_t output;
    output.real = z1->real - z2->real;
    output.imag = z1->imag - z2->imag;
    return output;
}


complex64_t mulComp(const complex64_t *z1, const complex64_t *z2)
{
    complex64_t output;
    output.real = (z1->real * z2->real) - (z1->imag * z2->imag);
    output.imag = (z1->real * z2->imag) + (z1->imag * z2->real);
    return output;
}

complex64_t divComp(const complex64_t *z1, const complex64_t *z2)
{
    
    complex64_t output;
    float32_t denom = ((z2->real * z2->real) + (z2->imag * z2->imag));


    if(denom == 0.0)
    {
        denom = 1e-8;
    }
    output = conjComp(z2);
    output = mulComp(z1, &output);
    output.real /= denom;
    output.imag /= denom;
    return output;
}

complex64_t conjComp(const complex64_t *z1)
{
    complex64_t output;
    output.real = z1->real;
    output.imag = -1 * z1->imag;
    return output;
}

float32_t absComp(const complex64_t *z1)
{
    float32_t output = sqrt((z1->real * z1->real) + (z1->imag * z1->imag));
    return output;
}



complex64_t phaseToComp(float32_t phase)
{
    complex64_t output;
    output.real = cos(phase);
    output.imag = sin(phase);
    return output;
}

float32_t compToPhase(complex64_t z)
{
    float32_t output;
    output = atan2(z.imag, z.real);
    return output;
}