#include<graphics.h>
#include <conio.h>
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

void Bai1() {

	int n;
	printf("Chosee path 1,2: ");
	scanf("%d",&n);

	if(n==1) {
		initwindow(800,800);

		for(int i=0; i<16; i++) {
			setcolor(i);
			outtextxy(100, 10+40*i, "Xin chao mau thu k");
		}

		int points1[]= {0,0,90,0,90,700,0,700,0,0};
		setfillstyle(USER_FILL, GREEN);
		fillpoly(5, points1);

		int points2[]= {250,0,340,0,340,700,250,700,250,0};
		setfillstyle(USER_FILL, BLUE);;
		fillpoly(5, points2);

		getch();
	} else if(n==2) {
		initwindow(800,800);

		for(int i=0; i<16; i++) {
			setcolor(i);
			outtextxy(100+20*i,10, "X");
		}

		getch();
	}

}

void Bai2() {
	int n;
	printf("1.Pixel 2.Line: ");
	scanf("%d",&n);
	if(n==1 ) {
		//int graphicdriver=DETECT,graphicmode;
		//initgraph(&graphicdriver,&graphicmode, "C:\\TC\\BGI");
		initwindow(800,800);

		for(int i=0; i<=300; i++) { //20,0 20,300
			putpixel(20,i,RED);
		}

		for(int i=40; i<=300; i++) { //40,10 300,10
			putpixel(i,10,BLUE);
		}

		for(int i=100; i<=270; i++) { //100,100 270,90
			putpixel(i,(int)(-i/17+1800/17),YELLOW);
		}

		getch();
	} else {
		//int graphicdriver=DETECT,graphicmode;
		//initgraph(&graphicdriver,&graphicmode, "C:\\TC\\BGI");
		initwindow(800,800);

		setcolor(RED);
		line(20,0,20,300);

		setcolor(BLUE);
		line(40,10,300,10);

		setcolor(YELLOW);
		line(100,100,270,90);

		getch();
	}
}

void Bai3() {
	printf("Input 2 point x1,y1,x2,y2: ");
	int x1,y1,x2,y2;
	scanf("%d%d%d%d",&x1,&y1,&x2,&y2);

	initwindow(800,800);

	setcolor(RED);
	line(x1,y1,x2,y2);

	setcolor(BLUE);
	line(x1+20,y1+20,x2+20,y2+20);

	setcolor(YELLOW);
	line(x1,y1,(y2-y1)*(y2+100)/(x1-x2),y2+100);

	getch();

}

void Bai4() {

	initwindow(800,800);

	setfillstyle(USER_FILL, BLUE);
	fillellipse(300, 300, 200, 100);

	int points1[]= {150,250,450,250,450,350,150,350,150,250};
	setfillstyle(USER_FILL, RED);
	fillpoly(5, points1);

	setfillstyle(USER_FILL, GREEN);
	fillellipse(300, 300, 50, 50);

	getch();
}

void Bai5() {
	initwindow(800,800);

	//for(int i=50;i<=150;i++)
	//putpixel(i,sin(i),RED);
	
	double x, y;
	int angle = 0;
	for(x = 0; x < getmaxx(); x+=3) {

		y = 50*sin(angle*3.141/180);
		y = getmaxy()/2 - y;

		putpixel(x, y, 15);

		angle+=5;
	}
	
	for(x = 0; x < getmaxx(); x+=3) {

		y = 50*sin(angle*3.141/180);
		y = getmaxy()/2 - y;

		putpixel(y, x, 1);

		angle+=5;
	}
	
	for(x = 0; x < getmaxx(); x+=3) {

		y = 50*sin(angle*3.141/180);
		y = getmaxy()/2 - y;

		putpixel(y-20, x, 3);

		angle+=5;
	}

	getch();
}
int main() {
	//Bai1();
	//Bai2();
	//Bai3();
	//Bai4();
	Bai5();
}
