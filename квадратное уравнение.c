#include "stdio.h"
#include "math.h"

//-----------------------------------------------

const double accuracy = 1E-6;

//-----------------------------------------------

int Solvelin (double b, double c);
int Solvesquare (double a, double b, double c);
int isZero (double x);

//-----------------------------------------------
int main()

    {

    double a = 0, b = 0, c= 0;

    printf ("\n"
            " Solving square equation: ax^2 + bx + c = 0.\n"
            " Enter a: ");
    scanf ("%lg", &a);

    printf (" Enter b: ");
    scanf ("%lg", &b);

    printf (" Enter c: ");
    scanf ("%lg", &c);

    if (isZero(a) == 0)
        Solvelin (b, c);

    else
        Solvesquare (a, b, c);

    return 0;
    }


//--------------------------------------------------------------

int Solvelin (double b, double c)

{

        printf ("\n"
                " You have entered a linear equation that has ");

        if ((isZero(b) == 0) && (isZero(c) != 0))

            printf ("no roots!\n");

        if ((isZero(b) == 0) && (isZero(c) == 0))

            printf ("infinity roots!\n");

        if (isZero(b) != 0)
            {
            double x;
            x = -c/b;
            printf ("1 root: \n x = %lg\n", x);
            }
return 0;

}

//-------------------------------------------------------


int Solvesquare (double a, double b, double c)

        {

        double discr = b*b - 4*a*c;

        if (discr > 0)
            {

            double sqrtdiscr = sqrt(b*b-4*a*c), x1, x2;

            x1 = (-b+sqrtdiscr)/2/a;
            x2 = (-b-sqrtdiscr)/2/a;

            printf (" 2 roots: x1 = %lg\n", x1);
            printf ("          x2 = %lg", x2);

            }

        if (isZero(discr) == 0)
            {
            double x;
            x = -b/2/a;
            printf (" 1 root: x1 = x2 = %lg", x);

            }
        if (discr < 0)

           printf (" No roots!");

        return 0;

        }

//-------------------------------------------------------

int isZero (double x)
{
if (fabs (x) >= accuracy)
return 1;
return 0;
}
