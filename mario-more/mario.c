#include <cs50.h>
#include <stdio.h>
#include <string.h>
int size (void);
string blocks (int i);
string edge (int i, string builder);
int main(void)
{
    int high= size();
    string baz = edge(high,"#");
    printf("%i %s",high, baz);

}
// Gets the size of the "blocks"
int size(void)
{
    int stacks = get_int("input a number 1-8: \n");
    if(stacks>0&&stacks<9) return stacks;
    printf("not valid input\n");
    size();
    return stacks;
}

string blocks(int i)
{
    i= i-1;
    return "lol";

}

string edge (int i, string builder)
{
    i = i-1;
    builder = strncat(builder,"#",strlen(builder+1));
    if(i==0) return builder;
    printf("%s",builder);
    edge(i,builder);
    return builder;

}