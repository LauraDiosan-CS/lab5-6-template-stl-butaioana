#pragma once
#include "RepoFile.h"
class Service {
private:
	RepoFile<Rezervare> repo;
	const int X = 200;
public:
	Service();
	Service(const RepoFile<Rezervare>& r);
	~Service();
	bool add(Rezervare& r, list<int> &l_d);
	list<Rezervare> get_all();
	int get_size();
	int remove(Rezervare& r);
	void update(Rezervare& r, Rezervare& rnew);
	bool modificare(Rezervare& r, Rezervare& rnew, list<int>& l_d);
	int find_element(Rezervare& r);
	void load_from_file(const char* file_name);
	bool availability(Rezervare& r);
	list<int> places_available(int nr_zbor);
	void save_to_file(const char* fileName);
	//void save_to_file(const char* fileName);
};