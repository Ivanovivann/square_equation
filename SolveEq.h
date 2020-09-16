#include <stdio.h>
#include <math.h>
#include <stdlib.h>


//=============================================================================


const int INFTY = -1; ///< Используется, если количество корней бесконечно

const double ACCURACY = 1E-6;  ///< Постоянная для точности определения нуля

const double ACCURACYNUMBER = 1E-4;  ///< Постоянная для точности определения числа


//=============================================================================


int Solvelin (double a, double b, double* x);

int Solvesquare (double a, double b, double c, double* x1, double* x2);

int isZero (double x);

int isNumber (double x, double number);


//=============================================================================


/*!
    \brief Функция для решения линейного уравнения
    \param[in] a, b коэффициенты уравнения вида ax + b = 0
    \details Работает с адресом корня, а не с копией переменной
    \return количество корней: если
*/

int Solvelin (double a, double b, double* x)

{

printf ("\n"
        " You have entered a linear equation that has \n");

if ((isZero(a) == 0) && (isZero(b) != 0))

    return 0;

if ((isZero(a) == 0) && (isZero(b) == 0))

    return INFTY;

if (isZero(a) != 0) {
    if (isZero(b) == 0)
        *x = 0;

    else
        *x = -b/a;

    return 1;
    }
return 0;
}


//-----------------------------------------------------------------------------


/*!
    \brief Функция служит для решения квадратного уравнения
    \param[in] a, b, с коэффициенты уравнения вида ax^2 + bx + с = 0
    \details Работает с адресами корней, а не с копиями переменных
    \return Количество корней
*/

int Solvesquare (double a, double b, double c, double* x1, double* x2)

{

double discr = b*b - 4*a*c;

if (discr > 0) {

    double sqrtdiscr = sqrt(b*b-4*a*c);

    *x1 = (-b+sqrtdiscr)/2/a;
    *x2 = (-b-sqrtdiscr)/2/a;

    return 2;
    }

if (isZero(discr) == 0) {
    if ((isZero(b) == 0) && (isZero(c) == 0))
        *x1 = 0;
    else
        *x1 = -b/2/a;

    return 1;
    }
if (discr < 0)
    return 0;

return 3;

}


//-----------------------------------------------------------------------------

/*!
    \brief Эта функция служит для определения точности сравнения с нулём
    \param[in] x - сравниваемое число
    \return  1 - x отличен от нуля более, чем значение константы accuracy, 0 - х отличен от нуля менее, чем значение константы ACCURACY

*/

int isZero (double x)
{
if (fabs (x) >= ACCURACY)
    return 1;

return 0;
}

//-----------------------------------------------------------------------------


/*!
    \brief Эта функция служит для определения точности сравнения с нулём
    \param[in] x - сравниваемое число, number - заданное число с которым сравнивают
    \return  1 - x отличен от заданного числа более, чем значение константы ACCURACYNUMBER ,
     0 - х отличен от заданного числа менее, чем значение константы ACCURACYNUMBER

*/

int isNumber (double x, double number)
{
double  delta = x - number;

if (fabs (delta) >= ACCURACYNUMBER)
    return 1;

return 0;
}
