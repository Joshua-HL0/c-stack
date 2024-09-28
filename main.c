#include <stdint.h>
#include <stdio.h>
#include "stack.h"

int main(int argc, char **argv){
    Stack intStack;
    stack_init(&intStack, sizeof(uint32_t), 5);

    uint32_t x = 12;
    stack_push(&intStack, &x);
    x = 56;
    stack_push(&intStack, &x);

    uint32_t y;
    stack_pop(&intStack, &y);
    printf("Pop: %u\n", y);

    stack_peek(&intStack, &y);
    printf("Peek: %u\n", y);

    stack_pop(&intStack, &y);
    printf("Pop: %u\n", y);
    
    printf("IsEmpty: %d\n", stack_is_empty(&intStack));
}
