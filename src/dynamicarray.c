#include <stdio.h>
#include <stdlib.h>
#include "dynamicarray.h"

DynamicArray* create_array(int initial_capacity) {
    DynamicArray *arr = malloc(sizeof(DynamicArray));
    if (arr == NULL) return NULL;

    arr->data = malloc(initial_capacity * sizeof(int));
    if (arr->data == NULL) {
        free(arr);
        return NULL;
    }

    arr->size = 0;
    arr->capacity = initial_capacity;
    return arr;
}

int add_element(DynamicArray *arr, int value) {
    if (arr->size == arr->capacity) {
        arr->capacity *= 2;
        int *temp = realloc(arr->data, arr->capacity * sizeof(int));
        if (temp == NULL) {
            fprintf(stderr, "Error: Memory allocation failed while resizing the array.\n");
            return -1; // Signal failure
        }
        arr->data = temp;
    }

    arr->data[arr->size++] = value;
    return 0; // Signal success
}

int get_element(DynamicArray *arr, int index) {
    if (index < 0 || index >= arr->size) {
        fprintf(stderr, "Índice fuera de rango\n");
        return -1; // Valor de error
    }
    return arr->data[index];
}

void print_array(DynamicArray *arr) {
    for (int i = 0; i < arr->size; i++) {
        printf("%d ", arr->data[i]);
    }
    printf("\n");
}

void free_array(DynamicArray *arr) {
    free(arr->data);
    free(arr);
}
