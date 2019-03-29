//
// Created by panderium on 21/02/19.
//

#include <iostream>
#include "Map.h"


Map::Map() {
    m_strategy = NULL;
}

Map::~Map() = default;

Map Map::add_place(Place p) {
    m_places.push_back(p);
    return Map();
}

void Map::set_strategy(Strategy *strat) {
    Map::m_strategy = strat;
}

void Map::apply_methode() {
    m_strategy->execute(this);
}

const std::vector<Place> &Map::getM_places() const {
    return m_places;
}


const std::vector<Truck> &Map::getM_trucks() const {
    return m_trucks;
}

const Headquater &Map::getM_hq() const {
    return m_hq;
}






