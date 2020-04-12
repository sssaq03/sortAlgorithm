#pragma once
class SortingBaseClass {
public:
	SortingBaseClass();
	virtual ~SortingBaseClass();

	void Update();

	void Start();
	void Stop();

	void SetDelay(int delay);
	void SetNode(int* node, int size);
	void SetNode(int size);
	void SethWnd(HWND hWnd);

protected:
	void Render(int node);
	virtual void Sort() = 0;

private:
	void BeginDraw();
	void EndDraw();
	void DrawRect(RECT pos, int color) const;


protected:
	bool b_isStart = false;
	int m_delay = 10;

	int* m_node = nullptr;
	int m_size = 0;

	int m_width = 0;
	int m_height = 0;

	int m_max = 0;
	int m_min = 0;

private:
	HWND m_hWnd = nullptr;
	HDC m_hdc = nullptr;
	HDC memHdc = nullptr;
	HBITMAP memHbm, omemHbm;
	HBRUSH bgBrush;

	RECT m_rectSize;

	int m_beepSnd = 1;
};