#include "UI.h"
#include <iostream>
#include <string>
#include <ctime>

using namespace std;
UI::UI() {};
UI::~UI() {};

char* allocate_memory()
{
	char* name = new char[0];
	string string_name;

	cin >> string_name;
	name = new char[string_name.size() + 1];
	strcpy_s(name, 1 + string_name.size(), string_name.c_str());

	return name;
}

/*void exist() {
	int nr_zbor;
	int loc;
	int X;
	cout << "Zborul numarul ";
	cin >> nr_zbor;
	//cout << "nr loc";
	//cin >> loc;
	cout << "Zborul " << nr_zbor << " are " ;
	cin >> X;
	cout << " locuri disponibile";
	
	
}*/

void UI::add() {
	//exist();
	Rezervare rezervare;
	cin >> rezervare;
	list<int> locuri_disponibile;
		bool ok = service.add(rezervare, locuri_disponibile);

		if (ok)
			cout << "Rezervare adaugata!" << endl;
		else
			if (locuri_disponibile.empty())
				cout << "Zborul nu are locuri dispunibile!" << endl;
			else {
				cout << "Zborul are locuri dispunibile: " << endl;
				for (int place : locuri_disponibile)
					cout << place << endl;
			}
}

void UI::remove()
{
	Rezervare rezervare;
	cout << "Rezervarea de sters: " << endl;
	cin >> rezervare;
	service.remove(rezervare);
}

void UI::find_element()
{
	Rezervare rezervare;
	cin >> rezervare;
	if (int i = service.find_element(rezervare))
		if (i >= 0)
			cout << "Rezervarea exista";
		else
		{
			cout << "Rezervarea nu exista";
			find_element();
		}

}
void UI::update()
{
	Rezervare rezervare;
	list<int> locuri_disponibile_u;
	cout << "Rezervarea de zbor: " << endl;
	cin >> rezervare;
	cout << "Noul nr de zbor este: ";
	int new_nr_zbor;
	cin >> new_nr_zbor;
	cout << "Modificati numele: ";
	char new_name[20];
	cin >> new_name;
	cout << "Dati noul numar de loc: ";
	int new_nr_loc;
	cin >> new_nr_loc;
}
void UI::modificare()
{	
	Rezervare rezervare;
	find_element();
	list<int> locuri_disponibile_u;
	cout << "Rezervarea de zbor: " << endl;
	cin >> rezervare;
	cout << "Noul nr de zbor este: ";
	int new_nr_zbor;
	cin >> new_nr_zbor;
	cout << "Modificati numele: ";
	char new_name[20];
	cin >> new_name;
	cout << "Dati noul numar de loc: ";
	int new_nr_loc;
	cin >> new_nr_loc;
	//bool ok = service.add(rezervare, locuri_disponibile_u);
		cout << "Rezervare modificata!" << endl;
	service.modificare(rezervare, Rezervare(new_name, new_nr_zbor, new_nr_loc), locuri_disponibile_u);

}



void UI::get_size()
{
	int size=service.get_size();
	cout << "Dimensiunea este: " << size << endl;
}

void UI::print() {
	list<Rezervare> all_element = service.get_all();
	for (Rezervare r : all_element)
		cout << r;
}


void UI::run()
{
	bool op = false;
	while (!op) {
		cout << endl;
		cout << "		  OPTIUNI:			" << endl;
		cout << "		   (^_^)			" << endl;
		cout << "	1. Adaugare.		" << endl;
		cout << "	2. Print.				" << endl;
		cout << "	3. Stergere.		" << endl;
		cout << "	4. Modificarea rezervarii unui loc." << endl;
		cout << "	5. Update.		" << endl;
		cout << "	0. EXIT!				" << endl;
		cout << "	->	Introduceti optiunea:	";

		int opt;
		cin >> opt;
		switch (opt) {
		case 1: {add(); break; }
		case 2: {print(); break; }
		case 3: {remove(); break; }
		case 4: {modificare(); break; }
		case 5: {update(); break; }
		case 0: {op = true; cout << "Paaaa! (>.<)" << endl; }
		}
	}
}