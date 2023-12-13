#include "Header.h"

void _sort_Bogo(int arr[], int arrSize, int order);
int _is_Sorted(int arr[], int arrSize, int order);
void _shuffle(int arr[], int arrSize);
int _size_Bogo();

void _bogo_Sort() {
    int arrSize = _size_Bogo();
    int* arr = (int*)calloc(arrSize, sizeof(int));

    if (arr == NULL) {
        printf("Memory allocation failed.\n");
        return;
    }

    srand((unsigned int)time(NULL));
    int interval = _get_Interval();

    for (int i = 0; i < arrSize; i++) {
        arr[i] = (rand() % (2 * interval)) - interval + 1;
    }

    int order = _get_Order(); // Get user's choice for order

    clock_t start = clock();

    _sort_Bogo(arr, arrSize, order);

    clock_t end = clock();

    double time = ((double)(end - start)) / CLOCKS_PER_SEC;
    printf("Time taken: %.4f seconds\n", time);

    free(arr);
}

int _is_Sorted(int arr[], int arrSize, int order) {
    for (int i = 0; i < arrSize - 1; i++) {
        if (order == 0) { // Ascending order
            if (arr[i] > arr[i + 1]) {
                return 0;
            }
        }
        else { // Descending order
            if (arr[i] < arr[i + 1]) {
                return 0;
            }
        }
    }
    return 1;
}

void _shuffle(int arr[], int arrSize) {
    for (int i = arrSize - 1; i > 0; i--) {
        int j = rand() % (i + 1);
        int temp = arr[i];
        arr[i] = arr[j];
        arr[j] = temp;
    }
}

void _sort_Bogo(int arr[], int arrSize, int order) {
    while (!_is_Sorted(arr, arrSize, order)) {
        _shuffle(arr, arrSize);
    }
}

int _size_Bogo() {
    int pick = 0, Size;
    printf("What type of sort do you want?\n\
		1 - 10\n\
		2 - 11\n\
		3 - 12\n\
		4 - 13\n\
		5 - 14\n\
		6 - 15\n\
		Enter here:");
    scanf_s("%d", &pick);

    switch (pick)
    {
    case 1: Size = 10; break;
    case 2: Size = 11; break;
    case 3: Size = 12; break;
    case 4: Size = 13; break;
    case 5: Size = 14; break;
    case 6: Size = 15; break;
    default: Size = 0; break;
    }
    return Size;
}
