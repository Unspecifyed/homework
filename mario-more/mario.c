#include <cs50.h>
#include <stdio.h>
int size (void);
void edge (int iteration, char c);
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
void edge (int iteration, char c)
{
    if(iteration==0) return;
    if(c==' '&&iteration==1)return;
    iteration=iteration-1;
    printf("%c",c);
    edge(iteration,c);
    return;
}

void line(int n)
{
    char hash='#';
    char space=' ';
    edge(n,space);
    edge(n,hash);
    printf("  ");
    edge(n,hash);
    edge(n,space);
    printf("\n");
}
void stack (int n, int total){
    n=n+1;
    line(n);
    if(n==total)return;
    stack(n,total);
    return;
}