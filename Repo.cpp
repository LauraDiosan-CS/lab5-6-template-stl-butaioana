#include "Repo.h"

Repo::Repo()
{
	this->len = 0;
}
Repo::~Repo() {
	this->len = 0;
}
void Repo::insert(Zbor examinare) {
	this->v[this->len++] = examinare;
}
int Repo::get_len() {
	return this->len;
}
Zbor* Repo::get_all() {
	return this->v;
}
void Repo::set_len(int new_len) {
	this->len = new_len;
}