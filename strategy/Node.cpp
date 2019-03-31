#include <utility>

//
// Created by panderium on 19-03-29.
//

#include "Node.h"
#include <regex>

const std::vector<Place> &Node::getM_left_places() const {
    return m_left_places;
}


void Node::remove_delivered_place(Place place) {
    m_left_places.erase(std::remove(m_left_places.begin(), m_left_places.end(), place), m_left_places.end());
}

const Place &Node::getPlace() const {
    return place;
}

int Node::computeSolution(float value) {

    while (!m_left_places.empty() && value > m_cost) {
        m_cost += m_left_places.back().getM_besoin() * place.calculate_distance(m_left_places.back());
        m_left_places.pop_back();
    }
    return m_left_places.empty() && m_cost < value;
}

float Node::getM_cost() const {
    return m_cost;
}

Node::Node(const Place &place, const std::vector<Place> &m_left_places, float m_cost) : place(place),
                                                                                        m_left_places(m_left_places),
                                                                                        m_cost(m_cost) {}



