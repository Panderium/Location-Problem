//
// Created by panderium on 21/02/19.
//

#include "road.h"

road::road() = default;

road::road(place city_a, place city_b) {
    this->city_a = city_a;
    this->city_b = city_b;
}

road::~road() = default;