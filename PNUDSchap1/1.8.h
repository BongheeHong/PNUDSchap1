#pragma once
#include "swap.h"


void SelectionSort(int *a, const int n)
{
	for (int i = 0; i < n; i++)
	{
		int j = i;
		for (int k = i + 1; k < n; k++)
			if (a[k] < a[j])	j = k;
		swap(a[i], a[j]);
	}
}