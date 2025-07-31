#include <stdlib.h>
#include <stdio.h>

typedef struct {
    int* items;
    int length;
} IntArray;

IntArray* IntArray_Create(int length) {
    IntArray* array = (IntArray*)malloc(sizeof(IntArray));
    if (array == NULL) {
        fprintf(stderr, "***ERROR in IntArray_Create method***: Failed to allocate memory for an IntArray pointer\n");
        exit(1);
    }
    array->items = (int*)calloc(length, sizeof(int));
    if (array->items == NULL) {
        fprintf(stderr, "***ERROR in IntArray_Create method***: Failed to allocate memory for the items of IntArray\n");
        exit(1);
    }
    array->length = length;
    return array;
}

void IntArray_Destroy(IntArray* array) {
    if (array != NULL) {
        free(array->items);
        free(array);
        array = NULL;
    }
}

int IntArray_Get(IntArray* array, int index) {
    if (index >= 0 && index < array->length) {
        return array->items[index];
    }
    fprintf(stderr, "***ERROR in IntArray_Get method***: Attempted to get index %d, but the index range is 0 to %d\n", index, array->length - 1);
    exit(1);
}

void IntArray_Set(IntArray* array, int index, int newValue) {
    if (index >= 0 && index < array->length) {
        array->items[index] = newValue;
        return;
    }
    fprintf(stderr, "***ERROR in IntArray_Set method***: Attempted to set index %d, but the index range is 0 to %d\n", index, array->length - 1);
    exit(1);
}