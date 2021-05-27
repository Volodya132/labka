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
	cout << "������ ����� �����: "; cin >> filename;
	fin.open(filename);
	if (fin.is_open())
	{
		float max;
		cout << "������ ������������ ���������: "; cin >> max;

		vector<string> pips; //��� ���� �������� ������� ���, �� ���������� �����
		int stayTime = 0; //��� ������� � ��������

		//���� ��� ����� �� � ����, ��� ��� �������� ���� ��������
		Driver d;
		fin >> d;
		if (d.getKm() > max)
			pips.push_back(d.getPIP());
		Time last = d.getFinishTime();
		while (!fin.eof()) //������ �� ����
		{
			fin >> d;
			if (last != d.getStartTime()) //���� ��� �������� � ����������� �� ����������, ������� ������ � ��������
			{
				stayTime += (d.getStartTime() - last).getTimeInSec();
			}
			if (d.getKm() > max) //���� ��������� �����, ������� � ������ �������
				pips.push_back(d.getPIP());
			last = d.getFinishTime();
		}
		fin.close(); //�������� ����

		if (stayTime)
		{
			cout << "��������� ��� ������� � ��������: " << stayTime << endl;
		}
		else if(pips.size())
		{
			cout << "��䳿, �� ���������� �����: " << endl;
			for (string cur : pips)
			{
				cout << cur << endl;
			}
		}
		else
		{
			cout << "������� � ��䳿�, �� ���������� ����� ����!" << endl;
		}
	}
	else
	{
		cout << "������� ���������� �����! " << endl;
	}



	
	return 0;
}