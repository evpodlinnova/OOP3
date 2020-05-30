// ООП1.2.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include "pch.h"
#include <iostream>
#include <string>
#include <windows.h>
using namespace std;
class Stationery {
protected:
	
	string brand;
	string name;
public:
	int price;
	Stationery() {
		name = "";
		brand = "";
		price = 0;
	}
	virtual void pprint() {
		cout << "Наименование: " << name << endl
			<< "Бренд: " << brand << endl 
			<< "Цена: " << price << endl;
		
	}
	virtual void pread() {
		cout << "Наименование: "; cin >> name;
		cout << endl;
		cout << "Бренд: "; cin>>brand;
		cout << endl;
		cout << "Цена: "; cin>>price;
		cout << endl;
	}
	Stationery(string _name, string _brand, int _price)
	{
		this->name=_name;
		this->brand=_brand;
		this->price=_price;
	}
	
};
/////////////////////

class Writing : virtual public  Stationery
{
protected:
	string color;
public:
	Writing() :Stationery() {
		color = "";
	}
	Writing(string _name, string _brand, int _price, string _color) :Stationery(_name,  _brand,  _price) {
		color = _color;
	}
	void pprint() {
		Stationery::pprint();
		cout << "Цвет: " << color << endl;
	}
	void pread() {
		Stationery::pread();
		cout << "Цвет: "; cin >> color;
		cout << endl;
	}
};
////////////////////////////
class Office : virtual public Stationery
{
protected:
	int quantity;
public:
	Office() : Stationery() {
		quantity = 0;
	}
	Office(string _name, string _brand, int _price, int _quantity) :Stationery(_name, _brand, _price) {
		quantity = _quantity;
	}
	void pprint() {
		Stationery::pprint();
		cout << "Количество: " << quantity << endl;
	}
	void pread() {
		Stationery::pread();
		cout << "Количество: "; cin >> quantity;
		cout << endl;
	}
};
////////////////////////////////
class Pencil : public Writing, public Office
{
protected:
	string erase;
	string softness;
public:
	Pencil() :Writing() {
		erase = "";
		softness = "";
	}
	Pencil(string _name, string _brand, int _price,string _color, string _erase, string _softness) :Writing(_name, _brand, _price, _color) {
		erase = _erase;
		softness = _softness;
	}
	void pprint() {
		Writing::pprint();
		cout << "Наличие стирателя: " << erase << endl;
		cout << "Мягкость: " << softness << endl;
	}
	void pread() {
		Writing::pread();
		cout << "Наличие стирателя: "; cin >> erase;
		cout << endl;
		cout << "Мягкость: "; cin >> softness;
		cout << endl;
	}
};
//////////////////////////////
class OrigPencil: public Pencil
{
protected:
	string shape;
	string material;
public:
	OrigPencil() : Pencil() {
		shape = "";
		material = "";
	}
	OrigPencil(string _name, string _brand, int _price, string _color, string _erase, string _softness, string _shape, string _material) :Pencil(_name, _brand, _price, _color, _erase, _softness) {
		shape = _shape;
		material = _material;
	}
	void pprint() {
		Pencil::pprint();
		cout << "Форма: " << shape << endl;
		cout << "Материал корпуса: " << material << endl;
	}
	void pread() {
		Pencil::pread();
		cout << "Форма: "; cin >> shape;
		cout << endl;
		cout << "Материал корпуса: "; cin >> material;
		cout << endl;
	}
	
};

