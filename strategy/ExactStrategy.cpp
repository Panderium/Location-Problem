//
// Created by panderium on 21/02/19.
//

#include "Strategies.h"
#include <vector>
#include <iostream>
#include <algorithm>
#include <functional>


void ExactStrategy::execute(Map *map) {
    Strategy::execute(map);
    build_bb_matrix();
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



