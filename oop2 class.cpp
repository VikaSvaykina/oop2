#include <conio.h>
#include <iostream>
using namespace std;

class Square {	//основной класс
protected:
	int length, width;
public:
	Square() {	//конструктор без параметров
		printf("Square()\n");
		length = 0;
		width = 0;
	}
	Square(int length, int width) {	//конструктор с параметрами
		printf("Square(int length, int width)\n");
		this->length = length;
		this->width = width;
	}
	Square(const Square& p) {	//конструктор копирования с параметром-объектом класса
		printf("Square(const Square& p)\n");
		length = p.length;
		width = p.width;
	}
	~Square() {	//деструктор
		printf("%d, %d\n", length, width);
		printf("~Square()\n");
	}
	void addsize(int value) {	//метод
		length = length + value;
		width = width + value;
	}
	void subsize(int value) {	//метод
		length = length - value;
		width = width - value;
	}
	void reset();	//метод
};

void Square::reset() {
	length = 0;
	width = 0;
}

class ColoredSquare : public Square {	//дочерний класс
protected:
	int color;
public:
	ColoredSquare() : Square() {	//конструктор без параметров
		printf("ColoredSquare()\n");
		color = 0;
	}
	ColoredSquare(int length, int width, int color) : Square(length, width) {	//конструктор с параметрами
		printf("ColoredSquare(int length, int width, int color)\n");
		this->color = color;
	}
	ColoredSquare(const ColoredSquare& p) {	//конструктор копирования с параметром-объектом класа
		printf("ColoredSquare(const ColoredSquare& p)\n");
		color = p.color;
		length = p.length;
		width = p.width;
	}
	~ColoredSquare() {	//деструктор
		printf("%d, %d color-%d\n", length, width, color);
		printf("~ColoredSquare()\n");
	}
	void change_color(int new_color) {	//метод
		color = new_color;
	}
};

class Mosaic {	//класс с композицией
protected:
	Square* p1;
	Square* p2;
public:
	Mosaic() {	//конструктор без параметров
		printf("Mosaic()\n");
		p1 = new Square;
		p2 = new Square;
	}
	Mosaic(int length1, int width1, int length2, int width2) {	//конструктор с параметрами
		printf("Mosaic(int length1, int width1, int length2, int width2)\n");
		p1 = new Square(length1, width1);
		p2 = new Square(length2, width2);
	}
	Mosaic(const Mosaic &s) {	//конструктор копирования с параметром-объектом класс
		printf("Mosaic(const Mosaic &s)\n");
		p1 = new Square(*(s.p1));
		p2 = new Square(*(s.p2));
	}
	~Mosaic() {	//деструктор
		printf("~Mosaic()\n");
		delete p1;
		delete p2;
	}
};

int main() 
{
	setlocale(LC_ALL, "rus");
	{
		cout << "Начальные значения для конструкторов: (10, 10)\n";
		cout << "Проверка конструкторов и деструкторов основного класса.\n";
		cout << "Проверка методов класса. Сначала обнуляем данные, затем добавляем 7 и вычитаем 5\n";
		Square* p = new Square;
		Square* p2 = new Square(10, 10);
		Square* p3 = new Square(*p2);
		p2->reset();
		p2->addsize(7);
		p2->subsize(5);
		delete p;
		delete p2;
		delete p3;
	}
	_getch();
	{
		cout << "Проверка конструкторов и деструкторов дочернего класса.\n";
		cout << "Проверка метода дочернего класса. Заменяется характеристика цвета в дочернем классе с 1 на 2\n";
		ColoredSquare* p = new ColoredSquare;
		ColoredSquare* p2 = new ColoredSquare(10, 10, 1);
		ColoredSquare* p3 = new ColoredSquare(*p2);
		p2->change_color(2);
		delete p;
		delete p2;
		delete p3;
	}
	_getch();
	{
		cout << "Проверка конструкторов и деструкторов класса c композицией.\n";
		Mosaic* s = new Mosaic();
		Mosaic* s2 = new Mosaic(10, 10, 10, 10);
		Mosaic* s3 = new Mosaic(*s2);
		delete s;
		delete s2;
		delete s3;
	}
	return 0;
}