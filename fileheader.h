#include<iostream>
#include<Windows.h>
#include<conio.h>
#include<string>
#include"fileheader1.h"
using namespace std;
void gotoxy(int x, int y);
void VeKhung(int x1, int y1,int x2,int y2,int mau_nen,int loai_khung);
int nhap_so();
void init(st & stack);
int push(st&stack,int chon,int &x);
int pop(st&stack,int chon,int &x);
void Khung();
int chuc_nang();
void chay(st stack,int chon,int x);
