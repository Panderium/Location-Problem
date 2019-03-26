//
// Created by panderium on 21/02/19.
//

#include "road.h"
#include <math.h>       /* sqrt */

road::road() = default;

road::road(place city_a, place city_b) {
    this->city_a = city_a;
    this->city_b = city_b;
}

void road::calcDist(){
    float lat_a = city_a.get_latitude();
    float lat_b = city_b.get_latitude();
    float long_a = city_a.get_longitude();
    float long_b = city_b.get_longitude();
    this->distance = sqrt((lat_a-lat_b)*(lat_a-lat_b)+
            (long_a-long_b)*(long_a-long_b));
}

road::~road() = default;