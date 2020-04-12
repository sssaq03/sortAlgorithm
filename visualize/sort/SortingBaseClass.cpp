#include "stdafx.h"
#include "SortingBaseClass.h"


SortingBaseClass::SortingBaseClass() {}


SortingBaseClass::~SortingBaseClass() {

	if(m_node != nullptr) {
		delete[] m_node;
		m_node = nullptr;
	}

	DeleteDC(m_hdc);
	ReleaseDC(m_hWnd, m_hdc);

}


void SortingBaseClass::Render(int node) {

	if (!b_isStart) return;

	if(GetAsyncKeyState(VK_ESCAPE)) {
		Stop();
		return;
	}
	
	BeginDraw();

	int rectWidth = m_width / m_size;
	int rectHeight = m_height / m_max;

	for(int i = 0; i < m_size; i++) {
		RECT rc = RECT{ rectWidth*i, (m_max - m_node[i]) * rectHeight,
						rectWidth*(i + 1), m_height };

		if(m_node[i] == node) {
			DrawRect(rc, 0xff0000);
		}else {
			DrawRect(rc, 0);
		}
		

	}

	EndDraw();

	//Beep(m_beepSnd * node, m_delay);
	Sleep(m_delay);

}


void SortingBaseClass::Update() {

	if (!b_isStart) return;

	Sort();

}


void SortingBaseClass::Start() {
	b_isStart = true;
}


void SortingBaseClass::Stop() {
	b_isStart = false;
}


void SortingBaseClass::SetDelay(int delay) {
	m_delay = delay;
}


void SortingBaseClass::SetNode(int* node, int size) {
	m_node = node;
	m_size = size;
}


void SortingBaseClass::SetNode(int size) {

	if (m_node != nullptr) {
		delete[] m_node;
		m_node = nullptr;
	}

	m_node = new int[size + 1];
	m_size = size;
	m_min = 0;
	m_max = size;

	m_beepSnd = 1000 / m_max - m_min;

	for(int i = 0; i < size; i++) {
		m_node[i] = -1;
	}

	for(int i = m_min; i <m_max; i++) {
		
		while(true) {
			int index = rand() % size;

			if (m_node[index] >= m_min) continue;

			m_node[index] = i;
			break;
		}
	}

}


void SortingBaseClass::SethWnd(HWND hWnd) {
	RECT rc;
	GetClientRect(hWnd, &rc);
	m_width = rc.right;
	m_height = rc.bottom;


	m_hWnd = hWnd;
	m_hdc = GetDC(hWnd);
	CreateSolidBrush(RGB(255, 0, 255));
}


void SortingBaseClass::BeginDraw() {
	RECT size = { 0, 0, GetSystemMetrics(SM_CXSCREEN), GetSystemMetrics(SM_CYSCREEN) };
	memHdc = CreateCompatibleDC(m_hdc);
	memHbm = CreateCompatibleBitmap(m_hdc, GetSystemMetrics(SM_CXSCREEN), GetSystemMetrics(SM_CYSCREEN));
	omemHbm = (HBITMAP)SelectObject(memHdc, memHbm);
	FillRect(memHdc, &size, bgBrush);
}


void SortingBaseClass::EndDraw() {
	BitBlt(m_hdc, 0, 0, GetSystemMetrics(SM_CXSCREEN), GetSystemMetrics(SM_CYSCREEN), memHdc, 0, 0, SRCCOPY);
	SelectObject(memHdc, omemHbm);
	DeleteObject(memHbm);
	DeleteObject(omemHbm);
	DeleteDC(memHdc);
}


void SortingBaseClass::DrawRect(RECT pos, int color) const {

	SetTextColor(memHdc, color);
	Rectangle(memHdc, pos.left, pos.top, pos.right, pos.bottom);

}
