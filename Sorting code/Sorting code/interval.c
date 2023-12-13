#include "Header.h"

int _get_Interval() {
    int interval, temp_intr;

    printf("Do you want:\n\
    1 - small interval(-20 - 20)\n\
    0 - big interval(-1000 - 1000)\n\
    Enter here: ");
    scanf_s("%d", &temp_intr);
    printf("\n");
    // Validating interval input
    while (temp_intr != 0 && temp_intr != 1) {
        printf("Please enter either 1 or 0 for the interval choice: ");
        scanf_s("%d", &temp_intr);
    }

    switch (temp_intr) {
    case 0:
        interval = 1001;
        break;
    case 1:
        interval = 21;
        break;
    default:
        printf("Invalid interval choice\n");
        return -1; // Returning -1 for an invalid interval choice
    }

    return interval;
}