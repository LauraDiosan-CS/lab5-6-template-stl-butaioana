#pragma once
#include "repo.h"
class Service {
private:
	Repo repo;

public:

	void insert_sevice(char*,int, int);
	int get_len();
	Zbor* get_all();
	void set_len(int);
};