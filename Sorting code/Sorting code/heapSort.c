#include "Header.h"

void _sort_Heap(int arr[], int n, int order);
void _heapify(int arr[], int n, int i);
void _swap_heap(int* a, int* b);

void _heap_Sort(int arrSize){
    int* arr = (int*)malloc(arrSize * sizeof(int));

    if (arr == NULL) {
        printf("Memory allocation failed.\n");
        return;
    }

    int order;

    order = _get_Order();

    int interval;

    interval = _get_Interval();

    srand((unsigned int)time(NULL));
    for (int i = 0; i < arrSize; i++) {
        arr[i] = (rand() % (2 * interval)) - interval + 1;
    }

    clock_t start = clock();

    _sort_Heap(arr, arrSize, order);

    clock_t end = clock();

    double time_taken = ((double)(end - start)) / CLOCKS_PER_SEC;

    printf("Time taken: %.4f seconds\n", time_taken);

    free(arr);
}

void _swap_heap(int* a, int* b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

void _sort_Heap(int arr[], int n, int order) {
    for (int i = n / 2 - 1; i >= 0; i--)
        _heapify(arr, n, i, order);

    for (int i = n - 1; i >= 0; i--) {
        _swap(&arr[0], &arr[i]);
        _heapify(arr, i, 0, order);
    }
}

void _heapify(int arr[], int n, int i, int order) {
    int largest = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;

    if (order == 1) { // Ascending order
        if (left < n && arr[left] > arr[largest])
            largest = left;

        if (right < n && arr[right] > arr[largest])
            largest = right;
    }
    else if (order == 0) { // Descending order
        if (left < n && arr[left] < arr[largest])
            largest = left;

        if (right < n && arr[right] < arr[largest])
            largest = right;
    }

    if (largest != i) {
        _swap_heap(&arr[i], &arr[largest]);
        _heapify(arr, n, largest, order);
    }
}
