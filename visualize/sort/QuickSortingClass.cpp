#include "stdafx.h"
#include "QuickSortingClass.h"


QuickSortingClass::QuickSortingClass() {}


QuickSortingClass::~QuickSortingClass() {}


void QuickSortingClass::Sort() {

	quickSort(0, m_size);

	Stop();
}




void QuickSortingClass::quickSort(int left, int right) {

	if (!b_isStart) return;

	int i = left, j = right;
	int pivot = m_node[(left + right) / 2];
	int temp;
	do {
		if (!b_isStart) break;
		while (m_node[i] < pivot)
			i++;
		while (m_node[j] > pivot)
			j--;
		if (i <= j) {
			temp = m_node[i];
			m_node[i] = m_node[j];
			m_node[j] = temp;
			i++;
			j--;
		}

		Render(0);
	} while (i <= j);

	/* recursion */
	if (left < j)
		quickSort(left, j);

	if (i < right)
		quickSort(i, right);
}
