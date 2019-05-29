#pragma once
#include <assert.h>
#include "BasicListFunctions.h"
#include "AirplaneFlights.h"
#include "DijkstraAlgorithm.h"
#include "AdjList.h"
#include <stdio.h>
#include <fstream>
#include <iostream>
#include <string>
#include <clocale>
#include <cstdlib>
#include <conio.h>
#include <Windows.h>

using namespace std;

void test_all() {
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	List<AirFlights> flights_list;
	AirFlights buffer;
	buffer.start = "SaintPetersburg";
	buffer.finish = "Moscow";
	buffer.price = 10;
	flights_list.push_back(buffer);

	buffer.start = "Moscow";
	buffer.finish = "SaintPetersburg";
	buffer.price = 20;
	flights_list.push_back(buffer);

	buffer.start = "Moscow";
	buffer.finish = "Saratov";
	buffer.price = 40;
	flights_list.push_back(buffer);

	buffer.start = "Saratov";
	buffer.finish = "Moscow";
	buffer.price = 35;
	flights_list.push_back(buffer);

	buffer.start = "SaintPetersburg";
	buffer.finish = "Saratov";
	buffer.price = 14;
	flights_list.push_back(buffer);

	buffer.start = "Saratov";
	buffer.finish = "SaintPetersburg";
	buffer.price = 10;
	flights_list.push_back(buffer);

	buffer.start = "Kostroma";
	buffer.finish = "Saratov";
	buffer.price = 13;
	flights_list.push_back(buffer);

	buffer.start = "Saratov";
	buffer.finish = "Kostroma";
	buffer.price = 8;
	flights_list.push_back(buffer);

	buffer.start = "SaintPetersburg";
	buffer.finish = "Kostroma";
	buffer.price = 20;
	flights_list.push_back(buffer);

	buffer.start = "Moscow";
	buffer.finish = "RostovOnDon";
	buffer.price = 15;
	flights_list.push_back(buffer);

	DijkstraAlogrithm result1(flights_list);
	DijkstraAlogrithm result2(flights_list);
	string test1, test2;

	test1 = "SaintPetersburg";
	test2 = "Moscow";
	assert(result1.dij_shortest(test1, test2) == 10);
	cout << "\ntest - simple adjuiced nodes - succsesful\n";

	test1 = "Moscow";
	test2 = "Saratov";
	assert(result2.dij_shortest(test1, test2) == 34);
	cout << "\ntest - complex adjuiced nodes - succsesful\n";
}