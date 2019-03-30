//
// Created by panderium on 19-03-29.
//
#include <algorithm>
<<<<<<< Updated upstream
#include "Strategies.h"
=======
#include <functional>


void ExactStrategy::execute(Map map) {
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
>>>>>>> Stashed changes

void ExactStrategy::execute(std::vector<Place> places) {
    build_bb_matrix(places);
    std::vector<Node *> frontier = init_frontier(places);
}

void ExactStrategy::build_bb_matrix(std::vector<Place> places) {
    for (Place place : places) {
        std::for_each(places.begin(), places.end(),
                      [&](Place otherPLace) {
                          m_matrix[place.getM_num_ville()][otherPLace.getM_num_ville()] = place.calculate_distance(otherPLace);
                      });
    }
    for (int i = 0; i < m_matrix.size(); ++i) {
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