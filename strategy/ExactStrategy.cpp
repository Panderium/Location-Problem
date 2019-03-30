//
// Created by panderium on 19-03-29.
//
#include <algorithm>
#include <iostream>
#include "Strategies.h"

void ExactStrategy::execute(std::vector<Place> places) {

    build_bb_matrix(places);
    std::vector<Node *> frontier = init_frontier(places);
}

void ExactStrategy::build_bb_matrix(std::vector<Place> places) {
    m_matrix.resize(places.size() + 1);
    std::for_each(places.begin(), places.end(), [=](Place place) {
        m_matrix[place.getM_num_ville()].resize(places.size() + 1);
        std::for_each(places.begin(), places.end(), [=](Place place1) {
            this->m_matrix[place.getM_num_ville()][place1.getM_num_ville()] = place1.calculate_distance(place);
        });
    });
    for (int i = 1; i < places.size() + 1; ++i) {
        m_matrix[i][i] = std::numeric_limits<float>::infinity();
    }
}

std::vector<Node *> ExactStrategy::init_frontier(std::vector<Place> places) {
    std::vector<Node *> nodes;
    for (Place place : places) {
        Node *node = new Node(&place, NULL, places, 0, 0);
        //node->remove_delivered_place(&place);
        nodes.push_back(node);
    }
    return nodes;
}