#include <cs50.h>
#include <stdio.h>
int size (void);
string blocks (int i);
string edge (int i, string builder);
int main(void)
{
    int high= size();
    string baz = edge();
    printf("%i %s",high, baz);

}
// Gets the size of the "blocks"
int size(void){
    int stacks = get_int("input a number 1-8: \n");
    if(stacks>0&&stacks<9) return stacks;
    printf("not valid input\n");
    size();
    return stacks;
}

string blocks(int i){
    i= i-1;

}

string edge (int i, string builder){
    i = i-1;
    builder = strgcat(builder,"#");
    if(i==0) return builder;
    edge(i,builder);
    return builder;

}