#include <cs50.h>
#include <stdio.h>
int size (void);
int main(void)
{
    int high= size();
    printf("%i",high);

}

int size(void){
    int dicks = get_int("input a number 1-8");
    if(size>0&&size<9) return size;
    printf("not valid input");
    size();
}