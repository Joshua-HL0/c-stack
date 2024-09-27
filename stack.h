#ifndef STACK_H
#define STACK_H

#include <stdlib.h>

typedef struct {
    void* data;
    int elementSize;
    int capacity;
    int size;
} Stack;

void stack_init(Stack* stack, int elementSize, int capacity);

void stack_push(Stack* stack, void* element);
void stack_pop(Stack* stack, void* element);
void stack_peek(Stack* stack, void* element);
int stack_is_empty(Stack* stack);
int stack_is_full(Stack* stack);

void stack_resize(Stack* stack, int additional);
void stack_free(Stack* stack);

#endif

