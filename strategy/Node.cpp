//
// Created by panderium on 19-03-27.
//

#include "Node.h"

Node::Node(Node *m_father, int m_num_city, float m_coast) : m_father(m_father), m_num_city(m_num_city),
                                                            m_coast(m_coast) {}

Node *Node::getM_father() const {
    return m_father;
}


int Node::getM_num_city() const {
    return m_num_city;
}


float Node::getM_coast() const {
    return m_coast;
}


Truck *Node::getM_truck() const {
    return m_truck;
}


