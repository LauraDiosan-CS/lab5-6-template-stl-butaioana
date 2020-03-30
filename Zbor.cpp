#include "Zbor.h"
#include <cstring>
Zbor::Zbor() {

	this->nume = NULL;
	this->id = 0;
	this->loc = 0;
}

Zbor::Zbor(char* name, int id, int loc) {

	this->nume = new char[strlen(name) + 1];
	strcpy_s(this->nume, 1 + strlen(name), name);
	this->id = id;
	this->loc = loc;
}

Zbor::Zbor(const Zbor& expence) {

	this->nume = new char[strlen(expence.nume) + 1];
	strcpy_s(this->nume, 1 + strlen(expence.nume), expence.nume);
	this->id = id;
	this->loc = expence.loc;
}

Zbor::~Zbor() {

	if (this->nume) {

		delete[] this->nume;
		this->nume = NULL;
		delete[] this->nume;
		this->nume = NULL;
	}
}

//Getters

char* Zbor::get_nume() {
	return this->nume;
}

int Zbor::get_loc() {
	return this->loc;
}

int Zbor::get_id() {
	return this->id;
}

//Setters

void Zbor::set_nume(char* new_name) {

	this->nume = new char[strlen(new_name) + 1];
	strcpy_s(this->nume, 1 + strlen(new_name), new_name);
}

void Zbor::set_id(int new_id) {
	this->id = new_id;
}

void Zbor::set_loc(int new_loc) {
	this->loc = new_loc;
}

Zbor& Zbor:: operator =(const Zbor& expence) {
	this->set_nume(expence.nume);
	this->set_loc(expence.loc);
	this->set_id(expence.id);
	return *this;
}

bool Zbor:: operator==(const Zbor& s) {
	return  this->id == s.id == 0 and this->loc == s.loc and strcmp(this->nume, s.nume) == 0;
}

std::ostream& operator <<(std::ostream& os, const Zbor& expence) {
	os << std::endl << "Name: " << expence.nume << " ne zbor: " << expence.id<< " loc: " << expence.loc << std::endl;
	return os;
}