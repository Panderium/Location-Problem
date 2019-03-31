//
// Created by panderium on 19-03-29.
//
#include <algorithm>
#include <iostream>
#include "Strategies.h"

void ExactStrategy::execute(std::vector<Place> places) {

    build_bb_matrix(places);
    m_frontier.resize(places.size());
    m_frontier = init_frontier(places);
    bb();
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
        //new Place(place.getM_name(), place.getM_loc(), place.getM_num_ville(), place.getM_latitude(),place.getM_longitude(), place.getM_type(), place.getM_besoin())
        Node *node = new Node(place, places, 0);
        node->remove_delivered_place(place);
        nodes.push_back(node);
        std::cout << nodes.back()->getPlace().getM_num_ville() << std::endl;
    }
    return nodes;
}

int ExactStrategy::bb() {
    float bestSolution = std::numeric_limits<float>::infinity();
    int idxBestSolution = 0;
    for (int i = 0; i < m_frontier.size(); ++i) {
        if (m_frontier[i]->computeSolution(bestSolution)) {
            bestSolution = m_frontier[i]->getM_cost();
            idxBestSolution = i;
        }
    }

    return idxBestSolution;
}