#ifndef __INCLUDED_SET1_H__
#define __INCLUDED_SET1_H__
#include <windows.h>

void SetAnisotropic(HDC, int, int, int, int);
void SetAnisotropic(HDC hdc, int cx, int cy, int _x, int _y){
	SetMapMode(hdc, MM_ANISOTROPIC);
	SetWindowExtEx(hdc, _x, _y, NULL);
	SetViewportExtEx(hdc, cx, -cy, NULL);
	SetViewportOrgEx(hdc, cx/2, cy/2, NULL);	
}

#endif 