/////////////////////////////////
class MechPencil : public Pencil {
protected:
	double diametr;
	int rod;
public:
	MechPencil() : Pencil() {
		diametr = 0.0;
		rod = 0;
	}
	MechPencil(string _name, string _brand, int _price, string _color, string _erase, string _softness, double _diametr, int _rod) :Pencil(_name, _brand, _price, _color, _erase, _softness) {
		diametr = _diametr;
		rod = _rod;
	}
	void pprint() {
		Pencil::pprint();
		cout << "Диаметр: " << diametr << endl;
		cout << "Стержень: " << rod << endl;
	}
	void pread() {
		Pencil::pread();
		cout << "Диаметр: "; cin >> diametr;
		cout << endl;
		cout << "Стержень: "; cin >> rod;
		cout << endl;
	}
};
/////////////////////////////////
class Pen : public Writing
{
protected:
	double thickness;
public:
	Pen(): Writing() {
		thickness = 0.0;
	}
	Pen(string _name, string _brand, int _price, string _color, double _thickness) :Writing(_name, _brand, _price, _color) {
		thickness = _thickness;
	}
	void pprint() {
		Writing::pprint();
		cout << "Толщина линии: " << thickness << endl;
	}
	void pread() {
		Writing::pread();
		cout << "Толщина линии: "; cin >> thickness;
		cout << endl;
	}
};
////////////////////////////////
class FountainPen : public Pen
{
protected:
	string grip;
	int consumables;
public:
	FountainPen():Pen() {
		grip="";
		consumables = 0;
	}
	FountainPen(string _name, string _brand, int _price, string _color, double _thickness, string _grip, int _consumables) :Pen(_name, _brand, _price, _color, _thickness) {
		grip = _grip;
		consumables = _consumables;
	}
	void pprint() {
		Pen::pprint();
		cout << "Наличие грипа: " << grip << endl;
		cout << "Код расходных материалов: " << consumables << endl;
	}
	void pread() {
		Pen::pread();
		cout << "Наличие грипа: "; cin >> grip;
		cout << endl;
		cout << "Код расходных материалов: "; cin >> consumables;
		cout << endl;
	}
};
/////////////////////////////////
class BallPen : public Pen
{
protected:
	string avto;
	int length;
public:
	BallPen() :Pen() {
		avto = "";
		length = 0;
	}
	BallPen(string _name, string _brand, int _price, string _color, double _thickness, string _avto, int _length) :Pen(_name, _brand, _price, _color, _thickness) {
		avto = _avto;
		length = _length;
	}
	void pprint() {
		Pen::pprint();
		cout << "Наличие грипа: " << avto << endl;
		cout << "Код расходных материалов: " << length << endl;
	}
	void pread() {
		Writing::pread();
		cout << "Наличие грипа: "; cin >> avto;
		cout << endl;
		cout << "Код расходных материалов: "; cin >> length;
		cout << endl;
	}
};
/////////////////////////////////

class SmallOffice : public Office
{
protected:
	string cover;
	string shapee;
public:
	SmallOffice() :Office() {
		cover = "";
		shapee = "";
	}
	SmallOffice(string _name, string _brand, int _price, int _quantity, string _cover, string _shapee) :Office(_name, _brand, _price, _quantity) {
		cover = _cover;
		shapee = _shapee;
	}
	void pprint() {
		Office::pprint();
		cout << "Покрытие: " << cover << endl;
		cout << "Форма: " << shapee << endl;
	}
	void pread() {
		Office::pread();
		cout << "Покрытие: "; cin >> cover;
		cout << endl;
		cout << "Форма: "; cin >> shapee;
		cout << endl;
	}
};
////////////////////////////////////
class Buttons : public SmallOffice
{
protected:
	int diametrr;
public:
	Buttons() :SmallOffice() {
		diametrr = 0;
	}
	Buttons(string _name, string _brand, int _price, int _quantity, string _cover, string _shapee, int _diametrr) :SmallOffice(_name, _brand, _price, _quantity, _cover, _shapee) {
		diametrr = _diametrr;
		
	}
	void pprint() {
		SmallOffice::pprint();
		cout << "Диаметр шляпки: " << diametrr << endl;
	}
	void pread() {
		SmallOffice::pread();
		cout << "Диаметр шляпки: "; cin >> diametrr;
		cout << endl;
	}
};
////////////////////////////////////
class Clips : public SmallOffice
{
protected:
	int lengthh;
public:
	Clips() :SmallOffice() {
		lengthh = 0;
	}
	Clips(string _name, string _brand, int _price, int _quantity, string _cover, string _shapee, int _lengthh) :SmallOffice(_name, _brand, _price, _quantity, _cover, _shapee) {
		lengthh = _lengthh;

	}
	void pprint() {
		SmallOffice::pprint();
		cout << "Длина: " << lengthh << endl;
	}
	void pread() {
		SmallOffice::pread();
		cout << "Длина: "; cin >> lengthh;
		cout << endl;
	}
};
///////////////////////////////////
class Correct : public Office
{
protected:
	string colorbody;
public:
	Correct() :Office() {
		colorbody = "";
	}
	Correct(string _name, string _brand, int _price, int _quantity, string _colorbody) :Office(_name, _brand, _price, _quantity) {
		colorbody = _colorbody;
	}
	void pprint() {
		Office::pprint();
		cout << "Цвет покрытия: " << colorbody << endl;
	}
	void pread() {
		Office::pread();
		cout << "Цвет покрытия: "; cin >> colorbody;
		cout << endl;
	}
};
class CorrectPen : public Correct
{
protected:
	string fluidsupply;
	string tipmaterial;
public:
	CorrectPen() :Correct() {
		fluidsupply = "";
		tipmaterial = "";
	}
	CorrectPen(string _name, string _brand, int _price, int _quantity, string _colorbody, string _fluidsupply,  string _tipmaterial) :Correct(_name, _brand, _price, _quantity, _colorbody) {
		fluidsupply = _fluidsupply;
		tipmaterial = _tipmaterial;
	}
	void pprint() {
		Correct::pprint();
		cout << "Подача жидкости: " << fluidsupply << endl;
		cout << "Материал наконечника: " << tipmaterial << endl;
	}
	void pread() {
		Correct::pread();
		cout << "Подача жидкости: "; cin >> fluidsupply;
		cout << endl;
		cout << "Материал наконечника: "; cin >> tipmaterial;
		cout << endl;
	}
};
//////////////////////////////////////////
class CorrectTape : public Correct
{
protected:
	int width;
public:
	CorrectTape() :Correct() {
		width = 0;
	}
	CorrectTape(string _name, string _brand, int _price, int _quantity, string _colorbody, int _width) :Correct(_name, _brand, _price, _quantity, _colorbody) {
		width = _width;
	}
	void pprint() {
		Correct::pprint();
		cout << "Ширина ленты: " << width << endl;
	}
	void pread() {
		Correct::pread();
		cout << "Ширина ленты: "; cin >> width;
		cout << endl;
	}
};
//////////////////////////////////

