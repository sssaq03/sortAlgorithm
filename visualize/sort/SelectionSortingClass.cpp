#include "stdafx.h"
#include "SelectionSortingClass.h"


SelectionSortingClass::SelectionSortingClass() {}


SelectionSortingClass::~SelectionSortingClass() {}


void SelectionSortingClass::Sort() {

	selectionSort(m_node, m_size);

	Stop();
}


void SelectionSortingClass::selectionSort(int* list, const int n) {

	int i, j, indexMin, temp;

	for (i = 0; i < n; i++) {
		if (!b_isStart) break;
		indexMin = i;
		for (j = i + 1; j < n; j++) {
			if (list[j] < list[indexMin]) {
				indexMin = j;
			}
		}
		Render(list[j]);

		temp = list[indexMin];
		list[indexMin] = list[i];
		list[i] = temp;
	}

}
