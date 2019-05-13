#include <windows.h>
#include "Set1.h"
#define LENX 200
#define LENY 5000
#define START -100
#define FINISH 100

char szClassName[] = "askldfjasldfjakldjfalk", szWindowName[] = "´òÓ¡º¯ÊýÍ¼Ïó"; 

LRESULT CALLBACK WndProc(HWND, UINT, WPARAM, LPARAM);
int Func(int);
int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR szCmdLine, int iCmdShow){
	WNDCLASSEX wc;
	wc.cbSize = sizeof(wc);
	wc.style = CS_HREDRAW | CS_VREDRAW;
	wc.lpfnWndProc = WndProc;
	wc.cbClsExtra = 0;
	wc.cbWndExtra = 0;
	wc.hInstance = hInstance;
	wc.hIcon = LoadIcon(NULL, IDI_APPLICATION);
	wc.hCursor = LoadCursor(NULL, IDC_ARROW);
	wc.hbrBackground = (HBRUSH)GetStockObject(WHITE_BRUSH);
	wc.lpszMenuName = NULL;
	wc.lpszClassName = szClassName;
	wc.hIconSm = NULL;
	RegisterClassEx(&wc);
	HWND hwnd = CreateWindowEx(0, szClassName, szWindowName, WS_OVERLAPPEDWINDOW,
							   CW_USEDEFAULT, CW_USEDEFAULT, CW_USEDEFAULT, CW_USEDEFAULT,
							   NULL, NULL, hInstance, NULL);
	ShowWindow(hwnd, iCmdShow);
	UpdateWindow(hwnd);
 	MSG msg;
 	while (GetMessage(&msg, NULL, 0, 0)){
	 	TranslateMessage(&msg);
	 	DispatchMessage(&msg);
	 }
	 return msg.wParam;
}

LRESULT CALLBACK WndProc(HWND hwnd, UINT message, WPARAM wp, LPARAM lp){
	HDC hdc;
	PAINTSTRUCT ps;
	RECT rt;
	int x, y;
	switch (message){
		case WM_PAINT:{
			hdc = BeginPaint(hwnd, &ps);
			GetClientRect(hwnd, &rt);
			SetAnisotropic(hdc, rt.right, rt.bottom, LENX, LENY);
			MoveToEx(hdc, -LENX, 0, NULL);
			LineTo(hdc, LENX, 0);
			MoveToEx(hdc, -LENY, 0, NULL);
			LineTo(hdc, LENY, 0);
			x = START;
			y = Func(x);
			MoveToEx(hdc, x, y, NULL);
			for (x = START + 1; x <= FINISH; ++x){
				y = Func(x);
				if (y != -2000){
					LineTo(hdc, x, y);
					MoveToEx(hdc, x, y, NULL);
				}
			}
			EndPaint(hwnd, &ps);
			return 0;
		}
		case WM_DESTROY:{
			PostQuitMessage(0);
			return 0;
		}
		default:{
			return DefWindowProc(hwnd, message, wp, lp);
		}
	}
}

int Func(int x){
	return (3 * x + 20);
}

