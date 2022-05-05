#include <cs50.h>
#include <stdio.h>

void scramb(string input);
bool checkKey(string key);
int main(int argc, string argv[])
{
    string plainText = get_string("plaintext: ");
    int argumentCount = argc;
    string key = argv[1];
    bool error = checkKey(string key);

    printf("ciphertext: ");
    return 0;
}
bool checkKey(string key)
{
    int n = 0;
    bool valid = true;
    int value = -1;
    while(key[n] != '\0')
    {
        value = (int)key[n];
        if(value < 65)
        {
            valid = false;
            break;
        }
        if(n > 23)
        {
            valid = false;
            break;
        }
        n++;
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