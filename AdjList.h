#pragma once

#include <iostream>
#include <string>
#include "BasicListFunctions.h"

using namespace std;

class AdjList
{
public:
	string departure;

	List<string> arrivals;
	List<int> arrival_prices;

	AdjList()
	{
	}

	~AdjList() {}
};

class dijkstra_node
{
public:
	AdjList curr_node;
	int path_price;
	string path = "\0";
	dijkstra_node(AdjList *curr_node, int path_price)
	{
		this->curr_node = *curr_node;

		this->path_price = path_price;
		for (int i = 0; i < curr_node->arrival_prices.get_size(); i++) {
			int curr_price = curr_node->arrival_prices.at(i) + path_price;
			curr_node->arrival_prices.set(i, curr_price);
		}

	}

	dijkstra_node() {}
	~dijkstra_node() {}
};