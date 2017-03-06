#include <iostream>
#include <Windows.h>
#include <ctime>
#define RIGHT 1
#define LEFT 2
#define UP 4
#define DOWN 8
using namespace std;

struct cell{
	int way;
};

int dice(int min, int max);
void printLabirint(cell** labirint, int length, int width);
void preProc(cell** labirint, int length, int width);
cell** labirintEller(int length, int width);

int main(){
SetConsoleCP(1251);
SetConsoleOutputCP(1251);
SetConsoleTitle("Default title");
CONSOLE_FONT_INFOEX font;
font.cbSize=sizeof(font);
font.dwFontSize.X=14;
font.dwFontSize.Y=14;
font.FontWeight=FW_NORMAL;
font.FontFamily=54;
font.nFont=100;
wcscpy(font.FaceName, L"Lucida Console");
SetCurrentConsoleFontEx(GetStdHandle(STD_OUTPUT_HANDLE), false, &font);
//srand(time(0));
//for (int i = 0; i < 10; i++)
//	cout<<dice(0, 1)<<" ";
cout<<endl;
int length, width;
length = 4;
width = 4;
cell** labirint = labirintEller(length, width);
cout<<"Лабиринт:"<<endl;
printLabirint(labirint, length, width);

system("pause");
return 0;
}

cell** labirintEller(int length, int width){
	cell** labirint = new cell* [length];
	int* marker = new int [width];
	for(int i = 0; i < width; i++)
		marker[i] = i;
	for (int i = 0; i < length; i++){
		labirint[i] = new cell [width];
		for (int j = 0; j < width; j++){
			labirint[i][j].way = 0;
		}
	}
	int id = width;
	preProc(labirint, length, width);
	srand(time(0));
	for (int i = 0; i < length - 1; i++){
		cout<<"до"<<endl;//////////////////////////////
		for (int j = 0; j < width; j++)////////////////////////////
			cout<<marker[j]<<" ";///////////////
		cout<<endl;////////////////////
		for (int j = 0; j < width - 1; j++){
			if (marker[j] == marker[j + 1])
				labirint[i][j].way |= RIGHT;
		}
		for (int j = 0; j < width - 1; j++){
			if (dice(0, 4))
				labirint[i][j].way |= RIGHT;
			else
				marker[j + 1] = marker[j];
		}
		cout<<"Правые границы"<<endl;//////////////////////////////
		for (int j = 0; j < width; j++)////////////////////////////
			cout<<marker[j]<<" ";///////////////
		cout<<endl;////////////////////
		for (int j = 0; j < width; j++){
			if (dice(0, 4) && ((marker[j] == marker[j + 1] && !j) || (marker[j] == marker[j - 1] && j))){
				labirint[i][j].way |= DOWN;
				marker[j] = id++;
			}
		}
		cout<<"низ"<<endl;//////////////////////////////
		for (int j = 0; j < width; j++)////////////////////////////
			cout<<marker[j]<<" ";///////////////
		cout<<endl;////////////////////
	}
	for (int j = 0; j < width - 1; j++){
		if (marker[j] == marker[j + 1])
			labirint[length - 1][j].way |= RIGHT;
	}
	delete []marker;
	return labirint;
}

void printLabirint(cell** labirint, int length, int width){
	for (int i = 0; i < width; i++)
		cout<<" _";
	cout<<endl;
	for (int i = 0; i < length; i++){
		cout<<"|";
		for (int j = 0; j < width; j++){
			if (labirint[i][j].way & DOWN)
				cout<<"_";
			else
				cout<<" ";
			if (labirint[i][j].way & RIGHT)
				cout<<"|";
			else
				cout<<" ";
		}
		cout<<endl;
	}
}

int dice(int min, int max){
	return min + rand()%(max + 1 - min);
}

void preProc(cell** labirint, int length, int width){
	for (int i = 0; i < length; i++){
		labirint[i][0].way |= LEFT;
		labirint[i][width-1].way |= RIGHT;
	}
	for (int i = 0; i < width; i++){
		labirint[0][i].way |= UP;
		labirint[length-1][i].way |= DOWN;
	}
}

