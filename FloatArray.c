#include <stdlib.h>
#include <stdio.h>

typedef struct {
    float* items;
    int length;
} FloatArray;

FloatArray* FloatArray_Create(int length) {
    FloatArray* array = (FloatArray*)malloc(sizeof(FloatArray));
    if (array == NULL) {
        fprintf(stderr, "***ERROR in FloatArray_Create method***: Failed to allocate memory for an FloatArray pointer\n");
        exit(1);
    }
    array->items = (float*)calloc(length, sizeof(float));
    if (array->items == NULL) {
        fprintf(stderr, "***ERROR in FloatArray_Create method***: Failed to allocate memory for the items of FloatArray\n");
        exit(1);
    }
    array->length = length;
    return array;
}

void FloatArray_Destroy(FloatArray* array) {
    if (array != NULL) {
        free(array->items);
        free(array);
        array = NULL;
    }
}

float FloatArray_Get(FloatArray* array, int index) {
    if (index >= 0 && index < array->length) {
        return array->items[index];
    }
    fprintf(stderr, "***ERROR in FloatArray_Get method***: Attempted to get index %d, but the index range is 0 to %d\n", index, array->length - 1);
    exit(1);
}

void FloatArray_Set(FloatArray* array, int index, float newValue) {
    if (index >= 0 && index < array->length) {
        array->items[index] = newValue;
        return;
    }
    fprintf(stderr, "***ERROR in FloatArray_Set method***: Attempted to set index %d, but the index range is 0 to %d\n", index, array->length - 1);
    exit(1);
}