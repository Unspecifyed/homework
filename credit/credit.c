#include <cs50.h>
#include <stdio.h>
#include <math.h>
int credit_number_digits(long n);
int first_two(long cn, int dig);
int brand(int digit, int last);
int getNthDigit(long num, int n);
int checksum(long creditNumber, int creditDigit, int n, bool odd, int sum);
int splitAdd(int n);
void output(int n);
bool isValid(int even, int odd);
// main function
int main(void)
{
    const long CREDIT_NUMBER = get_long("Number: ");
    const int CREDIT_DIGIT = credit_number_digits(CREDIT_NUMBER);
    const int CREDIT_FIRST_TWO = first_two(CREDIT_NUMBER, CREDIT_DIGIT);
    const int BRAND_NUMBER = brand(CREDIT_DIGIT, CREDIT_FIRST_TWO);
    const int ODD_SUM = checksum(CREDIT_NUMBER, CREDIT_DIGIT, 2, true, 0);
    const int EVEN_SUM = checksum(CREDIT_NUMBER, CREDIT_DIGIT, 1, false, 0;
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
    long digit = (int) log10(n);
    digit = digit + 1;
    return digit ;
}
// Finds the last two numbers
int first_two(long n, int dig)
{
    int first = getNthDigit(n, dig -1) * 10;
    int second = getNthDigit(n, dig -2);
    int result = (first + second);
    return result;
}
// Finds the brand
int brand(int digit, int last)
{
    bool di13 = (digit == 13);
    bool di15 = (digit == 15);
    bool di16 = (digit == 16);
    bool visaDig = (di13 || di16);
    bool fistAE = (last == 34 || last == 37);
    bool fistMC = (last > 50 && last < 56);
    bool fistV = (last > 39 && last < 50);
    // American Express test
    if(di15 && fistAE)
    {
        return 1;
    }
    // MasterCard test
    if(di16 && fistMC)
    {
        return 2;
    }
    // Visa test
    if(visaDig && fistV)
    {
        return 3;
    }
    return 0;
}
// Gets the nth diget of the number inputed
int getNthDigit(long num, int n)
{
    long tensPlace = pow(10, n);
    long result = (num / tensPlace) % 10;
    return result;
}
// check sum of the number given the number, nth element, amount of digets
int checksum(long creditNumber, int creditDigit, int n, bool odd, int sum);
{
    int addition = 0;
    bool done = (n > creditDigit);
    if(done)
    {
        return sum;
    }
    if(odd)
    {
        addition = getNthDigit(creditNumber, n) * 2;
    }
    else
    {
        addition = getNthDigit(creditNumber, n);
    }
    if (addition > 9)
    {
        additon = splitAdd(additon);
    }
    sum = sum + addition;
    n = n +2;
    checksum(long creditNumber, int creditDigit, int n, bool odd, int sum);
    return 0; // should never happen
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
    int result = getNthDigit(n,1) + getNthDigit(n, 2);
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