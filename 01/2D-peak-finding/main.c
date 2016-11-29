#include "main.h"

EqualityType compareValues(void *vp1, void *vp2)
{
    int *item1 = (int *)vp1, *item2 = (int *)vp2;
    EqualityType result = EQUAL_TO;

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

int main(int argc, char **argv)
{
    int arg = 1, rows, cols;
    int x, y;
    int peak;
    int *array = NULL;
    int **ptrArray = NULL;

    /* User will enter two digits: the number of rows R and the number of
     * columns C. The matrix values follow and must be R x C in size. */
    printf("clargs=%d\n", argc);

    rows = atoi(argv[arg++]);
    cols = atoi(argv[arg++]);

    array = (int *)malloc((rows * cols) * sizeof(int));
    ptrArray = (int **)malloc((rows * cols) * sizeof(int *));

    for (y = 0; y < rows; y++)
    {
        for (x = 0; x < cols; x++)
        {
            int i = arg - 3;
            array[i] = atoi(argv[arg]);
            ptrArray[i] = &array[i];

            printf("%d ", array[i]);
            arg++;
        }
        printf("\n");
    }

    peak = find2dPeak((void **)ptrArray, rows, cols, &compareValues);
    printf("Peak: %d\n", peak);

    return 0;
}
