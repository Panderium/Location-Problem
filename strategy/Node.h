//
// Created by panderium on 19-03-29.
//

#ifndef LOCATION_PROBLEM_NODE_H
#define LOCATION_PROBLEM_NODE_H


#include <vector>
#include "../model/Place.h"
#include "../model/Solution.h"

class Node {
public:

    Node(const Place &place, const std::vector<Place> &m_left_places, float m_cost);

    const Place &getPlace() const;

    float getM_cost() const;

    const std::vector<Place> &getM_left_places() const;

    void remove_delivered_place(Place place);

    int computeSolution(float value);

private:
    Place place;
    std::vector<Place> m_left_places;
    float m_cost;
};


#endif //LOCATION_PROBLEM_NODE_H
