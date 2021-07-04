#include "Typedef.h"


/***********************************************************************************************
 * Global Variables
 ***********************************************************************************************/
complex64_t a = {2.4, 3.6};
complex64_t b = {12.0, 42.0};
complex64_t result = {0.0f, 0.0f};
uint32_t calc_type = 3;
byteTypeConv parseBytes;
/***********************************************************************************************
 * Main
 ***********************************************************************************************/
int main()
{
    FILE *fp;
    fp = fopen("output_log.txt", "w");
    if(fp == NULL)
    {
        printf("input file read fail!!\n");
        return -1;
    }
    else
    {
        printf("input file read success..\n");
    }
    printf("Enter first input complex value : ");
    scanf("%f %f",&a.real, &a.imag);
    printf("Enter second input complex value : ");
    scanf("%f %f",&b.real, &b.imag);
    result = compCalculator(0, a, b);
    fprintf(fp, "SUM\n");
    fprintf(fp, "real : %.8f, imag : %.8f\n", result.real, result.imag);
    result = compCalculator(1, a, b);
    fprintf(fp, "SUB\n");
    fprintf(fp, "real : %.8f, imag : %.8f\n", result.real, result.imag);
    result = compCalculator(2, a, b);
    fprintf(fp, "MUL\n");
    fprintf(fp, "real : %.8f, imag : %.8f\n", result.real, result.imag);
    result = compCalculator(3, a, b);
    fprintf(fp, "DIV\n");
    fprintf(fp, "real : %.8f, imag : %.8f\n", result.real, result.imag);

    fclose(fp);
    return 0;
}

/***********************************************************************************************
 * Function Declaration
 ***********************************************************************************************/

complex64_t compCalculator(uint32_t calcType, complex64_t a, complex64_t b)
{
    complex64_t z;
    switch(calcType)
    {
        case ADD:
            z = addComp(&a, &b);
            break;
        case SUB:
            z = subComp(&a, &b);
            break;
        case MUL:
            z = mulComp(&a, &b);
            break;
        case DIV:
            z = divComp(&a, &b);
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

float32_t absComp(const complex64_t *z1)
{
    float32_t output = sqrt((z1->real * z1->real) + (z1->imag * z1->imag));
    return output;
}

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