#include "stack.h"
#include <string.h>

void stack_init(Stack *stack, int elementSize, int capacity){
    stack->elementSize = elementSize;
    stack->capacity = capacity;
    stack->size = 0;
    stack->data = malloc(elementSize * capacity);
}

void stack_push(Stack *stack, void *element){
    if (stack_is_full(stack)){
        stack_resize(stack, stack->capacity);
    }

    memcpy((char*)stack->data + stack->size * stack->elementSize, element, stack->elementSize); //must use memcpy because no array indexing with void pointers!
    stack->size++;                                                                              //and char pointer cast because no arithmetic with void pointers!
}

void stack_pop(Stack *stack, void *element){
    if (stack_is_empty(stack)){
        return;
    }

    stack->size--;
    memcpy(element, (char*)stack->data + stack->size * stack->elementSize, stack->elementSize);
}

void stack_peek(Stack *stack, void *element){
if (stack_is_empty(stack)){
        return;
    }

    memcpy(element, (char*)stack->data + ((stack->size - 1) * stack->elementSize), stack->elementSize);
}

int stack_is_full(Stack *stack){
    return (stack->size == stack->capacity);
}

int stack_is_empty(Stack *stack){
    return (stack->size == 0);
}

void stack_resize(Stack *stack, int additional){
    stack->capacity += additional;
    stack->data = realloc(stack->data, stack->capacity * stack->elementSize);
}

void stack_free(Stack *stack){
    free(stack->data);
    stack->data = NULL;
    stack->size = 0;
    stack->capacity = 0;
}
