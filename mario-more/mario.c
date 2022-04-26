#include <cs50.h>
#include <stdio.h>
int size (void);
string edge (int i, string builder);
int main(void)
{
    int high= size();
    string hashz= "########";
    printf("%s",edge(high,hashz));

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


string edge (int i, string builder)
{
    char[i] cut ={};
    cut=builder;

    return cut;

}