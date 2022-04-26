#include <cs50.h>
#include <stdio.h>

int main(void)
{
    int size =size();

}

int size(void){
    int size = get_int("input a number 1-8");
    if(size>0&&size<9) return size;
    printf("not valid input");
    size();
}