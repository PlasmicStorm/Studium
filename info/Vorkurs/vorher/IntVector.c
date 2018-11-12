#include <stdio.h>

#pragma once
struct IntVector {
    size_t capacity;
    size_t size;
    int *memory;
}

IntVector *IntVector_new(size_t capa)
