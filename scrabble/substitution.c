#include <cs50.h>
#include <stdio.h>
bool valid(int count, string key);
int strCount(string key);
int main(int argc, string argv[]) 
{
    const int ARGUMENTCOUNT = argc;
    const string KEY = argv[1];
    bool validkey = true;

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