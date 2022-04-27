#include <cs50.h>
#include <stdio.h>
int size (void);
void edge (int iteration, char c);
int main(void)
{
    int high= size();// how high the blocks are
    char hash='#';
    char space=' ';
    edge(high,space);
    edge(high,hash);
    return 0;
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
// Creates the edge of the blocks
void edge (int iteration, char c)
{
    if(iteration==0) return;
    iteration=iteration-1;
    printf(c);
    edge(iteration);
    return;
}

