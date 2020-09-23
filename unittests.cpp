#include <stdio.h>
#include <math.h>
#include "SolveEq.h"
#include "onlynumbers.h"


//=============================================================================

const int NUMBER_OF_TESTS = 10;

//=============================================================================

int test_isZero();

int test_power();

//=============================================================================


int main ()
{
test_isZero();

test_power();

return 0;
}


//-----------------------------------------------------------------------------


int test_isZero()
{
FILE* input = fopen("input_isZero.txt", "r");
FILE* output = fopen("output_isZero.txt", "w");

if (input == NULL)

    {
        fprintf(stderr, "This file is empty!\n");
        return 1;
    }

double  x      = 0;
int i          = 0,
    nt         = 0,
    is_zero    = 0;

for (i = 0; i < NUMBER_OF_TESTS; i++)
    {
        fscanf (input, "%lg", &x);

        is_zero = isZero(x);

        switch (is_zero) {

            case 0:  {
                fprintf (output, "It is approximately '0' \n");
                break;
                }

            case 1:  {
                fprintf (output, "It is not '0'\n");
                break;
                }

            default:;
            }

    switch (nt = i + 1) {     //nt - numbertest

        case 1:  {
            if (is_zero == 1)
                fprintf (output, "Test %d is ok \n\n", nt);
            else
                fprintf (output, "Test %d is NOT ok \n\n", nt);
            break;
            }

        case 2:  {
            if (is_zero == 1)
                fprintf (output, "Test %d is ok \n\n", nt);
            else
                fprintf (output, "Test %d is NOT ok \n\n", nt);
            break;
            }

        case 3:  {
            if (is_zero == 1)
                fprintf (output, "Test %d is ok \n\n", nt);
            else
                fprintf (output, "Test %d is NOT ok \n\n", nt);
            break;
            }

        case 4:  {
            if (is_zero == 1)
                fprintf (output, "Test %d is ok \n\n", nt);
            else
                fprintf (output, "Test %d is NOT ok \n\n", nt);
            break;
            }

        case 5:  {
            if (is_zero == 0)
                fprintf (output, "Test %d is ok \n\n", nt);
            else
                fprintf (output, "Test %d is NOT ok \n\n", nt);
            break;
            }

        case 6:  {
            if (is_zero == 0)
                fprintf (output, "Test %d is ok \n\n", nt);
            else
                fprintf (output, "Test %d is NOT ok \n\n", nt);
            break;
            }

        case 7:  {
            if (is_zero == 1)
                fprintf (output, "Test %d is ok \n\n", nt);
            else
                fprintf (output, "Test %d is NOT ok \n\n", nt);
            break;
            }

        case 8:  {
            if (is_zero == 0)
                fprintf (output, "Test %d is ok \n\n", nt);
            else
                fprintf (output, "Test %d is NOT ok \n\n", nt);
            break;
            }

        case 9:  {
            if (is_zero == 0)
                fprintf (output, "Test %d is ok \n\n", nt);
            else
                fprintf (output, "Test %d is NOT ok \n\n", nt);
            break;
            }

        case 10:  {
            if (is_zero == 1)
                fprintf (output, "Test %d is ok \n\n", nt);
            else
                fprintf (output, "Test %d is NOT ok \n\n", nt);
            break;
            }


        default:;

        }
    }

printf("All tests are done\n");

fclose(input);
fclose(output);

return 0;
}


//-----------------------------------------------------------------------------


int test_power()
{
FILE* input = fopen("input_power.txt", "r");
FILE* output = fopen("output_power.txt", "w");

if (input == NULL)

    {
        fprintf(stderr, "This file is empty!\n");
        return 1;
    }

double  x       = 0,
    power_value = 0;
int i           = 0,
    nt          = 0,
    y           = 0;

for (i = 0; i < NUMBER_OF_TESTS; i++)
    {
    fscanf (input, "%lg %d", &x, &y);

    power_value = power(x, y);

    fprintf (output, "%lg\n", power_value);

    switch (nt = i + 1) {     //nt - numbertest

        case 1:  {
            if (isNumber(power_value, 18104624.18) == 0)
                fprintf (output, "Test %d is ok \n\n", nt);
            else
                fprintf (output, "Test %d is NOT ok \n\n", nt);
            break;
            }

        case 2:  {
            if (isNumber(power_value, 0) == 0)
                fprintf (output, "Test %d is ok \n\n", nt);
            else
                fprintf (output, "Test %d is NOT ok \n\n", nt);
            break;
            }

        case 3:  {
            if (isNumber(power_value, -1) == 0)
                fprintf (output, "Test %d is ok \n\n", nt);
            else
                fprintf (output, "Test %d is NOT ok \n\n", nt);
            break;
            }

        case 4:  {
            if (isNumber(power_value, 4096) == 0)
                fprintf (output, "Test %d is ok \n\n", nt);
            else
                fprintf (output, "Test %d is NOT ok \n\n", nt);
            break;
            }

        case 5:  {
            if (isNumber(power_value, 0.008) == 0)
                fprintf (output, "Test %d is ok \n\n", nt);
            else
                fprintf (output, "Test %d is NOT ok \n\n", nt);
            break;
            }

        case 6:  {
            if (isNumber(power_value, 1.5625E10) == 0)
                fprintf (output, "Test %d is ok \n\n", nt);
            else
                fprintf (output, "Test %d is NOT ok \n\n", nt);
            break;
            }

        case 7:  {
            if (isNumber(power_value, 10000) == 0)
                fprintf (output, "Test %d is ok \n\n", nt);
            else
                fprintf (output, "Test %d is NOT ok \n\n", nt);
            break;
            }

        case 8:  {
            if (isNumber(power_value, 0.02941) == 0)
                fprintf (output, "Test %d is ok \n\n", nt);
            else
                fprintf (output, "Test %d is NOT ok \n\n", nt);
            break;
            }

        case 9:  {
            if (isNumber(power_value, 144) == 0)
                fprintf (output, "Test %d is ok \n\n", nt);
            else
                fprintf (output, "Test %d is NOT ok \n\n", nt);
            break;
            }

        case 10:  {
            if (isNumber(power_value, 523) == 0)
                fprintf (output, "Test %d is ok \n\n", nt);
            else
                fprintf (output, "Test %d is NOT ok \n\n", nt);
            break;
            }


        default:;

        }
    }


printf("All tests are done\n");

fclose(input);
fclose(output);

return 0;
}
