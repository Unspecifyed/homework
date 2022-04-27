#include <cs50.h>
#include <stdio.h>
int size (void);
void whiteSpace(int iteration, int total);
void edge (int iteration);
void stacks(int iteration, int total);
int main(void)
{
    int high= size();// how high the blocks are
    stacks(0,high);
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

//creates whitespace to allign the center
void whiteSpace(int iteration, int total){
    iteration=iteration+1;
    if(iteration==total) return;
    printf(" ");
    whiteSpace(iteration, total);
    return;


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

//stacks the blocks
void stacks(int iteration, int total)
{
    iteration = iteration+1;
    whiteSpace(0, total);
    edge(iteration);// left side of blocks
    printf("  "); // space in the middle
    edge(iteration); //rightside
    printf("\n");
    if(iteration==total) return;
    stacks(iteration, total);
    return;
}