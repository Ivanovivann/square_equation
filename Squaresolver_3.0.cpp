#include <stdio.h>
#include <math.h>
#include "SolveEq.h"
#include "isNumber_notWord.h"

//#define DEBUG_MODE


//=============================================================================

const int NUMBER_OF_TESTS = 10; ///< Количество тестов

//=============================================================================


int debug_test();

int manual_test();


//=============================================================================


/*!

    \brief Переключение режимов
    \author Ivanov Ivan
    \version 3.0
    \date 3.10.2020г.

*/

int main()

{
	#ifdef DEBUG_MODE
		debug_test();
	#else
		manual_test();
	#endif
}


//-----------------------------------------------------------------------------


/*!

    \brief Обычный режим
    \warnings Можно упускать целую часть равную нулю при вводе
    \details Ввод данных в консоли

*/

int manual_test()

{

double a   = 0,
       b   = 0,
       c   = 0;
int nroots = 0;

printf (" Solving square equation: ax^2 + bx + c = 0.\n Enter a: \n ");
a = isNumber_notWord();

printf (" Enter b: \n ");
b = isNumber_notWord();

printf (" Enter c: \n ");
c = isNumber_notWord();

double x1 = 0, x2 = 0;

if (isZero(a) == 0)
    nroots = Solvelin (b, c, &x1);

else
    nroots = Solvesquare (a, b, c, &x1, &x2);

switch (nroots) {

    case INFTY:  {
        printf (" Infinity roots\n");
        break;
        }

    case 0:  {
        printf (" No roots!\n");
        break;
        }

    case 1:  {
        printf (" %lg\n", x1);
        break;
        }

    case 2:  {
        printf (" %lg %lg\n", x1, x2);
        break;
        }

    default: {
        printf (" Program works UNcorrectly!\n");
        break;
        }
    }

return 0;
}


//-----------------------------------------------------------------------------


/*!

    \brief Режим тестов
    \details Ввод данных из input.txt вывод в output.txt

*/

int debug_test()

{
FILE* inputSolver = fopen("inputSolver.txt", "r");
FILE* outputSolver = fopen("outputSolver.txt", "w");

if (inputSolver == NULL)

    {
        fprintf(stderr, "This file is empty!\n");
        return 1;
    }

double  a         = 0,
        b         = 0,
        c         = 0,
        x1        = 0,
        x2        = 0,
        x1_right  = 0,
        x2_right  = 0;
int i             = 0,
    nroots        = 0,
    nroots_right  = 0;

for (i = 1; i <= NUMBER_OF_TESTS; i++)
    {
        fscanf (inputSolver, "%lg %lg %lg %d %lg %lg", &a, &b, &c, &nroots_right, &x1_right, &x2_right);

        if (!isZero(a))
            nroots = Solvelin (b, c, &x1);

        else
            nroots = Solvesquare (a, b, c, &x1, &x2);

        switch (nroots) {
            case INFTY:  {
                fprintf (outputSolver, " Infinity roots\n");
                break;
                }

            case 0:  {
                fprintf (outputSolver, " No roots!\n");
                break;
                }

            case 1:  {
                fprintf (outputSolver, " %lg\n", x1);
                break;
                }

            case 2:  {
                fprintf (outputSolver, " %lg %lg\n", x1, x2);
                break;
                }

            default: printf("The program uncorrectly works!!!\n");
            }


        if ((nroots_right == nroots) && (!isZero(x1 - x1_right)) && (!isZero(x2 - x2_right)))
            fprintf (outputSolver, "Test %d is correct\n\n", i);
        else
            fprintf (outputSolver, "Test %d is UNcorrect!!!\n\n", i);

        x1 = x2 = 0;
    }

printf("All tests are done\n");

fclose(inputSolver);
fclose(outputSolver);

return 0;
}
