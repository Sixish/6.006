#ifndef PEAK_H
#define PEAK_H

#include "stdio.h"

typedef enum
{
    GREATER_THAN,
    LESS_THAN,
    EQUAL_TO
} EqualityType;


int findPeak(void **, int, EqualityType (*)(void *, void *));


#endif

