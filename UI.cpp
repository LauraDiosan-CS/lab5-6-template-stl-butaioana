#include"UI.h"
#include"Functions.h"
#include<iostream>
using namespace std;

char* allocate_memory()
{
	char* name = new char[0];
	string string_name;
	cin >> string_name;
	name = new char[string_name.size() + 1];
	strcpy_s(name, 1 + string_name.size(), string_name.c_str());

	return name;
}

void UI::add() {

	char nume[100];
	string aux_date;
	int loc;
	int id;
	cout << "Nume: ";
	cin >> nume;
	cout << endl;
	//int ok = 1;
		cout << " nr zbor: ";
		cin >> id;
		cout << endl;
		cout << "Nr loc: ";
		cin >> loc;
		this->service.insert_sevice(nume, id, loc);
}
void UI::print()
{
	for (int i = 0; i < this->service.get_len(); i++)
		cout << this->service.get_all()[i] << endl;
}
void UI::run() {
	int op = 1;
	while (op)
	{
		cout << "(^_^) " << endl;
		cout << "Alege o obtiune" << endl;
		menu();
		cout << "Obtiunea ta este" << endl;
		cin >> op;
		if (op == 1) {
			this->add();
		}
		if (op == 2) {
			this->print();
		}
	}
}