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
    while(key[n] != '\0')
    {
        n++;
        if(n > 23)
        {
            valid = false;
            return valid;
        }
    }
}
void scramb(string input)
{
    int n = 0;
    while(input[n] != '\0')
    {

    }
}