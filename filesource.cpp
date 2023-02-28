#include"fileheader.h"
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

void init(st & stack)
{
    stack.p1=-1;
    stack.p2=STACK_SIZE;
}
int push(st&stack,int chon,int &x){
	if(stack.p1==stack.p2-1){
		gotoxy(40,24);
		cout<<"STACK DAY";
		Sleep(980);
		gotoxy(40,24);
		cout<<"           ";
		return 0;
	}
	gotoxy(30,1);
	cout<<"Nhap x:";
	cin>>x;
	gotoxy(30,1);
	cout<<"                        ";
    if(chon==1)stack.A[++stack.p1]=x;
    else stack.A[--stack.p2]=x;
    return 1;
}
int pop(st&stack,int chon,int &x)
{
    if(chon==1)
    {
        if(stack.p1==-1)return 0;
        else x=stack.A[stack.p1--];
    }
    else
    {
        if(stack.p2==STACK_SIZE)return 0;
        else x=stack.A[stack.p2++];
    }
    return 1;
}
void Khung()
{
    VeKhung(10,20,107,22,-1,1);
     gotoxy(11,19);
    cout<<"  0      1      2      3      4       5      6      7      8      9     10     11     12     13 ";
    gotoxy(11,21);
    cout<<"     |      |      |      |      |       |      |      |      |      |      |      |      |     ";
    	gotoxy(4,23);
		cout<<char(30);
		gotoxy(109,23);
		cout<<char(30);
}
int chuc_nang()
{
	gotoxy(0,1);
	cout<<"1.THEM PHAN TU VAO STACK 1"<<endl;
	cout<<"2.THEM PHAN TU VAO STACK 2"<<endl;
	cout<<"3.XOA PHAN TU KHOI STACK 1"<<endl;
	cout<<"4.XOA PHAN TU KHOI STACK 2"<<endl;
	cout<<"ESC.THOAT";
	return nhap_so();
}
void chay(st stack,int chon,int x)
{
    switch(chon)
	{
	case 1:{
		gotoxy(11+(stack.p1-1)*7,23);
		cout<<" ";
		gotoxy(11+stack.p1*7,23);
		cout<<char(30);
		Sleep(980);
		gotoxy(11+stack.p1*7,21);
		cout<<x;
		break;
	}
	case 2:{
		gotoxy(11+(stack.p2+1)*7,23);
	    cout<<" ";
		gotoxy(11+stack.p2*7,23);
		cout<<char(30);
		Sleep(980);
		gotoxy(11+stack.p2*7,21);
		cout<<x;
		break;
	}
	case 3:{
		gotoxy(11+(stack.p1+1)*7,21);
		cout<<"     ";
		Sleep(980);
		gotoxy(11+(stack.p1+1)*7,23);
		cout<<" ";
		gotoxy(11+(stack.p1)*7,23);
		cout<<char(30);
		break;
	}
	case 4:{
        gotoxy(11+(stack.p2-1)*7,21);
		cout<<"     ";
		Sleep(980);
		gotoxy(11+(stack.p2-1)*7,23);
		cout<<" ";
		gotoxy(11+(stack.p2)*7,23);
		cout<<char(30);
		break;
	}
	}	
    
}
