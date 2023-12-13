#include "Header.h"

void _sort_Insertion(int arr[],int arrSize, int order);

void _insertion_Sort(int arrSize) {
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

    _sort_Insertion(arr, arrSize, order);
    
    clock_t end = clock();

    double time_taken = ((double)(end - start)) / CLOCKS_PER_SEC;

    printf("Time taken: %.4f seconds\n", time_taken);

	free(arr);
}


void _sort_Insertion(int arr[], int arrSize, int order){
    int i, key, j;
    for (i = 1; i < arrSize; i++) {
        key = arr[i];
        j = i - 1;

        /* Ascending Order */
        if (order == 1) {
            while (j >= 0 && arr[j] > key) {
                arr[j + 1] = arr[j];
                j = j - 1;
            }
        }
        /* Descending Order */
        else{
            while (j >= 0 && arr[j] < key) {
                arr[j + 1] = arr[j];
                j = j - 1;
            }
        }
        arr[j + 1] = key;
    }
}
