//
// Created by panderium on 19-03-27.
//

#ifndef LOCATION_PROBLEM_NODE_H
#define LOCATION_PROBLEM_NODE_H


#include "../model/Truck.h"

class Node {
public:
    Node(int m_num_city, Node *m_father, Truck *m_truck, float m_branch_cost, float m_total_cost);

    Node *getM_father() const;

    int getM_num_city() const;

    Truck *getM_truck() const;

    float getM_branch_cost() const;

    float getM_total_cost() const;

    void add_to_total_cost(float cost);

private:
    int m_num_city;
    Node *m_father;
    Truck *m_truck;
    float m_branch_cost;
    float m_total_cost;
};


#endif //LOCATION_PROBLEM_NODE_H
