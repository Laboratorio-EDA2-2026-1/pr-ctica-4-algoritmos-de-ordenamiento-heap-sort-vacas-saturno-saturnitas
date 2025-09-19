/*
 * Objetivo: Completar las funciones Max-Heapify, Build-Max-Heap y Heap-Sort.
 * Entradas (stdin):
 *   n

 *   a1 a2 ... an

 * Salida (stdout):
 *   a1 a2 ... an  // en orden ascendente
 */

#include <stdio.h>
#include <stdlib.h>

/* PROTOTIPOS: NO CAMBIAR LAS FIRMAS */
void max_heapify(int a[], int n, int i);
void build_max_heap(int a[], int n);
void heap_sort(int a[], int n);

/* MAIN de prueba mínima */
int main(void) {
    int n; if (scanf("%d", &n) != 1 || n <= 0) return 0;
    int *a = (int*)malloc(sizeof(int) * n);
    if (!a) return 0;
    for (int i = 0; i < n; ++i) scanf("%d", &a[i]);

    heap_sort(a, n);

    for (int i = 0; i < n; ++i) {
        if (i) putchar(' ');
        printf("%d", a[i]);
    }
    putchar('
');

    free(a);
    return 0;
}

/* IMPLEMENTAR AQUÍ */
void max_heapify(int a[], int n, int i) {
    int l = 2 * i + 1;  // hijo izquierdo
    int r = 2 * i + 2;  // hijo derecho
    int largest = i;

    if (l < n && a[l] > a[largest])
        largest = l;
    if (r < n && a[r] > a[largest])
        largest = r;

    if (largest != i) {
        int tmp = a[i];
        a[i] = a[largest];
        a[largest] = tmp;
        max_heapify(a, n, largest);
    }
}

void build_max_heap(int a[], int n) {
    // El último nodo que no es hoja está en n/2 - 1
    for (int i = n / 2 - 1; i >= 0; --i) {
        max_heapify(a, n, i);
    }
}

void heap_sort(int a[], int n) {
    build_max_heap(a, n);

    for (int i = n - 1; i > 0; --i) {
        // Intercambiar la raíz (máximo) con el último
        int tmp = a[0];
        a[0] = a[i];
        a[i] = tmp;

        // Reducir tamaño del heap y restaurar la propiedad
        max_heapify(a, i, 0);
    }
}