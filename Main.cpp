#include"fileheader.h"
//#include"fileheader1.h"
int main()
{
	int i,x=0,run;
	st stack;
	init(stack);
	Khung();
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
