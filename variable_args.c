#include <stdio.h>
#include <stdarg.h>

/* The three dots are used to say the compiler that we don't know the number of arguments to receive, the
 * 'int num' are the total number of parameters received
 */
int sum_all(int num, ...)
{
        /* Declaring a list with values but UNITIALIZED */
        va_list valist;
        /* Initializing the va_list with 'num' as total of arguments */
        va_start(valist, num);

        /* Result: multiplied values (initial in 1 because it's multiplication), i = times to loop */
        int result = 1, i;

        /* This for loop is used to access every value in valist, va_arg has a flag that changes the value for the next one
         * every time they access the function, the second parameter 'int' is the type of value they'll look for
         */
        for (i = 0; i < num; i++)
        {
                result *= va_arg(valist, int);
        }
      
        /* Terminate the list */
        va_end(valist);
        return result;
}

int main (void)
{
        /* When calling the function the first parameter is the total number of args */
        printf("%d\n", sum_all(4, 4, 6, 8, 6));
        return 0;
}
