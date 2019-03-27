//
// Created by panderium on 21/02/19.
//

#include <iostream>
#include "map.h"

map::map() {}

map::~map() {


}

map map::add_place(place p) {
    places.push_back(p);
    return map();
}
