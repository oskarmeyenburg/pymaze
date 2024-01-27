#include "bst.h" // implements binary search trees
#include <stdio.h> // implements printf
#include <stdlib.h> // implements malloc, calloc and realloc
#include <stdint.h> // implements int8_t
#include <time.h>


void init() {
    srand(time(NULL));
}


void c_print() {
    printf("Hello World from C!\n");
}

void print_maze1(int **array, int width, int height) {
    for (int i = 0; i < width; i++) {
        for (int j = 0; j < height; j++) {
            int value = array[i][j];
            printf("%d ", value);
        }
        printf("\n");
    }
}

void print_maze(int8_t *array, int width, int height) {
    for (int i = 0; i < width; i++) {
        for (int j = 0; j < height; j++) {
            int value = array[i + j * width];
            printf("%d ", value);
        }
        printf("\n");
    } 
}


void add_adjacent_cells(int x, int y, BinaryTree* adjacent_cells, int8_t* array, int width, int height) {
    int coord = x + y * width;

    if (x > 0) {
        if (array[coord - 1] == -1) {
            bst_insert(adjacent_cells, coord - 1);
        }
    }
    if (x < width - 1) {
        if (array[coord + 1] == -1) {
            bst_insert(adjacent_cells, coord + 1);
        }
    }
    if (y > 0) {
        if (array[coord - width] == -1) {
            bst_insert(adjacent_cells, coord - width);
        }
    }
    if (y < height - 1) {
        if (array[coord + width] == -1) {
            bst_insert(adjacent_cells, coord + width);
        }
    }
}


void generate_maze(int8_t *array, int width, int height) {
    for (int x = 0; x < width; x++)
    for (int y = 0; y < height; y++)
    array[x + y * width] = -1;

    // calloc(number of elements, size per element) -> allocates space + fills with 0
    // malloc(number of elements * size per element) -> allocates space (maybe prefered)
    BinaryTree* adjacent_cells = bst_create();
    bst_insert(adjacent_cells, 92);
    bst_insert(adjacent_cells, 48);
    bst_insert(adjacent_cells, 21);
    bst_insert(adjacent_cells, 23);
    bst_insert(adjacent_cells, 4);
    bst_insert(adjacent_cells, 2);
    bst_insert(adjacent_cells, 14);
    bst_insert(adjacent_cells, 11);
    bst_insert(adjacent_cells, 91);
    bst_insert(adjacent_cells, 94);
    bst_insert(adjacent_cells, 20);
    bst_insert(adjacent_cells, 25);
    bst_insert(adjacent_cells, 24);
    bst_insert(adjacent_cells, 26);
    bst_insert(adjacent_cells, 97);
    bst_insert(adjacent_cells, 85);
    
    bst_print(adjacent_cells);
    printf("--\n%d\n", adjacent_cells->size);
    bst_remove(adjacent_cells, 37);
    bst_remove(adjacent_cells, 21);
    bst_remove(adjacent_cells, 85);
    bst_remove(adjacent_cells, 14);
    bst_remove(adjacent_cells, 20);
    bst_remove(adjacent_cells, 25);
    printf("--\n%d\n--\n", adjacent_cells->size);
    for (int i = 0; i < 20; i++) {
        printf("%d: %d\n", i, bst_get(adjacent_cells, i));
    }
    printf("--\n%d\n", bst_get(adjacent_cells, -1));

    // Create starting point
    int center[2] = {width / 2, height / 2};
    array[center[0] + center[1] * width];
    add_adjacent_cells(center[0], center[1], adjacent_cells, array, width, height);

    for (int i = 0; i < width; i++) {
        for (int j = 0; j < height; j++) {
            int value = array[i + j * width];
            printf("%d ", value);
        }
        printf("\n");
    }

    for (int i = 0; i < 30; i++) printf("%d\n", bst_get_random(adjacent_cells));

    bst_delete(adjacent_cells);
}