#ifndef QUICKSORT_H
#define QUICKSORT_H

#include "inventory.h"

void quicksort(struct part a[], int low, int hight);
int split(struct part a[], int low, int high);

#endif
