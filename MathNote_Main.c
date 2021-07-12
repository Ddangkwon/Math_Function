#include "Calc_Comp.h"
#include "Calc_MathFunc.h"
#include "Sort_Algo.h"


#define SW_VERSION  "1.0.0"
/***********************************************************************************************
 * Global Variables
 ***********************************************************************************************/
complex64_t a = {2.4, 3.6};
complex64_t b = {12.0, 42.0};
complex64_t result = {0.0f, 0.0f};
uint32_t calc_type = 3;
byteTypeConv parseBytes;
float32_t arr[5] = { 0.0f };

/***********************************************************************************************
 * Local Functions
 ***********************************************************************************************/

static void  writeCompCalFile(FILE *fp, const complex64_t *a, const complex64_t *b, complex64_t *z);


/***********************************************************************************************
 * Main
 ***********************************************************************************************/
int main()
{
    FILE *inputfp;
    struct tm *datetime;
    time_t t;
    char currTime[16];
    t = time(NULL);
    datetime = localtime(&t);
    strftime(currTime, 16, "%Y%m%d_%H%M%S", datetime);

    inputfp = fopen("output_log.txt", "w");
    if(inputfp == NULL)
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

   
    writeCompCalFile(inputfp, &a, &b, &result);
    return 0;
}


static void writeCompCalFile(FILE *fp, const complex64_t *a, const complex64_t *b, complex64_t *z)
{
    fprintf(fp, "SW VERSION [v.%s] \n\n", SW_VERSION);
    fprintf(fp, "SUM\n");
     result = compCalculator(ADD, a, b);
    fprintf(fp, "real : %.8f, imag : %.8f\n", z->real, z->imag);
    
    fprintf(fp, "SUB\n");
    result = compCalculator(SUB, a, b);
    fprintf(fp, "real : %.8f, imag : %.8f\n", z->real, z->imag);
   
    fprintf(fp, "MUL\n");
     result = compCalculator(MUL, a, b);
    fprintf(fp, "real : %.8f, imag : %.8f\n", z->real, z->imag);
    
    fprintf(fp, "DIV\n");
    result = compCalculator(DIV, a, b);
    fprintf(fp, "real : %.8f, imag : %.8f\n", z->real, z->imag);
    fclose(fp);
}