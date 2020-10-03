#pragma once
#include "query.h"

istream& operator >> (istream& is, Query& q) {

	int flag = 0;
	string operation_code;
	int stop_count = 0;
	is >> operation_code;

	if (operation_code == "NEW_BUS") {
		q.type = QueryType::NewBus;
		is >> q.bus >> stop_count;

		q.stops.clear();
		for (size_t i = 0; i < stop_count; i++) {
			is >> q.stop;
			q.stops.push_back(q.stop);
		}
	}
	else if (operation_code == "BUSES_FOR_STOP") {
		q.type = QueryType::BusesForStop;
		is >> q.stop;
	}
	else if (operation_code == "STOPS_FOR_BUS") {
		q.type = QueryType::StopsForBus;
		is >> q.bus;
	}
	else if (operation_code == "ALL_BUSES") {
		q.type = QueryType::AllBuses;
	}
	return is;
}