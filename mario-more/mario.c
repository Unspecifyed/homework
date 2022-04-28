#include <cs50.h>
#include <stdio.h>
int size(void);
void edge(int iteration);
void line(int n, int total);
void stack(int n, int total);
void whiteSpace(int n, int total);
int main(void)
{
    int high = size(); // how high the blocks are
    stack(0, high);
    return 0;
}
// Gets the size of the "blocks"
int size(void)
{
    int stacks = get_int("input a number 1-8: \n");
    while (stacks < 0 || stacks > 8)
    {
        stacks = get_int("input a number 1-8: \n");
    }
    return stacks;
}
// Creates the edge of the blocks
void edge(int iteration)
{
    if (iteration == 0)return;
    iteration = iteration-1;
    printf("#");
    edge(iteration);
    return;
}
// make the full line
void line(int n, int total)
{
    whiteSpace(n,total);
    edge(n);
    printf("  ");
    edge(n);
    printf("\n");
}
//stacks the lines
void stack (int n, int total){
    n=n+1;
    line(n,total);
    if(n==total)return;
    stack(n,total);
    return;
}
//makes the whitespace before the
void whiteSpace(int n, int total)
{
    if(n==total)return;
    n=n+1;
    printf(" ");
    whiteSpace(n,total);
    return;
}