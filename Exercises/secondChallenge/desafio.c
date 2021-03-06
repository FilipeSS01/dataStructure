// Develop by Filipe Silva

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct node
{
    int dado;
    struct node *next;
} Node;

typedef struct list
{
    struct node *start;
    struct node *end;
} List;

void initializeList(List *list);
void insertStart(List *list, int dado, bool isCircular);
void insertEnd(List *list, int dado, bool isCircular);
void print(List list, bool isCircular);
void merge(List *list, List listCircular);
int hasLoop(List *list, int *quantNo);

int main()
{
    List list, listCircular;
    int quantNo = 0;
    initializeList(&list);
    initializeList(&listCircular);

    insertStart(&list, 1, false);
    insertStart(&list, 2, false);
    insertStart(&list, 3, false);
    // insertStart(&list, 4, false);

    insertStart(&listCircular, 5, true);
    insertStart(&listCircular, 6, true);
    insertStart(&listCircular, 7, true);
    insertStart(&listCircular, 7, true);
    insertStart(&listCircular, 7, true);

    print(list, false);
    print(listCircular, true);

    merge(&list, listCircular);

    if (hasLoop(&list, &quantNo))
        printf("Amount of NO is %d", quantNo);

    return 0;
}

void initializeList(List *list)
{
    list->start = NULL;
    list->end = NULL;
}

void insertStart(List *list, int dado, bool isCircular)
{
    Node *new = malloc(sizeof(List));
    if (new == NULL)
    {
        return;
    }
    new->dado = dado;
    if (list->start == NULL)
    {
        list->start = new;
        list->end = new;
        (isCircular) ? (list->end->next = list->start) : (list->end->next = NULL);
    }
    else
    {
        new->next = list->start;
        list->start = new;
        if (isCircular)
            list->end->next = list->start;
    }
    return;
}

void insertEnd(List *list, int dado, bool isCircular)
{
    Node *new = malloc(sizeof(List));
    if (new == NULL)
    {
        return;
    }
    new->dado = dado;
    if (list->start == NULL)
    {
        list->start = new;
        list->end = new;
        (isCircular) ? (list->end->next = list->start) : (list->end->next = NULL);
    }
    else
    {
        list->end->next = new;
        list->end = new;
        (isCircular) ? (list->end->next = list->start) : (list->end->next = NULL);
    }
    return;
}

void print(List list, bool isCircular)
{
    Node *aux;

    if (list.start == NULL)
    {
        return;
    }
    else
    {
        aux = list.start;
        if (isCircular)
        {
            do
            {
                printf("%d ", aux->dado);
                aux = aux->next;
            } while (aux != list.start);
        }
        else
        {
            while (aux != NULL)
            {
                printf("%d ", aux->dado);
                aux = aux->next;
            }
        }
    }
    printf("\n");
    return;
}

void merge(List *list, List listCircular)
{
    list->end->next = listCircular.start;
}

int hasLoop(List *list, int *quantNo)
{
    Node *slow = list->start;
    Node *fast = list->start;
    do
    {
        (*quantNo)++;
        slow = slow->next;
        if (slow->next == NULL)
            return 0;
        fast = fast->next->next;
    } while (slow != fast);
    return 1;
}