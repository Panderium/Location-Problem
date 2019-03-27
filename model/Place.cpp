//
// Created by panderium on 21/02/19.
//
#include <math.h>
#include "Place.h"

Place::Place() = default;

Place::Place(std::string name, location loc) {
    this->m_name = std::move(name);
    this->m_loc = loc;
}

float Place::calculate_distance(Place *place) {
    return sqrt((m_latitude - place->m_latitude) * (m_latitude - place->m_latitude) +
                (m_longitude - place->m_longitude) * (m_longitude - place->m_longitude));
}

const std::string &Place::getM_name() const {
    return m_name;
}

const location &Place::getM_loc() const {
    return m_loc;
}

int Place::getM_num_ville() const {
    return m_num_ville;
}

float Place::getM_latitude() const {
    return m_latitude;
}

float Place::getM_longitude() const {
    return m_longitude;
}

char Place::getM_type() const {
    return m_type;
}

int Place::getM_besoin() const {
    return m_besoin;
}

Place::~Place() = default;