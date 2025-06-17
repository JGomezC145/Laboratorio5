#ifndef DYNAMIC_ARRAY_H
#define DYNAMIC_ARRAY_H

typedef struct {
    int *data;
    int size;
    int capacity;
} DynamicArray;

// Funciones del arreglo dinámico
DynamicArray* create_array(int initial_capacity);
int add_element(DynamicArray *arr, int value);
int get_element(DynamicArray *arr, int index);
void print_array(DynamicArray *arr);
void free_array(DynamicArray *arr);

#endif
