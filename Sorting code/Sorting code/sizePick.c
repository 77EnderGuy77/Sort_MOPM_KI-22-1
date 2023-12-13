#include "Header.h"

int _size_Pick() {
	int arr_size, choice = 0;
	printf("Choose the size of the array(not for Bogo Sort): \n\
	1 - 10\n\
	2 - 100\n\
	3 - 1 000\n\
	4 - 10 000\n\
	5 - 100 000\n\
	6 - 1 000 000\n\
	Enter here: ");
	scanf_s("%d", &choice);
	printf("\n");
	switch (choice)
	{
	case 1: arr_size = 10; break;
	case 2: arr_size = 100; break;
	case 3: arr_size = 1'000; break;
	case 4: arr_size = 10'000; break;
	case 5: arr_size = 100'000; break;
	case 6: arr_size = 1'000'000; break;
	default: arr_size = 0; break;
	}
	return arr_size;
}