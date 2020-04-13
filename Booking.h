#pragma once
#include <iostream>
#include <string>
#include <ostream>
using namespace std;

class Rezervare {
private:
	char* nume;
	int nr_zbor;
	int nr_loc;

public:
	Rezervare();
	Rezervare(char*,int , int);
	Rezervare(const Rezervare&);
	~Rezervare();

	//Getters

	char* get_nume();
	int get_nr_zbor();
	int get_nr_loc();

	//Setters
	
	void set_nume(char*);
	void set_nr_zbor(int);
	void setnr_loc(int);

	//Overwrite operators '=' , "==" and "<<"

	Rezervare& operator=(const Rezervare& r);
	bool operator==(const Rezervare& r);
	friend ostream& operator<<(ostream& os, Rezervare r);
	friend istream& operator>>(istream&, Rezervare& r);
	
};
void load_from_file_element(istream&, Rezervare&);