//
// Created by panderium on 19-03-27.
//

#include <regex>
#include "Node.h"


Node *Node::getM_father() const {
    return m_father;
}


Truck *Node::getM_truck() const {
    return m_truck;
}

float Node::getM_branch_cost() const {
    return m_branch_cost;
}

float Node::getM_total_cost() const {
    return m_total_cost;
}

void Node::add_to_total_cost(float cost) {
    m_total_cost += cost;
}

const std::vector<Place> &Node::getM_left_places() const {
    return m_left_places;
}

int Node::remove_delivered_place(Place *place) {
    auto it = std::find(m_left_places.begin(), m_left_places.end(), place);
    if (m_left_places.end() >= it) {
        m_left_places.erase(m_left_places.begin(), m_left_places.begin() + std::distance(m_left_places.begin(), it));
        return 0;
    }
    return 1;
}

Place *Node::getPlace() const {
    return place;
}

Node::Node(Place *place, Node *m_father, Truck *m_truck, const std::vector<Place> &m_left_places, float m_branch_cost,
           float m_total_cost) : place(place), m_father(m_father), m_truck(m_truck), m_left_places(m_left_places),
                                 m_branch_cost(m_branch_cost), m_total_cost(m_total_cost) {}




