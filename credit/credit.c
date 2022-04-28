#include <cs50.h>
#include <stdio.h>
#include <math.h>
int credit_number_digits(long n);
int main(void)
{
    const long CREDIT_NUMBER= get_long("Number: ");
    return 0;
}
// Finds the number of digits
int credit_number_digits(long n)
{
    int digit = (int) log10(n);
    
}