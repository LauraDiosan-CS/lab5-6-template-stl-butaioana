#pragma once
#include "Service.h"

class UI {
private:
	Service service;
public:
	UI();
	~UI();
	void add();
	void remove();
	void update();
	void modificare();
	void find_element();
	void get_size();
	void print();
	void run();
};