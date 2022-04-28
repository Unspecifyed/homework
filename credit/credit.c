#include <cs50.h>
#include <stdio.h>
#include <math.h>
int credit_number_digits(long n);
int last_two(int n);
int main(void)
{
    const long CREDIT_NUMBER = get_long("Number: ");
    const int CREDIT_DIGIT = credit_number_digits(CREDIT_NUMBER);
    const int CREDIT_LAST_TWO = last_two(CREDIT_NUMBER);
    return 0;
}
// Finds the number of digits
int credit_number_digits(long n)
{
    int digit = (int) log10(n);
    digit = digit + 1;
    printf("digits %d \n", digit);
    return digit ;
}
// Finds the last two numbers
int last_two(int n)
{
    if(n < 100)
    {
        printf("last two %d \n", n);
        return n;
    }
    n = n / 10;
    last_two(n);
    return 0;
}