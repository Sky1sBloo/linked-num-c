#include <stdio.h>
#include "LinkedInt.h"


int main(int argc, char* argv[])
{
    if (argc < 3)
    {
        fprintf(stderr, "Error: Argument provided too few\n");
        return 1;
    }
    struct LinkedInt* testNum;
    struct LinkedInt* testNumB;
    struct LinkedInt* output;

    generateLinkedInt(&testNum, argv[1]); 
    generateLinkedInt(&testNumB, argv[2]);

    addLinkedInt(&output, testNum, testNumB);

    printLinkedInt(output);

    freeLinkedInt(testNum);
    freeLinkedInt(testNumB);
    freeLinkedInt(output);

    return 0;
}
