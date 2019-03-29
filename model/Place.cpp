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

float Place::calculate_distance(Place place) {
    return sqrt((m_latitude - place.m_latitude) * (m_latitude - place.m_latitude) +
                (m_longitude - place.m_longitude) * (m_longitude - place.m_longitude));
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

void Place::setM_name(const std::string &m_name) {
    Place::m_name = m_name;
}

void Place::setM_loc(const location &m_loc) {
    Place::m_loc = m_loc;
}

void Place::setM_num_ville(int m_num_ville) {
    Place::m_num_ville = m_num_ville;
}

void Place::setM_latitude(float m_latitude) {
    Place::m_latitude = m_latitude;
}

void Place::setM_longitude(float m_longitude) {
    Place::m_longitude = m_longitude;
}

void Place::setM_type(char m_type) {
    Place::m_type = m_type;
}

void Place::setM_besoin(int m_besoin) {
    Place::m_besoin = m_besoin;
}

Place::~Place() = default;