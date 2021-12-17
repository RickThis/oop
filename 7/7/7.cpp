﻿// 7.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include <fstream>
#include <stdlib.h>
#include <sstream>
#include <cctype>

using namespace std;


class MyClass {
	string str = "";

	friend istream& operator >> (istream& s, fstream& obj)
	{
		s.read((char*)&obj, sizeof(int));
		return s;
	}
	template<typename T>
	friend ofstream& operator << (ofstream& f, T& A)
	{
		
		return f;
	}
public:
	void check();
	MyClass(string a) {
		this->str = a;
		check();
	}
};


void MyClass::check() {
	for (int i = 0; i < str.length(); i++)
	{
		if (!islower(str[i])) {
			str.erase(str.find(str[i]));
		}
		for (int j = 0; j < 10; j++)
		{
			char number = (char)j;
			if (str[i] == number) {
				str.erase(str.find(number), 1);
			}
		}
	}
}


int main()
{
	setlocale(LC_ALL, "rus");
	fstream a;
	try
	{
		a.open("floats.txt");
		cout << a;
	}
	catch (const exception&ex)
	{
		cout << ex.what() << endl;
	}
	a.close();
}

// Запуск программы: CTRL+F5 или меню "Отладка" > "Запуск без отладки"
// Отладка программы: F5 или меню "Отладка" > "Запустить отладку"

// Советы по началу работы 
//   1. В окне обозревателя решений можно добавлять файлы и управлять ими.
//   2. В окне Team Explorer можно подключиться к системе управления версиями.
//   3. В окне "Выходные данные" можно просматривать выходные данные сборки и другие сообщения.
//   4. В окне "Список ошибок" можно просматривать ошибки.
//   5. Последовательно выберите пункты меню "Проект" > "Добавить новый элемент", чтобы создать файлы кода, или "Проект" > "Добавить существующий элемент", чтобы добавить в проект существующие файлы кода.
//   6. Чтобы снова открыть этот проект позже, выберите пункты меню "Файл" > "Открыть" > "Проект" и выберите SLN-файл.
