#include "Header.h"

void _merge_sort_rec(int arr[], int left, int right, int order);
void _merge_sorted_arr(int arr[], int left, int mid, int right, int order);

void _merge_Sort(int arrSize){

	int* arr = (int*)malloc(arrSize * sizeof(int));

	if (arr == NULL) {
		printf("Memory allocation failed.\n");
		return;
	}

	int order;
	//in reverse order or not
	order = _get_Order();

	int interval;
	// interval from 41 or 2001
	interval = _get_Interval();

	srand((unsigned int)time(NULL));
	for (int i = 0; i < arrSize; i++) {
        arr[i] = (rand() % (2 * interval)) - interval + 1;
    }
    clock_t start = clock();

	_merge_sort_rec(arr, 0, arrSize - 1, order);
 
    clock_t end = clock();

    double time = ((double)(end - start)) / CLOCKS_PER_SEC;

    printf("Time taken: %.4f seconds\n", time);

	free(arr);
}

void _merge_sort_rec(int arr[], int left, int right, int order) {
    if (left < right) {
        int mid = left + (right - left) / 2;

        _merge_sort_rec(arr, left, mid, order);
        _merge_sort_rec(arr, mid + 1, right, order);

        _merge_sorted_arr(arr, left, mid, right, order);
    }
}


void _merge_sorted_arr(int arr[], int left, int mid, int right,int order){
    int i, j, k;
    int n1 = mid - left + 1;
    int n2 = right - mid;

    int* temp_left = malloc(n1 * sizeof(int));
    int* temp_right = malloc(n2 * sizeof(int));

    if (temp_left == NULL || temp_right == NULL) {
        printf("Memory allocation failed.\n");
        return;
    }

    for (i = 0; i < n1; i++)
        temp_left[i] = arr[left + i];
    for (j = 0; j < n2; j++)
        temp_right[j] = arr[mid + 1 + j];

    i = 0;
    j = 0;
    k = left;

    if (1 == order) {
        while (i < n1 && j < n2) {
            if (temp_left[i] <= temp_right[j]) { 
                arr[k] = temp_left[i];
                i++;
            }
            else {
                arr[k] = temp_right[j];
                j++;
            }
            k++;
        }
    }
    else {
        while (i < n1 && j < n2) {
            if (temp_left[i] >= temp_right[j]) { 
                arr[k] = temp_left[i];
                i++;
            }
            else {
                arr[k] = temp_right[j];
                j++;
            }
            k++;
        }
    }

    while (i < n1) {
        arr[k] = temp_left[i];
        i++;
        k++;
    }

    while (j < n2) {
        arr[k] = temp_right[j];
        j++;
        k++;
    }
    free(temp_left);
    free(temp_right);
}
