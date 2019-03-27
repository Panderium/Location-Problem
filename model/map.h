//
// Created by panderium on 21/02/19.
//

#ifndef LOCATION_PROBLEM_MAP_H
#define LOCATION_PROBLEM_MAP_H


#include <vector>
#include "place.h"
#include "road.h"
#include "truck.h"
#include "headquater.h"

class map {
public:
    map();

    virtual ~map();

public:
    void add_place(place p);
    std::vector<place> get_places();
private:
    std::vector<place> places;
    std::vector<road> roads;
    std::vector<truck> trucks;
    headquater hq;
};


#endif //LOCATION_PROBLEM_MAP_H
