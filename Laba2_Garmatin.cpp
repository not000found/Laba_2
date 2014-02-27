/*
Несколько изменений внёс, то что было на языке С, исправил на С++.
*/


//#include "stdafx.h"     //Можно вообще убрать
#include <iostream>
#include <cmath> 	//Так записывается в С++ библ. <mach.h>. P.S. И если не ошибаюсь, в этой чуть чуть больше функций.
#include <ctype.h>


float pper(float, float, float);
float square(float, float, float, float);
float high(float, float, float, float);
float median(float, float, float);
float bisek(float, float, float, float);
float chek(float);

using namespace std;

int main()
{
	setlocale(LC_ALL, "Russian");
	float a, b, c, p, sq, hig, med, bis, ch = 0;
	char quest;

beg:
ask :
	cout << "Введите стороны треугольника: \n";
	cout << "A: "; cin >> a;

	ch = chek(a);                                                   //Проверка на букву А
	if (ch == 1){
		cout << "Вы ввели сивол или букву. Введите число.\n\n";
		system("pause");					//Тоже что и _getch(), находится в библиотеке <iostream>
		system("cls");
		goto beg;
	}


	cout << "B: "; cin >> b;
	ch = chek(b);                                                   //Проверка на букву B
	if (ch == 1){
		cout << "Вы ввели сивол или букву. Введите число.\n\n";
		system("pause");
		system("cls");
		goto beg;
	}


	cout << "C: "; cin >> c;
	ch = chek(c);                                                    //Проверка на букву C
	if (ch == 1){
		cout << "Вы ввели сивол или букву. Введите число.\n\n";
		system("pause");
		system("cls");
		goto beg;
	}



	if (a < 1 || b < 1 || c < 1){                                   //Проверака сторон > 0
		cout << "Одна или несколько сторон меньше 1. Повторите ввод.\n";
		system("pause");
		system("cls");
		goto beg;
	}


	if (!((a + b) > c) || !((a + c) > b) || !((b + c) > a)){              //Проверка на существования треугольника
		cout << "Треугольника с такими сторонами существовать не может. Повторите ввод.\n";
		system("pause");
		system("cls");
		goto beg;
	}


	system("cls");
	cout << "У треугольника стороны\n";                             //Глав. меню
	cout << "A-" << a << "\n";
	cout << "B-" << b << "\n";
	cout << "C-" << c << "\n\n";
ask2:
	cout << "Что найти?\n";
	cout << "1. Площадь\n";
	cout << "2. Периметр\n";
	cout << "3. Высоты\n";
	cout << "4. Медианы\n";
	cout << "5. Бисектрисы\n";
	cout << "6. Повторить ввод сторон\n";
	cout << "7. Выйти\n";
	cin >> quest;

	p = pper(a, b, c);
	switch (quest) {
	case '1':                                                         //Площадь
		sq = square(a, b, c, p);
		system("cls");
		cout << "У треугольника стороны\n";
		cout << "A-" << a << "\n";
		cout << "B-" << b << "\n";
		cout << "C-" << c << "\n\n";
		cout << "Площадь треугольника " << sq << "\n\n\n";
		goto ask2;

	case'2':                                                           //Периметр
		ch = 2 * p;
		system("cls");
		cout << "У треугольника стороны\n";
		cout << "A-" << a << "\n";
		cout << "B-" << b << "\n";
		cout << "C-" << c << "\n\n";
		cout << "Периметр треугольника " << ch << "\n\n\n";
		goto ask2;

	case'3':                                                            //Высоты
		hig = high(a, b, c, p);
		system("cls");
		cout << "У треугольника стороны\n";
		cout << "A-" << a << "\n";
		cout << "B-" << b << "\n";
		cout << "C-" << c << "\n\n";
		cout << "Высота треугольника " << hig << "\n\n\n";
		goto ask2;

	case'4':                                                            //Медианы
		med = median(a, b, c);
		system("cls");
		cout << "У треугольника стороны\n";
		cout << "A-" << a << "\n";
		cout << "B-" << b << "\n";
		cout << "C-" << c << "\n\n";
		cout << "Медиана треугольника " << med << "\n\n\n";
		goto ask2;

	case'5':
		bis = bisek(a, b, c, p);
		system("cls");
		cout << "У треугольника стороны\n";
		cout << "A-" << a << "\n";
		cout << "B-" << b << "\n";
		cout << "C-" << c << "\n\n";
		cout << "Бисектриса треугольника " << bis << "\n\n\n";
		goto ask2;

	case'6':
		system("cls");
		goto ask;


	case'7':
		system("cls");
		goto fin;

	}

fin:
	return 0;
}

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////										    Описание функций										    /////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

