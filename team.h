#ifndef COUNTRY_H
#define COUNTRY_H

struct Country {

	std::string name;
	int points;
	std::vector <int> marks;

	Country(std::string name) {
		this->name = name;
		this->points = 0;
	}
};

void readCountries(std::ifstream&, std::vector <Country>&, int);
int toInt(std::string);
void showCountries(std::ofstream&, const std::vector <Country>&);
void calcPoints(std::vector <Country>&);
void finalSort(std::vector <Country>&);
#endif // COUNTRY_H
