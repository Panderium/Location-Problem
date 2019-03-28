//
// Created by panderium on 19-03-27.
//

#ifndef LOCATION_PROBLEM_NODE_H
#define LOCATION_PROBLEM_NODE_H


#include "../model/Truck.h"

class Node {
public:
    Node(Node *m_father, int m_num_city, float m_coast);

    Node *getM_father() const;

    int getM_num_city() const;

    float getM_coast() const;

    Truck *getM_truck() const;

private:
    int m_num_city;
    Node *m_father;
    Truck *m_truck;
    float m_coast;
};


#endif //LOCATION_PROBLEM_NODE_H