float chek(float val){               //Функция проверки на букву
	float ch;
	if (cin.good()){
		ch = 0;
	}
	else {
		ch = 1;
	}
	cin.clear();
	_flushall();
	return (ch);
}


float pper(float a, float b, float c){      //Функция нахождения полупериметра
	float p;
	p = (a + b + c) / 2;
	return(p);
}


float square(float a, float b, float c, float p){     //Функция нахождения площади
	float sq;
	sq = sqrt(p*(p - a)*(p - b)*(p - c));
	return(sq);
}


float high(float a, float b, float c, float p){              //Функция нахождения высот
	float hig;
	char quest;
ask:

	cout << "\nК какой стороне проведена искомая высота?\n";
	cin >> quest;
	if (quest == 'a' || quest == 'A'){
		hig = (2 * sqrt(p*(p - a)*(p - b)*(p - c))) / a;
		quest = 'A';
	}
	else if (quest == 'b' || quest == 'B'){
		hig = (2 * sqrt(p*(p - a)*(p - b)*(p - c))) / b;
		quest = 'B';
	}
	else if (quest == 'c' || quest == 'C'){
		hig = (2 * sqrt(p*(p - a)*(p - b)*(p - c))) / c;
		quest = 'C';
	}
	else {
		cout << "Такой стороны не существует. Введите существующую сторону.\n";
		goto ask;
	}

	return (hig);
}



float median(float a, float b, float c){                            // Функция нахождения медиан
	float med;
	char quest;
	float a2;
	float b2;
	float c2;
	a2 = pow(a, 2);
	b2 = pow(b, 2);
	c2 = pow(c, 2);

ask:
	cout << "\nК какой стороне проведена искомая медиана?\n";
	cin >> quest;
	if (quest == 'a' || quest == 'A'){
		med = (sqrt(2 * b2 + 2 * c2 - a2) / 2);
		quest = 'A';
	}
	else if (quest == 'b' || quest == 'B'){
		med = (sqrt(2 * a2 + 2 * c2 - b2) / 2);
		quest = 'B';
	}
	else if (quest == 'c' || quest == 'C'){
		med = (sqrt(2 * b2 + 2 * a2 - c2) / 2);
		quest = 'C';
	}
	else {
		cout << "Такой стороны не существует. Введите существующую сторону.\n";
		goto ask;
	}

	return (med);
}

float bisek(float a, float b, float c, float p){                // Функция нахождения бисектрис
	float bis;
	char quest;
ask:
	cout << "\nК какой стороне проведена искомая бисектриса?\n";
	cin >> quest;
	if (quest == 'a' || quest == 'A'){
		bis = (sqrt(b*c*p*(p - a))) * 2 / (b + c);
		quest = 'A';
	}
	else if (quest == 'b' || quest == 'B'){
		bis = (sqrt(a*c*p*(p - b)) * 2 / (a + c));
		quest = 'B';
	}
	else if (quest == 'c' || quest == 'C'){
		bis = (sqrt(a*b*p*(p - c)) * 2 / (a + b));
		quest = 'C';
	}
	else {
		cout << "Такой стороны не существует. Введите существующую сторону.\n";
		goto ask;
	}

	return(bis);
}
