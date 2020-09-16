#include <stdio.h>
#include <math.h>
#include "SolveEq.h"
#include "onlynumbers.h"

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
    \version 2.0
    \date 17.09.2020г.

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
a = onlyNumbers();

printf (" Enter b: \n ");
b = onlyNumbers();

printf (" Enter c: \n ");
c = onlyNumbers();

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

    default:;
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

double  a  = 0,
        b  = 0,
        c  = 0,
        x1 = 0,
        x2 = 0;
int i      = 0,
    nroots = 0,
    nt     = 0;

for (i = 0; i < NUMBER_OF_TESTS; i++)
    {
        fscanf (inputSolver, "%lg %lg %lg", &a, &b, &c);

        if (isZero(a) == 0)
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

            default:;
            }

    switch (nt = i + 1) {     //nt - numbertest

        case 1:  {
            if (nroots == 0)
                fprintf (outputSolver, " Test %d is ok\n\n", nt);
            else
                fprintf (outputSolver, " Test %d is NOT ok\n", nt);
            break;
            }

        case 2:  {
            if ((nroots == 1) && (isNumber(x1,(-1.4)) == 0))
                fprintf (outputSolver, " Test %d is ok\n\n", nt);
            else
                fprintf (outputSolver, " Test %d is NOT ok\n\n", nt);
            break;
            }

        case 3:  {
            if (nroots == 0)
                fprintf (outputSolver, " Test %d is ok\n\n", nt);
            else
                fprintf (outputSolver, " Test %d is NOT ok\n\n", nt);
            break;
            }

        case 4:  {
            if ((nroots == 1) && (isZero(x1) == 0))
                fprintf (outputSolver, " Test %d is ok\n\n", nt);
            else
                fprintf (outputSolver, " Test %d is NOT ok\n\n", nt);
            break;
            }

        case 5:  {
            if ((nroots == 1) && (isZero(x1) == 0))
                fprintf (outputSolver, " Test %d is ok\n\n", nt);
            else
                fprintf (outputSolver, " Test %d is NOT ok\n\n", nt);
            break;
            }

        case 6:  {
            if ((nroots == 2) && (isZero(x1) == 0) && (isNumber(x2,(-2.5)) == 0))
                fprintf (outputSolver, " Test %d is ok\n\n", nt);
            else
                fprintf (outputSolver, " Test %d is NOT ok\n\n", nt);
            break;
            }

        case 7:  {
            if (nroots == INFTY)
                fprintf (outputSolver, " Test %d is ok\n\n", nt);
            else
                fprintf (outputSolver, " Test %d is NOT ok\n\n", nt);
            break;
            }

        case 8:  {
            if (nroots == 0)
                fprintf (outputSolver, " Test %d is ok\n\n", nt);
            else
                fprintf (outputSolver, " Test %d is NOT ok\n\n", nt);
            break;
            }

        case 9:  {
            if ((nroots == 1) && (isNumber(x1,(-1.333333)) == 0))
                fprintf (outputSolver, " Test %d is ok\n\n", nt);
            else
                fprintf (outputSolver, " Test %d is NOT ok\n\n", nt);
            break;
            }

        case 10:  {
            if ((nroots == 2) && (isNumber(x1,(1)) == 0) && (isNumber(x2,(-3)) == 0))
                fprintf (outputSolver, " Test %d is ok\n\n", nt);
            else
                fprintf (outputSolver, " Test %d is NOT ok\n\n", nt);
            break;
            }


        default:;

        }
    }

printf("All tests are done\n");

fclose(inputSolver);
fclose(outputSolver);

return 0;
}
