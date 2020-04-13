#include<iostream>
#include "Test.h"
#include <assert.h>
using namespace std;

void test() {
	list<Rezervare> lista;
	lista.clear();
	Rezervare b1("ioana",10,  5);
	Rezervare b2("ion",15,  2);
	lista.push_back(b1);
	lista.push_back(b2);
	assert(lista.size() == 2);
	assert(lista.front() == b1);
	assert(lista.back() == b2);

}
void testRepo() {
	Repo<Rezervare> r;
	Rezervare b1("ioana",10,  5);
	Rezervare b2("ion",15,  2);
	r.add(b1);
	r.add(b2);
	list<Rezervare> rezervari = r.get_all();
	assert(rezervari.front() == b1);
	assert(rezervari.back() == b2);
	int size = r.get_size();
	assert(size == 2);
	r.remove(b1);
	assert(r.get_size() == 1);
	int i0 = r.find_element(b2);
	assert(i0 == 0);
	r.update(b2, Rezervare( "iulian",12, 6));
	i0 = r.find_element(b2);
	assert(i0 == -1);
	
}

void testService() {
	Service serv;
	Rezervare b1("ioana", 10, 5);
	Rezervare b2("ion", 15, 2);
	list<int> locuri_disponibile;
	serv.add(b1, locuri_disponibile);
	serv.add(b2, locuri_disponibile);
	list<Rezervare> rezervari = serv.get_all();
	assert(rezervari.front() == b1);
	assert(rezervari.back() == b2);
	int size = serv.get_size();
	assert(size == 2);
	serv.remove(b1);
	assert(serv.get_size() == 1);
	int i0 = serv.find_element(b2);
	assert(i0 == 0);
	i0 = serv.find_element(b2);
	assert(i0 == -1);
}

void testFile() {
	//Repo<Booking> r;
	RepoFile<Rezervare> r;
	r.load_from_file("Bookings_test1.txt");
	int dim = r.get_size();
	assert(dim == 4);
}
void tests() {

	void test();
	void testRepo();
	void testService();
	void testFile();
	cout << "testele merg(*+*)";
}
/*void test_save_file() {
	Repo<Booking> r;
	r.load_from_file("Bookings_test1.txt");
	r.save_to_file("Bookings_write.txt");
}*/