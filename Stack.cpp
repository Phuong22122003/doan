#include"stack.h"
struct Stack{
    int p1,p2;
    int A[STACK_SIZE];
};
typedef Stack st;
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
int main()
{
	int i,x=0,run;
	st stack;
	init(stack);
	Khung();
	thread timer;
	while(true)
  {
	i=chuc_nang();
	switch(i)
	{
	case 1:	{
	run=push(stack,1,x);
		break;
	   }
	case 2: {
		run=push(stack,2,x);
		break;
	   }
	case 3:{
	    run=	pop(stack,1,x);
		break;
	   }
	case 4:{
	    run=pop(stack,2,x);
		break;
	   }
	case 27:break;
	default :{
		gotoxy(0,7);
		cout<<"NGUOI DUNG NHAP SAI";
		Sleep(980);
		gotoxy(0,7);
		cout<<"                    ";
		break;
	    }
    }
   if(run==1)chay(stack,i,x);
   if(i==27)break;
  }
}
