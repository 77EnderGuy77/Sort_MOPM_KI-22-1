#pragma once
#include <stdio.h>
#include <time.h>
#include <stdbool.h>
#include <stdlib.h>

int _get_Order();
int _get_Interval();
int _size_Pick();
void _shaker_Sort(int arrSize);
void _bogo_Sort();
void _heap_Sort(int arrSize);
void _selection_Sort(int arrSize);
void _insertion_Sort(int arrSize);
void _merge_Sort(int arrSize);
void _print(int arr[], int arrSize);