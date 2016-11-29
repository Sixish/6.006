#ifndef PEAK_H
#define PEAK_H

#include <unistd.h>
#include <stdio.h>

typedef enum
{
    GREATER_THAN,
    LESS_THAN,
    EQUAL_TO
} EqualityType;

int find2dPeak(void **, int, int, EqualityType (*)(void *, void *));

#endif
