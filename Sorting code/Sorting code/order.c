#include "Header.h"

int _get_Order() {
    int order;
    printf("In what order you want to sort array\n\
    1 - increasing \n\
    0 - decreasing \n\
    Enter here: ");
    scanf_s("%d", &order);
    printf("\n");
    while (order != 0 && order != 1) {
        printf("Please enter either 0 or 1 for the order: ");
        scanf_s("%d", &order);
    }
    return order;
}