class Matrix
{
public:
	Matrix(int c)
	{
		try {
			if (c==0) throw 1;
				b = c;
				M = new Stationery *[b];
				for (int i = 0; i < b; i++)
				{
					M[i] = new Stationery[b];
				}
			
			
		}
		catch (int a) {
			cout << "Матрица не может быть размером 0"<<endl;
		}
	}
	
	friend ostream& operator<< (ostream& out,const Matrix & m)
	{
		for (int i = 0; i < m.b; i++)
		{
			for (int j = 0; j < m.b; j++)
			{
				m.M[i][j].pprint();
			}
		}out << endl << endl;
		return out;
	}
	void CIN(int i,int j, Stationery& a)
	{			
				M[i][j] = a;		
		cout << endl;
	}
	void summa(const Matrix & m)
	{
		int sum = 0;
		for (int i = 0; i < m.b; i++)
		{
			for (int j = 0; j < m.b; j++)
			{
				sum += m.M[i][j].price;
			}
		}
		cout<< sum;
	}

private:
	Stationery** M;
	int b;
};


int main()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	int r, add,i=0,j=0;
	cout << "Сколько хотите добавить экземпляров к*к?" << endl;
	cin >> r;
	Matrix STAT(r);
	while (r == 0) {
		cout << "Сколько хотите добавить экземпляров к*к?" << endl;
		cin >> r;
		Matrix STAT(r);
	}
	cout << "Какой вид канцелярии хотите добавить к*к?"
		<< endl << "0-Выход"
		<< endl << "1-Обычный карандаш"
		<< endl << "2-Механический карандаш"
		<< endl << "3-Перьевая ручка"
		<< endl << "4-Шариковая ручка"
		<< endl << "5-Канцелярские кнопки"
		<< endl << "6-Канцелярские скрепки"
		<< endl << "7-Корректирующий карандаш"
		<< endl << "8-Корректирующая лента"<<endl;
	cin >> add;
	while (add != 0) {
		
		if (add == 1) {
			OrigPencil o;
			o.pread();
			STAT.CIN(i, j, o);
			cout << endl;
		}
		if (add == 2) {
			
			MechPencil k;
			k.pread();
			STAT.CIN(i, j, k);
			cout << endl;
		}
		if (add == 3) {
			FountainPen f;
			f.pread();
			STAT.CIN(i, j, f);
			cout << endl;
		}
		if (add == 4) {
			
			BallPen b;
			b.pread();
			STAT.CIN(i, j, b);
			cout << endl;
			
		}
		if (add == 5) {
			Buttons bb;
			bb.pread();
			STAT.CIN(i, j, bb);
			cout << endl;
		}
		if (add == 6) {
			Clips c;
			c.pread();
			STAT.CIN(i, j, c);
			cout << endl;
		}
		if (add == 7) {
			CorrectPen cc;
			cc.pread();
			STAT.CIN(i, j, cc);
			cout << endl;
		}
		if (add == 8) {
			CorrectTape ct;
			ct.pread();
			STAT.CIN(i, j, ct);
			cout << endl;
		}
		if (j==r-1)
		{
			j = 0;
			i++;
		}
		else j++;
		if (i < r) {
			cout << "Какой вид канцелярии хотите добавить?"
				<< endl << "0-Выход"
				<< endl << "1-Обычный карандаш"
				<< endl << "2-Механический карандаш"
				<< endl << "3-Перьевая ручка"
				<< endl << "4-Шариковая ручка"
				<< endl << "5-Канцелярские кнопки"
				<< endl << "6-Канцелярские скрепки"
				<< endl << "7-Корректирующий карандаш"
				<< endl << "8-Корректирующая лента" << endl;
			cin >> add;
		}
		else add = 0;
	}
	cout << STAT;
	cout << "стоимость всех добавленных элементов: ";
	STAT.summa(STAT);
	cout << endl;
	system("pause");
	return 0;
}
