#include "LinkedInt.h"
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

void generateLinkedInt(struct LinkedInt **output, const char numString[])
{
    for (int i = 0; numString[i] != '\0'; ++i)
    {
        struct LinkedInt *newLinkedInt = malloc(sizeof(struct LinkedInt));
        newLinkedInt->num = numString[i];

        if (i > 0)
        {
            newLinkedInt->next = *output;
            *output = newLinkedInt;
        }
        else
        {
            *output = newLinkedInt;
            (*output)->next = NULL;
        }
    }
}

void appendLinkedInt(struct LinkedInt **origin, char value)
{
    if (origin == NULL)
    {
        *origin = malloc(sizeof(struct LinkedInt));
        (*origin)->num = value;
        (*origin)->next = NULL;
    }

    struct LinkedInt *newLinkedInt = malloc(sizeof(struct LinkedInt));
    newLinkedInt->num = value;

    newLinkedInt->next = *origin;
    *origin = newLinkedInt;
}

void freeLinkedInt(struct LinkedInt *linkedNum)
{
    struct LinkedInt *current = linkedNum;
    while (current != NULL)
    {
        struct LinkedInt *toFree = current;
        current = current->next;
        free(toFree);
    }
}

void addLinkedInt(struct LinkedInt **output, const struct LinkedInt *linkedNumA, const struct LinkedInt *linkedNumB)
{
    const struct LinkedInt *currentA = linkedNumA;
    const struct LinkedInt *currentB = linkedNumB;

    // Carry is int to simplify addition 
    int carry = 0;

    while (currentA != NULL || currentB != NULL || carry > 0)
    {
        char valueA = currentA ? currentA->num : '0';
        char valueB = currentB ? currentB->num : '0';

        char answer;
        addChar(valueA, valueB, &answer, &carry);
        appendLinkedInt(output, answer);

        if (currentA)  currentA = currentA->next;
        if (currentB)  currentB = currentB->next;
    }

    // To clear remaning carry
    if (carry > 0)
    {
        appendLinkedInt(output, carry + '0');
    }
}

void addChar(char valueA, char valueB, char *output, int *carry)
{
    char answer = valueA + valueB - '0';
    if (*carry != 0)
    {
        answer += *carry;
        *carry = 0;
    }

    if (answer > '9')
    {
        *carry = 1;
        answer = answer - 10;
    }

    *output = answer; 
}

void printLinkedInt(const struct LinkedInt *linkedNum)
{
    const struct LinkedInt *current = linkedNum;
    while (current != NULL)
    {
        printf("%c", current->num);
        current = current->next;
    }
    printf("\n");
}
