#include<iostream>
#include<string>
#include<conio.h>
#include<thread>
#include"ThuVien.h"
#include <unistd.h>
#include<math.h>
using namespace std;
#define Queue_size 8
int current=1,stop=0;
char k;
struct node{
	int data;
	int priority;
	node*next;
};
struct Queue{
	node*front,*rear;
	bool empty()
	{
		return front==NULL;
	}
}; 
Queue q;
void Init(Queue&q)
{
	q.front=NULL;
	q.rear=NULL;
}
void Insert(Queue&q,int n,int p)
{
	node *moi=new node();
	moi->data=n;
	moi->priority=p;
	if(q.front==NULL&&q.rear==NULL){
		q.front=moi;
		q.rear=moi;
	}
	else
	{
	node*run=q.front;
	node *flow_run=NULL;
	for(;run!=NULL&&run->priority<p;flow_run=run,run=run->next);
	if(run==NULL){
		q.rear=moi;
	   flow_run->next=moi;
	   moi->next=run;		
	}else if(p==run->priority&&run->data==n)return;
	else if(run==q.front)
	{
		moi->next=q.front;
		q.front=moi;
	}
	else{
	flow_run->next=moi;
	moi->next=run;			
	}

	}
}
int Delete(Queue&q,int&n,int &pri)
{
	node*temp;
	if(q.front==NULL||q.rear==NULL)return 0;
	else if(q.front!=NULL&&q.front==q.rear)
	{
	    n=q.front->data;
    	pri=q.front->priority;
    	temp=q.front;
		q.front=NULL;
		q.rear=NULL;
	}
	else
    {
    	n=q.front->data;
    	temp=q.front;
     	pri=q.front->priority;
    	q.front=q.front->next;
    	
	}
	delete temp;
	return 1;
}

void velai(int &i,int a){
	Box(40,i*3,"");
	if(a==0)i--;
    else i++;
	ToMau(40,i*3,5,"*****************||****************");
}
void control(){
	gotoxy(4,7);
	cout<<"BANG DIEU KHIEN";
	gotoxy(8,8);
	cout<<"1 2 3 ";
	gotoxy(8,9);
	cout<<"4 5 6";
	gotoxy(8,10);
	cout<<"7 8 9";
	gotoxy(14,8);
	cout<<char(17)<<char(16);
	gotoxy(14,9);
	cout<<char(16)<<char(17);
}
void vethang(){
	for(int i=1;i<=8;i++)
    {
    Box(40,i*3,"");
    }
    ToMau(40,1*3,5,"*****************||****************");
}
void mocua(int i){
	ToMau(40,i*3,5,"*****************||****************");
	Sleep(500);
	ToMau(40,i*3,5,"***************|    |***********");
	Sleep(500);
	ToMau(40,i*3,5,"*************|        |*********");
	Sleep(500);
	ToMau(40,i*3,5,"**********|                |*****");
	Sleep(500);
	ToMau(40,i*3,5,"******|                     |***");
	Sleep(500);
	ToMau(40,i*3,5,"*****|                        |**");
	Sleep(500);
	ToMau(40,i*3,5,"|                                 |");
	 
}
void dongcua(int i){
	ToMau(40,i*3,5,"|                                 |");
	Sleep(500);
	ToMau(40,i*3,5,"*****|                        |**");
	Sleep(500);
	ToMau(40,i*3,5,"******|                     |***");
	Sleep(500);
	ToMau(40,i*3,5,"*********|                |*****");
	Sleep(500);
	ToMau(40,i*3,5,"*************|        |*********");
	Sleep(500);
	ToMau(40,i*3,5,"***************|    |***********");
	Sleep(500);
	ToMau(40,i*3,5,"*****************||****************");
}
void Hien_thi(){
	control();
    vethang();
}
void songuyen(int &a,char k){
	gotoxy(0,0);
	SetBGColor(0);cout<<"                   ";
	switch(k)
	{
		case 49:{
			a=1;
			break;
		}
		case 50:
		{
			a=2;
			break;
		}
		case 51:
		{
			a=3;
			break;
		}
		case 52:
		{
			a=4;
			break;
		}
		case 53:
		{
			a=5;
			break;
		}
		case 54:
		{
			a=6;
			break;
		}
		case 55:
		{
			a=7;
			break;
		}
		case 56:
		{
			a=8;
			break;
		}

		default:{
			gotoxy(0,0);
			SetBGColor(0);
			cout<<"NGUOI DUNG NHAP SAI"<<endl;
			break;
		}
	}
}
void cau_thang_chay()
{
	int x=0,pri;
	while(stop==0)
	{
	    if(!q.empty()) Delete(q,x,pri);
		while(current!=x&&x!=0)
		{
			if(!q.empty()&&pri>q.front->priority){
				Insert(q,x,pri);
				Delete(q,x,pri);
			}
			if(current<x){
				Sleep(980);
				velai(current,1);
			}
			if(current>x){
				Sleep(980);
				velai(current,0);
			}
		}
			if(x==current)
			{
			mocua(current);
			dongcua(current);
			x=0;
			}
	}
}

void dieukhien(Queue &q){
	int a=0,i=0;
	while((k=getch())!=27)
	{
		songuyen(a,k);
		Insert(q,a,abs(a-current));
	}
	stop=1;
}
void run()
{
	thread t;
	Init(q);
	Hien_thi();
	t=thread(cau_thang_chay);
	dieukhien(q);
	t.join();
}
void show(){
	node*run=q.front;
	while(run!=NULL){
		cout<<run->data<<" ";
		run=run->next;
	}
}
int main(){
run();
 }
