#include<iostream>
#include<locale.h>
#include<time.h>
#include<stdlib.h>
#include<fstream>
#include<string>
#include<cstring>
#include<Windows.h>
using namespace std;
struct Entry
{
	char name[100], surname[100];
	int num : 10, num2 : 8, num3 : 8, num4 : 8;
};


int main()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	setlocale(LC_ALL, "RUS");
	srand(time(NULL));
	cout << "Сколько человек?" << endl;
	ifstream in("Телефонный справочник.txt");
	int g;
	cin >> g;
	int k, l;
	int n, n2, n3, n4;
	int t = 1;
	Entry *s = new Entry[g];
	cin.ignore();
	for (size_t i = 0; i < g; i++)
	{
		in >> s[i].name;
		in >> s[i].surname;
		in >> n;
		in >> n2;
		in >> n3;
		in >> n4;
		s[i].num = n;
		s[i].num2 = n2;
		s[i].num3 = n3;
		s[i].num4 = n4;

	}
	for (size_t i = 0; i < g; i++)
	{
		cout << s[i].name << " " << s[i].surname << " " << s[i].num << " " << s[i].num2 << " " << s[i].num3 << " " << s[i].num4 << endl;
	}

	
	int task;
	cout << "1 - сортировка по имени " << "2 - сортировка по номерам" << "3 - Удаление " << "4 - Редактирование " << "5 - добавление" << endl;
	cin >> task;
	switch (task)
	{
	case 1: 
		cout << "Вы хотите отсортировать их по именам?(1 - ДА,0 - НЕТ)" << endl;
		cin >> l;
		if (l == 1)
		{
			for (int i = 0; i < g - 1; i++)
			{
				for (size_t j = 0; j < g - 1; j++)
				{
					if ((strcmp(s[j].name, s[j + 1].name) == 1))
					{
						swap(s[j], s[j + 1]);
					}
					else if ((strcmp(s[j].surname, s[j + 1].surname) == 1))
					{
						swap(s[j], s[j + 1]);
					}
				}
			}
			for (size_t i = 0; i < g; i++)
			{
				cout << s[i].name << " " << s[i].surname << " " << s[i].num << " " << s[i].num2 << " " << s[i].num3 << " " << s[i].num4 << endl;
			}
		}
		break;
	case 2:
		cout << "Вы хотите отсортировать их по номерам?(1 - ДА,0 - НЕТ)" << endl;
		cin >> l;
		if (l == 1)
		{
			for (int i = 0; i < g - 1; i++)
			{
				for (size_t j = 0; j < g - 1; j++)
				{
					if (s[j].num > s[j + 1].num)
					{
						swap(s[j], s[j + 1]);
					}
					else if (s[j].num2 > s[j + 1].num2)
					{
						swap(s[j], s[j + 1]);
					}
					else if (s[j].num3 > s[j + 1].num3)
					{
						swap(s[j], s[j + 1]);
					}
					else if (s[j].num4 > s[j + 1].num4)
					{
						swap(s[j], s[j + 1]);
					}
				}
			}
			for (size_t i = 0; i < g; i++)
			{
				cout << s[i].name << " " << s[i].surname << " " << s[i].num << " " << s[i].num2 << " " << s[i].num3 << " " << s[i].num4 << endl;
			}
		}
		break;
	case 3:
		cout << "Вы хотите удалить что нибудь?(1 - ДА,0 - НЕТ)" << endl;
		cin >> l;
		if (l == 1)
		{
			int d, h = 0;;
			cout << "Какой?" << endl;
			cin >> d;
			Entry *tmp = new Entry[g - 1];
			for (size_t i = 0; i < g; i++)
			{
				if (i != d)
				{
					tmp[h] = s[i];
					h++;
				}
			}
			delete[] s;
			s = tmp;
			g = g - 1;
			for (size_t i = 0; i < g; i++)
			{
				cout << s[i].name << " " << s[i].surname << " " << s[i].num << " " << s[i].num2 << " " << s[i].num3 << " " << s[i].num4 << endl;
			}
		}
		break;

	case 4:
		cout << "Ты хочешь что-то изменить? (1 - ДА,0 - НЕТ)" << endl;
		cin >> k;
		int i;
		if (k == 1)
		{
			cout << "Который из?" << endl;
			cin >> i;
			cout << s[i].name << " " << s[i].surname << " " << s[i].num << " " << s[i].num2 << " " << s[i].num3 << " " << s[i].num4 << endl;

			int h;
			cout << "Что вы хотите изменить? (1 - имя, 2 - фамилия, 3 - первая часть номера, 4 - вторая часть номера, 5 - третья часть номера, 6 - четвертая часть номера" << endl;
			cin >> h;
			switch (h)
			{
			case 1:cin >> s[i].name; break;
			case 2:cin >> s[i].surname; break;
			case 3:int q;
				cin >> q;
				s[i].num = q;
				break;
			case 4:int e;
				cin >> e;
				s[i].num2 = e;
				break;
			case 5:int i;
				cin >> i;
				s[i].num3 = i;
			case 6:int x;
				cin >> x;
				s[i].num4 = x;
			default:
				break;
			}
			for (size_t i = 0; i < g; i++)
			{
				cout << s[i].name << " " << s[i].surname << " " << s[i].num << " " << s[i].num2 << " " << s[i].num3 << " " << s[i].num4 << endl;
			}
		}
		break;
	case 5:
		cout << "Вы хотите что-то добавить?(1 - Да,0 - Нет)" << endl;
		cin >> l;
		if (l == 1)
		{
			int d;
			Entry *tmp = new Entry[g + 1];
			for (size_t i = 0; i < g; i++)
			{
				tmp[i] = s[i];
			}
			cin >> tmp[g].name;
			cin >> tmp[g].surname;
			cin >> n;
			cin >> n2;
			cin >> n3;
			cin >> n4;
			tmp[g].num = n;
			tmp[g].num2 = n2;
			tmp[g].num3 = n3;
			tmp[g].num4 = n4;
			delete[] s;
			s = tmp;
			g = g + 1;

			for (size_t i = 0; i < g; i++)
			{
				cout << s[i].name << " " << s[i].surname << " " << s[i].num << " " << s[i].num2 << " " << s[i].num3 << " " << s[i].num4 << endl;
			}
		}
		break;

	default:
		break;
	}

	
	while (t == 1)
	{
		cout << "Снова?(1 - ДА,0 - НЕТ)" << endl;
		cin >> t;
	}


	system("pause");
	return 0;
}