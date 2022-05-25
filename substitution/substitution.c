#include <cs50.h>
#include <stdio.h>
int keySize( string s);
int main(int argc, string argv[]) 
{
    const int ARUMENTNUMBER = argc;

    if (ARUMENTNUMBER != 2)
    {
        printf("Usage: ./substitution key");
        return 1;
    }
    const string KEY = argv[1];
    const int SIZEKEY = keySize(KEY);

    if(SIZEKEY != 26)
    {
        return 1;
    }

    return 0;


}

int keySize(string s)
{
    int size = 0;
    char c = s[size];
    bool empty = (c == '\0');

    while(empty)
    {
        size ++;
        c = s[size];
        empty = (c == '\0');
    }
    return size;
}