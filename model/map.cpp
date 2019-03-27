//
// Created by panderium on 21/02/19.
//

#include <iostream>
#include "map.h"

map::map() {}

map::~map() {


}

void map::add_place(place p) {
    places.push_back(p);
}

std::vector<place> map::get_places() {
    return std::vector<place>();
}
