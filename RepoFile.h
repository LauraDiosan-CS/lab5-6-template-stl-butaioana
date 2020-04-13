#pragma once
#include "Repo.h"
template <class T>
class RepoFile :
	public Repo<Rezervare>
{
public:
	RepoFile();
	~RepoFile();
	void load_from_file(const char* file_name);
	void save_to_file(const char* file_name);
};

template <class T> 
RepoFile<T>::RepoFile() {

}

template <class T>
RepoFile<T>::~RepoFile() {

}

template <class T>
void RepoFile<T>::load_from_file(const char* file_name) {
	lista.clear();
	ifstream z(file_name);
	if (z.is_open()) {
		while (!z.eof()) {
			T element;
			load_from_file_element(z, element);
			lista.push_back(element);
		}
		z.close();
	}
}
template <class T>
void RepoFile<T>::save_to_file(const char* file_name) {
	ofstream z(file_name);
	list<T>::iterator it;
	for (it = lista.begin(); it != lista.end(); it++) {
		z << *it;
	}
	z.close();
}