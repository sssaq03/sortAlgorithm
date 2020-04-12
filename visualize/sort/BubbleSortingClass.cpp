#include "stdafx.h"
#include "BubbleSortingClass.h"


BubbleSortingClass::BubbleSortingClass() {
}


BubbleSortingClass::~BubbleSortingClass() {
}


void BubbleSortingClass::Sort() {
	for (int level = 0; level < m_size - 1; level++) {

		for (int i = 0; i < m_size - level - 1; i++) {

			if (m_node[i] > m_node[i + 1]) {
				lineup(m_node[i], m_node[i + 1]);
			}

		}
		Render(m_node[level]);

	}

	Stop();
}


void BubbleSortingClass::lineup(int& large, int& small) {
	int save = large;
	large = small;
	small = save;
}
