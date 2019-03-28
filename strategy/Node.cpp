//
// Created by panderium on 19-03-27.
//

#include "Node.h"

Node::Node(int m_num_city, Node *m_father, Truck *m_truck, float m_branch_cost, float m_total_cost) : m_num_city(
        m_num_city), m_father(m_father), m_truck(m_truck), m_branch_cost(m_branch_cost), m_total_cost(m_total_cost) {}

Node *Node::getM_father() const {
    return m_father;
}


int Node::getM_num_city() const {
    return m_num_city;
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




