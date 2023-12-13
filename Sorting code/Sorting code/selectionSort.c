#include "Header.h"

void _swap(int* xp, int* yp);
void _sort_selection(int arr[], int n, int order);

void _selection_Sort(int arrSize) {
    int* arr = malloc(arrSize * sizeof(int));

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

    _sort_selection(arr, arrSize, order);

    clock_t end = clock();

    double time_taken = ((double)(end - start)) / CLOCKS_PER_SEC;

    printf("Time taken: %.4f seconds\n", time_taken);
   
    free(arr);
}

void _swap(int* xp, int* yp)
{
    int temp = *xp;
    *xp = *yp;
    *yp = temp;
}

void _sort_selection(int arr[], int n, int order)
{
    int i, j, idx;

    for (i = 0; i < n - 1; i++)
    {
        idx = i;
        for (j = i + 1; j < n; j++) {
            if (order == 1) { // Ascending order
                if (arr[j] < arr[idx])
                    idx = j;
            }
            else { // Descending order
                if (arr[j] > arr[idx])
                    idx = j;
            }
        }
        _swap(&arr[idx], &arr[i]);
    }
}