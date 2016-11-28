#include "peak.h"

int findPeak(void **array, int length, EqualityType (*comparator)(void *, void *))
{
    int start = 0, end = length - 1, pivot;
    EqualityType rightResult, leftResult;

    do
    {
        pivot = (start + end) / 2;
        rightResult = EQUAL_TO;
        leftResult = EQUAL_TO;

        /* Compare the left and right elements, if they exist.
         * If not, the default value for leftResult and rightResult shall be
         * EQUAL_TO. */
        if (pivot != start)
        {
            leftResult = comparator(array[pivot - 1], array[pivot]);
        }

        if (pivot != end)
        {
            rightResult = comparator(array[pivot + 1], array[pivot]);
        }

        /* Check if either of the results were GREATER_THAN.
         * If so, then we're not at a peak -- repeat the process for the half
         * with the greater value.
         * If both of them are GREATER_THAN, we will find a peak going either
         * direction, so just follow the first one.
         * If none of them are GREATER_THAN, then this is a peak. */
        if (leftResult == GREATER_THAN)
        {
            end = pivot - 1;
        }
        else if (rightResult == GREATER_THAN)
        {
            start = pivot + 1;
        }
        else
        {
            start = pivot;
            end = pivot;
        }

        /* Continue until start, pivot & end are such that there's only one
         * possible element (start == pivot && pivot == end). */
    }
    while (!(start == pivot && pivot == end));
    return pivot;
}

