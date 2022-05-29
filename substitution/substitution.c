#include <cs50.h>
#include <stdio.h>
bool valid(int count, string key);
int strCount(string key);
bool caps(char c);
void cyper(string key, string ptext);
int main(int argc, string argv[]) 
{
    const int ARGUMENTCOUNT = argc;
    const string KEY = argv[1];
    const bool VALIDKEY = valid(ARGUMENTCOUNT,KEY);

    if(!VALIDKEY)
    {
        return 1;
    }

    const string PLAINTEXT = get_string("plaintext: ");
    cyper(KEY,PLAINTEXT);

    return 0;

}


bool valid(int count, string key)
{
    bool isValid = true;
    if(count != 2)
    {
        printf("Usage: ./substitution key");
        isValid = false;

    }

    if(strCount(key) !=26)
    {
        printf("Key must contain 26 characters.");
        isValid = false;
    }
    return isValid;
}

int strCount(string key)
{
    int i = 0;
    while(key[i]!='\0')
    {
        i ++;
    }
    return i;
}
bool caps(char c)
{
    bool isCaps = false;
    if(c >64 && c<91)
    {
        isCaps =true;
    }
    return isCaps;
}


void cyper(string key, string ptext)
{
    int i = 0;
    int cAmount = 65;
    int lAmount = 97;
    int pValue = 0;
    char out = 'a';
    while(ptext[i]!='\0')
    {
        if(caps(ptext[i]))
        {
           pValue = ptext[i] - cAmount;
        }
        else
        {
            pValue =ptext[i] - lAmount;
        }
        out = key[pValue];
        printf("%c",out);
        i++;
    }
}