#include "Service.h"
void Service::insert_sevice(char* nume, int id, int loc) {
	Zbor zbor(nume, id, loc);
	repo.insert(zbor);
}
Zbor* Service::get_all() {
	return this->repo.get_all();
}
int Service::get_len() {
	return this->repo.get_len();
}

void Service::set_len(int new_len) {
	this->repo.set_len(new_len);
}
