#pragma once
#include "Booking.h"
#include <list>
#include <fstream>
using namespace std;
template <class T>
class Repo {
protected:
	list<T> lista;
public:
	Repo();
	~Repo();

	void add(const T r);
	list<T>& get_all();
	int get_size();
	int remove(const T r);
	void update(const T r, const T newr);
	int find_element(const T r);
	void load_from_file(const char* fileName);
	void save_to_file(const char* file_name);
};

template <class T> Repo<T>::Repo() {};

template <class T> Repo<T>::~Repo() {};

template <class T> void Repo<T>::add(const T r) {

	lista.push_back(r);
}

template <class T> list<T>& Repo<T>::get_all() {

	return lista;
}

template <class T> int Repo<T>::get_size() {

	return (int)lista.size();
}

template <class T> int Repo<T>::remove(const T r) {

	list<T>::iterator it;
	it = find(lista.begin(), lista.end(), r);
	if (it != lista.end()) {
		lista.erase(it);
		return 0;
	}
	return -1;
}

template <class T> void Repo<T>::update(const T r, const T newr)
{
	list<T>::iterator it;
	it = find(lista.begin(), lista.end(), r);
	if (it != lista.end()) {
		*it = newr;
	}
}

template <class T> int Repo<T>::find_element(const T r) 
{
	list<T>::iterator it;
	it = find(lista.begin(), lista.end(), r);
	if (it != lista.end()) {
		return distance(lista.begin(), it);
	}
	return -1;
}

template <class T> void Repo<T>::load_from_file(const char* fileName) {
	lista.clear();
	fis = fileName;
	ifstream f(fileName);
	if (f.is_open()) {
		while (!f.eof()) {
			T elem;
			load_from_file_elem(f, elem);
			f >> elem;
			lista.push_back(elem);
		}
		f.close();
	}
	char* nume = new char[10];
	int varsta;
	
}
template <class T> void Repo<T>::save_to_file(const char* file_name) {
	ofstream z(file_name);
	list<T>::iterator it;
	for (it = lista.begin(); it != lista.end(); it++) {
		z << *it;
	}
	z.close();
}
