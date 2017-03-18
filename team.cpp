#include <string>
#include <fstream>
#include <vector>
#include <math.h>
#include <algorithm>
#include "team.h"

#define LUCKY 10 // number of teams that receive points from one other country
int pointsForMarks[] = {12, 10, 8, 7, 6, 5, 4, 3, 2, 1};

int toInt(std::string s) {
	int res = 0;
	for (int i = s.length() - 1; i >= 0; --i) {
		res += int(s.at(i) - 48) * _Pow_int(10, s.length() - 1 - i);
	}
	return res;
}

void readCountries(std::ifstream& in, std::vector <Country>& country, int numberOfTeams) {
	std::string s; //current field in file

	for (int i = 0; i < numberOfTeams; ++i) {
		// reading of the name
		getline(in, s, ',');
		country.push_back(Country(s));
		for (int j = 0; j < numberOfTeams - 1; ++j) {
			//reading of the score
			getline(in, s, ',');
			country[i].marks.push_back(toInt(s));
		}
		//reading of the last score
		getline(in, s, '\n');
		country[i].marks.push_back(toInt(s));
	}
}

void showCountries(std::ofstream& out, const std::vector <Country>& country) {
	for (int i = 0; i < country.size(); ++i) {
		out << country.at(i).name
			<< ','
			<< country.at(i).points
			<< std::endl;
	}
}

void calcPoints(std::vector <Country>& country) {
	//i - number of country
	for (int i = 0; i < country.size(); ++i) {

		//sorting according to marks from country #i
		std::sort(country.begin(), country.end(), [i](const Country& country1, const Country& country2) {
		return country1.marks[i] > country2.marks[i];
		});

		//adding points
		for (int j = 0; j < LUCKY; ++j) {
			country[j].points += pointsForMarks[j];
		}

	}
}

void finalSort(std::vector <Country>& country) {
	std::sort(country.begin(), country.end(), [](const Country& country1, const Country& country2) {
		return country1.points > country2.points;
		});
}