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
    comparator = 0;

for (i = 0; i < NUMBER_OF_TESTS; i++)
    {
        fscanf (input, "%lg", &x);

        comparator = isZero(x);

        switch (comparator) {

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
            if (comparator == 1)
                fprintf (output, "Test %d is ok \n\n", nt);
            else
                fprintf (output, "Test %d is NOT ok \n\n", nt);
            break;
            }

        case 2:  {
            if (comparator == 1)
                fprintf (output, "Test %d is ok \n\n", nt);
            else
                fprintf (output, "Test %d is NOT ok \n\n", nt);
            break;
            }

        case 3:  {
            if (comparator == 1)
                fprintf (output, "Test %d is ok \n\n", nt);
            else
                fprintf (output, "Test %d is NOT ok \n\n", nt);
            break;
            }

        case 4:  {
            if (comparator == 1)
                fprintf (output, "Test %d is ok \n\n", nt);
            else
                fprintf (output, "Test %d is NOT ok \n\n", nt);
            break;
            }

        case 5:  {
            if (comparator == 0)
                fprintf (output, "Test %d is ok \n\n", nt);
            else
                fprintf (output, "Test %d is NOT ok \n\n", nt);
            break;
            }

        case 6:  {
            if (comparator == 0)
                fprintf (output, "Test %d is ok \n\n", nt);
            else
                fprintf (output, "Test %d is NOT ok \n\n", nt);
            break;
            }

        case 7:  {
            if (comparator == 1)
                fprintf (output, "Test %d is ok \n\n", nt);
            else
                fprintf (output, "Test %d is NOT ok \n\n", nt);
            break;
            }

        case 8:  {
            if (comparator == 0)
                fprintf (output, "Test %d is ok \n\n", nt);
            else
                fprintf (output, "Test %d is NOT ok \n\n", nt);
            break;
            }

        case 9:  {
            if (comparator == 0)
                fprintf (output, "Test %d is ok \n\n", nt);
            else
                fprintf (output, "Test %d is NOT ok \n\n", nt);
            break;
            }

        case 10:  {
            if (comparator == 1)
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

double  x      = 0,
    comparator = 0;
int i          = 0,
    nt         = 0,
    y          = 0;

for (i = 0; i < NUMBER_OF_TESTS; i++)
    {
    fscanf (input, "%lg %d", &x, &y);

    comparator = power(x, y);

    fprintf (output, "%lg\n", comparator);

    switch (nt = i + 1) {     //nt - numbertest

        case 1:  {
            if (isNumber(comparator, 18104624.18) == 0)
                fprintf (output, "Test %d is ok \n\n", nt);
            else
                fprintf (output, "Test %d is NOT ok \n\n", nt);
            break;
            }

        case 2:  {
            if (isNumber(comparator, 0) == 0)
                fprintf (output, "Test %d is ok \n\n", nt);
            else
                fprintf (output, "Test %d is NOT ok \n\n", nt);
            break;
            }

        case 3:  {
            if (isNumber(comparator, -1) == 0)
                fprintf (output, "Test %d is ok \n\n", nt);
            else
                fprintf (output, "Test %d is NOT ok \n\n", nt);
            break;
            }

        case 4:  {
            if (isNumber(comparator, 4096) == 0)
                fprintf (output, "Test %d is ok \n\n", nt);
            else
                fprintf (output, "Test %d is NOT ok \n\n", nt);
            break;
            }

        case 5:  {
            if (isNumber(comparator, 0.008) == 0)
                fprintf (output, "Test %d is ok \n\n", nt);
            else
                fprintf (output, "Test %d is NOT ok \n\n", nt);
            break;
            }

        case 6:  {
            if (isNumber(comparator, 1.5625E10) == 0)
                fprintf (output, "Test %d is ok \n\n", nt);
            else
                fprintf (output, "Test %d is NOT ok \n\n", nt);
            break;
            }

        case 7:  {
            if (isNumber(comparator, 10000) == 0)
                fprintf (output, "Test %d is ok \n\n", nt);
            else
                fprintf (output, "Test %d is NOT ok \n\n", nt);
            break;
            }

        case 8:  {
            if (isNumber(comparator, 0.02941) == 0)
                fprintf (output, "Test %d is ok \n\n", nt);
            else
                fprintf (output, "Test %d is NOT ok \n\n", nt);
            break;
            }

        case 9:  {
            if (isNumber(comparator, 144) == 0)
                fprintf (output, "Test %d is ok \n\n", nt);
            else
                fprintf (output, "Test %d is NOT ok \n\n", nt);
            break;
            }

        case 10:  {
            if (isNumber(comparator, 523) == 0)
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
