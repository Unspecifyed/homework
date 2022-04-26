#include <cs50.h>
#include <stdio.h>
int size (void);
int main(void)
{
    int high= size();
    printf("%i",high);

}

int size(void){
    int stacks = get_int("input a number 1-8");
    if(stacks>0&&stacks<9) return stacks;
    printf("not valid input");
    size();
}