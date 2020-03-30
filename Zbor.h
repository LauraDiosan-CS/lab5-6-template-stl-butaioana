#pragma once
#include<ostream>
class Zbor
{
private:
	char* nume;
	int id;
	int loc;
public:
	Zbor();
	Zbor(char*, int, int);
	Zbor(const Zbor&);
	~Zbor();
	char* get_nume();
	int get_id();
	int get_loc();

	void set_nume(char* new_nume);
	void set_id(int new_id);
	void set_loc(int new_loc);
	// Suprascrierea operatorilor '=', "==" și "<<"Student& operator = (const Student& );
	Zbor& operator =(const Zbor&);
	bool operator == (const Zbor&);
	friend std::ostream& operator << (std::ostream&, const Zbor&);

};
