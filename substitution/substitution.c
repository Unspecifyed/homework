#include <cs50.h>
#include <stdio.h>

string scramb(string input, string key);
int checkKey(string key, int aCount);
int main(int argc, string argv[])
{
    int argumentCount = argc;
    string key = argv[1];
    int valid = checkKey(key, argumentCount);

    switch(valid)
    {
    case 1:
    printf("no specal char");
    return 1;
    case 2:
    printf("Key must contain 26 characters.");
    return 1;
    case 3:
    printf("Usage: ./substitution key"); // null set
    return 1;
    case 4:
    printf("Usage: ./substitution key"); // more then one argument
    return 1;
    }

    string plainText = get_string("plaintext: ");
    string cipherText = scramb(plainText, key);
    printf("ciphertext: ");
    return 0;
}
int checkKey(string key, int aC)
{
    int n = 0;
    int valid = 0;
    int value = -1;
    if(aC != 2)
    {
        return 4;
    }

    if(key[0] == '\0')
    {
        return 3; // null key
    }
    while(key[n] != '\0')
    {
        value = (int)key[n];
        if(value < 65)
        {
            valid = 1; // invalid char
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
string scramb(string input, string key)
{
    int n = 0;
    int lowerOffset = 97;
    int upperOffset = 65;
    while(input[n] != '\0')
    {

    }
}