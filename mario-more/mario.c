#include <cs50.h>
#include <stdio.h>
int size (void);
void edge (int iteration);
void line (int n);
void stack (int n, int total);
int main(void)
{
    int high= size();// how high the blocks are
    stack(0,high);
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
void edge (int iteration)
{
    if(iteration==0) return;
    iteration=iteration-1;
    printf("#");
    edge(iteration);
    return;
}

void line(int n)
{
    edge(n);
    printf("  ");
    edge(n);
    printf("\n");
}
void stack (int n, int total){
    n=n+1;
    line(n);
    if(n==total)return;
    stack(n,total);
    return;
}