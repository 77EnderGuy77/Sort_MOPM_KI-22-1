#include "Header.h"

int main() {
	int choice;
	int arrSize;
	int exit = 0;

	do {
		printf("What type of sort do you want?\n\
		1 - Shaker Sort\n\
		2 - Merge Sort\n\
		3 - Insertion Sort\n\
		4 - Double Selection Sort\n\
		5 - Heap Sort\n\
		6 - Bogo Sort(only from 10 to 20)\n\
		Enter here: ");
		scanf_s("%d", &choice);

		if(choice != 6)	arrSize = _size_Pick();
		

	switch (choice)
	{
	case 1: _shaker_Sort(arrSize); break;
	case 2: _merge_Sort(arrSize); break;
	case 3: _insertion_Sort(arrSize); break;
	case 4: _selection_Sort(arrSize); break;
	case 5: _heap_Sort(arrSize); break;
	case 6: _bogo_Sort(); break;
	default: printf("NO CODE WAS RUNNED\n"); break;
	}

	printf("Do you want to exit?\n\
	1 - yes \n\
	0 - no\n\
	Enter here: ");
	scanf_s("%d", &exit);
	} while (exit != 1);
	return 0;
}
