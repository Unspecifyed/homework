#include <cs50.h>
#include <stdio.h>
#include <math.h>
int credit_number_digits(long n);
int last_two(int n);
int brand(int digit, int last);
int getNthDigit(int num, int n);
int checksum(int num, int n, int size, int sum, int odd);
int splitAdd(int n);
void output(int n);
bool isValid(int even, int odd);
// main function
int main(void)
{
    const long CREDIT_NUMBER = get_long("Number: ");
    const int CREDIT_DIGIT = credit_number_digits(CREDIT_NUMBER);
    const int CREDIT_LAST_TWO = last_two(CREDIT_NUMBER);
    const int BRAND_NUMBER = brand(CREDIT_DIGIT, CREDIT_LAST_TWO);
    const int ODD_SUM = checksum(CREDIT_NUMBER, 1, CREDIT_DIGIT, 0, 2);
    const int EVEN_SUM = checksum(CREDIT_NUMBER, 0, CREDIT_DIGIT, 0, 1);
    const bool VALID = isValid(ODD_SUM, EVEN_SUM);

    if(VALID)
    {
        output(BRAND_NUMBER);
    }
    else
    {
        output(0);
    }
    return 0;
}
// Finds the number of digits
int credit_number_digits(long n)
{
    int digit = (int) log10(n);
    digit = digit + 1;
    return digit ;
}
// Finds the last two numbers
int last_two(int n)
{
    int one = getNthDigit(n,0);
    int ten = getNthDigit(n,1) * 10;
    int result = ten + one;
    return result;
}
// Finds the brand
int brand(int digit, int last)
{
    // American Express test
    if(digit == 15 && (last == 34 || last == 37))
    {
        return 1;
    }
    // MasterCard test
    if(digit == 16 && (last > 50 && last < 56))
    {
        return 2;
    }
    // Visa test
    if((digit == 13 || digit == 16) && (last > 39 && last < 50))
    {
        return 3;
    }
    return 0;
}
// Gets the nth diget of the number inputed
int getNthDigit(int num, int n)
{
    int tensPlace = pow(10, n);
    int result = num % tensPlace;
    return result;
}
// check sum of the number given the number, nth element, amount of digets
int checksum(int num, int n, int size, int sum, int odd)
{
    if(n < size)
    {

        return sum;
    }
    int nthSum = (odd * getNthDigit(num, n)); // adds twice of the nth element
    if (nthSum > 9)
    {
        sum = sum + splitAdd(nthSum);
    }
    else
    {
        sum = sum + nthSum;
    }
    n = n + 2;
    checksum(num, n, size, sum, odd);
    return 1;
}
// outputs the results
void output(int n)
{
    switch(n)
    {
        case 0:
            printf("INVALID\n");
            break;
        case 1:
            printf("AMEX\n");
            break;
        case 2:
            printf("MASTERCARD\n");
            break;
        case 3:
            printf("VISA\n");
            break;
  }
}
// spitis and adds numbers grader then 10
int splitAdd(int n)
{
    int result = getNthDigit(n,0) + getNthDigit(n, 1);
    return result;
}
// sees if checksum is valid
bool isValid(int even, int odd)
{
    int sum = even + odd;
    bool valid = false;
    if(sum % 10 == 0)
    {
        valid = true;
    }
    return valid;
}