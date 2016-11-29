#include "peak.h"


int index(int row, int col, int numRows, int numCols)
{
    return (row * numCols + col);
}

int row(int index, int numRows, int numCols)
{
    return (index / numCols);
}

int column(int index, int numRows, int numCols)
{
    return (index % numCols);
}

int findLargest(int index1, int index2, void **array, int rows, int cols,
    EqualityType (*comparator)(void *, void *))
{
    /* Assume at least one is valid. If both are invalid then this function
     * returns incorrect results (there are no correct results). */
    int larger, isValid1, isValid2;

    larger = index1;

    /* Check if the indexes are within the bounds. */
    isValid1 = 0 <= index1 && index1 <= index(rows - 1, cols - 1, rows, cols);
    isValid2 = 0 <= index2 && index2 <= index(rows - 1, cols - 1, rows, cols);

    /* Check if index1 is valid. */
    if (isValid1 && isValid2)
    {
        /* Compare the two items. */
        if (comparator(array[index2], array[index1]) == GREATER_THAN)
        {
            larger = index2;
        }
    }
    else if (isValid1)
    {
        /* index1 is greater because index2 is invalid. */
        larger = index1;
    }
    else
    {
        /* Assume that at least one is valid, thus: index2 is larger because
         * index1 is invalid. */
        larger = index2;
    }

    return larger;

}

int find2dPeak(void **array, int rows, int cols,
    EqualityType (*comparator)(void *, void *))
{
    int curIndex, pivot, largest, north, south, left, right;
    /* TODO REMOVE */
    int iterations = 0;

    largest = -1;
    pivot = curIndex = index(rows / 2, cols / 2, rows, cols);

    /* While an adjacent neighbour has a higher value, follow it. */
    do
    {
        /* Follow the largest neighbour. */
        curIndex = pivot;

        /* Get the indexes corresponding to adjacent positions. */
        north = index(row(curIndex, rows, cols) - 1,
            column(curIndex, rows, cols), rows, cols);
        south = index(row(curIndex, rows, cols) + 1,
            column(curIndex, rows, cols), rows, cols);
        left = index(row(curIndex, rows, cols),
            column(curIndex, rows, cols) - 1, rows, cols);
        right = index(row(curIndex, rows, cols),
            column(curIndex, rows, cols) + 1, rows, cols);

        /* Check which is the largest. */
        largest = curIndex;
        largest = findLargest(largest, north, array, rows, cols, comparator);
        largest = findLargest(largest, south, array, rows, cols, comparator);
        largest = findLargest(largest, left, array, rows, cols, comparator);
        largest = findLargest(largest, right, array, rows, cols, comparator);

        pivot = largest;

        /* Continue until the largest is the current index (no change). */
        iterations++;
    }
    while (curIndex != largest);

    printf("Iterations: %d\n", iterations);
    return curIndex;
}

