//
// Created by panderium on 21/02/19.
//

#include "Strategies.h"
#include "Node.h"
#include <vector>
#include <iostream>
#include <algorithm>
#include <functional>


void ExactStrategy::execute(Map &map) {
    Strategy::execute(map);
    build_bb_matrix();
    std::vector<Node *> frontier = init_frontier();

    while (std::for_each(frontier.begin(), frontier.end(),
                         [](Node *node) { return !node->getM_left_places().empty(); })) {
        branch();
        bound();
    }
    //TODO : traiter la branche ayant la solution
}

ExactStrategy::ExactStrategy() : Strategy() {
}

void ExactStrategy::build_bb_matrix() {
    for (Place place : m_places) {
        std::for_each(m_places.begin(), m_places.end(),
                      [&](Place *otherPLace) {
                          m_matrix[place.getM_num_ville()][otherPLace->getM_num_ville()] = place.calculate_distance(
                                  otherPLace);
                      });
    }
    for (int i = 0; i < m_matrix.size(); ++i) {
        m_matrix[i][i] = std::numeric_limits<float>::infinity();
    }
}

std::vector<Node *> ExactStrategy::init_frontier() {
    std::vector<Node *> nodes;
    for (Place place : m_places) {
        Node *node = new Node(&place, NULL, new Truck, m_places, 0, 0);
        node->remove_delivered_place(&place);
        nodes.push_back(node);
    }
    return nodes;
}

void ExactStrategy::branch() {

}

void ExactStrategy::bound() {

}
