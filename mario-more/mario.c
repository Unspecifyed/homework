#include <cs50.h>
#include <stdio.h>
int size (void);
void edge (int iteration);
int main(void)
{
    int high= size();

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


void edge (int iteration)
{
    iteration=iteration-1;
    printf("#");
    if(iteration==0) return;
    edge(iteration);
    return;



}