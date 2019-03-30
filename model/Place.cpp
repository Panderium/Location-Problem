//
// Created by panderium on 19-03-29.
//

#include <iostream>
#include "Place.h"

const std::string &Place::getM_name() const {
    return m_name;
}

void Place::setM_name(const std::string &m_name) {
    Place::m_name = m_name;
}

const Location &Place::getM_loc() const {
    return m_loc;
}

void Place::setM_loc(const Location &m_loc) {
    Place::m_loc = m_loc;
}

int Place::getM_num_ville() const {
    return m_num_ville;
}

void Place::setM_num_ville(int m_num_ville) {
    Place::m_num_ville = m_num_ville;
}

float Place::getM_latitude() const {
    return m_latitude;
}

void Place::setM_latitude(float m_latitude) {
    Place::m_latitude = m_latitude;
}

float Place::getM_longitude() const {
    return m_longitude;
}

void Place::setM_longitude(float m_longitude) {
    Place::m_longitude = m_longitude;
}

char Place::getM_type() const {
    return m_type;
}

void Place::setM_type(char m_type) {
    Place::m_type = m_type;
}

int Place::getM_besoin() const {
    return m_besoin;
}

void Place::setM_besoin(int m_besoin) {
    Place::m_besoin = m_besoin;
}

float Place::calculate_distance(Place place) const {
    return sqrt((m_latitude - place.m_latitude) * (m_latitude - place.m_latitude) +
                (m_longitude - place.m_longitude) * (m_longitude - place.m_longitude));
}

void Place::print() {
    std::cout << "Numero de ville " << std::endl;
    std::cout << m_num_ville << std::endl;
    std::cout << " latitude " << std::endl;
    std::cout << m_latitude << std::endl;
    std::cout << " longitude " << std::endl;
    std::cout << m_longitude << std::endl;

}
