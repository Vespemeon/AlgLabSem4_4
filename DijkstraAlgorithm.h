#pragma once

#include <iostream>
#include "BasicListFunctions.h"
#include "AirplaneFlights.h"
#include "AdjList.h"
#include <string>

using namespace std;

class DijkstraAlogrithm {
public:
	List<AdjList> adj_list;
	DijkstraAlogrithm(List<AirFlights> flights_list) {
		bool found = 0;
		size_t found_num;

		for (int i = 0; i < flights_list.get_size(); i++)
		{
			AdjList *temp = new AdjList;
			for (int j = 0; j < adj_list.get_size(); j++)
				if (adj_list.at(j).departure == flights_list.at(i).start) {
					found = 1;
					found_num = j;
					break;
				}
			if (!found) {
				temp->departure = flights_list.at(i).start;
				temp->arrivals.push_back(flights_list.at(i).finish);
				temp->arrival_prices.push_back(flights_list.at(i).price);
				adj_list.push_back(*temp);
			}
			else
			{
				*temp = adj_list.at(found_num);
				temp->arrivals.push_back(flights_list.at(i).finish);
				temp->arrival_prices.push_back(flights_list.at(i).price);
				adj_list.set(found_num, *temp);
			}
			found = 0;

		}
	}
	AdjList* find(string name) {
		for (int i = 0; i < adj_list.get_size(); i++)
			if (adj_list.at(i).departure == name) {
				AdjList *found = new AdjList;
				*found = adj_list.at(i);
				return found;
			}
		return nullptr;
	}

	int dij_shortest(string pt1, string pt2) {
		int number_of_points = adj_list.get_size();
		AdjList *st_point = find(pt1);
		if (st_point == nullptr) {
			cout << "There is no such point as " << pt1 << " or no ways from it\n";
			return -1;
		}

		AdjList *fin_point = find(pt2);
		if (fin_point == nullptr) {
			cout << "There is no such point as " << pt2 << "\n";
			return -1;
		}
		List<dijkstra_node> dijkstra_list;
		List<string> checked_list;
		dijkstra_node start_dijkstra(st_point, 0);
		start_dijkstra.path = pt1;
		dijkstra_list.push_back(start_dijkstra);
		checked_list.push_front(start_dijkstra.curr_node.departure);
		number_of_points--;
		while (number_of_points > 0) {
			int min = 10000000;
			int out_cur_num = -1;
			int in_cur_num = -1;
			for (int i = 0; i < dijkstra_list.get_size(); i++)
				for (int j = 0; j < dijkstra_list.at(i).curr_node.arrival_prices.get_size(); j++)
					if ((min > dijkstra_list.at(i).curr_node.arrival_prices.at(j)) && (!checked_list.isThere(dijkstra_list.at(i).curr_node.arrivals.at(j)))) {
						min = dijkstra_list.at(i).curr_node.arrival_prices.at(j);
						out_cur_num = i;
						in_cur_num = j;
					}
			if (out_cur_num<0 || in_cur_num < 0) {
				for (int i = 0; i< adj_list.get_size(); i++)
					if (!checked_list.isThere(adj_list.at(i).departure)) {
						AdjList *new_unreach = new AdjList;
						*new_unreach = adj_list.at(i);
						dijkstra_node unreacheble(new_unreach, -1);
						unreacheble.path = "INF";
						dijkstra_list.push_back(unreacheble);
						checked_list.push_back(unreacheble.curr_node.departure);
					}
				number_of_points--;
				break;

			}
			else {
				AdjList *cur_point = find(dijkstra_list.at(out_cur_num).curr_node.arrivals.at(in_cur_num));
				if (cur_point == nullptr) {
					cur_point = new AdjList();
					string buf = dijkstra_list.at(out_cur_num).curr_node.arrivals.at(in_cur_num);
					cur_point->departure = buf;
				}
				dijkstra_node *cur_dijkstra = new dijkstra_node(cur_point, dijkstra_list.at(out_cur_num).curr_node.arrival_prices.at(in_cur_num));
				cur_dijkstra->path = dijkstra_list.at(out_cur_num).path;
				cur_dijkstra->path += "-";
				cur_dijkstra->path += cur_point->departure;

				dijkstra_list.push_back(*cur_dijkstra);
				checked_list.push_back(cur_dijkstra->curr_node.departure);
				number_of_points--;
			}

		}
		for (int i = 0; i < dijkstra_list.get_size(); i++)
			if (dijkstra_list.at(i).curr_node.departure == pt2) {
				cout << "Minimal price for jorney from " << pt1 << " to " << pt2 << " is " << dijkstra_list.at(i).path_price;
				cout << "\nMinimal path: ";
				cout << dijkstra_list.at(i).path;
				return dijkstra_list.at(i).path_price;
			}
		cout << "There is no way from " << pt1 << " to " << pt2;
		return -1;
	}
	~DijkstraAlogrithm() {}
};