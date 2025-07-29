#include <stdlib.h>
#include <stdio.h>

typedef struct {
    double* items;
    int length;
} DoubleArray;

DoubleArray* DoubleArray_Create(int length) {
    DoubleArray* array = (DoubleArray*)malloc(sizeof(DoubleArray));
    if (array == NULL) {
        fprintf(stderr, "***ERROR in DoubleArray_Create method***: Failed to allocate memory for an DoubleArray pointer\n");
        exit(1);
    }
    array->items = (double*)calloc(length, sizeof(double));
    if (array->items == NULL) {
        fprintf(stderr, "***ERROR in DoubleArray_Create method***: Failed to allocate memory for the items of DoubleArray\n");
        exit(1);
    }
    array->length = length;
    return array;
}

void DoubleArray_Destroy(DoubleArray* array) {
    if (array != NULL) {
        free(array->items);
        free(array);
    }
}

double DoubleArray_Get(DoubleArray* array, int index) {
    if (index >= 0 && index < array->length) {
        return array->items[index];
    }
    fprintf(stderr, "***ERROR in DoubleArray_Get method***: Attempted to get index %d, but the index range is 0 to %d\n", index, array->length - 1);
    exit(1);
}

void DoubleArray_Set(DoubleArray* array, int index, double newValue) {
    if (index >= 0 && index < array->length) {
        array->items[index] = newValue;
        return;
    }
    fprintf(stderr, "***ERROR in DoubleArray_Set method***: Attempted to set index %d, but the index range is 0 to %d\n", index, array->length - 1);
    exit(1);
}
