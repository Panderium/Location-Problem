//
// Created by panderium on 21/02/19.
//

#ifndef LOCATION_PROBLEM_ROAD_H
#define LOCATION_PROBLEM_ROAD_H

#include "place.h"

class road {
public:
    road();

    road(place city_a, place city_b);

    ~road();

private:
    place city_a;
    place city_b;
};

#endif //LOCATION_PROBLEM_ROAD_H
