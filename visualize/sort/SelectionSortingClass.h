#pragma once
#include "SortingBaseClass.h"
class SelectionSortingClass : public SortingBaseClass {
public:
	SelectionSortingClass();
	~SelectionSortingClass();

protected:
	void Sort() override;
	void selectionSort(int *list, const int n);
};

