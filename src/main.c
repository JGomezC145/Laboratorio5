#include <stdio.h>
#include "dynamicarray.h"

int main() {
    // Crear un arreglo dinámico con capacidad inicial de 2
    DynamicArray *arr = create_array(2);
    if (arr == NULL) {
        fprintf(stderr, "Error al crear el arreglo dinámico\n");
        return 1;
    }

    // Agregar algunos elementos
    add_element(arr, 10);
    add_element(arr, 20);
    add_element(arr, 30);
    add_element(arr, 40);

    // Imprimir el arreglo
    printf("Contenido del arreglo: ");
    print_array(arr);

    // Obtener e imprimir un elemento por índice
    int index = 2;
    int value = get_element(arr, index);
    printf("Elemento en la posición %d: %d\n", index, value);

    // Liberar memoria
    free_array(arr);

    return 0;
}
