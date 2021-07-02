#include "Typedef.h"

int main()
{
    complex64_t a = {8.0, 5.0};
    complex64_t b = {4.0, 2.0};
    complex64_t result = {0.0f, 0.0f};
    uint32_t calc_type = 3;
    switch(calc_type)
    {
        case ADD:
            result = addComp(&a, &b);
            break;
        case SUB:
            result = subComp(&a, &b);
            break;
        case MUL:
            result = mulComp(&a, &b);
            break;
        case DIV:
            result = divComp(&a, &b);
            break;
        default:
            /* NOP */
            break;
    }
    printf("real : %f, imag : %f\n", result.real, result.imag);
    return 0;
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
    float32_t nume;
    complex64_t a;
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