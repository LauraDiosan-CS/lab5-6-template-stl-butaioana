#pragma once
#include "Zbor.h"
class Repo
{
public:
	Repo();
	~Repo();
	void insert(Zbor);
	int get_len();
	Zbor* get_all();
	void set_len(int);

private:
	Zbor v[101];

	int len;
};

