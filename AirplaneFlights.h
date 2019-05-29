#pragma once

#include <iostream>
#include <string>

using namespace std;

class AirFlights
{
public:
	string start;
	string finish;

	int price;

	AirFlights()
	{
		start = '\0';
		finish = '\0';
		price = 0;
	}
	friend ostream& operator << (ostream &s, const AirFlights &ptOut)
	{
		s << "\nFrom: " << ptOut.start << " \nTo: " << ptOut.finish << " \nPrice: " << ptOut.price << " \n";
		return s;
	}
	~AirFlights() {}
};