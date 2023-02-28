#pragma once
#include<iostream>
#include<Windows.h>
#include<conio.h>
#include<string>
using namespace std;

// di chuyển con trỏ đến tọa độ x,y
void gotoxy(short x,short y)
{
        HANDLE hConsoleOutput;
        COORD Cursor_an_Pos = { x,y};
        hConsoleOutput = GetStdHandle(STD_OUTPUT_HANDLE);
        SetConsoleCursorPosition(hConsoleOutput , Cursor_an_Pos);
} 
// Tô màu chữ
void TextColor(int color) {
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), color);
}

//Tô màu nền 
void SetBGColor(WORD color)
{
	HANDLE hConsoleOutput;
	hConsoleOutput = GetStdHandle(STD_OUTPUT_HANDLE);

	CONSOLE_SCREEN_BUFFER_INFO screen_buffer_info;
	GetConsoleScreenBufferInfo(hConsoleOutput, &screen_buffer_info);

	WORD wAttributes = screen_buffer_info.wAttributes;
	color &= 0x000f;
	color <<= 4;
	wAttributes &= 0xff0f;
	wAttributes |= color;

	SetConsoleTextAttribute(hConsoleOutput, wAttributes);
}
void ClearScreen()
{
	SetBGColor(0);
	TextColor(7);
	HANDLE                     hStdOut;
	CONSOLE_SCREEN_BUFFER_INFO csbi;
	DWORD                      count;
	DWORD                      cellCount;
	COORD                      homeCoords = { 0, 0 };

	hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);
	if (hStdOut == INVALID_HANDLE_VALUE) return;

	/* Get the number of cells in the current buffer */
	if (!GetConsoleScreenBufferInfo(hStdOut, &csbi)) return;
	cellCount = csbi.dwSize.X * csbi.dwSize.Y;

	/* Fill the entire buffer with spaces */
	if (!FillConsoleOutputCharacter(
		hStdOut,
		(TCHAR)' ',
		cellCount,
		homeCoords,
		&count
	)) return;

	/* Fill the entire buffer with the current colors and attributes */
	if (!FillConsoleOutputAttribute(
		hStdOut,
		csbi.wAttributes,
		cellCount,
		homeCoords,
		&count
	)) return;

	/* Move the cursor home */
	SetConsoleCursorPosition(hStdOut, homeCoords);
}

// xác định tọa độ tại X
int wherex()
{
	HANDLE hConsoleOutput;
	hConsoleOutput = GetStdHandle(STD_OUTPUT_HANDLE);
	CONSOLE_SCREEN_BUFFER_INFO screen_buffer_info;
	GetConsoleScreenBufferInfo(hConsoleOutput, &screen_buffer_info);
	return screen_buffer_info.dwCursorPosition.X;
}

//Xác định tọa độ tại Y
int wherey(void)
{
	HANDLE hConsoleOutput;
	hConsoleOutput = GetStdHandle(STD_OUTPUT_HANDLE);
	CONSOLE_SCREEN_BUFFER_INFO screen_buffer_info;
	GetConsoleScreenBufferInfo(hConsoleOutput, &screen_buffer_info);
	return screen_buffer_info.dwCursorPosition.Y;
}
int  GetKey1() {
	char key; key = _getch();
	if (key == -32 || key == 0)
		return -(_getch());
	else return key;
}
//*VẼ 1 KHUNG
void Box(int x, int y,string nd) {
	TextColor(14);
	for (int ix = x; ix <= x + 40; ix++) {
		gotoxy(ix, y);
		cout << char(196);
		gotoxy(ix, y + 2);
		cout << char(196);
	}
	for (int iy = y + 1; iy <= y + 1; iy++) {
		gotoxy(x, iy);
		cout << char(179);
		gotoxy(x + 40, iy);
		cout << char(179);
	}
	gotoxy(x, y); cout << char(218);
	gotoxy(x, y + 2); cout << char(192);
	gotoxy(x + 40, y); cout << char(191);
	gotoxy(x + 40, y + 2); cout << char(217);
	gotoxy(x +1, y+1 );
	TextColor(1);
	SetBGColor(7);
	cout << "                                      ";
	gotoxy(x + 1, y + 1); cout << nd;
	gotoxy(x, y);
}
//Tô màu
void ToMau(int x,int y,int mau,string nd) {
	gotoxy(x + 1, y + 1);
	TextColor(1);
	SetBGColor(mau);
	cout << "                                      ";
	gotoxy(x + 1, y + 1); cout << nd;
	gotoxy(x, y);
}