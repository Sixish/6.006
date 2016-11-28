#include "main.h"

/*
 * Comparator for integer pointers.
 */
EqualityType compareArrayElements(void *vp1, void *vp2)
{
    EqualityType result = EQUAL_TO;
    int *item1 = (int *)vp1, *item2 = (int *)vp2;

    if (*item1 < *item2)
    {
        result = LESS_THAN;
    }
    else if (*item1 > *item2)
    {
        result = GREATER_THAN;
    }

    return result;
}

/*
 * Generates a sample array of integer pointers.
 */
int **generatePointerArray(int *items, int size)
{
    int i, **ptrArray;
    ptrArray = (int **)malloc(size * sizeof(int *));
    for (i = 0; i < size; i++)
    {
        ptrArray[i] = &items[i];
    }
    return ptrArray;
}

/*
 * Prints the integers in an array.
 */
void printIntegerArray(int *array, int length)
{
    int i;
    for (i = 0; i < length; i++)
    {
        printf("%d ", array[i]);
    }
}

/*
 * Reads the command line and returns the integers as an array.
 */
int *readCommandLineItems(int argc, char **argv)
{
    int i, *array = NULL;
    
    array = (int *)malloc((argc - 1) * sizeof(int));
    for (i = 1; i < argc; i++)
    {
        array[i - 1] = atoi(argv[i]);
    }

    return array;
}

int main(int argc, char **argv)
{
    int status = 0, size, *items = NULL, **ptrs = NULL, peak;

    if (argc > 1)
    {
        /* Convert the command line arguments to an array of integers. */
        items = readCommandLineItems(argc, argv);

        /* There will be (argc - 1) integers. */
        size = argc - 1;
        ptrs = generatePointerArray(items, size);

        /* Output the input data. */
        printf("Input: ");
        printIntegerArray(items, size);
        printf("\n");

        /* Find * output the peak. */
        peak = findPeak((void **)ptrs, argc - 1, &compareArrayElements);
        printf("Peak: element %d (%d).\n", peak, items[peak]);
    }
    else
    {
        /* Not enough command line arguments. */
        printf("Usage: findpeak value1[, value2[, value3[, ...]]]\n");
        status = -1;
    }
    return status;
}
