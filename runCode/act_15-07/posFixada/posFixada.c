// Develop by Filipe Silva

#include <stdio.h>
#include <stdlib.h>

typedef struct stack
{
    float value;
    struct stack *next;
} Stack;

void initialize(Stack *stack);
void push(Stack *stack, float value);
float pop(Stack *stack);
void print(Stack stack);

int main()
{
    Stack stack;
    initialize(&stack);

    return 0;
}

void initialize(Stack *stack)
{
    // stack->value = NULL;
    stack->next = NULL;
}
void push(Stack *stack, float value)
{
    Stack *new = (Stack *)malloc(sizeof(Stack));

    if (new == NULL)
        return;

    new->value = value;
    new->next = stack->next;
    stack->next = new;
}
float pop(Stack *stack)
{
    Stack *aux = stack->next;
    float value = aux->value;

    stack->next = stack->next->next;
    free(aux);

    return value;
}
void print(Stack stack)
{
    Stack *aux = stack.next;

    if (aux == NULL)
    {
        printf("\nPilha esta vazia !");
        return;
    }

    printf("\nPilha\n");
    while (aux != NULL)
    {
        printf("%.2f\n", aux->value);
        aux = aux->next;
    }
}
