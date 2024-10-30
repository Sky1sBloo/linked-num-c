#pragma once

/**
 * Node representing a Integer
 */
struct LinkedInt
{
    char num;
    struct LinkedInt* next;
};

/**
 * Generates Linked Num struct based on numString
 *
 * @param output Generated LinkedInt will return from here
 * @param numString the value of the linked num
*/
void generateLinkedInt(struct LinkedInt** output, const char numString[]);

/**
 * Use this if you want to append LinkedInt by value
 * Generates a new LinkedInt
 *
 * @param origin The LinkedInt where new LinkedInt will be appended
 * @param value Character value for the new LinkedInt
*/
void appendLinkedInt(struct LinkedInt** origin, char value);

/**
 * Adds two characters and sets the carry
 *
 * @param valueA First value
 * @param valueB Second Value
 * @param output The sum of valueA, valueB and input carry
 * @param carry Input carry will be added to output, it will also return the new carry after addition
*/
void addChar(char valueA, char valueB, char* output, int* carry);

/**
 * Deallocates LinkedInt
*/
void freeLinkedInt(struct LinkedInt* linkedNum);

/**
 * Performs addition between LinkedInt
 *
 * @param output New LinkedInt representing the sum linkedNumA and linkedNumB 
*/
void addLinkedInt(struct LinkedInt** output, const struct LinkedInt* linkedNumA, const struct LinkedInt* linkedNumB);

/**
 * Prints linked num
*/
void printLinkedInt(const struct LinkedInt* linkedNum);
