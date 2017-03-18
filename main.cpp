#include <fstream>
#include <string>
#include <vector>
#include <algorithm>
#include "team.h"

int main() {
	std::ifstream in("eurovision.csv");
	std::ofstream out("results.csv");

	std::string s;
	getline(in, s, '\n');
	int N = toInt(s); // number of teams

	std::vector <Country> country;

	readCountries(in,country,N);
	calcPoints(country);
	finalSort(country);
	showCountries(out, country);

	return 0;
}