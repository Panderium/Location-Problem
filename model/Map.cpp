//
// Created by panderium on 19-03-29.
//

#include "Map.h"

void Map::add_place(Place p) {
    m_places.push_back(p);
}

const std::vector<Place> &Map::getM_places() const {
    return m_places;
}

void Map::setM_strategy(Strategy *m_strategy) {
    this->m_strategy = m_strategy;

}

void Map::execut_strategy() const{
    m_strategy->execute(m_places);
}

Map::Map() = default;
