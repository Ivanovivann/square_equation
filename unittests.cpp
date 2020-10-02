#include <stdio.h>
#include <math.h>
#include "SolveEq.h"
#include "isNumber_notWord.h"


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
int     i      = 0,
        right  = 0;

for (i = 1; i <= NUMBER_OF_TESTS; i++)
    {
        fscanf (input, "%lg %d", &x, &right);

        fprintf (output, "%d\n", !isZero(x));

        if (!isZero(x) == right)
            fprintf (output, "Test %d is correct\n\n", i);
        else
            fprintf (output, "Test %d is UNcorrect!!!\n\n", i);
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

double  x        = 0,
    right_answer = 0,
    answer       = 0;
int i            = 0,
    y            = 0;

for (i = 1; i <= NUMBER_OF_TESTS; i++)
    {
    fscanf (input, "%lg %d %lg", &x, &y, &right_answer);

    answer = pow(x, y);

    fprintf (output, "%lg\n", answer);

    if (!isZero(answer - right_answer))
        fprintf (output, "Test %d is correct\n\n", i);
    else
        fprintf (output, "Test %d is UNcorrect!!!\n\n", i);
    }


printf("All tests are done\n");

fclose(input);
fclose(output);

return 0;
}
