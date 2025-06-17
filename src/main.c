#include <stdio.h>
#include <stdlib.h>

int main() {
    int *array = NULL;    // Puntero al arreglo dinámico
    int size = 0;         // Cantidad de elementos actualmente
    int capacity = 2;     // Capacidad inicial

    // Reservar memoria inicial
    array = malloc(capacity * sizeof(int));
    if (array == NULL) {
        fprintf(stderr, "Error al asignar memoria\n");
        return 1;
    }

    // Función para agregar elementos al arreglo
    for (int i = 0; i < 5; i++) {
        if (size == capacity) {
            // Redimensionar el arreglo (doblar capacidad)
            capacity *= 2;
            int *temp = realloc(array, capacity * sizeof(int));
            if (temp == NULL) {
                fprintf(stderr, "Error al redimensionar el arreglo\n");
                free(array);
                return 1;
            }
            array = temp;
        }
        array[size] = i * 10;
        size++;
    }

    // Imprimir el contenido del arreglo
    printf("Contenido del arreglo:\n");
    for (int i = 0; i < size; i++) {
        printf("%d ", array[i]);
    }
    printf("\n");

    // Liberar memoria
    free(array);
    return 0;
}
