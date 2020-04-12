#pragma once
#include "SortingBaseClass.h"

class BubbleSortingClass : public SortingBaseClass {
public:
	BubbleSortingClass();
	~BubbleSortingClass();


protected:
	void Sort() override;

private:
	static void lineup(int& large, int& small);
};
