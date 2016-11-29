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

int findLargestColumn(void **array, int row, int rows, int cols,
    EqualityType (*comparator)(void *, void *))
{
    int col, max = index(row, 0, rows, cols);
    for (col = 0; col < cols; col++)
    {
        if (comparator(array[index(row, col, rows, cols)], array[max]) ==
            GREATER_THAN)
        {
            max = index(row, col, rows, cols);
        }
    }

    return max;
}

int find2dPeak(void **array, int rows, int cols,
    EqualityType (*comparator)(void *, void *))
{
    int leftBound, rightBound, curIndex, largest, left, right, iterations;

    /* Start with the whole array [0, cols - 1]. */
    leftBound = 0;
    rightBound = index(rows - 1, cols - 1, rows, cols);

    /* Record the number of iterations the loop took for the input. */
    iterations = 0;

    largest = -1;

    do
    {
        /* Search the middle of the array. */
        curIndex = (leftBound + rightBound) / 2;

        /* Get the index corresponding to the largest value in the row. */
        curIndex = findLargestColumn(array, row(curIndex, rows, cols), rows, cols,
            comparator);

        /* We know that this item is the largest in the row; check if this is a
         * peak. */
        left = index(row(curIndex, rows, cols) - 1,
            column(curIndex, rows, cols), rows, cols);
        right = index(row(curIndex, rows, cols) + 1,
            column(curIndex, rows, cols) , rows, cols);

        /* Check which is the largest. */
        largest = curIndex;
        largest = findLargest(largest, left, array, rows, cols, comparator);
        largest = findLargest(largest, right, array, rows, cols, comparator);

        /* If the left is largest, repeat the process on the left half, and
         * vice versa for the right. */
        if (left == largest)
        {
            rightBound = curIndex - cols;
        }
        else if (right == largest)
        {
            leftBound = curIndex + cols;
        }
        else
        {
            leftBound = rightBound = curIndex;
        }

        /* Continue until the largest is the current index (no change). */
        iterations++;
    }
    while (rightBound != leftBound);

    printf("Iterations: %d\n", iterations);
    return rightBound;
}

