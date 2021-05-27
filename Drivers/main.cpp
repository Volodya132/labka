#include "Driver.h"
#include <windows.h>
#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

int main()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

	ifstream fin;
	string filename;
	cout << "Введіть назву файла: "; cin >> filename;
	fin.open(filename);
	if (fin.is_open())
	{
		float max;
		cout << "Введіть максимальний кілометраж: "; cin >> max;

		vector<string> pips; //тут буду зберігати ініціали тих, що перевищили норму
		int stayTime = 0; //час простою в секундах

		//один раз ввожу не в циклі, щоб час минулого водія записати
		Driver d;
		fin >> d;
		if (d.getKm() > max)
			pips.push_back(d.getPIP());
		Time last = d.getFinishTime();
		while (!fin.eof()) //зчитую до кінця
		{
			fin >> d;
			if (last != d.getStartTime()) //якщо час минулого і теперішнього не одинаковий, записую різницю у секундах
			{
				stayTime += (d.getStartTime() - last).getTimeInSec();
			}
			if (d.getKm() > max) //якщо перевищив норму, записую у вектор ініціали
				pips.push_back(d.getPIP());
			last = d.getFinishTime();
		}
		fin.close(); //закриваю файл

		if (stayTime)
		{
			cout << "Загальний час простою у секундах: " << stayTime << endl;
		}
		else if(pips.size())
		{
			cout << "Водії, які перевищили норму: " << endl;
			for (string cur : pips)
			{
				cout << cur << endl;
			}
		}
		else
		{
			cout << "Простою і водіїв, які перевищили норму немає!" << endl;
		}
	}
	else
	{
		cout << "Помилка відкривання файла! " << endl;
	}



	
	return 0;
}