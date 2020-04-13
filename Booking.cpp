#include "Booking.h"
#include <string.h>

Rezervare::Rezervare() {
	nume = NULL;
	nr_zbor = 0;
	nr_loc = 0;
}
Rezervare::Rezervare(char* name, int zbor,  int loc) {
	nr_zbor = zbor;
	nr_loc = loc;
	nume = new char[strlen(name) + 1];
	strcpy_s(nume, strlen(name) + 1, name);

}
Rezervare::Rezervare(const Rezervare& r) {
	nr_zbor = r.nr_zbor;
	nr_loc = r.nr_loc;
	nume = new char[strlen(r.nume) + 1];
	strcpy_s(nume, strlen(r.nume) + 1, r.nume);

}
Rezervare::~Rezervare() {
	nr_zbor = 0;
	nr_loc = 0;
	if (nume) {
		delete[] nume;
		nume = NULL;
	}

}
//Getters

char* Rezervare::get_nume() {
	return nume;
}

int Rezervare::get_nr_zbor() {
	return nr_zbor;
}

int Rezervare::get_nr_loc() {
	return nr_loc;
}

//Setters

void Rezervare::set_nume(char* new_name) {
	if (nume)
	{
		delete[] nume;
		nume = NULL;
	}
	nume = new char[strlen(new_name) + 1];
	strcpy_s(nume, 1 + strlen(new_name), new_name);
}

void Rezervare::set_nr_zbor(int new_nr_zbor) {
	nr_zbor = new_nr_zbor;
}

void Rezervare::setnr_loc(int new_nr_loc) {
	nr_loc = new_nr_loc;
}

Rezervare& Rezervare::operator=(const Rezervare& flight) {
	if (this == &flight) return *this;
	nr_zbor = flight.nr_zbor;
	nr_loc = flight.nr_loc;
	if (nume) {
		delete[] nume;
		nume = NULL;
	}
	nume = new char[strlen(flight.nume) + 1];
	strcpy_s(nume, strlen(flight.nume) + 1, flight.nume);
	return *this;
}
bool Rezervare::operator==(const Rezervare& flight) {
	return (strcmp(nume, flight.nume) == 0) && (nr_zbor == flight.nr_zbor) && (nr_loc==flight.nr_loc);
}
ostream& operator<<(ostream& os, Rezervare flight) {
	os << flight.nr_zbor << " " << flight.nume << " " << flight.nr_loc << endl;
	return os;
}
istream& operator>>(istream& s, Rezervare& r)
{
	std::cout << "Numele clientului: ";
	char* nume = new char[10];
	s >> nume;
	std::cout << "Numarul de zbor: ";
	int nr_zbor;
	s >> nr_zbor;
	std::cout << "Numarul locului: ";
	int nr_loc;
	s >> nr_loc;
	r.set_nume(nume);
	r.set_nr_zbor(nr_zbor);
	r.setnr_loc(nr_loc);
	delete[] nume;
	return s;

}
void load_from_file_element(istream& z, Rezervare& r) {
	char* nume = new char[10];
	z >> nume;
	int nr_zbor;
	z >> nr_zbor;
	int nr_loc;
	z >> nr_loc;

	r.set_nume(nume);
	r.set_nr_zbor(nr_zbor);
	r.setnr_loc(nr_loc);

	delete[] nume;
	return;
}