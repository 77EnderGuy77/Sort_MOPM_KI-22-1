#include "Header.h"

void _sort_Shaker(int arr[], int arrSize, int order);

void _shaker_Sort(int arrSize) {

    int* arr = (int*)calloc(arrSize, sizeof(int));

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

    _sort_Shaker(arr, arrSize, order);

    clock_t end = clock();

    double time_taken = ((double)(end - start)) / CLOCKS_PER_SEC;

    printf("Time taken: %.4f seconds\n", time_taken);

    free(arr);
}


void _sort_Shaker(int arr[], int arrSize, int order) {
    int left = 0, right = arrSize - 1;
    int swapped = 1;

    while (left < right && swapped) {
        swapped = 0;

        if (order == 1) { // Ascending order
            for (int i = left; i < right; ++i) {
                if (arr[i] > arr[i + 1]) {
                    int temp = arr[i];
                    arr[i] = arr[i + 1];
                    arr[i + 1] = temp;
                    swapped = 1;
                }
            }

            --right;

            for (int i = right; i > left; --i) {
                if (arr[i] < arr[i - 1]) {
                    int temp = arr[i];
                    arr[i] = arr[i - 1];
                    arr[i - 1] = temp;
                    swapped = 1;
                }
            }
        }
        else if (order == 0) { // Descending order
            for (int i = left; i < right; ++i) {
                if (arr[i] < arr[i + 1]) {
                    int temp = arr[i];
                    arr[i] = arr[i + 1];
                    arr[i + 1] = temp;
                    swapped = 1;
                }
            }

            --right;

            for (int i = right; i > left; --i) {
                if (arr[i] > arr[i - 1]) {
                    int temp = arr[i];
                    arr[i] = arr[i - 1];
                    arr[i - 1] = temp;
                    swapped = 1;
                }
            }
        }

        ++left;
    }
}