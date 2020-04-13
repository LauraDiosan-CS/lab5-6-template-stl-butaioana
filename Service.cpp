#include "Service.h"
#include <set>
Service::Service()
{}

Service::Service(const RepoFile<Rezervare>& r)
{
	repo = r;
}
bool Service::add(Rezervare& r, list<int>& available_flight)
{
	if (availability(r)) {
		repo.add(r);
		return true;
	}
	else
	{
		available_flight = places_available(r.get_nr_zbor());
		return false;
	}
}
list<Rezervare> Service::get_all()
{
	return repo.get_all();
}
int Service::get_size()
{
	return repo.get_size();
}
int Service::remove(Rezervare& r)
{
	return repo.remove(r);
}
void Service::update(Rezervare& r, Rezervare& rnew)
{
		repo.update(r, rnew);
}
int Service::find_element(Rezervare& r)
{
	return repo.find_element(r);
}


Service::~Service() {

}
void Service::load_from_file(const char* file_name) {
	repo.load_from_file(file_name);
}
void Service::save_to_file(const char* fileName){
	repo.save_to_file(fileName);
}
list<int> Service::places_available(int nr_zbor) {
	list<Rezervare> lista = repo.get_all();
	set<int> locuri_ocupate;
	if (nr_zbor >200)
		cout << "locul nu exista";
	else
	{
		for (Rezervare rr : lista) {
			int fl_nr = rr.get_nr_zbor();
			if (fl_nr == nr_zbor) {
				locuri_ocupate.insert(rr.get_nr_loc());
				cout << "locul este ocupat";
			}
		}
		list<int> locuri_libere;
		for (int place = 1; place <= X; place++) {
			if (locuri_ocupate.find(place) == locuri_ocupate.end())
				locuri_libere.push_back(place);

		}

		return locuri_libere;
	}
}
bool Service::modificare(Rezervare& r, Rezervare& rnew, list<int>& seats_available_flight_update)
{

	if (availability(r)) {
		repo.update(r, rnew);
		return true;
	}
	else
	{
		seats_available_flight_update = places_available(r.get_nr_zbor());
		return false;
	}
}
bool Service::availability(Rezervare& r) {
	list<Rezervare> lista = repo.get_all();
	int place = r.get_nr_loc();
	int flight = r.get_nr_zbor();
	for (Rezervare rr : lista)
	{
		if (rr.get_nr_zbor() == flight && rr.get_nr_loc() == place) {
			return false;
		}
			
	}
	if (place > X)
			cout << "locul nu exista"<<endl;
	return true;
}


