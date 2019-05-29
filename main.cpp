#include "BasicListFunctions.h"
#include "AirplaneFlights.h"
#include "DijkstraAlgorithm.h"
#include "AdjList.h"
#include "TestDijkstraAlgorithm.h"
#include <fstream>
#include <iostream>
#include <string>
#include <clocale>
#include <cstdlib>
#include <conio.h>
#include <Windows.h>

using namespace std;

template <class T>
void separateString(List<T> *graph_list);

int main()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

	cout << "\n";
	test_all();

	string str;
	List<string> *rec_list = new List<string>;

	ifstream in("input.txt");
	while (getline(in, str)) {
		rec_list->push_back(str);

	}

	separateString(rec_list);
	system("PAUSE");
}

template <class T>
void separateString(List<T> *rec_list) {
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	List<AirFlights> flights_list;

	string temp_sep, sity1, sity2, pr1, pr2;
	int cost1, cost2, sublen;
	for (int i = 0; i < rec_list->get_size(); i++) {
		temp_sep = rec_list->at(i);

		sublen = temp_sep.find_first_of(";");
		sity1 = temp_sep.substr(0, sublen);
		temp_sep.erase(0, sublen + 1);

		sublen = temp_sep.find_first_of(";");
		sity2 = temp_sep.substr(0, sublen);
		temp_sep.erase(0, sublen + 1);

		sublen = temp_sep.find_first_of(";");
		pr1 = temp_sep.substr(0, sublen);
		temp_sep.erase(0, sublen + 1);
		if (pr1 == "N/A")
			cost1 = -1;
		else
			cost1 = atoi(pr1.c_str());

		pr2 = temp_sep;
		if (pr2 == "N/A")
			cost2 = -1;
		else
			cost2 = atoi(pr2.c_str());

		if (cost1 > 0) {
			AirFlights nextflight; 
			nextflight.start = sity1;
			nextflight.finish = sity2;
			nextflight.price = cost1;
			flights_list.push_back(nextflight);
		}
		if (cost2 > 0) {
			AirFlights nextflight; 
			nextflight.start = sity2;
			nextflight.finish = sity1;
			nextflight.price = cost2;
			flights_list.push_back(nextflight);
		}
	}
	DijkstraAlogrithm result(flights_list);
	string point1, point2;
	cout << "\n";
	getline(cin, point1);
	getline(cin, point2);
	result.dij_shortest(point1, point2);
}