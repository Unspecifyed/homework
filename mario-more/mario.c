#include <cs50.h>
#include <stdio.h>
int size (void);
void edge (int iteration);
void stacks(int iteration, int total);
int main(void)
{
    int high= size();// how high the blocks are
    edge(high);

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
    iteration=iteration-1;
    printf("#");
    if(iteration==0) return;
    edge(iteration);
    return;
}

void stacks(int iteration, int total)
{
    iteration = iteration+1;
    edge(iteration);// left side of blocks
    printf(" "); // space in the middle
    edge(iteration); //rightside
    printf("\n");
    if(iteration==total) return;
    
}