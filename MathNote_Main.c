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
    fp = fopen("output_log1.txt", "w");
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
