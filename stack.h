//#pragma once
#include<iostream>
#include<Windows.h>
#include<conio.h>
#include<string>
#define STACK_SIZE 14
using namespace std;
void gotoxy(int x, int y) {
	COORD coord;
	coord.X = x;
	coord.Y = y;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}
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
void VeKhung(int x1, int y1,int x2,int y2,int mau_nen,int loai_khung) {
	int khung_ngang=196,khung_doc=179,goc1=218,goc2=191,goc3=192,goc4=217;
	int nen=1;
	//*****************TO MAU**************************
	if(loai_khung==0)nen=0;
	if(mau_nen!=-1)
	{
		SetBGColor(mau_nen);
		for (int ix = x1+nen; ix < x2; ix++) 
		{
			for (int iy = y1+nen; iy < y2; iy++)
			{
				gotoxy(ix,iy);
				cout<<" ";
			}
		}
		SetBGColor(0);
	}
	if(loai_khung==0)return;
	if(loai_khung==2)
	{
		khung_ngang=205;khung_doc=186;
		goc1=201;goc2=187;goc3=200;goc4=188;
	}
	for (int ix = x1+1; ix < x2; ix++) 
	{
		gotoxy(ix, y1);
		cout << char(khung_ngang);
		gotoxy(ix, y2 );
		cout << char(khung_ngang);
	}
	for (int iy = y1+1; iy < y2; iy++) 
	{
		gotoxy(x1, iy);
		cout << char(khung_doc);
		gotoxy(x2, iy);
		cout << char(khung_doc);
	}
	//*****************VE GOC************************** 
	gotoxy(x1, y1); cout << char(goc1);
	gotoxy(x2 , y1); cout << char(goc2);
	gotoxy(x1, y2 ); cout << char(goc3);
	gotoxy(x2 , y2); cout << char(goc4);
    
   return;
}
int nhap_so()
{
	char so;
	so=getch();
	if(so>='1'&&so<='5')
		return so-'0';
	else return int(so);	
}
