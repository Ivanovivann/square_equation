#include <stdio.h>
#include <math.h>
#include <stdlib.h>


//=============================================================================

const int MAX_NUMBER = 1000;  ///< Максимальное количество знаков в вводимом числе

//=============================================================================

double onlyNumbers();

double power (double a, int b);

//=============================================================================


/*!
    \brief Функция, проверяющая является ли вводимый набор символов числом
    \return число, или если вводимая поседовательность не является числом, то пишет предупреждение пока не получит число

*/

double onlyNumbers()

    {
    int number[MAX_NUMBER],
        numberpoints       = 0,    ///< считает количество точек
        countbeforepoint   = 0,    ///< считает количество цифр до точки
        countafterpoint    = 0,    ///< считает количество цифр после точки
        after_e_count      = 0,    ///< считает количество цифр после "Е"
        i                  = 0,    ///< цикловая переменная
        quantity           = 0,    ///< число равное общему количеству знаков в числе
        m                  = 0,    ///< содержит информацию об отрицательности числа
        m_after_e          = 0,    ///< содержит информацию о наличии минуса после "Е"
        e_location         = 0,    ///< содержит информацию о  положении "Е" в записи числа
        number_e           = 0,    ///< содержит информацию о наличии и количестве "Е" в записи
        y                  = 0;    ///< число равное степени 10 в записи числа через "Е"

    double x = 0, ten_or_not = 0;

    for (i = 0; i < MAX_NUMBER; i++)
        number[i] = 0;

    for (i = 0; (number[i] = getchar ()) != '\n' ; i++)
        {

        quantity++;

        if ((e_location == i - 1) && (number[i] == '-') && (i >= 2))
            m_after_e = 1;

        if ((number_e == 1) && (number[i] == '.')) {

            printf(" This is not number!\n");
            printf(" ");

            return onlyNumbers();
            }


        if ((number[i] == 'E') || (number[i] == 'e')) {

            number_e++;

            if (number_e > 1) {

                printf(" This is not number!\n");
                printf(" ");

                return onlyNumbers();
                }

            e_location = i;
            }
        }

    i = 0;

    if (number_e == 0) {

        if (number[0] == '-')
            m = 1;

        while (i < quantity)
            {

            if (number[i] == '.')
                numberpoints++;

            else if ((number[i] >= '0') && (number[i] <= '9') && (numberpoints <= 1)) {

                if (numberpoints == 0)
                    countbeforepoint++;

                else
                    countafterpoint++;

                }

            i++;

            }
        }

    if (number_e == 1) {
        if (number[0] == '-')
            m = 1;

        while (i < quantity)
            {

            if (i <= e_location) {
                if (number[i] == '.')
                    numberpoints++;

                else if ((number[i] >= '0') && (number[i] <= '9') && (numberpoints <= 1)) {

                    if (numberpoints == 0)
                        countbeforepoint++;

                    else
                        countafterpoint++;

                    }
                }


            if (i > e_location) {
                if (number[i] == '.') {

                    printf(" This is not number!\n");
                    printf(" ");

                    return onlyNumbers();
                    }

                if ((number[i] >= '0') && (number[i] <= '9') && (numberpoints <= 1))
                    after_e_count++;
                }
            i++;
            }
        }

    if (quantity == 0)

        return onlyNumbers();

    switch(number_e) {

        case 0:  {

            if ((quantity != m + countafterpoint + countbeforepoint + numberpoints) || (numberpoints > 1)) {
                printf(" This is not number!\n");
                printf(" ");

                return onlyNumbers();
                }

            for (i = 0;((m == 1) && (i < (quantity))); i++)

                number[i] = number[i + 1];

            for (i = 0; i < countbeforepoint; i++)

                x = x + power(10, countbeforepoint - i - 1) * (number[i] - '0');

            for (i = countbeforepoint + 1 + numberpoints; i <= (countafterpoint + countbeforepoint + numberpoints); i++)

                x = x + power(0.1, i - countbeforepoint - numberpoints) * (number[i-1] - '0');

            if (m == 1)
                x = x * (-1);

            break;
            }

        case 1:  {

            if ((quantity != 1 + m + m_after_e + countafterpoint + countbeforepoint + after_e_count + numberpoints) || (numberpoints > 1)) {
                 // 1 потому что есть символ "е" или "Е"

                printf(" This is not number!\n");
                printf(" ");

                return onlyNumbers();
                }

            for (i = 0;((m == 1) && (i < (quantity))); i++)

                number[i] = number[i + 1];

            for (i = 0; i < countbeforepoint; i++)

                x = x + power(10, countbeforepoint - i - 1) * (number[i] - '0');

            for (i = countbeforepoint + 1 + numberpoints; i <= (countafterpoint + countbeforepoint + numberpoints); i++)

                x = x + power(0.1, i - countbeforepoint - numberpoints) * (number[i-1] - '0');


            for (i = e_location;((m_after_e == 1) && (i < (quantity - 1))); i++)

                number[i] = number[i + 1];


            if (m_after_e == 0)

                ten_or_not = 10;

            else

                ten_or_not = 0.1;


            for (i = e_location - m; i < e_location + after_e_count - m; i++)

                    y = y + power(10, e_location + after_e_count - i - 1 - m) * (number[i + 1] - '0');


            if (m == 1)
                x = x * (-1);

            x = x * power (ten_or_not, y);

            break;
            }

        default:;
        }

    return x;
    }


//-----------------------------------------------------------------------------

/*!
    \brief Функция, возводящая действительное число в степень, являющуюся неотрицательным целым числом
    \param[in] a - основание степени, b - показатель степени
    \return Результат возведения в степень

*/

double power (double a, int b)

{
int    i = 0;
double q = 1;

if (b < 0)
    while (i < abs(b))
        {
        i++;
        q = q / a;
        }

else
    while (i < b)
        {
        i++;
        q = q * a;
        }

return q;
}
