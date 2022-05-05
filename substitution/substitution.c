#include <cs50.h>
#include <stdio.h>

void scramb(string input);
int checkKey(string key);
int main(int argc, string argv[])
{
    string plainText = get_string("plaintext: ");
    int argumentCount = argc;
    string key = argv[1];
    int valid = checkKey(string key);

    while(valid != 0)
    {
        key = get_string("")

    }

    printf("ciphertext: ");
    return 0;
}
int checkKey(string key)
{
    int n = 0;
    int valid = 0;
    int value = -1;

    if(key[0] == '\0')
    {
        return 3; // null key
    }
    while(key[n] != '\0')
    {
        value = (int)key[n];
        if(value < 65)
        {
            valid = 1 // invalid char
            break;
        }
        if(value > 90 && value < 97)
        {
            valid = 1;
            break;
        }
        if(value > 122)
        {
            valid = 1;
            break;
        }
            n++;
    }
    if(n !=25)
    {
        valid =2; // wrong input
    }
    return valid;
}
void scramb(string input)
{
    int n = 0;
    while(input[n] != '\0')
    {

    }
}