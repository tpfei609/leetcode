/* 
 *  convert a string to an integer
 *  
 */

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <math.h>

#define INT_MIN     -pow(2,31)
#define INT_MAX     pow(2,31)-1
int atoi(const char *str)
{
    if (str == NULL || *str == '\0') {
        return 0;
    }

    int ret = 0;

    for (; isspace(*str); str++);

    bool neg = false;
    if (*str == '-' || *str == '+') {
        neg = (*str=='-');
        str++;
    }

    for (; isdigit(*str); str++) {
        int digit = (*str - '0');
        if(neg) {
            if (-ret < (INT_MIN + digit) / 10 ) {
                return INT_MIN;
            }
        }else{
            if (ret > (INT_MAX - digit) / 10 ) {
                return INT_MAX;
            }
        }

        ret = 10 * ret + digit;
    }

    return neg?-ret:ret;
}

int main()
{
    printf("\"%s\" = %d \n", "-2147483648", atoi("-2147483648"));
}
