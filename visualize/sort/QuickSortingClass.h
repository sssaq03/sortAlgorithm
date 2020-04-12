#pragma once
#include "SortingBaseClass.h"
class QuickSortingClass : public SortingBaseClass {
public:
	QuickSortingClass();
	~QuickSortingClass();

protected:

	void Sort() override;
	void quickSort(int left, int right);
};

