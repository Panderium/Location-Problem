//
// Created by panderium on 19-03-27.
//

#ifndef LOCATION_PROBLEM_NODE_H
#define LOCATION_PROBLEM_NODE_H


#include <vector>
#include "../model/Truck.h"
#include "../model/Place.h"

class Node {
public:
    Node(Place *place, Node *m_father, Truck *m_truck, const std::vector<Place> &m_left_places, float m_branch_cost,
         float m_total_cost);

    Node *getM_father() const;

    Place *getPlace() const;

    Truck *getM_truck() const;

    float getM_branch_cost() const;

    float getM_total_cost() const;

    void add_to_total_cost(float cost);

    const std::vector<Place> &getM_left_places() const;

    int remove_delivered_place(Place *place);

private:
    Place *place;
    Node *m_father;
    Truck *m_truck;
    std::vector<Place> m_left_places;
    float m_branch_cost;
    float m_total_cost;
};


#endif //LOCATION_PROBLEM_NODE_H
