// Лабораторная работа №5
// Вариант 5
// Реализовать базовый класс Футболл и унаследовать от него 3 разных дочерних класса(на свое усмотрение), 
// каждый из которых будет добавлять разные поля и методы к базовому классу.
// В каждом классе должно быть как минимум 2 поля(в дочерних классах также должно быть как минимум 2 своих поля), характеризующие объект.
// Инициализация полей базового класса при создании объекта дочернего класса должна реализоваться через вызов конструктора базового класса.
// Реализовать возможность просмотра содержимого.
// Продемонстрировать создание, инициализацию полей и работу объектов дочерних классов.
// Также необходимо продемонстрировать диаграмму классов.

#include <iostream>
#include <string>
#include <string.h>
using namespace std;

class Football
{
public:
	virtual int getnumberplayers()=0;
	virtual int getfieldsize()=0;
	virtual void printall()=0;
	virtual void vvod()=0;
	virtual int proverka(string n)=0;
};

class Mini_Football : public Football
{
private:
	int* collar_size;
	string* place;
	int* number_players;
	int* field_size;

public:
	Mini_Football(int number_players = 0, int field_size = 0, int collar_size = 0, string place = "no name") : Football()
	{
		this->number_players = new int(number_players);
		this->field_size = new int(field_size);
		this->collar_size = new int(collar_size);
		this->place = new string(place);
	}

	~Mini_Football()
	{
		delete number_players;
		delete field_size;
		delete collar_size;
		delete place;
	}

	int getnumberplayers() override
	{
		return *number_players; 
	}

	int getfieldsize() override
	{
		return *field_size;
	}

	int getcollarsize()
	{
		return *collar_size;
	}

	string getplace()
	{
		return *place;
	}

	void printall() override
	{
		cout << "Mini_Football" << endl;
		cout << "количество игроков " << getnumberplayers() << endl;
		cout << "размер поля " << getfieldsize() << endl;
		cout << "размер ворот " << getcollarsize() << endl;
		cout << "место " << getplace() << endl << endl;
	}

	void vvod() override
	{
		cout << "Mini_Football" << endl;
		cout << "введите количество игроков: ";
		*number_players = proverka("количество игроков");
		cout << "введите размер поля: ";
		*field_size = proverka("размер поля");
		cout << "введите размер ворот: ";
		*collar_size = proverka("размер ворот");
		cout << "введите место: ";
		cin >> *place;
	}

	int proverka(string n) override
	{
		int buf;
		while (!(cin >> buf))
		{
			cout << "Некорректный ввод!!! Повторите ...\n";
			cout << "Введите " << n << ':';
			cin.clear();
			cin.ignore(INT_MAX, '\n');
		}
		return buf;
	}
};

class Beach_Football : public Football
{
private:
	string* beach;
	int* number_players;
	int* field_size;

public:
	Beach_Football(int number_players = 0, int field_size = 0, string beach = "no name") : Football()
	{
		this->number_players = new int(number_players);
		this->field_size = new int(field_size);
		this->beach = new string(beach);
	}

	~Beach_Football()
	{
		delete number_players;
		delete field_size;
		delete beach;
	}

	string getbeach()
	{
		return *beach;
	}

	int getnumberplayers() override
	{
		return *number_players;
	}

	int getfieldsize() override
	{
		return *field_size;
	}

	void printall() override
	{
		cout << "Beach_Football" << endl;
		cout << "количество игроков " << getnumberplayers() << endl;
		cout << "размер поля " << getfieldsize() << endl;
		cout << "пляж " << getbeach() << endl << endl;
	}

	void vvod() override
	{
		cout << endl << "Beach_Football" << endl;
		cout << "введите количество игроков: ";
		*number_players = proverka("количество игроков");
		cout << "введите размер поля: ";
		*field_size = proverka("размер поля");
		cout << "введите пляж: ";
		cin >> *beach;
	}

	int proverka(string n) override
	{
		int buf;
		while (!(cin >> buf))
		{
			cout << "Некорректный ввод!!! Повторите ...\n";
			cout << "Введите " << n << ':';
			cin.clear();
			cin.ignore(INT_MAX, '\n');
		}
		return buf;
	}
};

class Rugby_Football : public Football
{
private:
	string* stadium;
	string* team_name;
	int* number_players;
	int* field_size;

public:
	Rugby_Football(int number_players = 0, int field_size = 0, string stadium = "no name", string team_name = "no name") : Football()
	{
		this->number_players = new int(number_players);
		this->field_size = new int(field_size);
		this->stadium = new string(stadium);
		this->team_name = new string(team_name);
	}

	~Rugby_Football()
	{
		delete number_players;
		delete field_size;
		delete stadium;
		delete team_name;
	}

	int getnumberplayers() override
	{
		return *number_players;
	}

	int getfieldsize() override
	{
		return *field_size;
	}

	string getstadium()
	{
		return *stadium;
	}

	string getteam_name()
	{
		return *team_name;
	}

	void printall() override
	{
		cout << "Rugby_Football" << endl;
		cout << "количество игроков " << getnumberplayers() << endl;
		cout << "размер поля " << getfieldsize() << endl;
		cout << "стадион " << getstadium() << endl;
		cout << "название команды " << getteam_name() << endl;
	}

	void vvod() override
	{
		cout << endl << "Rugby_Football" << endl;
		int buf;
		cout << "введите количество игроков: ";
		*number_players = proverka("количество игроков");
		cout << "введите размер поля: ";
		*field_size = proverka("размер поля");
		cout << "введите стадион: ";
		cin >> *stadium;
		cout << "введите название команды: ";
		cin >> *team_name;
	}

	int proverka(string n) override
	{
		int buf;
		while (!(cin >> buf))
		{
			cout << "Некорректный ввод!!! Повторите ...\n";
			cout << "Введите " << n << ':';
			cin.clear();
			cin.ignore(INT_MAX, '\n');
		}
		return buf;
	}
};

int main()
{
	setlocale(LC_ALL, "Russian");

	Mini_Football* mini = new Mini_Football();
	Beach_Football* beach = new Beach_Football();
	Rugby_Football* rugby = new Rugby_Football();

	mini->vvod();
	beach->vvod();
	rugby->vvod();
	cout << endl;

	mini->printall();
	beach->printall();
	rugby->printall();

	delete mini;
	delete beach;
	delete rugby;
}

